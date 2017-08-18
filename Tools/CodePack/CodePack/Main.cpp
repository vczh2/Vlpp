#include "../../../Release/Vlpp.h"

using namespace vl;
using namespace vl::collections;
using namespace vl::filesystem;
using namespace vl::parsing;
using namespace vl::parsing::xml;
using namespace vl::regex;
using namespace vl::console;
using namespace vl::stream;

LazyList<FilePath> SearchFiles(const Folder& folder, const WString& extension)
{
	List<File> files;
	List<Folder> folders;
	folder.GetFiles(files);
	folder.GetFolders(folders);

	return From(files)
		.Select([](const File& file) { return file.GetFilePath(); })
		.Where([=](const FilePath& path) { return INVLOC.EndsWith(path.GetName(), extension, Locale::IgnoreCase); })
		.Concat(
			From(folders)
			.SelectMany([=](const Folder& folder) { return SearchFiles(folder, extension); })
			);
}

LazyList<FilePath> GetCppFiles(const FilePath& folder)
{
	return SearchFiles(folder, L".cpp");
}

LazyList<FilePath> GetHeaderFiles(const FilePath& folder)
{
	return SearchFiles(folder, L".h");
}

void CategorizeCodeFiles(Ptr<XmlDocument> config, LazyList<FilePath> files, Group<WString, FilePath>& categorizedFiles)
{
	FOREACH(Ptr<XmlElement>, e, XmlGetElements(XmlGetElement(config->rootElement, L"categories"), L"category"))
	{
		auto name = XmlGetAttribute(e, L"name")->value.value;
		auto pattern = wupper(XmlGetAttribute(e, L"pattern")->value.value);

		List<WString> exceptions;
		CopyFrom(
			exceptions,
			XmlGetElements(e,L"except")
				.Select([](const Ptr<XmlElement> x)
				{
					return XmlGetAttribute(x, L"pattern")->value.value;
				})
			);

		List<FilePath> filterFiles;
		CopyFrom(
			filterFiles,
			From(files).Where([&](const FilePath& f)
				{
					auto path = f.GetFullPath();
					return INVLOC.FindFirst(path, pattern, Locale::IgnoreCase).key != -1
						&& From(exceptions).All([&](const WString& ex)
						{
							return INVLOC.FindFirst(path, ex, Locale::IgnoreCase).key == -1;
						});
				})
			);

		FOREACH(FilePath, file, filterFiles)
		{
			if (!categorizedFiles.Contains(name, file))
			{
				categorizedFiles.Add(name, file);
			}
		}
	}

	FOREACH(WString, a, categorizedFiles.Keys())
	{
		FOREACH(WString, b, categorizedFiles.Keys())
		{
			if (a != b)
			{
				const auto& as = categorizedFiles.Get(a);
				const auto& bs = categorizedFiles.Get(b);
				CHECK_ERROR(!From(as).Intersect(bs).IsEmpty(), L"A file should not appear in multiple categories.");
			}
		}
	}
}

LazyList<FilePath> GetIncludedFiles(const FilePath& codeFile)
{
	static Dictionary<FilePath, LazyList<FilePath>> scannedFiles;
	static Regex regexInclude(LR"/(^\s\#include\s*"(?<path>[^"]+)"\s*$)/");

	{
		vint index = scannedFiles.Keys().IndexOf(codeFile);
		if (index != -1)
		{
			return scannedFiles.Values()[index];
		}
	}

	List<FilePath> includes;
	WString text;
	{
		BomEncoder::Encoding encoding;
		bool containsBom;
		File(codeFile).ReadAllTextWithEncodingTesting(text, encoding, containsBom);
	}

	StringReader reader(text);
	while (!reader.IsEnd())
	{
		auto line = reader.ReadLine();
		if (auto match = regexInclude.MatchHead(line))
		{
			auto path = codeFile.GetFolder() / match->Groups()[L"path"][0].Value();
			if (!includes.Contains(path))
			{
				includes.Add(path);
			}
		}
	}

	auto result = MakePtr<List<FilePath>>();
	CopyFrom(
		*result.Obj(),
		From(includes)
			.Concat(From(includes).SelectMany(GetIncludedFiles))
			.Distinct()
		);

	scannedFiles.Add(codeFile, result);
	return result;
}

LazyList<WString> SortDependencies(const Group<WString, WString>& dependencies)
{
	List<WString> unsorted;
	Group<WString, WString> deps;
	CopyFrom(
		unsorted,
		From(dependencies.Keys())
		.Concat(Range<vint>(0, dependencies.Count())
			.SelectMany([&](vint index)->LazyList<WString> { return dependencies.GetByIndex(index); })
			)
			.Distinct()
		);
	CopyFrom(deps, dependencies);

	auto sorted = MakePtr<List<WString>>();
	while (true)
	{
		vint count = unsorted.Count();

		FOREACH_INDEXER(WString, category, index, unsorted)
		{
			if (!deps.Keys().Contains(category))
			{
				sorted->Add(category);
				for (vint i = deps.Count() - 1; i >= 0; i--)
				{
					deps.Remove(deps.Keys()[i], category);
				}
				break;
			}
		}

		if (unsorted.Count() == 0) break;
		CHECK_ERROR(count != unsorted.Count(), L"Cycle dependency is not allowed.");
	}
	return sorted;
}

FilePath GetCommonFolder(const List<FilePath>& paths)
{
	auto folder = paths[0].GetFolder();
	while (true)
	{
		if (From(paths).All([&](const FilePath& path)
			{
				return INVLOC.StartsWith(path.GetFullPath(), folder.GetFullPath() + WString(folder.Delimiter), Locale::IgnoreCase);
			}))
		{
			return folder;
		}
		folder = folder.GetFolder();
	}
	CHECK_FAIL(L"Cannot process files across multiple drives.");
}

#if defined VCZH_MSVC
int wmain(int argc, wchar_t* argv[])
#elif defined VCZH_GCC
int main(int argc, char* argv[])
#endif
{
	return 0;
}