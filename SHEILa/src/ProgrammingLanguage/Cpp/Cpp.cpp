//SHEILa========================================================================
// Name        : Cpp.cpp
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#include "Cpp.h"

namespace sheila {
namespace cpp {

#if (BUILD_FOR_SHEILA_DAEMON == 1)
template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_names;

template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_authors;

template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_versions;

template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_copyrights;

template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_descriptions;

template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_modules;

template<class _N>
std::string              Cpp::Project::Artifact::Object<_N>::this_object_created;

template<class _N>
std::vector<std::string> Cpp::Project::Artifact::Object<_N>::this_object_modified;

template<class _N>
CppSource* 				 Cpp::Project::Artifact::Object<_N>::this_object_source;

template<class _N>
std::vector<CppHeader*>  Cpp::Project::Artifact::Object<_N>::this_object_headers;
#endif

std::vector<std::string> Cpp::reserved_words = {
		"and",
		"and_eq",
		"asm",
		"auto",
		"bitand",
		"bitor",
		"bool",
		"break",
		"case",
		"catch",
		"char",
		"class",
		"compl",
		"const",
		"const_cast",
		"continue",
		"default",
		"delete",
		"do",
		"double",
		"dynamic_cast",
		"else",
		"enum",
		"explicit",
		"export",
		"extern",
		"false",
		"float",
		"for",
		"friend",
		"goto",
		"if",
		"inline",
		"int",
		"long",
		"mutable",
		"namespace",
		"new",
		"not",
		"not_eq",
		"operator",
		"or",
		"or_eq",
		"private",
		"protected",
		"public",
		"register",
		"reinterpret_cast",
		"return",
		"short",
		"signed",
		"sizeof",
		"static",
		"static_cast",
		"struct",
		"switch",
		"template",
		"this",
		"throw",
		"true",
		"try",
		"typedef",
		"typeid",
		"typename",
		"union",
		"unsigned",
		"using",
		"virtual",
		"void",
		"volatile",
		"wchar_t",
		"while",
		"xor",
		"xor_eq"
};

bool Cpp::isReservedWord(std::string word) {
	for (std::vector<std::string>::iterator it = reserved_words.begin();
			it != reserved_words.end(); ++it) {
		if ((*it) == word) {
			return true;
		}
	}

	return false;
}

std::string Cpp::accessLevel(AccessLevel lvl) {

	switch(lvl) {
	case PRIVATE:
		return "private";
	case PROTECTED:
		return "protected";
	case PUBLIC:
		return "public";
	}

	return "";
}

std::string Cpp::storageClass(StorageClass cla) {

	switch(cla) {
	case STATIC:
		return "static";
	case EXTERN:
		return "extern";
	case MUTABLE:
		return "mutable";
	case AUTO:
		return "auto";
	case REGISTER:
		return "register";
	}

	return "";
}

std::string Cpp::fundamentalType(FundamentalType typ) {

	switch(typ) {
	case VOID:
		return "void";
	case BOOL:
		return "bool";
	case CHAR:
		return "char";
	case WCHAR:
		return "wchar_t";
	case SHORT:
		return "short";
	case INT:
		return "int";
	case LONG:
		return "long";
	case FLOAT:
		return "float";
	case DOUBLE:
		return "double";
	case LONG_DOUBLE:
		return "long double";
	}

	return "void";

}
//
//static Header std_stl_algorithm = Header("algorithm", true);
//static Header std_bitset        = Header("bitset", true);
//static Header std_complex       = Header("complex", true);
//static Header std_stl_deque     = Header("deque", true);
//static Header std_exception     = Header("exception",true);
//static Header std_fstream       = Header("fstream",true);
//static Header std_stl_functional= Header("functional",true);
//static Header std_iomanip       = Header("iomanip",true);
//static Header std_ios           = Header("ios",true);
//static Header std_iosfwd        = Header("iosfwd",true);
//static Header std_iostream      = Header("iostream",true);
//static Header std_istream       = Header("istream",true);
//static Header std_stl_iterator  = Header("iterator",true);
//static Header std_limits        = Header("limits",true);
//static Header std_stl_list      = Header("list",true);
//static Header std_locale        = Header("locale",true);
//static Header std_stl_map       = Header("map",true);
//static Header std_stl_memory    = Header("memory",true);
//static Header std_new           = Header("new",true);
//static Header std_stl_numeric   = Header("numeric",true);
//static Header std_ostream       = Header("ostream",true);
//static Header std_stl_queue     = Header("queue",true);
//static Header std_stl_set       = Header("set",true);
//static Header std_sstream       = Header("sstream",true);
//static Header std_stl_stack     = Header("stack", true);
//static Header std_stdexcept     = Header("stdexcept",true);
//static Header std_streambuf     = Header("streambuf",true);
//static Header std_string        = Header("string",true);
//static Header std_typeinfo      = Header("typeinfo",true);
//static Header std_stl_utility   = Header("utility",true);
//static Header std_valarray      = Header("valarray",true);
//static Header std_stl_vector    = Header("vector",true);

Cpp::PreProcessor::Macro::Macro() {

	std::cerr << "C++ macro object initialized without being declared" << std::endl;
	defined = false;

}

Cpp::PreProcessor::Macro::Macro(std::string id, std::string value,
		std::vector<std::string> allocator) {
	this->identifier = id;
	this->statement = value;

	if (allocator.size() > 0) {
		arguments = std::vector<std::string>(allocator);
	}

	this->defined = true;
}

std::string Cpp::PreProcessor::Macro::cpp_str() {

	return "";
}

std::string Cpp::PreProcessor::Macro::xml_str() {

	// TODO xml_str for CppMacro

	return "";
}


Cpp::PreProcessor::Macro::~Macro() {
	// TODO Auto-generated destructor stub
}

Cpp::File::File() {
}

Cpp::File::~File() {
}

const std::string& Cpp::File::getPath() const {
}

void Cpp::File::setPath(std::string abspath) {
}

} /* namespace cpp */
} /* namespace sheila */

