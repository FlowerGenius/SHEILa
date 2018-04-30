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
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_names;

template<class _N>
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_authors;

template<class _N>
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_versions;

template<class _N>
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_copyrights;

template<class _N>
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_descriptions;

template<class _N>
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_modules;

template<class _N>
std::string              Cpp::Structure::Files::OutFiles::Object<_N>::this_object_created;

template<class _N>
std::vector<std::string> Cpp::Structure::Files::OutFiles::Object<_N>::this_object_modified;

template<class _N>
Cpp::Structure::Files::InFiles::Source* 				 Cpp::Structure::Files::OutFiles::Object<_N>::this_object_source;

template<class _N>
std::vector<Cpp::Structure::Files::InFiles::Header*>  Cpp::Structure::Files::OutFiles::Object<_N>::this_object_headers;
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

//Cpp::PreProcessor::Macro::Macro() {
//
//	std::cerr << "C++ macro object initialized without being declared" << std::endl;
//	defined = false;
//
//}

namespace Cpp {
namespace Types {

using namespace LexicalElements::ReservedWords;


Types::Type::Type(std::initializer_list<std::string> nm) {
	this->type_name = nm;
	rwords = false;
}

Types::Type::Type(std::initializer_list<const ReservedWord*> nm) {
	this->words = nm;
	rwords = true;
}

Types::Type::~Type() {

}

const Type Type::Type_name = Type({&ReservedWord::R_typename});

namespace FundamentalTypes {

FundamentalType::FundamentalType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) : Type(req){

	words.insert(words.end(), opt);

}

FundamentalType::~FundamentalType() {

}

const FundamentalType FundamentalType::Void =
		FundamentalType({&ReservedWord::R_void});

namespace ArithmeticTypes {

ArithmeticType::ArithmeticType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) :
				FundamentalType(req,opt) {

}

ArithmeticType::~ArithmeticType() {

}

namespace IntegralTypes {

IntegralType::IntegralType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt) :
				ArithmeticType(req,opt) {

}

IntegralType::~IntegralType() {

}

const IntegralType IntegralType::Boolean =
		IntegralType({&ReservedWord::R_bool});

namespace CharacterTypes {

CharacterType::CharacterType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) : IntegralType(req,opt) {

}

CharacterType::~CharacterType() {

}

const CharacterType CharacterType::Char =
		CharacterType({&ReservedWord::R_char},{&ReservedWord::R_signed});

const CharacterType CharacterType::WideChar =
		CharacterType({&ReservedWord::R_wchar_t},{&ReservedWord::R_signed});

const CharacterType CharacterType::UnsignedChar =
		CharacterType({&ReservedWord::R_unsigned,&ReservedWord::R_char});

const CharacterType CharacterType::UnsignedWideChar =
		CharacterType({&ReservedWord::R_unsigned,&ReservedWord::R_wchar_t});

} /* namespace CharacterTypes */

namespace IntegerTypes {

IntegerType::IntegerType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) : IntegralType(req,opt) {

}

IntegerType::~IntegerType() {

}

const IntegerType IntegerType::ShortInteger =
		IntegerType({&ReservedWord::R_short},
				{&ReservedWord::R_signed,&ReservedWord::R_int});

const IntegerType IntegerType::BasicInteger =
		IntegerType({&ReservedWord::R_int},{&ReservedWord::R_signed});

const IntegerType IntegerType::LongInteger =
		IntegerType({&ReservedWord::R_long},
				{&ReservedWord::R_signed,&ReservedWord::R_int});

const IntegerType IntegerType::LongLongInteger =
		IntegerType({&ReservedWord::R_long,&ReservedWord::R_long},
				{&ReservedWord::R_signed,&ReservedWord::R_int});

const IntegerType IntegerType::UnsignedShortInteger =
		IntegerType({&ReservedWord::R_unsigned,&ReservedWord::R_short},
				{&ReservedWord::R_int});

const IntegerType IntegerType::UnsignedBasicInteger =
		IntegerType({&ReservedWord::R_unsigned,&ReservedWord::R_int});

const IntegerType IntegerType::UnsignedLongInteger =
		IntegerType({&ReservedWord::R_unsigned,&ReservedWord::R_long},
				{&ReservedWord::R_int});

const IntegerType IntegerType::UnsignedLongLongInteger =
		IntegerType({&ReservedWord::R_unsigned,&ReservedWord::R_long,
	&ReservedWord::R_long},{&ReservedWord::R_int});


} /* namespace IntegerTypes */

} /* namespace IntegralTypes */

namespace FloatingPointTypes {

FloatingPointType::FloatingPointType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) :
		ArithmeticType(req,opt) {

}

FloatingPointType::~FloatingPointType() {


}

const FloatingPointType FloatingPointType::Float =
		FloatingPointType({&ReservedWord::R_float});

const FloatingPointType FloatingPointType::Double =
		FloatingPointType({&ReservedWord::R_double});

const FloatingPointType FloatingPointType::LongDouble =
		FloatingPointType({&ReservedWord::R_long,&ReservedWord::R_double});

const FloatingPointType FloatingPointType::LongLongDouble =
		FloatingPointType({&ReservedWord::R_long,&ReservedWord::R_long,
	&ReservedWord::R_double});

} /* namespace FloatingPointTypes */
} /* namespace ArithmeticTypes */
} /* namespace FundamentalTypes */

namespace CompoundTypes {

CompoundType::CompoundType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) : Type(req) {
	words.insert(words.end(),opt);
}

CompoundType::CompoundType(std::initializer_list<std::string> nm) : Type(nm) {

}

CompoundType::~CompoundType() {

}

const CompoundType CompoundType::T_Enum =
		CompoundType({&ReservedWord::R_enum});

const CompoundType CompoundType::T_ScopedEnum =
		CompoundType({&ReservedWord::R_enum},{&ReservedWord::R_class,
		&ReservedWord::R_struct});

namespace EnumerationTypes {

EnumerationType::EnumerationType(std::initializer_list<const ReservedWord*> req,
		std::initializer_list<const ReservedWord*> opt) : CompoundType(req,opt) {

}

EnumerationType::~EnumerationType() {

}



} /* namespace EnumerationTypes */


ArrayType::ArrayType(const Types::Type *target) :
		CompoundType({target->getName().front()+"[]"}) {

}

ArrayType::~ArrayType() {

}



StringType::StringType(const Types::FundamentalTypes::ArithmeticTypes::
		IntegralTypes::CharacterTypes::CharacterType *string_of) :
			CompoundType({string_of->getName().front()+"[]"}) {

}

StringType::~StringType() {

}

const StringType StringType::T_CharString =
		StringType(&Types::FundamentalTypes::ArithmeticTypes::IntegralTypes::
				CharacterTypes::CharacterType::Char);

const StringType StringType::T_WideCharString =
		StringType(&Types::FundamentalTypes::ArithmeticTypes::IntegralTypes::
				CharacterTypes::CharacterType::WideChar);

const StringType StringType::T_UnsignedCharString =
		StringType(&Types::FundamentalTypes::ArithmeticTypes::IntegralTypes::
				CharacterTypes::CharacterType::UnsignedChar);

const StringType StringType::T_UnsignedWideCharString =
		StringType(&Types::FundamentalTypes::ArithmeticTypes::IntegralTypes::
				CharacterTypes::CharacterType::UnsignedWideChar);


PointerType::PointerType(Types::Type *target) :
	CompoundType({target->getName().front()+"*"}) {

}

PointerType::~PointerType() {

}


PointerToMemberType::PointerToMemberType(Types::Type *member) :
	CompoundType() {

}

PointerToMemberType::~PointerToMemberType() {

}

ReferenceType::ReferenceType(Types::Type *target) :
		CompoundType({target->getName().front()+"&"}) {

}

ReferenceType::~ReferenceType() {

}

namespace ClassTypes {

ClassType::ClassType(std::initializer_list<res_word_ptr>
req, std::initializer_list<res_word_ptr> opt) : CompoundType(req,opt) {

}

ClassType::~ClassType() {

}

const ClassType ClassType::T_Class =
		ClassType({&ReservedWord::R_class});

const ClassType ClassType::T_Struct =
		ClassType({&ReservedWord::R_struct});

const ClassType ClassType::T_Union =
		ClassType({&ReservedWord::R_union});

} /* namespace ClassTypes */
} /* namespace CompoundTypes */
} /* namespace Types */

namespace LexicalElements {

LexicalElement::LexicalElement() {

}

LexicalElement::~LexicalElement() {

}

Comment::Comment() {

}

Comment::~Comment() {

}

Identifier::Identifier(std::string unf) {

}

Identifier::~Identifier() {

}

Typename::Typename(std::string nm, Types::Type typ) : name(nm) {

}

Typename::~Typename() {

}

namespace ReservedWords {

ReservedWord::ReservedWord(std::string str) : name(str) {

}

ReservedWord::~ReservedWord() {

}

namespace ReservedTypenames {

ReservedTypename::ReservedTypename(Types::Type typ) :
	ReservedWord(typ.get()), Typename(typ.get(),typ) {

}

ReservedTypename::~ReservedTypename() {

}

} /* namespace ReservedTypenames */

namespace Qualifiers {

Qualifier::Qualifier(std::string str) : ReservedWord(str) {

}

Qualifier::~Qualifier() {

}

} /* namespace Qualifiers */

} /* namespace ReservedWords */

} /* namespace LexicalElements */
} /* namespace Cpp */























Cpp::PreProcessor::Macro::Macro(void *scope,
		std::string id, std::string value,
		std::vector<std::string> allocator) {
	this->identifier = id;
	this->statement = value;

	if (allocator.size() > 0) {
		arguments = std::vector<std::string>(allocator);
	}

	this->defined = true;

	Cpp::Project::Artifact *a = static_cast<Cpp::Project::Artifact *>(scope);

	a->addMacro(this);
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

/*========================= Variables ========================================*/
#ifdef LANG_CPP_CLASS_VARIABLE

Cpp::Variable::Variable(LexicalElements::Identifier id,Types::Type typ,
		LexicalElements::Expression *val) {

}

std::string Cpp::Variable::cpp_str() {

}

std::string Cpp::Variable::xml_str() {

}

Cpp::Variable::~Variable() {

}

#endif
/*========================= Functions ========================================*/



/*========================= Enums ============================================*/
#ifdef LANG_CPP_CLASS_ENUMERATOR

Cpp::Enumerator::Enumerator(EnumeratorDefinition* enumerator,
		std::string id,ENUM_INT_SIZE val) :
				Variable(val,id), enumerator_def(enumerator) {}

std::string Cpp::Enumerator::cpp_str() {
	return getAbsoluteIdentifier();
}

std::string Cpp::Enumerator::xml_str() {

}

Cpp::Enumerator::~Enumerator() {
}


Cpp::EnumeratorDefinition::EnumeratorDefinition(
		EnumerationDefinition* enum_ptr, std::string id) {
	enumeration_def = enum_ptr;
	data = Enumerator(this,id,enum_ptr->next());
	explicit_enumerator = false;
}

Cpp::EnumeratorDefinition::EnumeratorDefinition(
		EnumerationDefinition* enum_ptr, std::string id, ENUM_INT_SIZE n) {
	enumeration_def = enum_ptr;
	data = Enumerator(this,id,n);
	explicit_enumerator = true;
}

std::string Cpp::EnumeratorDefinition::cpp_str() {
	if (explicit_enumerator) {
		return this->data.getIdentifier() + " = " +
				std::string(this->data.getValue());
	} else {
		return this->data.getIdentifier();
	}
}

std::string Cpp::EnumeratorDefinition::xml_str() {
	if (explicit_enumerator) {
		return "<enumeratordef id='" + this->data.getIdentifier() +
				"' value='" + std::string(this->data.getValue()) + "' />";
	} else {
		return "<enumeratordef id='" + this->data.getIdentifier() + "' />";
	}

}

Cpp::EnumeratorDefinition::~EnumeratorDefinition() {
	//Destroys @a data automatically
}

#endif
#ifdef LANG_CPP_CLASS_ENUMERATION

Cpp::Enumeration::Enumeration() {

}

std::string Cpp::Enumeration::cpp_str() {

}

std::string Cpp::Enumeration::xml_str() {

}

Cpp::Enumeration::~Enumeration() {
}

Cpp::EnumerationDefinition::EnumerationDefinition(bool anonymous,
		std::string id) {

	data = Enumeration();
}

ENUM_INT_SIZE Cpp::EnumerationDefinition::next() {
	if (enumerator_definitions.size() > 0) {
		return enumerator_definitions.back().data.getValue() + 1;
	} else {
		return 0;
	}
}

void Cpp::EnumerationDefinition::addEnumerator(std::string id) {
	;
}

void Cpp::EnumerationDefinition::addEnumerator(std::string id,ENUM_INT_SIZE n) {
	;
}

std::string Cpp::EnumerationDefinition::cpp_str() {
	std::stringstream ss;

	ss << "enum ";
	if (!this->data.isAnonymous()) { ss << this->getIdentifier(); }
	ss << " {\n";
	for (auto&& enumerator_def : enumerator_definitions) {
		ss << enumerator_def.cpp_str() + ",\n";
	}
	ss << "} ";

	return ss.str();
}

std::string Cpp::EnumerationDefinition::xml_str() {

}

Cpp::EnumerationDefinition::~EnumerationDefinition() {

	delete enumeration;
}

#endif

#ifdef LANG_CPP_CLASS_SCOPED_ENUMERATION



#endif
/*========================== Project =========================================*/

Cpp::Project::Project(std::string) {

}

Cpp::Project::~Project(){
}

Cpp::Project::Artifact::Artifact() {
}

const std::map<std::string, Cpp::Feature*>&
Cpp::Project::Artifact::scopeFeatures() const {
	return global_scope;
}

std::map<std::string, Cpp::Feature*>
Cpp::Project::Artifact::accessibleFeatures() {
	std::map<std::string, Cpp::Feature*> all_features;
	all_features.insert(global_scope.begin(),global_scope.end());

	return all_features;
}

Cpp::Project::Artifact::~Artifact() {

}



} /* namespace cpp */
} /* namespace sheila */


