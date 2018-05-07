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

#include "CppLanguage.h"



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


namespace Cpp {
namespace Types {

using namespace LexicalElements::ReservedWords;

std::map<Scopes::Scope*,std::list<Type*> > Type::all_types;

Type::Type(std::initializer_list<std::string> nm, Scopes::Scope *scop) {
	this->type_name = nm;
	rwords = false;
	if (scop != nullptr) {
		myscope = scop;
	} else { myscope = &Scopes::Scope::global_scope; }
	all_types[myscope].push_back(this);
}

Type::Type(std::initializer_list<rw_ptr> nm) {
	this->words = nm;
	rwords = true;
	myscope = &Scopes::Scope::global_scope;
	all_types[myscope].push_back(this);
}

Type::~Type() {
	all_types[myscope].remove(this);
}

const Type Type::Type_name = Type({&ReservedTypeWord::R_typename});

namespace FundamentalTypes { /*===============================================*/

std::list<const FundamentalType*> FundamentalType::all_fundamental_types;

FundamentalType::FundamentalType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt) : Type(req){

	words.insert(words.end(), opt);
	all_fundamental_types.push_back(this);
}

FundamentalType::~FundamentalType() {
	all_fundamental_types.remove(this);
}

const FundamentalType FundamentalType::Void =
		FundamentalType({&ReservedTypeWord::R_void});

namespace ArithmeticTypes { /*================================================*/

std::list<const ArithmeticType*> ArithmeticType::all_arithmetic_types;

ArithmeticType::ArithmeticType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt) :
				FundamentalType(req,opt) {
	all_arithmetic_types.push_back(this);
}

ArithmeticType::~ArithmeticType() {
	all_arithmetic_types.remove(this);
}

namespace IntegralTypes { /*==================================================*/

std::list<const IntegralType*> IntegralType::all_integral_types;

IntegralType::IntegralType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt, bool sgn) :
				ArithmeticType(req,opt), _signed_(sgn) {
	all_integral_types.push_back(this);
}

IntegralType::~IntegralType() {
	all_integral_types.remove(this);
}

const IntegralType IntegralType::Boolean =
		IntegralType({&ReservedTypeWord::R_bool});

namespace CharacterTypes { /*=================================================*/

std::list<const CharacterType*> CharacterType::all_character_types;

CharacterType::CharacterType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt,bool sgn) :
				IntegralType(req,opt,sgn) {
	all_character_types.push_back(this);
}

CharacterType::~CharacterType() {
	all_character_types.remove(this);
}

const CharacterType CharacterType::Char =
		CharacterType({&ReservedTypeWord::R_char},
				{&ReservedTypeWord::R_signed});

#ifdef CPP_SUPPORT_WIDE_CHAR
const CharacterType CharacterType::WideChar =
		CharacterType({&ReservedTypeWord::R_wchar_t},
				{&ReservedTypeWord::R_signed});
#endif

const CharacterType CharacterType::UnsignedChar =
		CharacterType({&ReservedTypeWord::R_unsigned,
	&ReservedTypeWord::R_char},
				{},false);

#ifdef CPP_SUPPORT_WIDE_CHAR
const CharacterType CharacterType::UnsignedWideChar =
		CharacterType({&ReservedTypeWord::R_unsigned,
	&ReservedTypeWord::R_wchar_t},
				{},false);
#endif

} /* namespace CharacterTypes */

namespace IntegerTypes { /*===================================================*/

std::list<const IntegerType*> IntegerType::all_integer_types;


IntegerType::IntegerType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt, bool sgn) :
				IntegralType(req,opt,sgn) {
	all_integer_types.push_back(this);
}

IntegerType::~IntegerType() {
	all_integer_types.remove(this);
}

const IntegerType IntegerType::ShortInteger =
		IntegerType({&ReservedTypeWord::R_short},
				{&ReservedTypeWord::R_signed,&ReservedTypeWord::R_int});

const IntegerType IntegerType::BasicInteger =
		IntegerType({&ReservedTypeWord::R_int},{&ReservedTypeWord::R_signed});

#ifdef CPP_SUPPORT_LONG_INT
const IntegerType IntegerType::LongInteger =
		IntegerType({&ReservedTypeWord::R_long},
				{&ReservedTypeWord::R_signed,&ReservedTypeWord::R_int});
#endif

#ifdef CPP_SUPPORT_LONGLONG_INT
const IntegerType IntegerType::LongLongInteger =
		IntegerType({&ReservedTypeWord::R_long,&ReservedTypeWord::R_long},
				{&ReservedTypeWord::R_signed,&ReservedTypeWord::R_int});
#endif

const IntegerType IntegerType::UnsignedShortInteger =
		IntegerType({&ReservedTypeWord::R_unsigned,&ReservedTypeWord::R_short},
				{&ReservedTypeWord::R_int},false);

const IntegerType IntegerType::UnsignedBasicInteger =
		IntegerType({&ReservedTypeWord::R_unsigned,&ReservedTypeWord::R_int},
				{},false);

#ifdef CPP_SUPPORT_LONG_INT
const IntegerType IntegerType::UnsignedLongInteger =
		IntegerType({&ReservedTypeWord::R_unsigned,&ReservedTypeWord::R_long},
				{&ReservedTypeWord::R_int},false);
#endif

#ifdef CPP_SUPPORT_LONGLONG_INT
const IntegerType IntegerType::UnsignedLongLongInteger =
		IntegerType({&ReservedTypeWord::R_unsigned,&ReservedTypeWord::R_long,
	&ReservedTypeWord::R_long},{&ReservedTypeWord::R_int},false);
#endif

} /* namespace IntegerTypes */

} /* namespace IntegralTypes */

namespace FloatingPointTypes { /*=============================================*/

std::list<const FloatingPointType*> FloatingPointType::all_floating_point_types;


FloatingPointType::FloatingPointType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt) :
		ArithmeticType(req,opt) {
	all_floating_point_types.push_back(this);
}

FloatingPointType::~FloatingPointType() {
	all_floating_point_types.remove(this);
}

const FloatingPointType FloatingPointType::Float =
		FloatingPointType({&ReservedTypeWord::R_float});

const FloatingPointType FloatingPointType::Double =
		FloatingPointType({&ReservedTypeWord::R_double});

#ifdef CPP_SUPPORT_LONG_DOUBLE
const FloatingPointType FloatingPointType::LongDouble =
		FloatingPointType({&ReservedTypeWord::R_long,
	&ReservedTypeWord::R_double});
#endif

#ifdef CPP_SUPPORT_LONGLONG_DOUBLE
const FloatingPointType FloatingPointType::LongLongDouble =
		FloatingPointType({&ReservedTypeWord::R_long,&ReservedTypeWord::R_long,
	&ReservedTypeWord::R_double});
#endif

} /* namespace FloatingPointTypes */
} /* namespace ArithmeticTypes */
} /* namespace FundamentalTypes */

namespace CompoundTypes { /*==================================================*/

CompoundType::CompoundType(std::initializer_list<res_word_ptr> req,
		std::initializer_list<res_word_ptr> opt) : Type(req) {
	words.insert(words.end(),opt);
}

CompoundType::CompoundType(std::initializer_list<std::string> nm) : Type(nm) {

}

CompoundType::~CompoundType() {

}

const CompoundType CompoundType::T_Enum =
		CompoundType({&ReservedTypeWord::R_enum});

const CompoundType CompoundType::T_ScopedEnum =
		CompoundType({&ReservedTypeWord::R_enum},{&ReservedTypeWord::R_class,
		&ReservedTypeWord::R_struct});

namespace EnumerationTypes {

EnumerationType::EnumerationType(std::string nm) : CompoundType({nm}) {

}

EnumerationType::~EnumerationType() {

}

#ifdef CPP_SUPPORT_SCOPED_ENUM
ScopedEnumType::ScopedEnumType(
		const Types::ClassType *scopetype,
		std::string nm,
		const Types::IntegralType *dtype) : EnumerationType(nm) {
	scope_class = scopetype;
	datatype = dtype;

}

ScopedEnumType::~ScopedEnumType() {

}
#endif


} /* namespace EnumerationTypes */


ArrayType::ArrayType(const Types::Type *target) :
		CompoundType({target->getName().front()+"[]"}) {
	contents_type = const_cast<Types::Type*>(target);
}

ArrayType::~ArrayType() {

}



StringType::StringType(const Types::CharacterType *string_of) :
			CompoundType({string_of->getName().front()+"[]"}) {
	contents_type = const_cast<Types::CharacterType*>(string_of);
}

StringType::~StringType() {

}

const StringType StringType::T_CharString =
		StringType(&Types::CharacterType::Char);

#ifdef CPP_SUPPORT_WIDE_CHAR
const StringType StringType::T_WideCharString =
		StringType(&Types::CharacterType::WideChar);
#endif


const StringType StringType::T_UnsignedCharString =
		StringType(&Types::CharacterType::UnsignedChar);

#ifdef CPP_SUPPORT_WIDE_CHAR
const StringType StringType::T_UnsignedWideCharString =
		StringType(&Types::CharacterType::UnsignedWideChar);
#endif

PointerType::PointerType(Types::Type *target) :
	CompoundType({target->getName().front()+"*"}) {
	contents_type = target;
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
	contents_type = target;

}

ReferenceType::~ReferenceType() {

}

namespace ClassTypes {

ClassType::ClassType(std::initializer_list<res_word_ptr> req) :
		CompoundType(req) {

}

ClassType::~ClassType() {

}

const ClassType ClassType::T_Class =
		ClassType({&ReservedTypeWord::R_class});

const ClassType ClassType::T_Struct =
		ClassType({&ReservedTypeWord::R_struct});

const ClassType ClassType::T_Union =
		ClassType({&ReservedTypeWord::R_union});

CppUnionType::CppUnionType(std::string nm) : Type({nm}) {

}

CppUnionType::~CppUnionType() {

}

CppClassType::CppClassType(std::string nm) : Type({nm}) {

}

CppClassType::~CppClassType() {

}

CppStructType::CppStructType(std::string nm) : CppClassType(nm) {

}

CppStructType::~CppStructType() {

}



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

Identifier::Identifier(std::string unf, Types::Type *typ) {
	this->name = unf;
	this->t = typ;
}

void Identifier::declare(Types::Type *t) {
	this->t = t;
}

Identifier::~Identifier() {

}

Typename::Typename(std::string nm, Types::Type typ) : name(nm) {

}

Typename::~Typename() {

}

namespace ReservedWords {

std::list<const ReservedWord*> ReservedWord::all_words;;

ReservedWord::ReservedWord(std::string str) : name(str) {
	all_words.push_back(this);
}

ReservedWord::~ReservedWord() {
	all_words.remove(this);
}

std::list<const ReservedTypeWord*> ReservedTypeWord::all_type_words;

ReservedTypeWord::ReservedTypeWord(std::string str) : ReservedWord(str) {
	all_type_words.push_back(this);
}

ReservedTypeWord::~ReservedTypeWord() {
	all_type_words.remove(this);
}

std::list<const Qualifier*> Qualifier::all_qualifiers;

Qualifier::Qualifier(std::string str) : ReservedWord(str) {
	all_qualifiers.push_back(this);
}

Qualifier::~Qualifier() {
	all_qualifiers.remove(this);
}

std::list<const StorageClass*> StorageClass::all_storage_classes;

StorageClass::StorageClass(std::string str) : ReservedWord(str) {
	all_storage_classes.push_back(this);
}

StorageClass::~StorageClass() {
	all_storage_classes.remove(this);
}

std::list<const AccessLevel*> AccessLevel::all_access_levels;

AccessLevel::AccessLevel(std::string str) : ReservedWord(str) {
	all_access_levels.push_back(this);
}

AccessLevel::~AccessLevel() {
	all_access_levels.remove(this);
}


} /* namespace ReservedWords */

Expression::Expression(std::initializer_list<LexicalElement> expr) {

}

Expression::~Expression() {

}

namespace Literals {

Literal::Literal(std::string str, const Types::Type *typ) {
	verbatim = str;

	using namespace Types::FundamentalTypes::ArithmeticTypes::IntegralTypes;

	if (verbatim == "true")  {
		data = new bool(true);
		data_type = &IntegralType::Boolean;
	} else if (verbatim == "false") {
		data = new bool(false);
		data_type = &IntegralType::Boolean;
	}

	using namespace CharacterTypes;

	if (verbatim.at(0) == 'L' ) {
		if (verbatim.at(1) == '\'') { /* wide character literal */
			data = new char();
		} else if (verbatim.at(1) == '\"') { /* wide string literal */

		} else {

		}
	} else if (verbatim.at(0) == '\'') { /* character literal */

	} else if (verbatim.at(0) == '\"') { /* string literal */

	} else {

	}


	{ data_type = typ; }


}

Literal::~Literal() {
	delete data;
}

} /* namespace Literals */

namespace Operators {

Operator::Operator(std::string regex, short associativity) {

}

Operator::~Operator() {

}

} /* namespace Operators */

} /* namespace LexicalElements */

namespace Scopes {

std::list<Scope*> Scope::scopes;

Scope Scope::global_scope = Scope();

Scope::Scope(std::initializer_list<LexicalElements::Identifier> ls) {
	scopes.push_back(this);
}

Scope::~Scope() {
	scopes.remove(this);
}

} /* namespace Scopes */


Cpp::Variable::Variable(std::string proposed_id,Types::Type *typ,
		LexicalElements::Expression *val) : id(LexicalElements::Identifier(proposed_id)) {

//	id = LexicalElements::Identifier(proposed_id);
	type = typ;
	value = val;

	if (type != nullptr) {
		id.declare(type);
	}
}

std::string Cpp::Variable::cpp_str() {

}

std::string Cpp::Variable::xml_str() {

}

Cpp::Variable::~Variable() {

}


namespace Enumerations {


Enumeration::Enumeration(std::string nm,
		const Types::IntegralType *etype,
		std::map<std::string,LexicalElements::Literals::Literal> mp) {

	enumerator_type = etype;

	for (auto&& val : mp) {
		Variable *var = new Variable
				(
					val.first,
					const_cast<Types::IntegralType*>(enumerator_type),
					&val.second
				);

		enumerators.push_back(var);
	}

	new_type = new Types::EnumerationType(nm);

}

Enumeration::~Enumeration() {
	delete new_type;

	for (auto&& val : enumerators) {
		delete val;
	}
}

} /* namespace Enumerations */


namespace Classes {


BasicClass::BasicClass(const AccessLevel* acc, std::string prop_name){

}

BasicClass::~BasicClass() {

}

UnionClass::UnionClass(std::string prop_name) :
		BasicClass(&AccessLevel::R_public, prop_name) {

}

UnionClass::~UnionClass() {

}

CppClass::CppClass(const AccessLevel* acc, std::string prop_name,
		parent_list mp) : BasicClass(acc,prop_name) {

}

CppClass::~CppClass() {

}

ClassClass::ClassClass(std::string prop_name, parent_list mp) :
		Classes::CppClass(&AccessLevel::R_private, prop_name, mp) {

}

ClassClass::~ClassClass() {

}

StructClass::StructClass(std::string prop_name, parent_list mp) :
		Classes::CppClass(&AccessLevel::R_public, prop_name, mp) {

}

StructClass::~StructClass() {

}

} /* namespace Classes */

#ifdef CPP_SUPPORT_SCOPED_ENUM
namespace Enumerations {

ScopedEnumeration::ScopedEnumeration(const Types::ClassType scopetype,
		std::string nm,
		const Types::IntegerType *dtype,
		std::map<std::string,LexicalElements::Literals::Literal> mp) :
				Enumeration(nm,dtype,mp) {

}

ScopedEnumeration::~ScopedEnumeration() {

}


} /* namespace Enumerations */
#endif

} /* namespace Cpp */






















//
//Cpp::PreProcessor::Macro::Macro(void *scope,
//		std::string id, std::string value,
//		std::vector<std::string> allocator) {
//	this->identifier = id;
//	this->statement = value;
//
//	if (allocator.size() > 0) {
//		arguments = std::vector<std::string>(allocator);
//	}
//
//	this->defined = true;
//
//	Cpp::Project::Artifact *a = static_cast<Cpp::Project::Artifact *>(scope);
//
//	a->addMacro(this);
//}
//
//std::string Cpp::PreProcessor::Macro::cpp_str() {
//
//	return "";
//}
//
//std::string Cpp::PreProcessor::Macro::xml_str() {
//
//	// TODO xml_str for CppMacro
//
//	return "";
//}
//
//
//Cpp::PreProcessor::Macro::~Macro() {
//	// TODO Auto-generated destructor stub
//}

/*========================= Variables ========================================*/
#ifdef LANG_CPP_CLASS_VARIABLE



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

//Cpp::Project::Artifact::Artifact() {
//}
//
//const std::map<std::string, Cpp::Feature*>&
//Cpp::Project::Artifact::scopeFeatures() const {
//	return global_scope;
//}
//
//std::map<std::string, Cpp::Feature*>
//Cpp::Project::Artifact::accessibleFeatures() {
//	std::map<std::string, Cpp::Feature*> all_features;
//	all_features.insert(global_scope.begin(),global_scope.end());
//
//	return all_features;
//}
//
//Cpp::Project::Artifact::~Artifact() {
//
//}



} /* namespace cpp */
} /* namespace sheila */


