//SHEILa========================================================================
// Name        : Cpp.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 4, 2018
// Modified    :
//==============================================================================

#ifndef CPP_CPP_H_
#define CPP_CPP_H_

#include <string>
#include <vector>
#include <list>
#include <map>
#include <ctime>
#include <iostream>
#include <sstream>


//#include "../C/language.inc"
//#include "../../symbols.inc"

#if( __cplusplus >= 201103L )
	#define CPP_SUPPORT_SCOPED_ENUM true
#endif

#if( __WORDSIZE >= 32)
	#define CPP_SUPPORT_LONG_INT true
#endif

#if( __WORDSIZE >= 64)
	#define CPP_SUPPORT_LONGLONG_INT true
	#define CPP_SUPPORT_LONG_DOUBLE true
#endif

#if( __WORDSIZE >= 128)
	#define CPP_SUPPORT_LONGLONG_DOUBLE true
#endif

namespace sheila {
namespace cpp {

typedef enum cpp_standard_library_headers {
	C_ASSERT,
	C_CTYPE,
	C_ERRNO,
	C_FLOAT,
	C_ISO646,
	C_LIMITS,
	C_LOCALE,
	C_MATH,
	C_SETJMP,
	C_SIGNAL,
	C_STDARG,
	C_STDDEF,
	C_STDIO,
	C_STDLIB,
	C_STRING,
	C_TIME,
	C_WCHAR,
	C_WCTYPE,
	ALGORITHM,
	BITSET,
	COMPLEX,
	DEQUE,
	EXCEPTION,
	FSTREAM,
	FUNCTIONAL,
	IOMANIP,
	IOS,
	IOSFWD,
	IOSTREAM,
	ISTREAM,
	ITERATOR,
	LIMITS,
	LIST,
	LOCALE,
	MAP,
	MEMORY,
	NEW,
	NUMERIC,
	OSTREAM,
	QUEUE,
	SET,
	SSTREAM,
	STACK,
	STDEXCEPT,
	STREAMBUF,
	STRING,
	TYPEINFO,
	UTILITY,
	VALARRAY,
	VECTOR
} CppStandardHeaderFile;

namespace exception {

//	/** @brief Exception thrown when an Emotion is compared relative to itself.
//	 *  @author FlowerGenius
//	 */
//	struct MacroReDefinitionWarning : public std::runtime_error {
//
//		/** @brief Create an instance of EmotionSelfDiffException.
//		 *  @author FlowerGenius
//		 *  @param e The PlutchikEmotion that was compared to itself.
//		 */
//		MacroRedefinitionWarning(PlutchikEmotion& e) : runtime_error(
//				"Attempted to get the difference between "+
//				Emotion_base::getPlutchikEmotionName(e)+" and itself")
//				{};
//
//		/** Destroy this instance of EmotionSelfDiffException */
//		virtual ~EmotionSelfDiffException() {
//			;
//		}
//
//	};

}



/** @brief Dummy class representing the C++ programming language.
 *  @author FlowerGenius
 *
 *  Stores actions and members which are part of the implementation of the
 *  language.
 *
 *  Important Note: This class is not mean to be instantiated, it is simply
 *  a scoped wrapper for functions and operations specific to C++.
 *
 */
namespace Cpp {

/** @brief An abstract model of a feature of the C++ programming language.
 *  @author FlowerGenius
 *
 *  A feature is essentially an component of the language that is "owned"
 *  by it's enclosing scope. with the only exception being the Macro and
 *  Declaration as the preprocessor does not follow C++ rules of scope.
 *
 */
class Feature {
public:

	enum class FeatureType {

	};

	/** @brief Initializes the @a activated data member by default
	 *  @author FlowerGenius
	 *
	 *  Important Note: This constructor is part of a pure virtual abstract
	 *  base class and as such should never be called excepting that a derived
	 *  class calls it as part of the derivation chain.
	 *
	 */
	Feature() : identifier(""), activated(true) {}

	/** @brief Destroys this CppFeature object
	 *  @author FlowerGenius
	 *
	 *  Important Note: This destructor is part of a pure virtual abstract
	 *  base class and as such should never be called excepting that a derived
	 *  class calls it as part of the derivation chain.
	 *
	 */
	virtual ~Feature(){}

	virtual const std::string& getScope() const { return cpp_scope; }

	/** @brief Retrieve the ID of this Feature
	 *
	 * @return
	 */
	virtual const std::string& getIdentifier() const { return identifier; }

	/** @brief Retrieve the scoped ID of this Feature
	 *
	 * @return
	 */
	virtual std::string getAbsoluteIdentifier() { return getScope() +
			getIdentifier(); }

	/** @brief Pure virtual member function promising the ability of derived
	 *  types of @c CppFeature to be represented in C++ syntax.
	 *  @author FlowerGenius
	 *  @return C++ string representing this feature in C++ syntax.
	 *
	 *  Since a @c CppFeature is a C++ lexical component, it must
	 *  be able to be represented in valid and portable C++ syntax such that
	 *  it can be inserted into a C++ file and form functioning code.
	 *
	 */
	virtual std::string cpp_str() = 0;

	/** @brief Pure virtual member function promising the ability of derived
	 *  types of @c CppFeature to be represented in XML syntax.
	 *  @author FlowerGenius
	 *  @return C++ string representing this feature in XML syntax.
	 *
	 *  Since a @c CppFeature is a C++ lexical component, it can be
	 *  represented using XML.
	 *
	 *  In the C++ program structure model that is defined in the classes found
	 *  in this library, any feature of C++ that can be represented in C++
	 *  syntax can also be represented in a strictly typed specialization of
	 *  XML that can be used to form a meta-level understanding of a C++
	 *  program and each of it's individual components.
	 *
	 *  TL;DR Any feature of C++ can be represented as an XML tag as well.
	 *
	 */
	virtual std::string xml_str() = 0;

protected:

	std::string cpp_scope;

	/** The ID of this Feature */
	std::string identifier;

	/** @brief Represents the commented/uncommented state of the feature */
	bool activated;
};

namespace LexicalElements {
class Identifier;
namespace ReservedWords {
class ReservedWord;
class ReservedTypeWord;
}
}

namespace Scopes {
class Scope;
}

//class Variable;

namespace Types {

/** @brief C++ Type
 *
 *  [O'reilly] The Type for an Identifier determines what you are
 *  allowed to do with it. You associate a type with an identifier
 *  when you declare it. When declaring an Identfier, you also may
 *  have the opportunity to specify a StorageClass and one or more
 *  Qualifiers (see " Declaration ").
 *
 */
class Type {

	typedef const LexicalElements::ReservedWords::ReservedTypeWord* rw_ptr;


	static std::map<Scopes::Scope*,std::list<Type*> > all_types;

public:

	Type(std::initializer_list<std::string> nm = {},  Scopes::Scope *scop=nullptr);
	Type(std::initializer_list<rw_ptr> nm);

	virtual ~Type();

	const bool& reserved_type() const { return rwords; }

	const void *get() const { return reserved_type() ?
			(void*)&words : (void*)&type_name; }

	const std::list<std::string>& getName() const { return type_name; }
	const std::list<rw_ptr>& getWords() const { return words; }

	bool operator==(const Type &t) {

	};

	const static Type Type_name;

protected:

	typedef rw_ptr res_word_ptr;

	std::list<std::string> type_name;
	std::list<rw_ptr> words;

private:

	bool rwords;

	Scopes::Scope *myscope;

};


/** The Fundamental Types of C++ */
namespace FundamentalTypes {

/** @brief A FundamentalType of the C++ ProgrammingLanguages
 *
 *  [O'Reilly] The fundamental types of C++ are its:
 *
 *  @arg @c BooleanType
 *  @arg @c CharacterType
 *  @arg @c IntegerType
 *  @arg @c FloatingPointType
 *  @arg @c VoidType
 *
 */
class FundamentalType : public Type {

	static std::list<const FundamentalType*> all_fundamental_types;

public:
	FundamentalType(std::initializer_list<res_word_ptr> req,
			std::initializer_list<res_word_ptr> opt = {});
	virtual ~FundamentalType();

	const std::list<res_word_ptr>& getReq() const
												{ return req_words; }

	const std::list<res_word_ptr>& getOpt() const
												{ return opt_words; }

	const static FundamentalType Void;;

	const static std::list<const FundamentalType*>& getFundamentalTypes()
				{ return all_fundamental_types; }

protected:
	std::list<res_word_ptr> req_words;
	std::list<res_word_ptr> opt_words;
private:
};

/** @brief The void type.
 *
 *  [O'Reilly] The void type indicates the absence of a value. One
 *  use is in declaring functions that do not return a value.
 *  Another use is in declaring a pointer that can point to any
 *  type of data. Variables that are not pointers cannot be
 *  declared as void.
 *
 */

/** The Arithmetic Types of C++ */
namespace ArithmeticTypes {

/** @brief An ArithmeticType of the C++ ProgrammingLanguage.
 *
 *  [O'Reilly] The ArithmeticTypes of C++ is the collection of
 *  IntegralType and FloatingPointType types.
 *
 */
class ArithmeticType : public FundamentalType {

	static std::list<const ArithmeticType*> all_arithmetic_types;

public:
	ArithmeticType(std::initializer_list<res_word_ptr> req,
			std::initializer_list<res_word_ptr> opt = {});
	virtual ~ArithmeticType();

	const static std::list<const ArithmeticType*>& getArithmeticTypes()
				{ return all_arithmetic_types; }

private:
};

/** The Integral Types of C++ */
namespace IntegralTypes {

/** @brief An IntegralType of the C++ ProgrammingLanguage.
 *
 */
class IntegralType : public ArithmeticType {

	static std::list<const IntegralType*> all_integral_types;

public:

	IntegralType(std::initializer_list<res_word_ptr> req = {},
			std::initializer_list<res_word_ptr> opt = {},
			bool sgn = true);
	virtual ~IntegralType();

	const bool& isSigned(void) const { return _signed_; }

	/** @brief The bool type in C++
	 *
	 *  [O'Reilly] Booleans are of type bool. The bool type
	 *  is used for values of truth.
	 *
	 */
	const static IntegralType Boolean;

	const static std::list<const IntegralType*>& getIntegralTypes()
				{ return all_integral_types; }

private:

	/** @brief Evaluates to true if signed */
	bool _signed_;

private:
};

/** The Character Types of C++ */
namespace CharacterTypes {

/** @brief Characters are of CharType or WideCharType.
 *
 *  [O'Reilly] Characters are of type char or wchar_t.
 *  Character types may be specified as either signed
 *  or unsigned and are sometiems used simply to store
 *  small integers.
 *
 */
class CharacterType : public IntegralType {

	static std::list<const CharacterType*> all_character_types;

public:

	CharacterType(std::initializer_list<res_word_ptr>
	req, std::initializer_list<res_word_ptr> opt = {}, bool sgn=true);
	virtual ~CharacterType();

	/** @brief The char type is a small integer.
	 *
	 *  [O'Reilly] The char type is used for integers
	 *  that refer to characters in a character
	 *  set (ex: ASCII).
	 *
	 */
	const static CharacterType Char;

#ifdef CPP_SUPPORT_WIDE_CHAR
	/** @brief wchar_t
	 *
	 *  [O'Reilly] The wchar_t type is a distinct type
	 *  large enough to represent the character sets of
	 *  all locales supported by the implementation.
	 *  To use facilities related to the wchar_t type,
	 *  you include the standard header file <cwchar>.
	 *
	 */
	const static CharacterType WideChar;
#endif

	/** @brief uchar */
	const static CharacterType UnsignedChar;

#ifdef CPP_SUPPORT_WIDE_CHAR
	/** @brief uwchar_t */
	const static CharacterType UnsignedWideChar;
#endif

	const static std::list<const CharacterType*>& getCharacterTypes()
				{ return all_character_types; }

private:

};

};

/** The Integer Types of C++ */
namespace IntegerTypes {

/** @brief a type representing an integer of some size.
 *
 *  [O'Reilly] Integers are of type short, int, long,
 *  or long long. They differ in size and the range
 *  of values that they can represent.
 *
 *  Integers may be specified as either signed or
 *  unsigned.
 *
 */
class IntegerType : public IntegralType {

	static std::list<const IntegerType*> all_integer_types;

public:

	IntegerType(std::initializer_list<res_word_ptr> req,
			std::initializer_list<res_word_ptr> opt={}, bool sgn=true);
	virtual ~IntegerType();

	/** @brief A short (half byte) integer */
	const static IntegerType ShortInteger;

	/** @brief A simple (full byte) integer */
	const static IntegerType BasicInteger;

#ifdef CPP_SUPPORT_LONG_INT
	/** @brief A long (4x byte) integer */
	const static IntegerType LongInteger;
#endif

#ifdef CPP_SUPPORT_LONGLONG_INT
	/** @brief A long long (8x byte) integer */
	const static IntegerType LongLongInteger;
#endif


	/** @brief A short (half byte) integer */
	const static IntegerType UnsignedShortInteger;

	/** @brief A simple (full byte) integer */
	const static IntegerType UnsignedBasicInteger;

#ifdef CPP_SUPPORT_LONG_INT
	/** @brief A long (4x byte) integer */
	const static IntegerType UnsignedLongInteger;
#endif

#ifdef CPP_SUPPORT_LONGLONG_INT
	/** @brief A long long (8x byte) integer */
	const static IntegerType UnsignedLongLongInteger;
#endif

	const static std::list<const IntegerType*> getIntegerTypes()
				{ return all_integer_types; }
private:

};
};
};

/** The Floating Point Types of C++ */
namespace FloatingPointTypes {


/** @brief Floating point type in C++
 *
 *  [O'Reilly] Floating points are of type float, double
 *  long double, or long long double. These types differ
 *  in size and in the range and precision of values they
 *  can represent.
 *
 */
class FloatingPointType : public ArithmeticType {

	static std::list<const FloatingPointType*> all_floating_point_types;

public:
	FloatingPointType(std::initializer_list<res_word_ptr>
	req, std::initializer_list<res_word_ptr> opt = {});
	virtual ~FloatingPointType();


	/** @brief A single precision floating point value */
	const static FloatingPointType Float;

	/** @brief A double precision floating point value */
	const static FloatingPointType Double;

#ifdef CPP_SUPPORT_LONG_DOUBLE
	/** @brief A long (x4) double precision floating point
	 * value
	 */
	const static FloatingPointType LongDouble;
#endif

#ifdef CPP_SUPPORT_LONGLONG_DOUBLE
	/** @brief A long long (x8) double precision floating
	 * point value
	 */
	const static FloatingPointType LongLongDouble;
#endif

	const static std::list<const FloatingPointType*>& getFloatingPointTypes()
				{ return all_floating_point_types; }

private:

};

};
};
};

/** The Compound Types of C++ */
namespace CompoundTypes {

/** @brief A complex type built on the Arithmetic Types.
 *
 *  [O'Reilly] The compound types of C++ are:
 *
 */
class CompoundType : public Type {
public:

	CompoundType(std::initializer_list<std::string> nm ={});

	CompoundType(std::initializer_list<res_word_ptr>
	req, std::initializer_list<res_word_ptr> opt = {});
	virtual ~CompoundType();

	const static CompoundType T_Enum;

#ifdef CPP_SUPPORT_SCOPED_ENUM
	const static CompoundType T_ScopedEnum;
#endif

	const static CompoundType T_Array;

	const static CompoundType T_Pointer;

	const static CompoundType T_PointerToMember;

	const static CompoundType T_Reference;

	const static CompoundType T_Function;

protected:

	Type *contents_type;

};

namespace EnumerationTypes {

/** @brief An enumeration type in C++.
 *
 *  [O'Reilly] An enumeration, specified by the keyword enum,
 *  is a set of integer constants associated with identifiers,
 *  called enumerators, that you define. In general
 *  enumerations provide a way to use meaningful names where
 *  you might otherwise use integer constants, prehaps defined
 *  using the preprocessor directive #define. Enumerations are
 *  preferred over the preprocessor for this in C++ because
 *  they obey the language's rules of scope.
 *
 */
class EnumerationType : public CompoundType {
public:

	EnumerationType(std::string nm = "");
	virtual ~EnumerationType();

};

}

/** @brief An array type in C++.
 *
 *  [O'Reilly] Arrays contain a specific number of elements of
 *  a particular type. So that when the compiler can reserve the
 *  requested amount of spce when the program is compiles, you
 *  must specify the type and number of elements that the array
 *  will contain when it is defined. The compiler must be able
 *  to determing this value when the program is compiled.
 */
class ArrayType : public CompoundType {
public:

	ArrayType(const Types::Type *array_of);
	virtual ~ArrayType();
};




/** @brief A string Type in C++.
 *
 *  [O'Reilly] Character (C-Style) strings are arrays of
 *  characters terminated with a null character (\0). The
 *  characters of the string are of type char or type wchar_t
 *  for wide character strings.
 *
 */
class StringType : public CompoundType {
public:
	StringType(const Types::FundamentalTypes::ArithmeticTypes::IntegralTypes::
			CharacterTypes::CharacterType *string_of);
	virtual ~StringType();

	/** @brief C-style string of char */
	const static StringType T_CharString;

	/** @brief C-style string wchar_t */
	const static StringType T_WideCharString;

	/** @brief C-style string of char */
	const static StringType T_UnsignedCharString;

	/** @brief C-style string wchar_t */
	const static StringType T_UnsignedWideCharString;

};

/** @brief A pointer type in C++.
 *
 *  [O'Reilly] For any type @a T there is a corresponding type
 *  @a pointer @a to @a T for variables that contain addresses in
 *  memory of where data of Type @a T resides. @a T is the
 *  base type of a pointer to @a T. Pointers are declared by
 *  placing an asterisk before the variable name in a declaration.
 *
 */
class PointerType : public CompoundType {
public:

	PointerType(Types::Type *target);
	virtual ~PointerType();

};

/** @brief [O'Reilly] Alternative name for a class member.
 *
 *  [O'Reilly] Pointers to members are like alternative names for
 *  class members.
 *
 */
class PointerToMemberType : public CompoundType {
public:
	PointerToMemberType(Types::Type *member);
	virtual ~PointerToMemberType();

};


/** @brief A reference provides an alternative name for a variable.
 *
 *  [O'Reilly] References are used to provide alternative names for
 *  variables. They are declared by placing an ampersand (&) before
 *  the variable name in a declaration. Because a reference always
 *  has to refer to something, references must be initialized where
 *  they are defined. Therefore, a reasonable way to think of a
 *  reference is as a constant Pointer. Once initialized, the
 *  reference itself cannot be made to refer to anything else;
 *  however, the variable or object to which it refers can be
 *  modified. Operations applied to the reference affect the
 *  variable or object to which the reference refers.
 *
 */
class ReferenceType : public CompoundType {
public:
	ReferenceType(Types::Type *target);
	virtual ~ReferenceType();

};


/** The Class Types of C++ */
namespace ClassTypes {

/** @brief A ClassType of C++.
 *
 *  The Class types of C++ are Unions, Structs, and Classes
 *
 *  [O'Reilly] Classes are types that group data and
 *  functionality together into encapsulated, cohesive units.
 *  Structs and unions are similar to classes, but differ
 *  in the ways outlined later... ...Classes, structs, and
 *  unions are collectively called @a class @a types.
 *
 */
class ClassType : public CompoundType {
public:

	ClassType(std::initializer_list<res_word_ptr>
	req = {});
	virtual ~ClassType();

	const static ClassType T_Class;

	const static ClassType T_Union;

	const static ClassType T_Struct;

};

/** @brief A C++ Union type.
 *
 * [O'Reilly] Unions are similar to classes; however they can
 * hold a value for only one data member at a time. As a
 * result, a union occupies only as much space as it's largest
 * data member requires. Other differences between unions and
 * classes are:
 *
 * @arg The default access level for unions is public; the
 * default access level for classes is private.
 * @arg Unions cannot have member functions that are declared
 * using the keyword @c virtual.
 * @arg Unions cannot inherit from anything, nor can anything
 * inherit from them.
 * @arg The members of unions cannot be objects that define
 * constructors or destructors, or that overload the assignment
 * operator.
 *
 * Unions can be anonymous (unnamed). This form is used when
 * nesting a union inside a struct or class that contains an
 * extra data member to indicate what the union contains.
 *
 */
class CppUnionType : public Type {
public:
	CppUnionType(std::string nm);
	virtual ~CppUnionType();

};

/** @brief A C++ Class type.
 *
 *  [O'Reilly] You define a class by declaring a set of data
 *  members and member functions for it.
 */
class CppClassType : public Type {
public:
	CppClassType(std::string nm = "");
	virtual ~CppClassType();

};

/** @brief A C++ Struct type.
 *
 *  [O'Reilly] Structs are functionally identical to classes
 *  except that the default access level for their members is
 *  public, not private. To define a struct, you use the
 *  keyword @c struct, in place of the keyword @c class.
 *
 */
class CppStructType : public CppClassType {
public:
	CppStructType(std::string nm);
	virtual ~CppStructType();
};

} /* namespace ClassTypes */

#ifdef CPP_SUPPORT_SCOPED_ENUM
namespace EnumerationTypes {

/** @brief A scoped enumeration type in C++.
 *
 *  A scoped enum can have the type either @c class or @c struct. the name
 *  is optional as enumerations can be anonymous. A scoped enum can also
 *  specify any integral data type as the type of it's enumerators.
 *
 */
class ScopedEnumType : public EnumerationType {
public:

	ScopedEnumType(const ClassTypes::ClassType *scopetype, std::string nm = "",
			const FundamentalTypes::ArithmeticTypes::IntegralTypes::IntegralType
			*dtype = &FundamentalTypes::ArithmeticTypes::IntegralTypes::
			IntegerTypes::IntegerType::BasicInteger);

	virtual ~ScopedEnumType();

private:

	const ClassTypes::ClassType *scope_class;
	const FundamentalTypes::ArithmeticTypes::IntegralTypes::IntegralType *datatype;

};

} /* namespace EnumerationTypes */
#endif

} /* namespace CompoundTypes */

using namespace FundamentalTypes;

typedef FundamentalType FundamentalType;

using namespace ArithmeticTypes;

typedef ArithmeticType ArithmeticType;

using namespace IntegralTypes;

typedef IntegralType IntegralType;

using namespace CharacterTypes;

typedef CharacterType CharacterType;

using namespace IntegerTypes;

typedef IntegerType IntegerType;

using namespace FloatingPointTypes;

typedef FloatingPointType FloatingPointType;

using namespace CompoundTypes;

typedef CompoundType CompoundType;

using namespace EnumerationTypes;

typedef EnumerationType EnumerationType;

typedef ArrayType ArrayType;
typedef StringType StringType;
typedef PointerType PointerType;
typedef PointerToMemberType PointerToMemberType;
typedef ReferenceType ReferenceType;

using namespace ClassTypes;

typedef ClassType ClassType;
typedef CppUnionType CppUnionType;
typedef CppClassType CppClassType;
typedef CppStructType CppStructType;

#ifdef CPP_SUPPORT_SCOPED_ENUM
	typedef ScopedEnumType ScopedEnumType;
#endif
/** @brief C++ Type definition. (Different From a @c typedef statement)
 *
 */
class TypeDefinition : public Feature {

};

/** @brief An alias name definition for a type, i.e. a typedef statement.
 *
 */
class TypeDeclaration : public Feature {

};
} /* namespace Types */

/** The Lexical Elements of C++ */
namespace LexicalElements {

/** @brief A Lexical element in C++ *
 *
 */
class LexicalElement {
public:

	LexicalElement();
	virtual ~LexicalElement();

};

class Comment : public LexicalElement {
public:

	Comment();
	virtual ~Comment();

};

/** @brief An identifier is a unique name that references data.
 *
 */
class Identifier : public LexicalElement {
public:

	Identifier(std::string unformatted_string,
			Types::Type *typ=nullptr);
	virtual ~Identifier();

	void declare(Types::Type *t);

	const Types::Type* getType() const { return t; }

	const std::string& getName() const { return name; }

private:

	std::string name;
	Types::Type *t;

};

/** @brief A Typename is an identifier that represents a Type
 *
 */
class Typename : public LexicalElement {
public:

	Typename(std::string nm, Types::Type typ);
	virtual ~Typename();

private:
	Identifier  name;
	Types::Type type_named;

};

/** The Reserved Words of C++ */
namespace ReservedWords {

/** @brief The reserved keywords and tokens of C++
 *
 */
class ReservedWord : public LexicalElement {
public:



	static const ReservedWord R_and;
	static const ReservedWord R_and_eq;
	static const ReservedWord R_not;
	static const ReservedWord R_not_eq;

	static const ReservedWord R_asm;
	static const ReservedWord R_bitand;
	static const ReservedWord R_bitor;
	static const ReservedWord R_break;
	static const ReservedWord R_case;
	static const ReservedWord R_catch;
	static const ReservedWord R_compl;
	static const ReservedWord R_const_cast;
	static const ReservedWord R_continue;
	static const ReservedWord R_default;
	static const ReservedWord R_delete;
	static const ReservedWord R_do;
	static const ReservedWord R_dynamic_cast;
	static const ReservedWord R_else;
	static const ReservedWord R_explicit;
	static const ReservedWord R_export;
	static const ReservedWord R_false;
	static const ReservedWord R_for;
	static const ReservedWord R_friend;
	static const ReservedWord R_goto;
	static const ReservedWord R_if;
	static const ReservedWord R_inline;
	static const ReservedWord R_namespace;
	static const ReservedWord R_new;

	static const ReservedWord R_operator;
	static const ReservedWord R_or;
	static const ReservedWord R_or_eq;

	static const ReservedWord R_reinterpret_cast;
	static const ReservedWord R_return;
	static const ReservedWord R_sizeof;
	static const ReservedWord R_static_cast;
	static const ReservedWord R_switch;
	static const ReservedWord R_template;
	static const ReservedWord R_this;
	static const ReservedWord R_throw;
	static const ReservedWord R_true;
	static const ReservedWord R_try;
	static const ReservedWord R_typedef;
	static const ReservedWord R_typeid;
	static const ReservedWord R_using;
	static const ReservedWord R_virtual;
	static const ReservedWord R_while;
	static const ReservedWord R_xor;
	static const ReservedWord R_xor_eq;

	//				template<typename _Tp>
	//				static const ReservedWord *rfromtype() {
	//
	//				}

	static const std::list<const ReservedWord*>& getAllWords() {
		return all_words;
	}

	static const bool isReservedWord(std::string nm) {
		for (auto&& word : all_words) {
			if (word->getWord() == nm) { return true; }
		}

		return false;
	}


	ReservedWord(std::string str);
	virtual ~ReservedWord();

	const std::string& getWord() const { return name.getName(); }



protected:
	Identifier name;

private:
	static std::list<const ReservedWord*> all_words;
};

class ReservedTypeWord : public ReservedWord {

	static std::list<const ReservedTypeWord*> all_type_words;

public:

	static const ReservedTypeWord R_void;

	static const ReservedTypeWord R_bool;

	static const ReservedTypeWord R_char;

	static const ReservedTypeWord R_wchar_t;

	static const ReservedTypeWord R_short;

	static const ReservedTypeWord R_int;

	static const ReservedTypeWord R_long;

	static const ReservedTypeWord R_float;

	static const ReservedTypeWord R_double;

	static const ReservedTypeWord R_enum;

	static const ReservedTypeWord R_class;

	static const ReservedTypeWord R_struct;

	static const ReservedTypeWord R_union;

	static const ReservedTypeWord R_signed;

	static const ReservedTypeWord R_unsigned;

	static const ReservedTypeWord R_typename;

	ReservedTypeWord(std::string str);
	virtual ~ReservedTypeWord();

};

class Qualifier : public ReservedWord {

	static std::list<const Qualifier*> all_qualifiers;

public:

	static const Qualifier R_const; // = Qualifier("const");
	static const Qualifier R_volatile; // = Qualifier("volatile");


	Qualifier(std::string str);
	virtual ~Qualifier();

};

class StorageClass : public ReservedWord {

	static std::list<const StorageClass*> all_storage_classes;

public:

	static const StorageClass R_extern;
	static const StorageClass R_auto;
	static const StorageClass R_mutable;
	static const StorageClass R_static;
	static const StorageClass R_register;

	StorageClass(std::string str);
	virtual ~StorageClass();

};

class AccessLevel : public ReservedWord {

	static std::list<const AccessLevel*> all_access_levels;

public:

	static const AccessLevel R_private;
	static const AccessLevel R_protected;
	static const AccessLevel R_public;

	AccessLevel(std::string str);
	virtual ~AccessLevel();

};


};


/** @brief An Expression in C++.
 *
 *  [O'Reilly] An expression is something that yields a value. Nearly
 *  every type of statement uses an expression in some way. The
 *  simplest expressions in C++ are just literals or variables by
 *  themselves.
 *
 */
class Expression : public LexicalElement {
public:

	Expression(std::initializer_list<LexicalElement> expr = {});
	virtual ~Expression();

	virtual void *yields();

protected:

	/** @brief The Stream of LexicalElement that this expression is
	 * composed of.
	 */
	std::vector<LexicalElement> composition;

};

namespace Literals {

/** @brief A literal expression in C++.
 *
 *  A literal expression is an expression that can be written
 *  as a string, but the preprocessor identifies the type
 *  implicitly based on the syntax.
 *
 */
class Literal : public Expression {

public:

	Literal(std::string,const Types::Type *typ=nullptr);

	//				Literal(bool);
	//				Literal(char);
	//				Literal(short);
	//				Literal(int);
	//				Literal(long);
	//				Literal(long long);

	virtual ~Literal();

	void *getData() const { return data; }

	template<typename _Tp>
	const _Tp get() {
		return (const _Tp)&data;
	}

	const static Literal Bool_true;
	const static Literal Bool_false;

protected:

	const Types::Type *data_type;

	std::string verbatim;

private:

	void *data;

};

};

/** The Operators of C++ */
namespace Operators {

/** @brief A C++ Operator.
 *
 *  [O'Reilly] An operator is used to perform a specific operation
 *  on a set of operands in an expression. Operators in C++ work
 *  with anywhere from one to three operands, depending on the
 *  operator.
 *
 */
class Operator : public LexicalElement {
public:

	/** @brief Scope resolution operator in C++ (::).
	 *
	 *  [O'Reilly] The scope resolution operator is used to specify
	 *  a scope. The scope operator can also be used without a scope
	 *  name to specify the @a global scope.
	 *
	 */
	static const Operator O_ScopeResolution;

	/** @brief Array subscript operator in C++ ([]).
	 *
	 *  [O'Reilly] The array subscript operator is used to access
	 *  individual elements of arrays or memory referenced by
	 *  pointers.
	 *
	 */
	static const Operator O_ArraySubscript;

	/** @brief Functon call operator in C++ (()).
	 *
	 *  [O'Reilly] The function call operator, which is ( ), is used
	 *  to invoke a function.
	 *
	 */
	static const Operator O_FunctionCall;

	/** @brief Value construction operator in C++ (()).
	 *
	 *  [O'Reilly] The value construction operator, which is also ( ),
	 *  is used to create an instance of a type.
	 *
	 */
	static const Operator O_ValueConstruction;

	static const Operator O_PostfixIncrement;

	static const Operator O_PostfixDecrement;

	/** @brief @c typeid operator in C++ (typeid).
	 *
	 *  [O'Reilly] The @c typeid operator gets runtime type information
	 *  for an operand... ...To get type information about a variable
	 *  or type itself [(Typename)], you use the @c typeid operator.
	 *
	 *  The operand for @c typeid may be an expression or a type. The
	 *  result of the @c typeid operator is a constant reference to
	 *  an object of type @c type_info.
	 *
	 */
	static const Operator O_TypeInformation;

	static const Operator O_SizeInformation;

	static const Operator O_PrefixIncrement;

	static const Operator O_PrefixDecrement;

	static const Operator O_BitwiseNot;

	static const Operator O_LogicalNot;

	static const Operator O_UnaryMinus;

	static const Operator O_UnaryPlus;

	static const Operator O_AddressOf;

	static const Operator O_Indirection;

	static const Operator O_Allocate;

	static const Operator O_ArrayAllocate;

	static const Operator O_Deallocate;

	static const Operator O_ArrayDeallocate;

	static const Operator O_CstyleCast;

	static const Operator O_DotPointerToMemberSelection;

	static const Operator O_ArrowPointerToMemberSelection;

	static const Operator O_Multiply;

	static const Operator O_Divide;

	static const Operator O_Modulo;

	static const Operator O_Add;

	static const Operator O_Subtract;

	static const Operator O_ShiftLeft;

	static const Operator O_ShiftRight;

	static const Operator O_LessThan;

	static const Operator O_LessEqual;

	static const Operator O_GreaterThan;

	static const Operator O_GreaterEqual;

	static const Operator O_EqualTo;

	static const Operator O_NotEqualTo;

	static const Operator O_BitwiseAnd;

	static const Operator O_BitwiseXor;

	static const Operator O_BitwiseOr;

	static const Operator O_LogicalAnd;

	static const Operator O_LogicalOr;

	static const Operator O_ConditionalExpression;

	static const Operator O_SimpleAssignment;

	static const Operator O_MultiplyAssign;

	static const Operator O_DivideAssign;

	static const Operator O_ModuloAssign;

	static const Operator O_AddAssign;

	static const Operator O_SubtractAssign;

	static const Operator O_ShiftLeftAssign;

	static const Operator O_ShiftRightAssign;

	static const Operator O_AndAssign;

	static const Operator O_XorAssign;

	static const Operator O_OrAssign;

	static const Operator O_ThrowException;

	static const Operator O_Sequence;

	Operator(std::string regex="", short associativity=0);
	virtual ~Operator();

private:

	/** @brief Determines the association of the Operator
	 *
	 *  @arg @c 0 No association.
	 *  @arg @c 1 Associates Left.
	 *  @arg @c 2 Associates Right.
	 */
	short associates;

	std::string regex;

};


class MemberSelectionOperator : public Operator {
public:

	static const MemberSelectionOperator O_DotMemberSelection;

	static const MemberSelectionOperator O_ArrowMemberSelection;

	MemberSelectionOperator();
	virtual ~MemberSelectionOperator();

};


/** @brief A C++ Cast Operator.
 *
 *  [O'Reilly] The cast operators specific to C++ are:
 *
 *  @arg @c dynamic_cast See O_DynamicCast.
 *  @arg @c static_cast See O_StaticCast.
 *  @arg @c const_cast See O_ConstCast.
 *  @arg @c reinterpret_cast See O_ReinterpretCast.
 *
 */
class CppCastOperator : public Operator {
public:

	/** @brief  C++ Type Cast - Dynamic
	 *
	 *  [O'Reilly] The @c dynamic_cast operator casts a pointer
	 *  of one class type to a pointer of another within a
	 *  derivation chain. It is allowed only with pointers and
	 *  references to polymorphic types, which are types that
	 *  have at least one virtual member function.
	 *
	 */
	static const CppCastOperator O_DynamicCast;

	/** @brief C++ Type Cast - Static
	 *
	 *  [O'Reilly] The @c static_cast operator is used to
	 *  cast a pointer of one class type to a pointer of another
	 *  within a derivation chain while avoiding the runtime
	 *  checks done with @c dynamic_cast. As a result, you can
	 *  use the @c static_cast operator with pointers to non-
	 *  polymorphic types, which are types that have no virtual
	 *  member functions. You can also use it to carry out some
	 *  of the conversions performed using C-style casts, generally
	 *  conversions between related types. The @c static_cast
	 *  operator has the same syntax as @c dynamic_cast.
	 *
	 */
	static const CppCastOperator O_StaticCast;

	/** @brief C++ Type Cast - Constant
	 *
	 *  [O'Reilly] You can use the @c const_cast operator to cast
	 *  away the @c const and @c volatile qualifiers. It has the
	 *  same syntax as @c dynamic_cast. Between the angle brackets,
	 *  you specify the same type as the original without the
	 *  @c const or @c volatile qualifier. Using the result is
	 *  assured to be safe only if the data to which the pointer
	 *  points was not declared as @c const or @c volatile when it
	 *  was first declared in the program.
	 *
	 */
	static const CppCastOperator O_ConstCast;

	/** @brief C++ Type Cast - Reinterpret
	 *
	 *  [O'Reilly] The @c reinterpret_cast allows you to convert
	 *  a pointer to any other pointer type. It also allows you
	 *  to convert any integral type to a pointer and back. It
	 *  uses syntax like the other forms of casting specific to
	 *  C++. It is typically used sparingly.
	 *
	 */
	static const CppCastOperator O_ReinterpretCast;


	CppCastOperator();
	virtual ~CppCastOperator();

};

};

};

namespace Scopes {

class Scope {

	static std::list<Scope*> scopes;

public:

	static Scope global_scope;

	//	static Scope* newScope(Scope &encloser = global_scope);

	Scope(std::initializer_list<LexicalElements::Identifier> ls = {});
	virtual ~Scope();

	std::string str();

};

};


//	/** A C++ Token
//	 *
//	 */
//	class Token {
//	public:
//
//
//		/** @brief Initializes the @a activated data member by default
//		 *  @author FlowerGenius
//		 *
//		 *  Important Note: This constructor is part of a pure virtual abstract
//		 *  base class and as such should never be called excepting that a derived
//		 *  class calls it as part of the derivation chain.
//		 *
//		 */
//		Token(std::string id = "", bool act = true) :
//			identifier(id), activated(act) {}
//
//		/** @brief Destroys this CppFeature object
//		 *  @author FlowerGenius
//		 *
//		 *  Important Note: This destructor is part of a pure virtual abstract
//		 *  base class and as such should never be called excepting that a derived
//		 *  class calls it as part of the derivation chain.
//		 *
//		 */
//		virtual ~Token(){}
//
//		virtual const Scopes::Scope& getScope() const { return cpp_scope; }
//
//		/** @brief Retrieve the ID of this Feature
//		 *
//		 * @return
//		 */
//		virtual const LexicalElements::Identifier& getIdentifier() const { return identifier; }
//
//		/** @brief Retrieve the scoped ID of this Feature
//		 *
//		 * @return
//		 */
//		virtual std::string getAbsoluteIdentifier() { return getScope().str() +
//				getIdentifier().getName(); }
//
//		/** @brief Pure virtual member function promising the ability of derived
//		 *  types of @c CppFeature to be represented in C++ syntax.
//		 *  @author FlowerGenius
//		 *  @return C++ string representing this feature in C++ syntax.
//		 *
//		 *  Since a @c CppFeature is a C++ lexical component, it must
//		 *  be able to be represented in valid and portable C++ syntax such that
//		 *  it can be inserted into a C++ file and form functioning code.
//		 *
//		 */
//		virtual std::string cpp_str() = 0;
//
//		/** @brief Pure virtual member function promising the ability of derived
//		 *  types of @c CppFeature to be represented in XML syntax.
//		 *  @author FlowerGenius
//		 *  @return C++ string representing this feature in XML syntax.
//		 *
//		 *  Since a @c CppFeature is a C++ lexical component, it can be
//		 *  represented using XML.
//		 *
//		 *  In the C++ program structure model that is defined in the classes found
//		 *  in this library, any feature of C++ that can be represented in C++
//		 *  syntax can also be represented in a strictly typed specialization of
//		 *  XML that can be used to form a meta-level understanding of a C++
//		 *  program and each of it's individual components.
//		 *
//		 *  TL;DR Any feature of C++ can be represented as an XML tag as well.
//		 *
//		 */
//		virtual std::string xml_str() = 0;
//
//	protected:
//
//		Scopes::Scope *cpp_scope;
//
//		/** The ID of this Feature */
//		LexicalElements::Identifier identifier;
//
//		/** @brief Represents the commented/uncommented state of the feature */
//		bool activated;
//	};

/** @brief A C++ variable.
 *
 */
class Variable : public LexicalElements::Expression {
	/* Usage:
	 *
	 *     !{{identifier}}
	 *
	 * XML:
	 *
	 *     <variable id=!{{identifier}} />
	 *
	 */
public:

	/** @brief A variable in C++.
	 *
	 *  @param id
	 *  @param typ
	 *  @param val
	 */
	Variable(std::string proposed_id,Types::Type *typ=nullptr,
			LexicalElements::Expression *val=nullptr);

	virtual ~Variable();

	/**
	 *
	 * @return
	 */
	const Types::Type* getType() const { return type; }

	/**
	 *
	 */
	void setType(Types::Type* type) { this->type = type; }


	/** @brief Get the value of this variable
	 *
	 *  @return A reference to @a value.
	 */
	const LexicalElements::Expression* getValue() const {
		return value;
	}

	std::string cpp_str();

	std::string xml_str();

protected:

	LexicalElements::Identifier id;

	/** Pointer to the value of this variable */
	LexicalElements::Expression *value;

	/** The type of value contained by this variable */
	Types::Type *type;

	std::vector<const LexicalElements::
	ReservedWords::Qualifier*> qualifiers;

	std::vector<const LexicalElements::
	ReservedWords::StorageClass*> storage_classes;

};

/** @brief A C++ Function.
 *
 */
class Function {
public:
	Function();
	virtual ~Function();

	std::string cpp_str();

	std::string xml_str();

private:

	/** Pointer to the value returned by this function */
	LexicalElements::Expression return_value;

	/** The return type of this function */
	Types::Type ret_type;


}; /* Function */

namespace Statements {

class Statement {

};

class ExpressionStatement {

};

namespace Declarations {

class Declaration : public Statement {

};

class VariableDeclaration : public Declaration {

};

class FunctionDeclaration : public Declaration {

};

namespace Definitions {

class Definition : public Declaration {

};

class VariableDefinition : public VariableDeclaration {

};

class FunctionDefinition : public FunctionDeclaration {

};

} /* namespace Definitions */

} /* namespace Declarations */

} /* namespace Statements */


#define LANG_CPP_CLASS_TYPE_DECLARATION

namespace Enumerations {

class Enumeration {
public:

	Enumeration(
		std::string nm,
		const Types::IntegralType *etype = &Types::IntegerType::BasicInteger,
		std::map<std::string,LexicalElements::Literals::Literal> = {}
	);

	virtual ~Enumeration();

	const std::vector<Variable*>&
	getEnumerators() const { return enumerators; }


protected:

	const Types::IntegralType *enumerator_type;

	const Types::EnumerationType *new_type;

private:

	std::vector<Variable*> enumerators;

};


} /* namespace Enumerations */

namespace ClassMembers {

class DataMember : public Variable {

};

class MemberFunction : public Function {

};

} /* namespace ClassMembers */

namespace Classes {

using namespace LexicalElements::ReservedWords;

class CppClass;

typedef std::map<CppClass*, std::pair<const AccessLevel*,bool> > parent_list;

class BasicClass : protected Scopes::Scope {

public:

	BasicClass(const AccessLevel *def_acc,
			std::string proposed_name="");
	virtual ~BasicClass();

protected:

	const AccessLevel *default_access;

private:

};

class UnionClass : public BasicClass {

public:

	UnionClass(std::string prop_name);
	virtual ~UnionClass();

};

class CppClass : public BasicClass {
public:
	CppClass(const AccessLevel* acc, std::string prop_name, parent_list mp);
	virtual ~CppClass();
};

class ClassClass : public CppClass {
public:
	ClassClass(std::string prop_name, parent_list mp);
	virtual ~ClassClass();

};

class StructClass : public CppClass {

public:

	StructClass(std::string prop_name, parent_list mp);
	virtual ~StructClass();

};


} /* namespace Classes */

#ifdef CPP_SUPPORT_SCOPED_ENUM
	namespace Enumerations {
		class ScopedEnumeration : public Enumeration, protected Scopes::Scope {
		public:

			ScopedEnumeration(const Types::ClassType scopetype,
					std::string nm = "",
					const Types::IntegerType *dtype = &Types::IntegerType::
					BasicInteger,
					std::map<std::string,LexicalElements::Literals::Literal>
			mp ={}
			);
			virtual ~ScopedEnumeration();

		protected:

		};
	} /* namespace Enumerations */
#endif


	/** @brief C++ namespace
	 *
	 */
	class Namespace : public Scopes::Scope {
	public:
		Namespace();
		virtual ~Namespace();

		std::string cpp_str();

		std::string xml_str();

	};

	namespace Structure {

		/** @brief the C++ preprocessor
		 *
		 */
		namespace PreProcessor {

			enum class PreProcessorDirectiveType {
				DEFINE,
				UNDEF,
				IFDEF,
				IFNDEF,
				ELSE,
				ENDIF,
				IF,
				ELIF,
				INCLUDE,
				ERROR,
				LINE,
				PRAGMA
			};

			/** @brief A C++ preprocessor Macro
			 *
			 */
			class Macro {
			public:

				/*
				 * Set the macro located at the address of the pointer to defined
				 */
				static int define_macro(Macro *mptr) { return mptr->define(); }

				/*
				 * Set the macro located at the address of the pointer to undefined
				 */
				static int undefine_macro(Macro *mptr) { return mptr->undefine(); }

				Macro(void* scope, std::string id,
						std::string value = "", std::vector<std::string> = {});

				virtual ~Macro();

				/*
				 * Test for whether the macro is defined
				 */
				//bool isDefined() { return (this->defined && this->activated); }

				/*
				 * Set the macro as defined
				 */
				int define() { defined = true; return (this->defined == true); }

				/*
				 * Set the macro as undefined
				 */
				int undefine() { defined = false; return (this->defined == false); }

				//const std::string& getIdentifier() const { return identifier; }
				const std::string& getStatement() const { return statement; }
				const std::vector<std::string>& getArguments() const {return arguments; }


				std::string cpp_str();

				std::string xml_str();


			private:

				bool defined;
				std::vector<std::string> arguments;
				std::string statement;
			};

			namespace Directives {

			enum class DirectiveType {
				DEFINE,
				UNDEF,
				IFDEF,
				IFNDEF,
				ELSE,
				ENDIF,
				IF,
				ELIF,
				INCLUDE,
				ERROR,
				LINE,
				PRAGMA,
				OTHER
			};


			/** @brief Abstract model of a C++ Preprocessor directive.
			 *  @author FlowerGenius
			 */
			struct Directive_base {
			public:
				static std::string T(DirectiveType t) {
					switch(t){
					case DirectiveType::DEFINE:
						return "define";
					case DirectiveType::UNDEF:
						return "undef";
					case DirectiveType::IFDEF:
						return "ifdef";
					case DirectiveType::IFNDEF:
						return "ifndef";
					case DirectiveType::ELSE:
						return "else";
					case DirectiveType::ENDIF:
						return "endif";
					case DirectiveType::IF:
						return "if";
					case DirectiveType::ELIF:
						return "elif";
					case DirectiveType::INCLUDE:
						return "include";
					case DirectiveType::ERROR:
						return "error";
					case DirectiveType::LINE:
						return "line";
					case DirectiveType::PRAGMA:
						return "pragma";
					default:
						return "other";
					}
				}

				Directive_base() {
					before = nullptr;
				}


				virtual ~Directive_base() {
					;
				}

				/** @brief The feature that comes before the directive
				 *
				 */
				Feature* before;

			};

			/** @brief Generic CppPPDirective template class
			 *  @author FlowerGenius
			 *  @tparam _Td Type of C++ preprocessor directive.
			 *
			 *
			 * Generic template for a C++ preprocessor directive, as there are a finite
			 * number of directives, templates are used with explicit specializations for
			 * each type of directive.
			 *
			 * Author's Note RE: The Generic CppPPDirective template class
			 *
			 * While the generic template can be used and will almost always produce good
			 * code, it does not contribute to the code model and should be used sparingly.
			 *
			 * - FlowerGenius
			 */
			template<DirectiveType _Td>
			class Directive : public Directive_base, public Feature {
			public:
				Directive(std::vector<std::string> allocator = {});

				virtual ~Directive();

				std::string cpp_str();

				std::string xml_str();

			private:
				std::vector<std::string> parameters;
			};

			/** @brief Type definition of the specialization DEFINE for convenience and
			 * 	readability.
			 * 	@author FlowerGenius
			 *
			 * 	A specialization of the CppPPDirective template
			 */
			typedef Directive<DirectiveType::DEFINE> DefineDirective;

			/** @brief Type definition of the specialization UNDEF for convenience and
			 * 	readability.
			 * 	@author FlowerGenius
			 *
			 * 	A specialization of the CppPPDirective template
			 */
			typedef Directive<DirectiveType::UNDEF> UndefDirective;

			/** @brief Type definition of the specialization IFDEF for convenience and
			 * 	readability.
			 * 	@author FlowerGenius
			 *
			 * 	A specialization of the CppPPDirective template
			 */
			typedef Directive<DirectiveType::IFDEF> IfdefDirective;

			typedef Directive<DirectiveType::IFNDEF> IfndefDirective;

			typedef Directive<DirectiveType::ELSE> ElseDirective;

			typedef Directive<DirectiveType::ENDIF> EndifDirective;

			typedef Directive<DirectiveType::IF> IfDirective;

			typedef Directive<DirectiveType::ELIF> ElifDirective;

			typedef Directive<DirectiveType::INCLUDE> IncludeDirective;

			typedef Directive<DirectiveType::ERROR> ErrorDirective;

			typedef Directive<DirectiveType::LINE> LineDirective;

			typedef Directive<DirectiveType::PRAGMA> PragmaDirective;

			};

		}; /* PreProcessor */

		/** @brief A C++ File
		 *
		 */
		namespace Files {

			namespace OutFiles {
				class Artifact;
			}

			/** @brief A basic file on the filesystem
			 *
			 */
			class File : protected Scopes::Scope {
			public:

				/** @brief Creates an object that represents a C++ file.
				 *	@author FlowerGenius
				 *
				 *	This constructor is meant only for initializing members required by
				 *	derived classes and should never be called excepting that the object
				 *	created then be cast to a derived type.
				 *
				 */
				File() {};

				/** @brief Destroys and object that represents a C++ file.
				 *  @author FlowerGenius
				 *
				 */
				virtual ~File() {};

				/** @brief Get the location of this file on the disk
				 *  @author FlowerGenius
				 *  @return C++ string containing the path
				 */
				const std::string& getPath() const;


			protected:

				/** @brief Set the location of this on the disk
				 *  @author FlowerGenius
				 *  @param abspath The absolute path to the file on the disk
				 */
				void setPath(std::string abspath);

			private:

				/** @brief The absolute path location of this file on the disk */
				std::string path;

			}; /* Basic File */


			namespace InFiles {
			/** @brief	An abstract model of a C++ Input File (ie. [source|header])
			 *	@author	FlowerGenius
			 *
			 *	This class represents a file in the C++ build structure model. A CppFile
			 *	can be either a header or a source file. All attributes that are shared
			 *	by both headers and source files is kept here.
			 */
			class InFile : public File {
			public:
				InFile();
				virtual ~InFile();

				/** @brief Represents this file in C++ code.
				 *  @author FlowerGenius
				 *  @return Returns a C++ string representing this C++ file in C++ syntax.
				 */
				virtual std::string cpp_str() = 0;

				/** @brief Represents this file in XML code.
				 *  @author FlowerGenius
				 *  @return Returns a C++ string representing this C++ file in XML syntax.
				 */
				virtual std::string xml_str() = 0;

			protected:

			private:

				OutFiles::Artifact* artifact;
			};

			/** @brief An abstract model of a header file in C++
			 *  @author FlowerGenius
			 *
			 *  Each instance of this class models a C++ header file. A header file is
			 *  either defined inside of object for the source file that it is first
			 *  included from or has a virtual definition in the case of files outside of
			 *  the project such as those in the C++ standard library and C++STL.
			 */
			class Header : public InFile {
			public:
				static const std::map<std::string,Header>& getAllHeaders();

				/** @brief Creates an object that represents a C++ header file.
				 *  @author FlowerGenius
				 */
				Header();

				/** @brief Creates an object that represents a C++ header file.
				 *  @author FlowerGenius
				 */
				Header(std::string path, bool stdlib = false);

				/** @brief Destroys this C++ header file model.
				 *  @author FlowerGenius
				 */
				virtual ~Header();

				/** @brief Tests for whether or not this header file is part of the active
				 *  project.
				 *  @author FlowerGenius
				 *  @return
				 */
				bool isStandard() const { return standard; }

				std::string cpp_str();
				std::string xml_str();

			protected:
				std::string header_name;
				std::map<std::string,Header*> includes;
			private:
				static std::map<std::string,Header> all_headers;

				/** @brief True if this header is defined outside of the project. */
				bool standard;

			}; /* Header */

//			static Header std_stl_algorithm;
//			static Header std_bitset;
//			static Header std_complex;
//			static Header std_stl_deque;
//			static Header std_exception;
//			static Header std_fstream;
//			static Header std_stl_functional;
//			static Header std_iomanip;
//			static Header std_ios;
//			static Header std_iosfwd;
//			static Header std_iostream;
//			static Header std_istream;
//			static Header std_stl_iterator;
//			static Header std_limits;
//			static Header std_stl_list;
//			static Header std_locale;
//			static Header std_stl_map;
//			static Header std_stl_memory;
//			static Header std_new;
//			static Header std_stl_numeric;
//			static Header std_ostream;
//			static Header std_stl_queue;
//			static Header std_stl_set;
//			static Header std_sstream;
//			static Header std_stl_stack;
//			static Header std_stdexcept;
//			static Header std_streambuf;
//			static Header std_string;
//			static Header std_typeinfo;
//			static Header std_stl_utility;
//			static Header std_valarray;
//			static Header std_stl_vector;

			/** @brief An abstract model of a source file in C++
			 *  @author FlowerGenius
			 *
			 *  Each instance of this class models a C++ source file. This file can
			 *  have a physical location on the disk, or exist entirely within memory.
			 *  In either case this model can produce valid C++ code that can be
			 *  written to a file, or valid XML code to be placed inside the definition
			 *  of the object associated with this source file.
			 */
			class Source : public InFile {
			public:
				static const std::map<std::string,Source>& getAllSources();

				/** @brief Creates an object that represents a C++ source file.
				 *  @author FlowerGenius
				 */
				Source();

				/** @brief Destroys this C++ source file model.
				 *  @author FlowerGenius
				 */
				virtual ~Source();

			protected:
				std::string source_name;
				std::map<std::string,Header*> includes;
			private:
				static std::map<std::string,Source> all_sources;

			}; /* Source */

			};


			namespace OutFiles {
			/** @brief A C++ Output file
			 *
			 */
			class OutFile : public File {

			};

			/** @brief The base for all of the specializations of @c CppClass.
			 *  @author FlowerGenius
			 *
			 *  This struct provides a base object for all of the specializations of
			 *  @c CppClass. This struct is not meant to ever be used in it's own right,
			 *  rather it exists as a wrapper allowing any @c CppObject types to be
			 *  accessed, stored, and used iteratively by upcasting to this base.
			 *
			 */
			struct Object_base : public OutFile {

				/** @brief Default constructor for all specializations of @c CppObject.
				 *  @author FlowerGenius
				 *
				 *  This constructor should never be called excepting that it is called
				 *  by a derived class as part of the derivation chain.
				 *
				 */
				Object_base() {}

				/** @brief Default destructor for all specializations of @c CppObject.
				 *  @author FlowerGenius
				 *
				 *  This denstructor should never be called excepting that it is called
				 *  by a derived class as part of the derivation chain.
				 *
				 */
				virtual ~Object_base(){}

			};

			/** @brief An abstract model of a compilation object in C++.
			 *  @author FlowerGenius
			 *  @tparam _N 1. @c void for typical usage; 2. @c class that this
			 *             specialization will model.
			 *
			 *  This template class is very strange and possibly not clearly intuitive,
			 *  thus this description may be too long to read, skip down to the end for a
			 *  concise summary - FlowerGenius
			 *
			 *  Important Note: The strange nature of the class is a result of it's
			 *  intended usage, as this library is not meant for the understanding of
			 *  a human developer, rather it is meant for the understanding of the
			 *  Software Human Emulated Intelligence (on) Linux [a] a.k.a. @c SHEILa.
			 *
			 *	Introduction: For the purposes of this model, a C++ compilation object
			 *	shall be defined as the combination of a single C++ source file and a
			 *	definition of the user defined Header Files included from that source.
			 *
			 *	All header files included from those main header files shall not be
			 *	@e defined by the object, rather they shall be referenced by the object.
			 *	That is to say that when a @c CppObject is represented in XML, the XML file
			 *	contains only references to non-primary header files. Where the properties
			 *	of them can be accessed through their pointer to their respective
			 *	@c CppHeader models such that modifications to those models modify them
			 *	globally, rather than modifying a local copy of them.
			 *
			 *  An XML representation of a @c CppObject or one of it's children must be
			 *  a model of an entire valid XML file.
			 *
			 *  Typical Usage (modeling a C++ compilation object) : @c CppObject<@a void >
			 *
			 *	Adv. Usage (child models a C++ compilation object) : @c CppObject<@a _N >
			 *	where @a _N is the class that the @c CppObject is going to model.
			 *
			 *  TL;DR This class can be used as a typical class where the object that it
			 *  represents is indicated by each unique instance of the class; OR it can
			 *  be used as a template class where each unique specialization represents
			 *  a compilation object.
			 *
			 */
			template<class _N = void>
			class Object : private Object_base {
			public:

				/** @brief Creates a new abstract model of a C++ object
				 *
				 */
				Object() {

					;
				}

				/** @brief Builds a new abstract model of a C++ object from an XML file
				 *
				 */
				//CppObject(xml::XmlFile*);

				/** @brief Destroys this C++ object model.
				 *
				 */
				virtual ~Object() {
					;
				}


			#if (BUILD_FOR_SHEILA_DAEMON == 1)

			protected:

				static std::vector<std::string> this_object_names;
				static std::vector<std::string> this_object_authors;
				static std::vector<std::string> this_object_versions;
				static std::vector<std::string> this_object_copyrights;
				static std::vector<std::string> this_object_descriptions;
				static std::vector<std::string> this_object_modules;
				static std::string              this_object_created;
				static std::vector<std::string> this_object_modified;


				static std::vector<Files::InFiles::Header*> this_object_headers;
				static Files::InFiles::Source*              this_object_source;

			#endif

			private:
				/** @brief List of names */
				std::vector<std::string> names;

				/** @brief List of authors */
				std::vector<std::string> authors;

				/** @brief List of versions */
				std::vector<std::string> versions;

				/** @brief List of copyrights */
				std::vector<std::string> copyrights;

				/** @brief List of descriptions */
				std::vector<std::string> descriptions;
				std::vector<std::string> modules;
				std::string              created;
				std::vector<std::string> modified;


				std::vector<Files::InFiles::Header*> object_headers;
				Files::InFiles::Source*              object_source;
				static std::map<std::string,Object> all_objects;

			}; /* Object */


			/** @brief Forward declaration of Executable */
			struct Executable;

			/** @brief Forward declaration of SharedLibrary */
			struct SharedLibrary;

			/** @brief Forward declaration of StaticLibrary */
			struct StaticLibrary;

			/** @brief Abstract model of a C++ compilation artifact.
			 *  @author FlowerGenius
			 *
			 *  This class represents a C++ artifact. An artifact can be a:
			 *
			 *  @arg @c Executable A binary that is meant to be run on it's target platform.
			 *  @arg @c StaticLibrary An archive that that defines features to be included
			 *                         in some other program or library.
			 *  @arg @c SharedLibrary A binary that contains features to be referenced in
			 *                         some other program or library.
			 *
			 *  No other types of artifacts are supported by the C++ language. For detailed
			 *  descriptions of each type of artifact, see the definition for the
			 *  respective subclasses.
			 *
			 *  All types of artifact are comprised of linked @c CppObject elements and
			 *  other @c CppArtifact elements given that they are library types. This is
			 *  modeled by having each artifact instance contain a vector of pointers to
			 *  the objects and libraries to be linked.
			 *
			 */
			class Artifact : public OutFile {
			public:
				static const std::map<std::string,Artifact>& getAllArtifacts();

				Artifact();
				virtual ~Artifact();

//				void addMacro(Cpp::PreProcessor::Macro *m) {
//					global_scope.insert({m->getIdentifier(),m});
//				}

				/** @brief Get all of the C++ features contained by this scope
				 *
				 */
				const std::map<std::string,Feature*>& scopeFeatures() const;

				/** @brief Get all of the C++ features accessible through this scope
				 *
				 */
				std::map<std::string,Feature*> accessibleFeatures();

			protected:
				std::string                         artifact_name;
				std::map<std::string,Object_base*>  linked_objects;
				std::map<std::string,SharedLibrary> linked_shared_libs;
				std::map<std::string,StaticLibrary> linked_static_libs;
			private:
				std::map<std::string,Feature*>       global_scope;
				static std::map<std::string,Artifact> all_artifacts;

			}; /* Artifact */

			struct Executable : public Artifact {

			}; /* Executable */

			struct SharedLibrary : public Artifact {

			}; /* Shared Library */

			struct StaticLibrary : public Artifact {

			}; /* Static Library */



			};
		};
	};


	/** @brief A C++ project
	 *
	 */
	struct Project {

		/** @brief Get the map containing all projects.
		 *
		 * @return
		 */
		static const std::map<std::string,Project>& getAllProjects();

		/**
		 *
		 * @param name
		 */
		Project(std::string name = "untitled");

		/**
		 *
		 */
		virtual ~Project();

	protected:
		std::map<std::string,Structure::Files::OutFiles::Artifact> artifacts;
		std::string                    project_name;
	private:
		static std::map<std::string,Project> all_projects;
	}; /* Project */

};
//
///** @brief C++ Preprocessor directive specialization for a define directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type DEFINE that represents an abstract
// *  model of a C++ preprocessor define directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::DEFINE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//
//	/** @brief	Creates a model of a C++ define directive and a macro object.
//	 *	@author	FlowerGenius
//	 *	@param	feat		Pointer to the C++ feature that comes immediately
//	 *	before this directive in the source code.
//	 *	@param	id			String that is a (typically) valid macro identifier.
//	 *	@param	statement	String that is a (typically) valid macro expression.
//	 *	@param	args		Vector of 0 or more strings for the macro arguments.
//	 *
//	 *	This constructor generates an abstract model of a C++ define
//	 *	directive. It also creates a new macro object representing the
//	 *	macro that has been defined by the directive.
//	 *
//	 */
//	Directive(Cpp::Project::Artifact* artifact, std::string id, Cpp::Feature *feat = nullptr,
//			std::string statement = "",
//			std::vector<std::string> args = {}) {
//		before = feat;
//
//		try {
//			macro = new Cpp::PreProcessor::Macro((void*)artifact,id,statement,args);
//		}
//		catch (std::bad_alloc &exception) {
//
//		}
//
//	}
//
//	virtual ~Directive();
//
//	std::string cpp_str() {
//		std::string s = "#"+T(Cpp::PreProcessor::DirectiveType::DEFINE)+macro->getIdentifier();
//		if (macro->getArguments().size() > 0) {
//			s.append("(");
//			for (auto const& value: macro->getArguments()) {
//				s.append(value + ",");
//			}
//			s.replace(s.rfind(','),1,1,')');
//		}
//
//		s.append(" " + macro->getStatement());
//		return s;
//	};
//
//	std::string xml_str() {
//		std::string s;
//		if (macro->getArguments().size() > 0) {
//			s.append("[");
//			for (auto const& value: macro->getArguments()) {
//				s.append(value + ",");
//			}
//			s.replace(s.rfind(','),1,1,']');
//		}
//
//		return "<"+T(Cpp::PreProcessor::DirectiveType::DEFINE)
//				+" id="+macro->getIdentifier()
//				+" arguments="+s
//				+" statement="+macro->getStatement()+" />";
//	}
//
//private:
//	Cpp::PreProcessor::Macro	*macro;	/** Pointer to the macro that this object defines */
//};
//
///** @brief C++ Preprocessor directive specialization for an undef directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type UNDEF that represents an abstract
// *  model of a C++ preprocessor undef directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::UNDEF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//
//	/** @brief Creates a model of a C++ undef directive and marks a macro
//	 * 	as undefined (destroying it's contents).
//	 *  @author FlowerGenius
//	 *  @param	macro	Reference to the macro object to undefine.
//	 *
//	 */
//	Directive(Macro &macro) {
//		this->macro = &macro;
//		this->macro->undefine();
//	}
//
//	/** @brief Creates a model of a C++ undef directive and marks a macro
//	 * 	as undefined (destroying it's contents).
//	 *  @author FlowerGenius
//	 *  @param	macro	Pointer to the macro object to undefine.
//	 *
//	 */
//	Directive(Macro *macro) {
//		this->macro = macro;
//		this->macro->undefine();
//	}
//
//	virtual ~Directive();
//private:
//	Macro	*macro;	/** Pointer to the macro that this object undefines */
//};
//
///** @brief C++ Preprocessor directive specialization for an ifdef directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type IFDEF that represents an abstract
// *  model of a C++ preprocessor ifdef directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IFDEF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//
//	/** @brief Creates a model of a C++ ifdef directive
//	 *  @author FlowerGenius
//	 *  @param	macro	Reference to the macro being tested for existence.
//	 *
//	 */
//	Directive(Macro &macro) {
//		this->macro = &macro;
//	}
//
//	/** @brief Creates a model of a C++ ifdef directive
//	 *  @author FlowerGenius
//	 *  @param	macro	Pointer to the macro being tested for existence.
//	 *
//	 */
//	Directive(Macro *macro) {
//		this->macro = macro;
//	}
//
//	virtual ~Directive();
//private:
//	Macro    *macro;
//};
//
///** @brief C++ Preprocessor directive specialization for an ifndef directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type IFNDEF that represents an abstract
// *  model of a C++ preprocessor ifndef directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IFNDEF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//	Macro    *macro;
//};
//
///** @brief C++ Preprocessor directive specialization for an else directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type ELSE that represents an abstract
// *  model of a C++ preprocessor else directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ELSE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//
//};
//
///** @brief C++ Preprocessor directive specialization for an endif directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type ENDIF that represents an abstract
// *  model of a C++ preprocessor endif directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ENDIF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//
//};
//
///** @brief C++ Preprocessor directive specialization for an if directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type IF that represents an abstract
// *  model of a C++ preprocessor if directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//
//};
//
///** @brief C++ Preprocessor directive specialization for an include directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type INCLUDE that represents an abstract
// *  model of a C++ preprocessor include directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::INCLUDE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive() {
//		file_ptr = nullptr;
//		standard = false;
//	}
//
//	Directive(Cpp::Project::File::Header *header_ptr) {
//		file_ptr = header_ptr;
//		if (file_ptr->isStandard()){
//			standard = true;
//		} else {
//			standard = false;
//		}
//	}
//
//	Directive(Cpp::Project::File::Header &header) {
//		file_ptr = &header;
//		if (file_ptr->isStandard()){
//			standard = true;
//		} else {
//			standard = false;
//		}
//	}
//
//	virtual ~Directive();
//
//	std::string cpp_str() {
//
//		if (file_ptr == nullptr) { return ""; }
//
//		std::string ret;
//		const char enclosers[] = {'<','>','\"'};
//
//		if (standard) {
//
//		}
//
//		return ret;
//	}
//
//	std::string xml_str() {
//		;
//	}
//
//private:
//	bool        standard;
//	Cpp::Project::File::Header   *file_ptr;
//};
//
///** @brief C++ Preprocessor directive specialization for an elif directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type ELIF that represents an abstract
// *  model of a C++ preprocessor elif directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ELIF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//
//};
//
///** @brief C++ Preprocessor directive specialization for an error directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type ERROR that represents an abstract
// *  model of a C++ preprocessor error directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ERROR> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//	std::string error_message;
//};
//
///** @brief C++ Preprocessor directive specialization for an line directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type LINE that represents an abstract
// *  model of a C++ preprocessor line directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::LINE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//	int line_number;
//	std::string new_filename;
//};
//
///** @brief C++ Preprocessor directive specialization for an pragma directive.
// *  @author FlowerGenius
// *
// *  An explicit specialization of the type PRAGMA that represents an abstract
// *  model of a C++ preprocessor pragma directive.
// */
//template<>
//class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::PRAGMA> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
//public:
//	Directive();
//	virtual ~Directive();
//private:
//	std::vector<std::string> parameters;
//};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPP_H_ */
