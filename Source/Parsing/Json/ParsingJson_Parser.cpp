﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Parser::ParsingJson.parser.txt

This file is generated by: Vczh Parser Generator
***********************************************************************/

#include "../Parsing.h"
#include "../ParsingDefinitions.h"
#include "../ParsingAutomaton.h"
#include "ParsingJson_Parser.h"

namespace vl
{
	namespace parsing
	{
		namespace json
		{
/***********************************************************************
ParserText
***********************************************************************/

const wchar_t parserTextBuffer[] = 
L"\r\n" L""
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L"// AST"
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L""
L"\r\n" L"class Node"
L"\r\n" L"{"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Literal:Node"
L"\r\n" L"{"
L"\r\n" L"\tenum Value"
L"\r\n" L"\t{"
L"\r\n" L"\t\tTrue,"
L"\r\n" L"\t\tFalse,"
L"\r\n" L"\t\tNull,"
L"\r\n" L"\t}"
L"\r\n" L""
L"\r\n" L"\tValue value;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class String:Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content(JsonUnescapingString)\t\t\t\t@Color(\"String\");"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Number:Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken content;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Array:Node"
L"\r\n" L"{"
L"\r\n" L"\tNode[] items;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class ObjectField:Node"
L"\r\n" L"{"
L"\r\n" L"\ttoken name(JsonUnescapingString)\t\t\t\t@Color(\"AttName\");"
L"\r\n" L"\tNode value;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"class Object:Node"
L"\r\n" L"{"
L"\r\n" L"\tObjectField[] fields;"
L"\r\n" L"}"
L"\r\n" L""
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L"// Lexer"
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L""
L"\r\n" L"token TRUEVALUE = \"true\"\t\t\t\t\t\t\t@Color(\"Keyword\");"
L"\r\n" L"token FALSEVALUE = \"false\"\t\t\t\t\t\t\t@Color(\"Keyword\");"
L"\r\n" L"token NULLVALUE = \"null\"\t\t\t\t\t\t\t@Color(\"Keyword\");"
L"\r\n" L"token OBJOPEN = \"\\{\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token OBJCLOSE = \"\\}\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token ARROPEN = \"\\[\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token ARRCLOSE = \"\\]\"\t\t\t\t\t\t\t\t@Color(\"Boundary\");"
L"\r\n" L"token COMMA = \",\";"
L"\r\n" L"token COLON = \":\";"
L"\r\n" L"token NUMBER = \"[\\-]?\\d+(.\\d+)?([eE][+\\-]?\\d+)?\"\t@Color(\"Number\");"
L"\r\n" L"token STRING = \"\"\"([^\\\\\"\"]|\\\\[^u]|\\\\u\\d{4})*\"\"\"\t\t@ContextColor();"
L"\r\n" L""
L"\r\n" L"discardtoken SPACE = \"\\s+\";"
L"\r\n" L""
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L"// Rules"
L"\r\n" L"//////////////////////////////////////////////////////////////////"
L"\r\n" L""
L"\r\n" L"rule Node JLiteral"
L"\r\n" L"\t= STRING:content as String"
L"\r\n" L"\t= NUMBER:content as Number"
L"\r\n" L"\t= \"true\" as Literal with {value = \"True\"}"
L"\r\n" L"\t= \"false\" as Literal with {value = \"False\"}"
L"\r\n" L"\t= \"null\" as Literal with {value = \"Null\"}"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule ObjectField JField"
L"\r\n" L"\t= STRING:name \":\" JValue:value as ObjectField"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Object JObject"
L"\r\n" L"\t= \"{\" [JField:fields {\",\" JField:fields} ] \"}\" as Object"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Array JArray"
L"\r\n" L"\t= \"[\" [JValue:items {\",\" JValue:items} ] \"]\" as Array"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Node JValue"
L"\r\n" L"\t= !JLiteral"
L"\r\n" L"\t= !JObject"
L"\r\n" L"\t= !JArray"
L"\r\n" L"\t;"
L"\r\n" L""
L"\r\n" L"rule Node JRoot"
L"\r\n" L"\t= !JObject"
L"\r\n" L"\t= !JArray"
L"\r\n" L"\t;"
;

			vl::WString JsonGetParserTextBuffer()
			{
				return parserTextBuffer;
			}

/***********************************************************************
SerializedTable
***********************************************************************/

const vint parserBufferLength = 3792; // 17748 bytes before compressing
const vint parserBufferBlock = 1024;
const vint parserBufferRemain = 720;
const vint parserBufferRows = 4;
const char* parserBuffer[] = {
"\x00\x0B\x00\x02\x83\x80\x07\x7D\x00\x82\x03\xFF\x45\x08\x82\x83\x86\x81\x21\x6F\x6C\x2F\x32\x37\x84\x86\x02\x86\x00\x17\x82\x93\x24\x3A\x39\x34\x37\x67\x06\x98\x8A\x88\x8E\x84\x00\x88\x12\x94\x98\x87\x0B\x93\x81\x20\x3A\x74\x4E\x21\x2D\x35\x32\x90\x86\x92\x0C\xA6\xA8\x93\x85\x88\x84\x96\x86\x3F\x80\x0B\x25\x39\x3F\x3B\x88\x32\x36\x88\xB8\x88\x8A\x99\x88\x9F\x96\x40\x83\x83\xA5\xA7\xA1\xA4\x83\xA5\x04\xCD\xA9\x9D\x94\x81\xA1\xAE\xA9\x44\xC6\xB2\x28\xAC\xA9\x86\x93\xAC\x03\xBB\xAA\x8C\x88\x00\x8D\xB6\x81\x42\x6F\x35\x2E\x34\x31\x32\x39\x3C\x56\xE6\xA5\x89\xBE\xA3\xB4\x85\xB7\x7F\x83\xB1\xB3\xB5\xBF\xB9\xBC\x81\x58\x83\x9A\xAF\xAC\xB6\xB6\xC0\xB9\x74\xF6\xB8\xA5\xB8\xC7\xB2\xC4\xBE\x5B\x8E\xCD\xD0\xB0\xCD\xC3\xC9\x91\x96\x8D\x98\xCC\xC8\x82\x8D\xD3\x81\x4E\x75\x2D\x22\x35\x32\x3B\xC3\x82\x0C\x18\xB1\xCF\x8F\x36\x34\x3B\x32\x78\x74\x2A\xB8\x80\x06\xAF\xCB\x9C\x2E\xF2\x32\x21\x38\xBF\x7E\xE3\xE3\xFF\x3E\xC2\x81\xAC\x21\x37\xDB\xE1\x6C\x48\xC8\xE4\x08\x8C\xEA\x80\x27\x6F\x64\x35\x92\xE6\xE6\xD0\x82\xD3\xA9\xAB\xED\xDC\xED\xE8\x8E\xD3\x27\x62\x6A\x25\x23\x34\x3C\xF3\x7F\x80\x0C\xF0\xC0\x08\xFA\xF4\xF6\x23\x34\x65\x6C\x08\xA4\xFE\xEB\x82\xD2\x8E\x1E\x60\x4E\x7A\x72\x00\x21\x65\x81\x70\xC3\x79\x16\x82\x49\xCE\x65\x1D\x1B\x1C\x03\x90\x50\x01\x73\xCF\x61\x1C\x1B\x82\x03\x76\x16\x85\x1D\xDB\x5C\x7D\x7E\x40\xE0\x6A\x6C\x6A\x1C\x04\x81\x53\x19\x6D\xB7\x76\x6E\x7B\x87\x19\x43\x44\x7F\x7A\x74\x2C\x86\x6A\x19\xF8\x7A\x70\x84\x79\xF2\x44\x42\x7F\x8B\xF6\x75\x84\x1A\x75\x08\x40\x9E\x1B\x4C\x65\x14\x60\x40\x46\x3B\xA9\x70\x8F\x7D\xF9\x64\x18\x86\x40\x1A\xAC\x1C\x87\x8A\xE6\x43\x40\x83\x47\x67\x25\x83\x43\x89\xB6\x65\x16\x6C\x6F\x0F\x18\x44\x08\x46\x61\xBC\x66\x9A\x52\xEE\x64\x77\x9B\x4D\x69\x9C\x7B\x98\x9A\x6D\x88\x7F\x9B\x55\x71\x88\x79\x00\x46\x77\x82\x44\x16\x14\x55\x05\x16\x15\x10\x4C\x3D\x90\x90\x41\x40\x9D\x4C\x84\x6F\x02\x18\x4A\x02\xA2\x03\x46\x10\xA3\x14\x7E\x80\xAD\x9F\x93\x00\x26\x16\x87\x1C\x45\x98\x43\x00\x9E\x9C\x97\x75\x14\x13\x4C\x3F\x91\xA1\x11\x83\x83\x42\x91\x1D\x6C\x2C\x19\xA0\x43\xA5\x8B\x72\x87\x13\x42\x0A\x1F\x10\x14\x45\x0E\x1B\xA8\x42\xB7\x9C\x1B\x1F\xA6\xC0\x5B\x61\x62\x40\xB0\x8A\x13\x10\x13\x4F\x10\xA7\xAC\x41\xB9\xBD\x1D\xA9\x8B\x51\x4D\xB0\x01\x10\x52\x12\x13\xAD\xAD\xC7\x83\x49\xAF\x16\x06\x84\x80\x60\x41\x80\x50\xB2\x17\xB0\xC5\x85\x15\xB6\x40\xB9\x9D\x1C\x8B\xB6\xBF\x4C\x59\x5B\x13\x4D\x0D\x11\x12\x91\x3D\x6C\x04\x82\x7B\x94\x83\x1F\x10\xB1\x4E\x30\xB3\x42\x0E\xE8\x88\x6C\x7D\x95\x9E\x8D\x12\x11\x11\x52\x1F\x08\x46\xC1\x02\x5B\x1C\x15\x0B\x5D\x3F\x0C\x14\x19\x2B\x28\x0E\x0B\xC3\x2B\x29\x0F\x0C\x0A\x5B\x25\x15\x11\x17\x5B\x2B\x0B\xC1\xC3\x14\xD6\xC9\x9C\x42\x23\xDF\x70\xC0\x00\x53\x3B\x99\x12\x13\x47\x1B\x08\x46\xCB\x02\x62\x08\xC6\x17\x5C\x1C\x12\x09\x17\x7C\x35\xCB\x16\x17\x75\x38\xC5\xCD\x1D\x0F\xFB\x14\x0D\x1F\x29\x2A\x02\x0B\xA2\x0C\x48\xD8\x42\x91\x94\x93\x10\x15\x10\x43\x05\x1C\xAC\x42\x53\xDC\x13\x1F\x0A\x39\x89\x44\x7B\x98\x16\x67\xCA\x12\x15\x1B\xA5\x10\x04\x46\x63\xC2\x4F\xD5\xD8\x2E\x12\x1F\x1B\x1B\x74\x1C\x46\x5C\x1D\x59\xC2\x42\x7C\x10\x20\x24\x0C\x0F\xD9\x52\xA5\x1E\x0E\x8C\x03\x78\xDC\x87\x6C\x08\x40\xEE\xDD\x19\x2E\x2E\xD2\x1C\x1D\x4A\xC4\x4A\xD0\xDD\x77\xE0\xD9\xDE\x0F\xFD\x80\x00\x62\x12\x14\xAD\x66\x85\xE2\x03\x4A\xD4\xE5\x83\xD0\x6E\x01\x0E\x3E\x18\x60\xE2\x43\xDD\x95\xD0\x7E\x0E\x0E\x20\x22\x0E\x18\xAA\x6C\x22\x00\x09\x18\x73\x20\x05\xEA\x85\x74\xF7\x1E\x70\x1A\x20\x3B\x10\x09\x94\x1C\xA0\x0D\x0D\xEA\xA9\x69\xAE\xE9\x1F\x0D\x0A\x04\xE8\xE7\x16\xA7\xE0\x09\xCA\x52\x2B\xC7\x10\x08\xA8\xDC\x99\x88\x1D\xAF\xF1\xE7\x94\x48\x40\x05\xF7\xF1\x85\x6C\x0A\xF2\x0A\xA1\x65\x2E\xE0\xEE\xEC\xC8\xEC\x15\xEF\xED\xB9\xFB\xE1\xDA\xEF\xA9\xD4\x12\x1C\x87\xC3\xDA\xFB\xE4\xF7\xDE\xD6\xAC\x18\xA6\xE2\xF1\xE3\xEE\xF9\x20\x36\xE4\x1C\xEE\xBA\x7C\x75\x19\x6C\x72\x04\x23\x17\x51\x7C\x20\x04\x7A\xF1\x73\x76\x73\xEE\x68\x76\x09\x55\x02\x60\xC1\x50\x70\x04\xE9\x5E\x4C\x7A\xE3\x61\x3F\x88\x40\x0A\x4A\xB3\x7C\x44\x0E\x25\x63\x23\xC8\x32\x5A\x48\xF6\x1E\x71\x09\x18\x28\x87\xE8\x24\x85\x3E\x3A\x1E\x7B\x0F\x22\x14\x6F\x16\x20\x0A\x08\x26\x7A\x3C\x82\x34\x4D\x49\xEC\x3A\x72\x04\x16\x2E\x75\x86\x3E\x58\x86\x8F\x31\x7D\x0E",
"\x10\x1D\x09\x75\x7D\x19\x7C\x08\x1F\x8C\x6E\xB3\x41\x0A\x38\xC4\x31\x73\xE4\x4F\x89\x40\xCF\x45\x08\x23\x57\x8B\x84\x15\xC4\x3E\x7B\x2D\x31\x80\x04\x33\x83\x70\x05\x8D\x4F\x41\xF4\x7D\x87\x87\x8E\x7D\x74\xEA\x64\x84\x88\x23\xA9\x75\x0B\x4A\x9B\x89\x1E\x4D\x80\x01\xC1\x52\x8D\x6F\x69\x84\x71\x0C\x3D\x08\x22\x3E\xAB\x81\x8F\xCA\x61\x04\x0B\xB0\x49\x7B\x05\x80\x90\x75\x82\x92\x8D\x21\x8D\x71\x6D\x40\x8C\x80\x3A\x40\x17\x8E\xD9\x7B\x75\x6C\x84\x15\x97\x91\x16\x49\x6F\xDA\x74\x05\x08\xBA\x0D\x00\x23\x9F\x82\x22\xDD\x18\x9D\x7A\x10\x1C\x82\x42\x83\x8C\x3D\x08\x82\x23\x85\x0F\xAE\x02\x06\x2A\x88\x21\x2C\xF7\x6F\x83\x17\xAE\x71\x8C\x36\x84\x0E\x10\xBA\x86\x8C\x1F\xB4\x81\x97\xBB\x96\x45\x02\xEE\x82\x05\x24\x95\x7B\x89\x25\x94\x0C\x10\x74\x80\x89\x26\x52\x95\x8E\xB9\x9E\x72\x0E\x18\x23\x9B\x15\xB9\x92\x79\xCC\x6E\x78\x05\xC3\x44\x26\xBA\x62\x02\x07\x68\x8B\x7C\xEA\x02\x87\x99\x0F\xB9\x94\x99\x72\x8F\x9A\x12\x72\x8F\x95\x2C\x88\x26\x9D\x77\x72\x8D\x17\xB7\x94\x87\x3C\xA3\x8F\x36\x65\x9C\x86\x2F\xE2\x8B\x8C\x7C\xAD\x8F\x88\x37\x71\x8C\x14\xF9\x0B\x98\xAF\x79\x8E\x01\x18\x28\xA2\xD9\x79\x8A\x92\xB6\x5D\x94\x0C\x71\x67\x4A\x28\x8C\x9F\x70\x53\xA8\x9B\xA0\xEA\x8C\x9D\x0D\x0C\x18\x22\x8E\x9A\x8B\xA0\xF3\x80\x8D\x3D\xE2\x90\x04\x36\xA6\x92\x9F\xE1\x99\x6F\x3D\x8E\x4F\x9F\x37\x82\xA1\x41\xF2\x72\x9C\xEA\x22\x0E\x8A\x91\xBC\x9D\xA4\xFE\x94\x6C\x4A\xA3\xAA\xA5\x7E\xAC\xA3\x98\x00\xB0\x8F\x31\xF2\x8C\x99\x5C\xAA\x99\x9A\x33\x15\x98\x42\x4A\xA7\x6F\x6B\xA8\x71\x9B\x2C\x7B\x98\x91\x29\x70\x9C\x9E\xAA\x8A\x7D\x2A\xA3\x7E\x39\xBE\x40\x08\x4A\x4A\x0A\x6D\x6C\x7D\x81\x1D\xE0\xA4\x0E\xCF\x65\x00\x23\x67\xAB\x84\x59\x8E\x9F\x83\x45\x9F\xAB\x93\x8E\x8A\x92\x58\xA9\x94\x0F\x32\x48\x26\xAE\x74\xAD\xA0\x27\xF4\x20\x70\x82\x00\x73\x94\xB5\x96\xA2\xD7\x46\xAA\x32\x68\xBE\x47\x95\x4A\xA4\x20\x53\xCD\x9A\x3E\x6C\xAA\x61\xAA\xA8\x7C\x9B\x00\xDF\x9F\x8B\x9B\xA4\x9A\xAB\xC9\x87\x9E\xD7\x72\x8A\xA0\x84\x1D\xB3\x9D\x03\xBA\xAF\x43\x91\xA2\x3F\x51\xB2\x9A\xB0\x5D\x6E\x88\x46\x85\xB0\xB5\x2A\xB3\x06\x9D\x04\x30\x9D\x6B\xDC\x83\xA7\x9A\xA1\x8E\x9E\x3E\xB9\x9D\xEA\x3E\x84\x6F\x9B\xA6\xA5\x88\x41\xAF\xA4\x71\x73\xAF\x83\x55\x80\x05\x95\xC9\x8E\x05\x0D\x14\x18\x22\xE6\xAB\x85\x96\x33\xB0\x86\x4D\xC0\x98\x75\x1C\x82\x98\x08\x3B\xAC\xB2\x2E\xD5\xB3\x88\xA0\x88\x8A\x89\x1F\x92\x7C\x74\xA9\x72\xBA\x5C\x81\x8C\xBB\x3A\x9A\xA7\x6E\xBF\x84\xBA\x10\x16\xBC\x0C\x2D\xA5\x98\x78\xC9\x95\xA8\x1F\x5D\xB4\x20\x9F\xB1\x98\x59\xA3\xB8\x49\x81\x23\x97\x9A\xA6\x9E\xA8\x59\xA1\x98\x20\x02\xEF\xAC\x6D\xA2\xB4\x2C\xE6\x02\x2A\x69\x51\xAB\xAE\x94\xC4\xA9\x9A\x71\xC8\xBD\x84\x17\x33\x01\x96\x04\x33\x94\x5D\xB6\x93\xBB\xF3\xAE\xBD\xBB\x28\xBD\xB5\x7B\xEF\xB1\xBE\x63\x98\xB5\x85\xEA\x9B\x7E\x04\x18\x2B\xC5\x49\xA5\x7A\xAF\x86\x74\x0C\x81\x84\x24\xC0\xBA\x63\x93\x7F\x90\x6C\xB7\xFE\x77\xB3\x21\xCF\xBB\x7D\x70\x74\x0F\x6D\x5F\x83\x20\x70\xC6\x64\x96\x07\x02\xDB\x92\x5D\x84\x28\xAE\xB2\xB0\xC1\xC8\x87\x6B\xC0\x00\x0B\x75\x6F\xBB\x6B\xA9\xC9\x6C\x64\xB5\xDF\x4E\xC1\xC7\x09\xC3\x26\xC8\x6B\xB7\xA1\x82\x15\x94\x21\x4B\xAC\x9C\xAC\x31\xDA\xCA\x40\x36\xC1\x9E\x90\xA2\xCC\x38\x43\xC2\x22\xE0\x6C\x91\xC6\x29\xD4\xCD\xCD\x09\x5E\x05\x84\xAD\x81\x02\x8C\x3D\xCE\x83\xC9\xA8\xCC\x94\xF4\x01\xCE\x00\x05\xCD\xCA\x1B\xDB\xCC\x8C\x33\xC3\x20\x03\xEE\x91\xCD\xFD\xAB\xCC\x08\x34\x99\x99\xBD\x43\xB6\x47\x64\xC3\x23\x25\xFA\xBB\x92\x48\xF1\x3F\xCB\x88\xD7\x99\x7D\xCD\x45\xD0\xC1\x51\x9D\xCE\x8C\x52\xD1\x53\xBE\x49\xC6\x5F\x64\x96\xCE\x7D\x7F\xC6\x0C\x22\x78\x20\x5A\xDB\x7D\x81\xF5\x67\x82\x12\xFB\x7D\x7E\xF4\x41\x83\x7D\xBF\x65\x82\xAE\x89\x8E\xAC\x1C\xF3\xA0\x7C\xBB\xC5\x7D\xAF\xFF\x79\x7C\x72\x81\xDE\x7D\xF0\x64\xDA\xFC\x46\xD9\x75\xD5\x42\x7F\x98\xBC\xDE\x7C\x00\xD8\xAD\x77\x60\xC1\x7D\x75\xD2\xCB\x80\xB5\xD0\xAF\x79\xE8\x68\x47\x82\xC7\x97\x7B\x19\x45\xD5\x7C\xE5\x50\x82\x82\x52\x14\x82\x05\xB6\x37\x98\x0D\xAD\x35\xA0\xA9\xB5\x8D\x3A\xAC\xBC\x9C\x1A\x30\xB3\x20\xB2\xB2\xA5\xEA\x36\xB6\xAB\x01\xB9\xB3\x87\xEB\xA5\xE3\x4A\xE5\x80\xB8\x97\x83\xAB\xA0\xA7\x8E\x58\x5D\xDE\xC0\xD1\x0A\xF4\x00\xC3\x03\x3A\xC3\x78\xA2\x05\xBD\x5F\x9E\xC4\xC4\xBD\x8C\xBF\xC7\xDD\xBD\xE0\xF9\xA5\x99\x99\xF8\xC7\x36\xD9\x04\xBE\xD5\x68",
"\xB4\x01\xB1\xFB\x43\x23\xAA\xCD\x4E\xB1\xE6\x50\xB0\x04\x92\xB4\xA9\x4A\xD7\xA7\xB3\xD8\x5B\xAD\x49\x29\xE6\x65\xBE\x83\x7B\x58\x20\x58\x3A\x3B\x73\x5A\x68\x77\x29\xC5\x7D\xA2\xE8\x31\x3B\x65\x1C\x36\x05\x23\x24\x3C\x2C\xF4\x0E\xE9\xD7\x30\xE8\x6F\x18\x04\xEA\x0F\x5B\xB3\xA0\x94\x52\x8C\x6F\x1A\x0D\xEA\xE9\x0A\xD4\x3D\x74\x9F\x80\x6F\x1C\x05\xEC\xE4\x23\xD2\x3F\x6A\xD3\x3D\x66\xBE\x4C\x36\x0F\x2D\xEF\x38\x1C\x03\x5F\x6B\x7F\x1C\x36\x23\x49\xEF\xEF\x73\x5B\xEF\xB2\x63\x50\xF0\x00\x13\x68\x2D\x0C\x3E\xEF\xDF\xCC\x99\x8F\x65\x7C\x34\x52\x02\x98\xE8\x00\x50\xD5\x0C\xA6\xDC\x78\xF0\x62\xBB\x7C\x6F\x16\xFD\x81\xBD\xC6\x44\xF0\x80\xE7\xF1\xBA\x04\x2A\xF1\xA4\xCC\xF1\x6C\x8E\xFB\x2D\xAF\x00\x02\x80\x4A\x46\x87\x7E\x95\xFA\xC5\xF9\x18\xF2\x42\xCD\xC5\xB4\x5B\xB1\xC5\x7F\xDE\xAC\x40\xF5\xBF\xE2\xF2\x34\x89\xE5\xF1\xBE\xC2\xE5\x8F\xC6\xFF\xE8\xF2\xA8\xF5\x38\x6A\x2C\x7C\xF2\xE8\x34\xF6\x59\xB6\xFE\x54\xEE\xAE\xCC\x7B\xBD\xC4\x47\xF7\x85\xEC\x68\x46\x25\xF3\x4F\xD3\xF9\x6D\x20\x46\x5F\x1E\x71\xA9\xF9\xE8\xED\xC1\xFA\xF8\xC4\xE4\xFB\xE0\x09\x21\xFC\x46\xE4\x58\xFD\x04\x38\xFA\x81\x5C\xFF\x4C\xEF\xDC\x44\xFE\x03\x22\xAF\xBC\xF4\x0B\xF2\xD9\xD7\xF3\xF1\x27\x36\x6F\x72\x0D\x7F\xAE\x6B\x3F\x7B\x7C\x63\xEF\x70\x7F\x02\x12\x7F\xDB\x7A\x80\x20\x26\x50\x61\x38\x7F\xAE\x2E\x2C\xFB\x74\x80\xBF\x25\x47\xD1\x7D\x7D\x27\x3A\x6E\x16\x83\x7D\x18\x83\x7B\x7B\x76\x24\x2C\x2E\x80\x88\x11\x7E\x84\x76\x20\x7D\x7D\x80\x0C\x14\x78\x2C\x22\x81\x66\x2D\x7C\x16\x28\x7D\x24\x8C\x2C\x2A\x75\x7C\x61\x30\x7F\x7B\x71\x39\x04\x23\x83\x4A\x11\x7E\x08\x82\x39\x24\x87\x82\x9A\x24\x82\x67\x74\x07\x2E\x82\x79\x92\x5C\x1B\x6F\x74\x06\x57\x11\x7E\x83\x74\x82\xCB\x26\x20\xE4\x7A\x81\x43\x72\x47\xF3\x74\x82\xF6\x75\x06\x53\x88\x78\xEA\x20\x25\xC9\x7C\x2A\x03\x14\x79\x30\x8C\x06\xCF\x7E\x13\x03\x19\x81\x1E\x8E\x81\xA4\x4E\x79\x18\x1D\x7B\x49\x71\x85\xCA\x7E\x80\x6F\x6A\x20\x2A\x8A\x80\x59\x8B\x85\xA3\x79\x2E\xAD\x7A\x7A\x00\x0F\x7A\x98\x23\x86\x65\x8F\x15\x02\x18\x86\x03\x13\x86\xBB\x7D\x86\x50\x8C\x87\x84\x28\x85\x5F\x79\x20\x57\x82\x87\x10\x89\x37\x78\x80\x7C\x5D\x8C\x7A\x5F\x81\x24\xCB\x79\x2A\x80\x8F\x77\x99\x73\x7B\xB7\x75\x88\xB9\x75\x7D\xE1\x77\x7D\x41\x8A\x88\xA6\x2C\x88\x55\x80\x76\x75\x80\x7F\x59\x80\x7E\x23\x13\x7E\xA5\x8B\x7A\x8B\x80\x89\xA9\x8E\x88\xAB\x88\x7E\x59\x8B\x77\x52\x66\x5C\x3C\x8E\x8A\x37\x1E\x7E\x00\x0E\x86\x73\x20\x87\x60\x84\x8B\x35\x83\x5B\x74\x87\x7E\x76\x81\x89\xF7\x7C\x89\x12\x25\x81\x9F\x82\x10\x93\x34\x88\x67\x24\x47\x02\x8D\x81\xA0\x84\x7D\x9D\x7E\x83\x88\x8E\x80\xC4\x88\x89\xC6\x8A\x7E\x56\x87\x8B\xC2\x79\x85\x2E\x8A\x7F\xE7\x6F\x25\xD1\x80\x84\xDA\x8E\x7C\x00\x89\x6F\x1C\x8B\x8E\xD3\x80\x82\xE1\x76\x24\x52\x63\x83\xFF\x08\x7D\xFF\x04\x78\x11\x59\x82\x0C\x1F\x67\xB8\x27\x32\x04\x10\x90\xAC\x8C\x8C\x65\x02\x8C\x5C\x8C\x85\x6C\x4A\x84\x8D\x84\x1C\xFB\x82\x1B\x7F\x76\x24\x4B\x66\x2D\x02\x93\x10\x13\x95\x8E\x06\x9E\x82\xC8\x7F\x7D\x15\x9F\x80\x2B\x7E\x23\x0F\x9F\x69\xE5\x71\x87\x01\x93\x7C\xA7\x81\x8E\xFE\x18\x47\x61\x38\x90\x79\x84\x89\x0B\x9D\x91\x34\x88\x8C\xBD\x85\x82\x23\x16\x24\x3F\x80\x78\x2E\x8C\x90\xF9\x6A\x76\x12\x22\x88\x75\x4F\x41\x21\x9A\x14\x84\x70\x8C\xFE\x88\x10\x19\x03\x84\x28\x9E\x91\x72\x7D\x42\xBC\x15\x84\x2C\x27\x94\x0E\x85\x84\x32\x84\x82\x56\x71\x94\x09\x9B\x26\xFA\x2C\x10\x53\x96\x7A\x27\x3C\x93\xCE\x2E\x93\x74\x5D\x82\x44\x88\x4A\x1F\x4B\x95\xCB\x83\x74\x79\x48\x8F\xE1\x75\x68\x17\x93\x93\xBE\x8D\x83\x64\x34\x82\x39\x96\x8A\x94\x82\x76\x30\x96\x1A\xC8\x86\x95\x09\x13\x94\x11\x98\x11\x50\x94\x35\x54\x9C\x87\x76\x96\x92\x4A\x98\x8C\x4F\x98\x8A\xC7\x82\x47\x66\x90\x7F\x55\x92\x84\x23\x9A\x8C\xF1\x71\x98\xAB\x73\x98\x35\x82\x8E\x03\x52\x96\x49\x91\x93\x8A\x9E\x96\x29\x98\x96\x37\x8C\x99\x35\x93\x12\xBB\x80\x9A\x6F\x97\x15\x11\x54\x90\xA4\x91\x82\x18\x13\x01\x72\x94\x82\x71\x7F\x73\xFA\x1A\x93\xC7\x89\x4B\x7A\x98\x18\x84\x7D\x62\x73\x26\x24\x15\x08\x94\x0A\x8F\x9A\x73\x7D\x24\xB2\x9A\x7E\x9A\x5C\x10\xBB\x99\x99\x78\x99\x4B\x2C\x9A\x94\xC4\x74\x62\x4D\x94\x96\xC9\x45\x9B\x00\x08\x9B\x6F\x26\x24\xD8\x7B\x98\x6B\x2E\x9B\x2D\x49\x4B\xC1\x9D\x99\x86\x5D\x24\x2C\x26\x9D\xD5\x87\x69\x4D\x29\x9C\x34\x8B\x9C\x43\x4D\x9C\x12\x7E\x95",
"\x67\x2A\x9A\x0C\x14\x01\xA4\x9F\x9E\x82\x7D\x8D\x0A\x8F\x8D\x4C\x68\x98\xC2\x9E\x23\x8F\x87\x96\xC7\x86\x7C\x49\x7B\x91\x1C\x22\x79\x62\x8E\x7F\x0D\x41\x88\xF9\x77\x86\x9E\x82\x7D\xD9\x8F\x81\xA2\x80\x1A\xF2\x90\x7F\xF4\x96\x91\xF6\x9C\x9D\xDA\x59\x9F\x05\x9E\x99\x92\x87\x7C\x7C\x8B\x87\xAB\x7E\x87\xB1\x75\x80\x07\xA3\x27\x9D\x8F\x7F\x08\xA2\x8D\xA1\x8B\x8D\x23\x1C\x7B\x89\x82\x8B\x10\xA6\x9C\x7D\x39\x4B\x14\xA8\x8B\x06\x93\x89\x07\x2B\x7A\x91\x74\x92\xDF\x6B\x89\x49\x71\xA2\x03\xA2\x8F\x25\xA0\x1D\xD6\x7C\x9B\xF0\x7E\x98\x77\x51\xA1\x85\x9E\xA2\xE4\x85\x78\xAD\x8B\x77\xB0\x8E\x80\x42\xA5\x9F\x2C\xAF\x91\x4D\x2F\xA2\x18\x96\xA1\x87\x24\x93\xBF\x8D\xA0\xE8\x7F\xA0\x02\x1D\x96\x80\x7B\x84\x52\xA8\xA4\x19\x9E\x8C\x14\x89\x8E\xFC\x7C\xA3\xED\x86\x21\x5D\xA1\x80\x22\x2D\x1A\xD8\x84\xA2\x67\xA1\x1D\xDC\x8B\x82\x29\xA5\x89\x4E\xAA\x9F\xF7\x91\xA5\x47\xA9\xA6\x54\xA9\x29\x39\xAF\x8C\x64\xAD\xA6\xEC\x8A\xA0\x3B\xAC\x95\xF0\x8D\x11\x58\x20\xA8\xF3\x82\xA2\x80\x71\x9F\x72\xAE\x8D\x74\x90\x00\xA8\x93\xA5\x89\x9A\x8A\x90\x90\xA3\x7B\xA2\xA3\xFE\x9A\x85\x24\x91\xA0\x1E\xAA\xA8\x6F\x2A\xA3\xEE\x83\xA2\x81\xAB\x86\xE1\x7F\x79\x73\xA7\x95\x02\x11\xA9\x60\xA5\x8B\xC4\x1F\xA5\x7A\xAB\x9F\x97\x8F\x26\x99\xAE\x7A\x07\x48\xA3\x20\xA5\x7B\x1F\xA9\x86\x09\xA4\xAA\x27\xA8\xA5\xC2\x7A\xA5\x90\xA4\xA4\x9A\x94\xA9\x4B\x32\xAC\x78\x9C\x9F\x73\x29\xA9\x92\x77\xA3\x02\xA1\xAA\xB7\xA0\x7D\xB9\xA9\xA0\x6A\x86\x80\xA3\x80\xA4\xE8\x7D\xA4\x03\x1A\xAA\xAF\xA6\x99\xB6\x85\xA9\x92\xAA\x7E\x69\x9A\xA4\x24\x91\xA4\x8F\xAA\xAD\xEF\x83\xA9\xDD\xA5\xAC\x4F\xA6\x83\x1C\x95\x9A\x09\x10\x8C\xE4\x9C\x1B\xC0\xA6\xAE\x84\xA8\xAE\xAD\xA9\xA7\xE7\xA0\xAE\x11\x82\xA6\x66\x82\x10\xD0\x82\xAA\x89\xA3\xA8\x54\x85\x83\xD7\x86\xA6\x82\xAE\xA3\x71\xA5\x92\xF3\x95\xAE\xC6\xAD\x37\xE3\x8E\xAD\xAB\xA0\xAB\x79\x37\x8E\x7E\xAD\x25\xEA\x80\xB0\x3D\xA8\xA6\xF9\xAC\x9D\xF1\x88\xB1\x6F\xAC\x1B\x39\x8D\x93\x9C\x9B\x77\x11\x55\x9C\xEF\x97\xB2\x6B\x27\x80\xEB\x80\x78\xD8\xA2\x10\x26\xB0\x7F\x45\x87\x84\x24\x99\x84\x77\x9D\xA2\x20\x91\x7E\xBC\x17\x01\x28\xBF\x77\x8C\xAA\xB0\xE4\xA5\x8C\xC9\xA9\xA1\xB1\xA7\x92\x93\x7F\x3E\x1D\xA7\x81\xA4\x44\xA0\x13\x83\x21\xD1\xAE\xA6\x48\xB4\xAD\x0C\xAD\xA8\x0A\x84\x78\x98\xA2\xB4\x79\x34\xAB\xB0\x76\xAB\x9F\xA8\xAB\x9E\xA2\xAD\xBB\xA0\xB5\x37\x18\xA2\x4C\xA3\xAE\x6B\x2A\xAC\x36\xAC\x7C\xCD\xAA\xB1\x7D\xA0\xAD\x5D\xBE\xB4\xD3\xA1\xAD\x7B\x70\xAF\xB1\x8A\xAE\xCF\xAD\xAF\x00\x0F\xAF\x17\x8F\xB6\x6D\xB6\x26\xD6\x8B\xA6\x03\x86\xB0\xBC\xA7\x13\x3F\x81\xAF\xBE\xA0\x00\x14\xB3\xA6\x16\xB5\xA6\x1E\xB7\xB0\x6A\xB3\xB0\xC4\x7D\xB1\x79\xBF\xB5\xBA\x78\xB3\x7E\x9B\xB3\x85\x7F\xA3\x5A\x9D\x9A\x2A\xA2\x10\x7F\x9C\x98\x7C\x87\x60\xFC\x72\xAE\x40\xB0\x7F\xE6\x76\x94\x92\x95\x89\xA0\xB0\x97\x37\x1C\x1B\x30\x36\xB9\x8B\xA1\x7E\x4B\xA8\xB2\x7B\x7C\x1B\x1D\x0E\xBA\x3C\xB5\xAD\x99\xBE\xBA\xB3\xB7\x30\xB6\xBA\x80\x2A\xB2\xAA\x38\x98\xAF\xA3\xB4\xB4\x34\xB4\x98\x31\x9A\x9D\xBD\xB0\x7F",
};

			void JsonGetParserBuffer(vl::stream::MemoryStream& stream)
			{
				vl::stream::MemoryStream compressedStream;
				for (vint i = 0; i < parserBufferRows; i++)
				{
					vint size = i == parserBufferRows - 1 ? parserBufferRemain : parserBufferBlock;
					compressedStream.Write((void*)parserBuffer[i], size);
				}
				compressedStream.SeekFromBegin(0);
				vl::stream::LzwDecoder decoder;
				vl::stream::DecoderStream decoderStream(compressedStream, decoder);
				vl::collections::Array<vl::vuint8_t> buffer(65536);
				while (true)
				{
					vl::vint size = decoderStream.Read(&buffer[0], 65536);
					if (size == 0) break;
					stream.Write(&buffer[0], size);
				}
				stream.SeekFromBegin(0);
			}
/***********************************************************************
Unescaping Function Foward Declarations
***********************************************************************/

			extern void JsonUnescapingString(vl::parsing::ParsingToken& value, const vl::collections::List<vl::regex::RegexToken>& tokens);

/***********************************************************************
Parsing Tree Conversion Driver Implementation
***********************************************************************/

			class JsonTreeConverter : public vl::parsing::ParsingTreeConverter
			{
			public:
				using vl::parsing::ParsingTreeConverter::SetMember;

				bool SetMember(JsonLiteral::JsonValue& member, vl::Ptr<vl::parsing::ParsingTreeNode> node, const TokenList& tokens)
				{
					vl::Ptr<vl::parsing::ParsingTreeToken> token=node.Cast<vl::parsing::ParsingTreeToken>();
					if(token)
					{
						if(token->GetValue()==L"True") { member=JsonLiteral::JsonValue::True; return true; }
						else if(token->GetValue()==L"False") { member=JsonLiteral::JsonValue::False; return true; }
						else if(token->GetValue()==L"Null") { member=JsonLiteral::JsonValue::Null; return true; }
						else { member=JsonLiteral::JsonValue::True; return false; }
					}
					member=JsonLiteral::JsonValue::True;
					return false;
				}

				void Fill(vl::Ptr<JsonNode> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
				}

				void Fill(vl::Ptr<JsonLiteral> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->value, obj->GetMember(L"value"), tokens);
				}

				void Fill(vl::Ptr<JsonString> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					if(SetMember(tree->content, obj->GetMember(L"content"), tokens))
					{
						JsonUnescapingString(tree->content, tokens);
					}
				}

				void Fill(vl::Ptr<JsonNumber> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->content, obj->GetMember(L"content"), tokens);
				}

				void Fill(vl::Ptr<JsonArray> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->items, obj->GetMember(L"items"), tokens);
				}

				void Fill(vl::Ptr<JsonObjectField> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					if(SetMember(tree->name, obj->GetMember(L"name"), tokens))
					{
						JsonUnescapingString(tree->name, tokens);
					}
					SetMember(tree->value, obj->GetMember(L"value"), tokens);
				}

				void Fill(vl::Ptr<JsonObject> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
				{
					SetMember(tree->fields, obj->GetMember(L"fields"), tokens);
				}

				vl::Ptr<vl::parsing::ParsingTreeCustomBase> ConvertClass(vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)override
				{
					if(obj->GetType()==L"Literal")
					{
						vl::Ptr<JsonLiteral> tree = new JsonLiteral;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"String")
					{
						vl::Ptr<JsonString> tree = new JsonString;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Number")
					{
						vl::Ptr<JsonNumber> tree = new JsonNumber;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Array")
					{
						vl::Ptr<JsonArray> tree = new JsonArray;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"ObjectField")
					{
						vl::Ptr<JsonObjectField> tree = new JsonObjectField;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else if(obj->GetType()==L"Object")
					{
						vl::Ptr<JsonObject> tree = new JsonObject;
						vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
						Fill(tree, obj, tokens);
						Fill(tree.Cast<JsonNode>(), obj, tokens);
						return tree;
					}
					else 
						return 0;
				}
			};

			vl::Ptr<vl::parsing::ParsingTreeCustomBase> JsonConvertParsingTreeNode(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				JsonTreeConverter converter;
				vl::Ptr<vl::parsing::ParsingTreeCustomBase> tree;
				converter.SetMember(tree, node, tokens);
				return tree;
			}

/***********************************************************************
Parsing Tree Conversion Implementation
***********************************************************************/

			vl::Ptr<JsonLiteral> JsonLiteral::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonLiteral>();
			}

			vl::Ptr<JsonString> JsonString::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonString>();
			}

			vl::Ptr<JsonNumber> JsonNumber::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonNumber>();
			}

			vl::Ptr<JsonArray> JsonArray::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonArray>();
			}

			vl::Ptr<JsonObjectField> JsonObjectField::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonObjectField>();
			}

			vl::Ptr<JsonObject> JsonObject::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
			{
				return JsonConvertParsingTreeNode(node, tokens).Cast<JsonObject>();
			}

/***********************************************************************
Parser Function
***********************************************************************/

			vl::Ptr<vl::parsing::ParsingTreeNode> JsonParseAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"JRoot");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				return node;
			}

			vl::Ptr<vl::parsing::ParsingTreeNode> JsonParseAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return JsonParseAsParsingTreeNode(input, table, errors, codeIndex);
			}

			vl::Ptr<JsonNode> JsonParse(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
			{
				vl::parsing::tabling::ParsingState state(input, table, codeIndex);
				state.Reset(L"JRoot");
				vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
				vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
				if(node && errors.Count()==0)
				{
					return JsonConvertParsingTreeNode(node, state.GetTokens()).Cast<JsonNode>();
				}
				return 0;
			}

			vl::Ptr<JsonNode> JsonParse(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
			{
				vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
				return JsonParse(input, table, errors, codeIndex);
			}

/***********************************************************************
Table Generation
***********************************************************************/

			vl::Ptr<vl::parsing::tabling::ParsingTable> JsonLoadTable()
			{
				vl::stream::MemoryStream stream;
				JsonGetParserBuffer(stream);
				vl::Ptr<vl::parsing::tabling::ParsingTable> table=new vl::parsing::tabling::ParsingTable(stream);
				table->Initialize();
				return table;
			}

		}
	}
}
