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

//std::string Cpp::classType(ClassType typ) {
//	switch(typ) {
//	case CLASS:
//		return "class";
//	case STRUCT:
//		return "struct";
//	case UNION:
//		return "union";
//	}
//
//	return "class";
//}

Cpp::Cpp() {
	// TODO Auto-generated constructor stub

}


Cpp::~Cpp() {
	// TODO Auto-generated destructor stub
}

} /* namespace cpp */
} /* namespace sheila */
