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
#include <map>
#include <ctime>
#include <iostream>
#include <sstream>


#include "../C/language.inc"
#include "../../symbols.inc"


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

typedef enum AccessLevels {
	PRIVATE,
	PROTECTED,
	PUBLIC
} AccessLevel;

typedef enum StorageClasses {
	STATIC,
	EXTERN,
	MUTABLE,
	AUTO,
	REGISTER
} StorageClass;

typedef enum FundamentalTypes {
	VOID = -1,
	BOOL,
	CHAR,
	WCHAR,
	SHORT,
	INT,
	LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE
} FundamentalType;

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
class Cpp {
public:

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


	struct Types {

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
		public:

			Type();
			virtual ~Type();

			const std::string& get() const { return type_name; }

		protected:
			std::string type_name;

		};

		const static Type Typename;

		/** @brief A Scalar Type of C++.
		 *
		 */
		class ScalarType : public Type {

		};

		/** The Fundamental Types of C++ */
		struct FundamentalTypes {

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

			public:
				FundamentalType();
				virtual ~FundamentalType();

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
			const static FundamentalType Void;

			/** The Arithmetic Types of C++ */
			struct ArithmeticTypes {

				/** @brief An ArithmeticType of the C++ ProgrammingLanguage.
				 *
				 *  [O'Reilly] The ArithmeticTypes of C++ is the collection of
				 *  IntegralType and FloatingPointType types.
				 *
				 */
				class ArithmeticType : public FundamentalType, public ScalarType {

				public:
					ArithmeticType();
					virtual ~ArithmeticType();

				};

				/** The Integral Types of C++ */
				struct IntegralTypes {

					/** @brief An IntegralType of the C++ ProgrammingLanguage.
					 *
					 */
					class IntegralType : public ArithmeticType {
					public:

						IntegralType();
						virtual ~IntegralType();

					protected:

						/** @brief Evaluates to true if signed */
						bool _signed_;

					};

					/** @brief The bool type in C++
					 *
					 *  [O'Reilly] Booleans are of type bool. The bool type is
					 *  used for values of truth.
					 *
					 */
					const static IntegralType Boolean;

					/** The Character Types of C++ */
					struct CharacterTypes {

						/** @brief Characters are of CharType or WideCharType.
						 *
						 *  [O'Reilly] Characters are of type char or wchar_t.
						 *  Character types may be specified as either signed
						 *  or unsigned and are sometiems used simply to store
						 *  small integers.
						 *
						 */
						class CharacterType : public IntegralType {
						public:

							CharacterType();
							virtual ~CharacterType();

						};

						/** @brief The char type is a small integer.
						 *
						 *  [O'Reilly] The char type is used for integers that
						 *  refer to characters in a character set (ex: ASCII).
						 *
						 */
						const static CharacterType Char;

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
					};

					/** The Integer Types of C++ */
					struct IntegerTypes {

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
						public:

							IntegerType();
							virtual ~IntegerType();

						};

						/** @brief A short (half byte) integer */
						const static IntegerType ShortInteger;

						/** @brief A simple (full byte) integer */
						const static IntegerType BasicInteger;

						/** @brief A long (4x byte) integer */
						const static IntegerType LongInteger;

						/** @brief A long long (8x byte) integer */
						const static IntegerType LongLongInteger;
					};
				};

				/** The Floating Point Types of C++ */
				struct FloatingPointTypes {


					/** @brief Floating point type in C++
					 *
					 *  [O'Reilly] Floating points are of type float, double
					 *  long double, or long long double. These types differ
					 *  in size and in the range and precision of values they
					 *  can represent.
					 *
					 */
					class FloatingPointType : public ArithmeticType {

					public:
						FloatingPointType();
						virtual ~FloatingPointType();

					};

					/** @brief A single precision floating point value */
					const static FloatingPointType Float;

					/** @brief A double precision floating point value */
					const static FloatingPointType Double;

					/** @brief A long (x4) double precision floating point
					 * value
					 */
					const static FloatingPointType LongDouble;

					/** @brief A long long (x8) double precision floating
					 * point value
					 */
					const static FloatingPointType LongLongDouble;
				};
			};
		};

		/** The Compound Types of C++ */
		struct CompoundTypes {

			/** @brief A complex type built on the Arithmetic Types.
			 *
			 *  [O'Reilly] The compound types of C++ are:
			 *
			 */
			class CompoundType : public Type {
			public:

				CompoundType();
				virtual ~CompoundType();

			protected:

				Type contents_type;

			};

			/** @brief An enumeration type in C++.
			 *
			 *  [O'Reilly] An enumeration, specified by the keyword enum, is
			 *  a set of integer constants associated with identifiers, called
			 *  enumerators, that you define. In general enumerations provide
			 *  a way to use meaningful names where you might otherwise use
			 *  integer constants, prehaps defined using the preprocessor
			 *  directive #define. Enumerations are preferred over the
			 *  preprocessor for this in C++ because they obey the language's
			 *  rules of scope.
			 */
			const static CompoundType EnumerationType;

			/** @brief An array type in C++.
			 *
			 *  [O'Reilly] Arrays contain a specific number of elements of
			 *  a particular type. So that when the compiler can reserve the
			 *  requested amount of spce when the program is compiles, you
			 *  must specify the type and number of elements that the array
			 *  will contain when it is defined. The compiler must be able
			 *  to determing this value when the program is compiled.
			 */
			const static CompoundType ArrayType;

			/** The String Types of C++ */
			struct StringTypes {

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
					StringType();
					virtual ~StringType();

				};

				/** @brief C-style string of char */
				const static StringType CharString;

				/** @brief C-style string wchar_t */
				const static StringType WideCharString;

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
			const static CompoundType PointerType;

			/** @brief [O'Reilly] Alternative name for a class member.
			 *
			 *  [O'Reilly] Pointers to members are like alternative names for
			 *  class members.
			 *
			 */
			const static CompoundType PointerToMemberType;

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
			const static CompoundType ReferenceType;

			/** The Class Types of C++ */
			struct ClassTypes {

				/** @brief A ClassType of C++.
				 *
				 *  The Class types of C++ are Unions, Structs, and Classes
				 *
				 */
				class ClassType : public CompoundType {

				};

				const static ClassType CppUnion;

				const static ClassType CppClass;

				const static ClassType CppStruct;

//				const static ClassType ScopedEnumerationType;

			};

			const static CompoundType FunctionType;

		};

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
	};

	/* The Lexical Elements of C++ */
	struct LexicalElements {

		class LexicalElement {

		};

		class Comment : public LexicalElement {

		};

		class Identifier : public LexicalElement {
		public:

			Identifier(std::string unformatted_string);
			virtual ~Identifier();

			void declare(Types::Type t, void* data=nullptr);

			const Types::Type* getType() const { return t; }

			const std::string& getName() const { return name; }

		private:

			std::string name;
			Types::Type *t;

		};

		/** The Reserved Words of C++ */
		struct ReservedWords {

			/** @brief The reserved keywords and tokens of C__
			 *
			 */
			class ReservedWord : public LexicalElement {

			};

			static const ReservedWord R_and;
			static const ReservedWord R_and_eq;
			static const ReservedWord R_asm;
			static const ReservedWord R_auto;
			static const ReservedWord R_bitand;
			static const ReservedWord R_bitor;
			static const ReservedWord R_bool;
			static const ReservedWord R_break;
			static const ReservedWord R_case;
			static const ReservedWord R_catch;
			static const ReservedWord R_char;
			static const ReservedWord R_class;
			static const ReservedWord R_compl;
			static const ReservedWord R_const;
			static const ReservedWord R_const_cast;
			static const ReservedWord R_continue;
			static const ReservedWord R_default;
			static const ReservedWord R_delete;
			static const ReservedWord R_do;
			static const ReservedWord R_double;
			static const ReservedWord R_dynamic_cast;
			static const ReservedWord R_else;
			static const ReservedWord R_enum;
			static const ReservedWord R_explicit;
			static const ReservedWord R_export;
			static const ReservedWord R_extern;
			static const ReservedWord R_false;
			static const ReservedWord R_float;
			static const ReservedWord R_for;
			static const ReservedWord R_friend;
			static const ReservedWord R_goto;
			static const ReservedWord R_if;
			static const ReservedWord R_inline;
			static const ReservedWord R_int;
			static const ReservedWord R_long;
			static const ReservedWord R_mutable;
			static const ReservedWord R_namespace;
			static const ReservedWord R_new;
			static const ReservedWord R_not;
			static const ReservedWord R_not_eq;
			static const ReservedWord R_operator;
			static const ReservedWord R_or;
			static const ReservedWord R_or_eq;
			static const ReservedWord R_private;
			static const ReservedWord R_protected;
			static const ReservedWord R_public;
			static const ReservedWord R_register;
			static const ReservedWord R_reinterpret_cast;
			static const ReservedWord R_return;
			static const ReservedWord R_short;
			static const ReservedWord R_signed;
			static const ReservedWord R_sizeof;
			static const ReservedWord R_static;
			static const ReservedWord R_static_cast;
			static const ReservedWord R_struct;
			static const ReservedWord R_switch;
			static const ReservedWord R_template;
			static const ReservedWord R_this;
			static const ReservedWord R_throw;
			static const ReservedWord R_true;
			static const ReservedWord R_try;
			static const ReservedWord R_typedef;
			static const ReservedWord R_typeid;
			static const ReservedWord R_typename;
			static const ReservedWord R_union;
			static const ReservedWord R_unsigned;
			static const ReservedWord R_using;
			static const ReservedWord R_virtual;
			static const ReservedWord R_void;
			static const ReservedWord R_volatile;
			static const ReservedWord R_wchar_t;
			static const ReservedWord R_while;
			static const ReservedWord R_xor;
			static const ReservedWord R_xor_eq;
		};


		class Expression : public LexicalElement {

		};

		struct Literals {

			class Literal : public Expression {

			};

		};

		struct Operators {

			class Operator : public LexicalElement {

			};

		};

	};

	struct Scopes {

		class Scope {

		};

	};


	/** A C++ Token
	 *
	 */
	class Token {
	public:


		/** @brief Initializes the @a activated data member by default
		 *  @author FlowerGenius
		 *
		 *  Important Note: This constructor is part of a pure virtual abstract
		 *  base class and as such should never be called excepting that a derived
		 *  class calls it as part of the derivation chain.
		 *
		 */
		Token() : identifier(""), activated(true) {}

		/** @brief Destroys this CppFeature object
		 *  @author FlowerGenius
		 *
		 *  Important Note: This destructor is part of a pure virtual abstract
		 *  base class and as such should never be called excepting that a derived
		 *  class calls it as part of the derivation chain.
		 *
		 */
		virtual ~Token(){}

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

		Scopes::Scope cpp_scope;

		/** The ID of this Feature */
		LexicalElements::Identifier identifier;

		/** @brief Represents the commented/uncommented state of the feature */
		bool activated;
	};

	class VariableDefinition;

	/** @brief A C++ variable.
	 *
	 */
	class Variable : public Token {
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

		/** Creates a representation of a C++ Variable
		 *
		 * @param var The declaration where this variable lives.
		 * @param id  The identifier of this Variable.
		 */
		Variable(LexicalElements::Identifier id);
		virtual ~Variable();

		/**
		 *
		 * @return
		 */
		const Types::Type getType() const { return definition->getType(); }

		/** @brief Get the value of this variable
		 *
		 *  @return A reference to @a value.
		 */
		const auto& getValue() const {
			return value;
		}

		std::string cpp_str();

		std::string xml_str();

	protected:

		/** Pointer to the value of this variable */
		void *value;

		/** The value contained by this variable */
		VariableDefinition *definition;

	};


#define LANG_CPP_CLASS_VARIABLE


	/** @brief A C++ Function.
	 *
	 */
	class Function : public Token {
	public:
		Function();
		virtual ~Function();

		std::string cpp_str();

		std::string xml_str();


	}; /* Function */


#define LANG_CPP_CLASS_FUNCTION

	struct Statements {

		class Statement {

		};

		class ExpressionStatement {

		};

		struct Declarations {

			class Declaration : public Statement {

			};

			class VariableDeclaration : public Declaration {

			};

			class FunctionDeclaration : public Declaration {

			};

			struct Definitions {

				class Definition : public Declaration {

				};

				class VariableDefinition : public VariableDeclaration {

				};

				class FunctionDefinition : public FunctionDeclaration {

				};

			};

		};

	};


#define LANG_CPP_CLASS_TYPE_DECLARATION



#define LANG_CPP_CLASS_EXPRESSION

#define ENUM_INT_SIZE int

	class Instance;
	class Namespace;
	class Enumeration;

	class EnumeratorDefinition;

	/** @brief A name that represents a constant ingeger defined in an Enum.
	 *
	 */
	class Enumerator : public Variable {
	/* Usage:
	 *
	 *     !{{identifier}}
	 *
	 * XML:
	 *
	 *     <enumerator id="!{{identifier}}" />
	 *
	 */
	public:
		Enumerator(EnumeratorDefinition* enumeration=nullptr,
				std::string id="",ENUM_INT_SIZE val=0);
		virtual ~Enumerator();

		/** @brief Represents this file in C++ code.
		 *  @author FlowerGenius
		 *  @return Returns a C++ string representing this C++ file in C++ syntax.
		 */
		std::string cpp_str();

		/** @brief Represents this file in XML code.
		 *  @author FlowerGenius
		 *  @return Returns a C++ string representing this C++ file in XML syntax.
		 */
		std::string xml_str();

	private:

		/** A pointer to the Enumeration that owns this Enumerator */
		EnumeratorDefinition* enumerator_def;

	};

	class EnumerationDefinition;


	/** @brief A definition of an Enumerator.
	 *  @author FlowerGenius
	 *
	 *  IMPORTANT: This definition can only occur within the context of an
	 *  Enumeration.
	 *
	 */
	class EnumeratorDefinition : public Feature {
	/* Usage:
	 * enum ??? {
	 *     !{{identifier}} #{ = {value}}
	 * };
	 * XML:
	 *
	 *     <enumerator id="!{identifier}" [value="{value}"] [type="{*(enumerator->enum_ptr)}"] " />
	 *
	 */
	public:

		/** @brief Creates an EnumeratorDefinition with the default next value.
		 *
		 *  @param enumdef_ptr Pointer to the Enum this Enumerator is defined in
		 *  @param id Identifier of this Enumerator
		 */
		EnumeratorDefinition(EnumerationDefinition* enum_ptr, std::string id);

		/** @brief Creates an instantiated EnumeratorDefinition.
		 *
		 *  @param enumdef_ptr Pointer to the Enum this Enumerator is defined in
		 *  @param id Identifier of this Enumerator
		 *  @param n const int value this Enumerator represents.
		 */
		EnumeratorDefinition(EnumerationDefinition* enum_ptr,
				std::string id,ENUM_INT_SIZE n);

		/** @brief Destroys this EnumeratorDefinition.
		 *
		 */
		virtual ~EnumeratorDefinition();


		/** @brief Represents this file in C++ code.
		 *  @author FlowerGenius
		 *  @return Returns a C++ string representing this C++ file in C++ syntax.
		 */
		std::string cpp_str();

		/** @brief Represents this file in XML code.
		 *  @author FlowerGenius
		 *  @return Returns a C++ string representing this C++ file in XML syntax.
		 */
		std::string xml_str();


	private:

		bool explicit_enumerator;

		Enumerator             data;
		EnumerationDefinition  *enumeration_def;

	};

//	/** @brief A declaration of an Enumerator.
//	 *  @author FlowerGenius
//	 *
//	 */
//	class EnumeratorDeclaration : public Feature {
//
//	};


#define LANG_CPP_CLASS_ENUMERATOR

	/** @brief A C++ Enum
	 *
	 */
	class Enumeration : public Type {
	public:
		Enumeration();
		virtual ~Enumeration();

		const bool& isAnonymous() const { return anonymous; }

		/** @brief Represents this file in C++ code.
		 *  @author FlowerGenius
		 *  @return Returns a C++ string representing this C++ file in C++ syntax.
		 */
		std::string cpp_str();

		/** @brief Represents this file in XML code.
		 *  @author FlowerGenius
		 *  @return Returns a C++ string representing this C++ file in XML syntax.
		 */
		std::string xml_str();

		/** @brief The variables of this enum
		 *
		 * @return
		 */


	private:

		bool anonymous;

		/** @brief The list of enumerators that this Enumeration defines.
		 *
		 */
		std::vector<Enumerator*> enumerators;

	};

	/** @brief A definition of a C++ enum
	 *
	 */
	class EnumerationDefinition : public Feature {
	/* Usage:
	 *
	 *  enum #{enumeration->identifer} {
	 *     #{enumeration->enumers[0]},
	 *     .
	 *     .
	 *     .
	 *     #{enumeration->enumers[n]}
	 * } #{this->type_name};
	 *
	 * XML:
	 *
	 * <enum [id="{enumeration->identifier}"] [objects="{this->objects}"]>
	 *     ?
	 *     ?
	 *     ?
	 * </enum>
	 *
	 */
	public:

		EnumerationDefinition(bool anonymous=true, std::string identifer="");


		virtual ~EnumerationDefinition();

		/** @brief Get the default value of the next
		 *
		 *  @return The default value for a proposed next Enumerator
		 */
		ENUM_INT_SIZE next();

		void addEnumerator(std::string id);

		void addEnumerator(std::string id, ENUM_INT_SIZE n);

		const std::vector<EnumeratorDefinition>& getEnumeratorDefinitions() const
				{ return enumerator_definitions; }

		const Enumeration& getData() const { return data; }

		std::string cpp_str();

		std::string xml_str();

	private:

		/** The list of the EnumeratorDefinitions that this Enumeration defines */
		std::vector<EnumeratorDefinition> enumerator_definitions;

		/** The Enumeration that this class will define */
		Enumeration data;

	};

	/** @brief A forward declaration of an enum
	 *
	 */
	class EnumerationDeclaration : public Feature {

	};

#define LANG_CPP_CLASS_ENUMERATION


	/** @brief Scope wrapper for C++ Class Types
	 *
	 */
	struct Classes {

		/** @brief A Basic class definition in C++
		 *
		 *  A basic class simply contains data members and controls
		 *  access to them through scope.
		 *
		 */
		class BasicClass : public Type {
		public:
			BasicClass();
			virtual ~BasicClass();

			/** @brief A C++ Data Member
			 *
			 */
			template<typename type>
			class DataMember : public Variable<type> {
			public:
				/** @brief Represents this DataMember in C++ code.
				 *  @author FlowerGenius
				 *  @return Returns a C++ string representing this C++ DataMember in C++ syntax.
				 */
				std::string cpp_str();

				/** @brief Represents this DataMemebr in C++ code.
				 *  @author FlowerGenius
				 *  @return Returns a C++ string representing this C++ DataMember in XML syntax.
				 */
				std::string xml_str();


			};

			/** @brief Variable definitions */
			std::vector<BasicClass::DataMember>  contained_members;

		}; /* BasicClass */

		/** @brief A definition of a basic C++ class
		 *
		 */
		class BasicClassDefinition : public Feature {

			/** @brief Represents this BasicClass in C++ code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this BasicClass in C++ syntax.
			 */
			std::string cpp_str();

			/** @brief Represents this BasicClass in XML code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ BasicClass in XML syntax.
			 */
			std::string xml_str();

		private:

			/** @brief Declarations of variables that are not also definitions */
			std::vector<Declaration<BasicClass::DataMember> > contained_declared_members;

		};

		/** @brief A forward declaration of a basic C++ class
		 *
		 */
		class BasicClassDeclaration : public Feature {

		};

		/** @brief A C++11 Scoped Enum [either class or struct]
		 *
		 */
		class ScopedEnumeration : public virtual  Enumeration, public virtual BasicClass {
		public:
			ScopedEnumeration();
			virtual ~ScopedEnumeration();

			/** @brief Represents this ScopedEnumeration in C++ code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ ScopedEnumeration in C++ syntax.
			 */
			std::string cpp_str();

			/** @brief Represents this ScopedEnumeration in XML code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ ScopedEnumeration in XML syntax.
			 */
			std::string xml_str();


		}; /* ScopedEnumeration */

		/** A definition of a C++ ScopedEnumeration
		 *
		 */
		class ScopedEnumerationDefinition : public virtual EnumerationDefinition, public virtual BasicClassDefinition {

		};

		/** A forward declaration of a C++ ScopednEnumeration
		 *
		 */
		class ScopedEnumerationDeclaration : public virtual EnumerationDeclaration, public virtual BasicClassDeclaration {

		};

		/** @brief A Generic Class with the same rules as a namespace.
		 *
		 *  A generic class contains data members as well as member functions,
		 *  and can inherit from other classes.
		 */
		class GenericClass	: public BasicClass {
		public:
			GenericClass();
			virtual ~GenericClass();

			std::string cpp_str();

			std::string xml_str();


			/** @brief A representation of a C++ class constructor
			 *  @author FlowerGenius
			 *
			 *  A Constructor is a special function called whenever an
			 *  instance of the class is created.
			 *
			 */
			class Constructor : public Function {

			};

			/** @brief A definition of a Constructor.
			 *
			 */
			class ConstructorDefinition : public FunctionDefinition {

			};

			/** @brief A prototype of a Constructor
			 *
			 */
			class ConstructorDeclaration : public FunctionDeclaration {

			};

			/** @brief A representation of a C++ class destructor
			 *  @author FlowerGenius
			 *
			 *  A Destructor is a special function called whenever an
			 *  instance of the class is destroyed.
			 *
			 */
			class Destructor : public Function {

			};

			/** @brief A definition of a Destructor.
			 *
			 */
			class DestructorDefinition : public FunctionDefinition {

			};

			/** @brief A prototype of a Destructor
			 *
			 */
			class DestructorDeclaration : public FunctionDeclaration {

			};


			/** @brief A C++ Member Function
			 *
			 */
			class MemberFunction : public Function {

			};


			/** @brief A definition of a MemberFunction.
			 *
			 */
			class MemberFunctionDefinition : public FunctionDefinition {

			};

			/** @brief A prototype of a MemberFunctionr
			 *
			 */
			class MemberFunctionDeclaration : public FunctionDeclaration {

			};

		private:

			/** @brief List of function definitions */
			std::vector<MemberFunction> contained_member_functions;

			/** @brief Declarations of prototype functions */
			std::vector<Declaration<MemberFunction> > contained_member_prototypes;

		}; /* Generic Class */

		/** @brief A generic Class definition
		 *
		 */
		class GenericClassDefinition : public BasicClassDefinition {

		};

		/** @brief a generic class forward declaration
		 *
		 */
		class GenericClassDeclaration : public BasicClassDeclaration {

		};


		/** @brief A C++ union.
		 *
		 */
		class Union  : public GenericClass {
		public:
			Union();
			virtual ~Union();

			/** @brief Represents this Union in C++ code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ Union in C++ syntax.
			 */
			 std::string cpp_str();

			/** @brief Represents this Union in XML code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ Union in XML syntax.
			 */
			 std::string xml_str();


		};

		/** @brief A definition of a Union
		 *
		 */
		class UnionDefinition : public GenericClassDefinition {

		};

		/** @brief A forward declaration of a Union
		 *
		 */
		class UnionDeclaration : public GenericClassDeclaration {

		};

		class Struct;

		/** @brief A C++ class.
		 *
		 */
		class Class : public GenericClass {
		public:
			Class();
			virtual ~Class();

			/** @brief Represents this Class in C++ code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ Class in C++ syntax.
			 */
			std::string cpp_str();

			/** @brief Represents this Class in XML code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ Class in XML syntax.
			 */
			std::string xml_str();

		};

		/** @brief A definition of a Class
		 *
		 */
		class ClassDefinition : public GenericClassDefinition {
		public:
			/** @brief Represents this Class in C++ code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ Class in C++ syntax.
			 */
			std::string cpp_str();

			/** @brief Represents this Class in XML code.
			 *  @author FlowerGenius
			 *  @return Returns a C++ string representing this C++ Class in XML syntax.
			 */
			std::string xml_str();

		protected:
			/** @brief List of class definitions */
			std::vector<Class>       contained_classes;

			/** @brief List of struct definitions */
			std::vector<Struct>		 contained_structs;

			/** @brief List of union definitions */
			std::vector<Union>		 contained_unions;

			/** @brief Object definitions */
			std::vector<Instance>  contained_objects;

			/** @brief List of enum defintiions */
			std::vector<Enumeration>  contained_enums;

			/** @brief List of type definitions */
			std::vector<TypeDefinition> contained_typedefs;

			/** @brief List of namespace definitions */
			std::vector<Namespace>    contained_namespaces;

			/** @brief Forward declarations of classes, unions, and structs */
			std::vector<Declaration<Classes::BasicClass> > contained_forward_declarations;
		};

		/** @brief A forward declaration of a Class
		 *
		 */
		class ClassDeclaration : public GenericClassDeclaration {

		};

		/** @brief A C++ struct.
		 *
		 */
		class Struct : public Class {
		public:
			std::string cpp_str();

			std::string xml_str();

		};

		/** @brief A definition of a Struct
		 *
		 */
		class StructDefinition : public ClassDefinition {

		};

		/** @brief A forward declaration of a Struct
		 *
		 */
		class StructDeclaration : public ClassDeclaration {

		};



	};

	/** @brief An Instance of a C++ class.
	 *
	 */
	class Instance : public Token {
	public:
		std::string cpp_str();

		std::string xml_str();

	};

	/** @brief A definition of an Instance
	 *
	 */
	class InstanceDefinition : public Feature {

	};

	/** @brief A declaration of an Instance
	 *
	 */
	class InstanceDeclaration : public Feature {

	};


	/** @brief C++ namespace
	 *
	 */
	class Namespace : public Token {
	public:
		Namespace();
		virtual ~Namespace();

		std::string cpp_str();

		std::string xml_str();

	};

	/** @brief A definition of a namespace.
	 *
	 */
	class NamespaceDefinition : public Feature {

	private:

		/** @brief Variable definitions */
		std::vector<Variable> 	 contained_variables;

		/** @brief List of function definitions */
		std::vector<Function> 	 contained_functions;

		/** @brief List of class definitions */
		std::vector<Classes::Class>       contained_classes;

		/** @brief List of struct definitions */
		std::vector<Classes::Struct>		 contained_structs;

		/** @brief List of union definitions */
		std::vector<Classes::Union>		 contained_unions;

		/** @brief Object definitions */
		std::vector<Instance>  contained_objects;

		/** @brief List of enum defintiions */
		std::vector<Enumeration>  contained_enums;

		/** @brief List of type definitions */
		std::vector<TypeDefinition> contained_typedefs;

		/** @brief List of namespace definitions */
		std::vector<Namespace>    contained_namespaces;



		/** @brief Declarations of variables that are not also definitions */
		std::vector<Declaration<Variable> > contained_declared_variables;

		/** @brief Declarations of prototype functions */
		std::vector<Declaration<Function> > contained_prototypes;

		/** @brief Forward declarations of classes, unions, and structs */
		std::vector<Declaration<Classes::BasicClass> > contained_forward_declarations;

	};

	/** @brief A declaration of a namespace, ie a @c using statement.
	 *
	 */
	class NamespaceDeclaration : public Feature {

	};

	struct Structure {

		/** @brief the C++ preprocessor
		 *
		 */
		struct PreProcessor {

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

			PreProcessor();
			virtual ~PreProcessor();

			/** @brief A C++ preprocessor Macro
			 *
			 */
			class Macro : public Token {
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
				bool isDefined() { return (this->defined && this->activated); }

				/*
				 * Set the macro as defined
				 */
				int define() { defined = true; return (this->defined == true); }

				/*
				 * Set the macro as undefined
				 */
				int undefine() { defined = false; return (this->defined == false); }

				const std::string& getIdentifier() const { return identifier; }
				const std::string& getStatement() const { return statement; }
				const std::vector<std::string>& getArguments() const {return arguments; }


				std::string cpp_str();

				std::string xml_str();


			private:

				bool defined;
				std::vector<std::string> arguments;
				std::string statement;
			};

			struct Directives {

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
		struct Files {

			/** @brief A basic file on the filesystem
			 *
			 */
			class File {
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

				/** @brief Get a list of all Classes in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the classes
				 */
				const std::vector<Classes::Class>&
				getClasses() const {
					return contained_classes;
				}

				/** @brief Get a list of all DeclaredVariables in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  declarations
				 */
				const std::vector<Declaration<Variable> >&
				getDeclaredVariables() const {
					return contained_declared_variables;
				}

				/** @brief Get a list of all Enumerations in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  enumerations
				 */
				const std::vector<Enumeration>&
				getEnums() const {
					return contained_enums;
				}

				/** @brief Get a list of all ForwardDeclarations in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  declarations
				 */
				const std::vector<Declaration<Classes::BasicClass> >&
				getForwardDeclarations() const {
					return contained_forward_declarations;
				}

				/** @brief Get a list of all Functions in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  functions
				 */
				const std::vector<Function>&
				getFunctions() const {
					return contained_functions;
				}

				/** @brief Get a list of all Namespaces in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  namespaces
				 */
				const std::vector<Namespace>&
				getNamespaces() const {
					return contained_namespaces;
				}

				/** @brief Get a list of all Instances in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  objects
				 */
				const std::vector<Instance>&
				getObjects() const {
					return contained_objects;
				}

				/** @brief Get a list of all function Prototypes in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  prototypes
				 */
				const std::vector<Declaration<Function> >&
				getPrototypes() const {
					return contained_prototypes;
				}

				/** @brief Get a list of all Structs in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  structs
				 */
				const std::vector<Classes::Struct>&
				getStructs() const {
					return contained_structs;
				}

				/** @brief Get a list of all TypeDefinitions in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  typedefs.
				 */
				const std::vector<TypeDefinition>&
				getTypedefs() const {
					return contained_typedefs;
				}

				/** @brief Get a list of all Unions in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  unions.
				 */
				const std::vector<Classes::Union>&
				getUnions() const {
					return contained_unions;
				}

				/** @brief Get a list of all Variables in this scope
				 *  @author FlowerGenius
				 *  @return A reference to the vector containing the
				 *  variables.
				 */
				const std::vector<Variable>&
				getVariables() const {
					return contained_variables;
				}


				std::map<std::string,Feature* >	scopeFeatures() {
					std::map<std::string,Feature* > features;
					for (auto&& var : getVariables()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getFunctions()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getClasses()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getStructs()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getUnions()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getObjects()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getEnums()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getTypedefs()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getNamespaces()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getDeclaredVariables()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getPrototypes()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					for (auto&& var : getForwardDeclarations()) {
						features.insert({var.getIdentifier(),(Feature*) &var});
					}
					return features;
				}

				std::map<std::string,Feature* > accessibleFeatures() {

				}

			protected:

				/** @brief Set the location of this on the disk
				 *  @author FlowerGenius
				 *  @param abspath The absolute path to the file on the disk
				 */
				void setPath(std::string abspath);

			private:

				/** @brief Variable definitions */
				std::vector<VariableDefinition> 	 contained_variables;

				/** @brief List of function definitions */
				std::vector<FunctionDefinition> 	 contained_functions;

				/** @brief List of class definitions */
				std::vector<Classes::Class>       contained_classes;

				/** @brief List of struct definitions */
				std::vector<Classes::Struct>		 contained_structs;

				/** @brief List of union definitions */
				std::vector<Classes::Union>		 contained_unions;

				/** @brief Object definitions */
				std::vector<InstanceDefinition>  contained_objects;

				/** @brief List of enum defintiions */
				std::vector<EnumerationDefinition>  contained_enums;

				/** @brief List of type definitions */
				std::vector<TypeDefinition> contained_typedefs;

				/** @brief List of namespace definitions */
				std::vector<NamespaceDefinition>    contained_namespaces;



				/** @brief Declarations of variables that are not also definitions */
				std::vector<Declaration<Variable> > contained_declared_variables;

				/** @brief Declarations of prototype functions */
				std::vector<Declaration<Function> > contained_prototypes;

				/** @brief Forward declarations of classes, unions, and structs */
				std::vector<Declaration<Classes::BasicClass> > contained_forward_declarations;


				/** @brief The absolute path location of this file on the disk */
				std::string path;

			}; /* Basic File */


			struct InFiles {
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

				/** @brief Get all of the C++ features contained by this scope
				 *
				 */
				const std::map<std::string,Feature>& scopeFeatures() const;

				/** @brief Get all of the C++ features accessible through this scope
				 *
				 */
				std::map<std::string,Feature> accessibleFeatures();

				/** @brief Retrieves the list of all PreProcessor Directives
				 *  matching type @a typ
				 *  @tparam typ The DirectiveType list to retrieve.
				 *  @return
				 *
				 */
				template<PreProcessor::DirectiveType typ>
				const std::vector<PreProcessor::Directive<typ> >&
				getDirective() const {
					switch(typ){
					case PreProcessor::DirectiveType::DEFINE:
						return pp_defines;
					case PreProcessor::DirectiveType::UNDEF:
						return pp_undefines;
					case PreProcessor::DirectiveType::IFDEF:
						return pp_ifdefines;
					case PreProcessor::DirectiveType::IFNDEF:
						return pp_ifnotdefines;
					case PreProcessor::DirectiveType::ELSE:
						return pp_elses;
					case PreProcessor::DirectiveType::ENDIF:
						return pp_endifs;
					case PreProcessor::DirectiveType::ELIF:
						return pp_elifs;
					case PreProcessor::DirectiveType::INCLUDE:
						return pp_includes;
					case PreProcessor::DirectiveType::ERROR:
						return pp_errors;
					case PreProcessor::DirectiveType::LINE:
						return pp_lines;
					case PreProcessor::DirectiveType::PRAGMA:
						return pp_pragmas;
					}
				}

			protected:

				void addDefineDirective( std::string identifier,
						Feature *after_this = nullptr, std::string value = "",
						std::vector<std::string> args = {} ) {



				}

				int addUndefDirective() {

				}

			private:

				/** @brief A list of all Macros in this file */
				std::map<std::string,PreProcessor::Macro>   pp_macros;

				/** @brief A list of all define directives in this file. */
				std::vector<PreProcessor::DefineDirective>  pp_defines;

				/** @brief A list of all undef directives in this file. */
				std::vector<PreProcessor::UndefDirective>   pp_undefines;

				/** @brief A list of all ifdef directives in this file. */
				std::vector<PreProcessor::IfdefDirective>   pp_ifdefines;

				/** @brief A list of all ifndef directives in this file. */
				std::vector<PreProcessor::IfndefDirective>  pp_ifnotdefines;

				/** @brief A list of all else directives in this file. */
				std::vector<PreProcessor::ElseDirective>    pp_elses;

				/** @brief A list of all endif directives in this file. */
				std::vector<PreProcessor::EndifDirective>   pp_endifs;

				/** @brief A list of all elif directives in this file. */
				std::vector<PreProcessor::ElifDirective>    pp_elifs;

				/** @brief A list of all include directives in this file. */
				std::vector<PreProcessor::IncludeDirective> pp_includes;

				/** @brief A list of all error directives in this file. */
				std::vector<PreProcessor::ErrorDirective>   pp_errors;

				/** @brief A list of all line directives in this file. */
				std::vector<PreProcessor::LineDirective>    pp_lines;

				/** @brief A list of all pragma directives in this file. */
				std::vector<PreProcessor::PragmaDirective>  pp_pragmas;

				std::map<std::string,Feature> file_scope;

				Artifact* artifact;
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


			struct OutFiles {
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
			struct Object_base : public File::OutFile {

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


				static std::vector<File::Header*> this_object_headers;
				static File::Source*              this_object_source;

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


				std::vector<File::Header*> object_headers;
				File::Source*              object_source;
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
			struct Artifact : public File::OutFile {

				static const std::map<std::string,Artifact>& getAllArtifacts();

				Artifact();
				virtual ~Artifact();

				void addMacro(Cpp::PreProcessor::Macro *m) {
					global_scope.insert({m->getIdentifier(),m});
				}

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


		class Artifact;



	protected:
		std::map<std::string,Artifact> artifacts;
		std::string                    project_name;
	private:
		static std::map<std::string,Project> all_projects;
	}; /* Project */

	static bool isReservedWord(std::string);
	static std::string accessLevel(AccessLevel);
	static std::string storageClass(StorageClass);
	static std::string fundamentalType(FundamentalType);

	Cpp() {};
	virtual ~Cpp() {};

private:

	static std::vector<std::string> reserved_words;

};

/** @brief C++ Preprocessor directive specialization for a define directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type DEFINE that represents an abstract
 *  model of a C++ preprocessor define directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::DEFINE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:

	/** @brief	Creates a model of a C++ define directive and a macro object.
	 *	@author	FlowerGenius
	 *	@param	feat		Pointer to the C++ feature that comes immediately
	 *	before this directive in the source code.
	 *	@param	id			String that is a (typically) valid macro identifier.
	 *	@param	statement	String that is a (typically) valid macro expression.
	 *	@param	args		Vector of 0 or more strings for the macro arguments.
	 *
	 *	This constructor generates an abstract model of a C++ define
	 *	directive. It also creates a new macro object representing the
	 *	macro that has been defined by the directive.
	 *
	 */
	Directive(Cpp::Project::Artifact* artifact, std::string id, Cpp::Feature *feat = nullptr,
			std::string statement = "",
			std::vector<std::string> args = {}) {
		before = feat;

		try {
			macro = new Cpp::PreProcessor::Macro((void*)artifact,id,statement,args);
		}
		catch (std::bad_alloc &exception) {

		}

	}

	virtual ~Directive();

	std::string cpp_str() {
		std::string s = "#"+T(Cpp::PreProcessor::DirectiveType::DEFINE)+macro->getIdentifier();
		if (macro->getArguments().size() > 0) {
			s.append("(");
			for (auto const& value: macro->getArguments()) {
				s.append(value + ",");
			}
			s.replace(s.rfind(','),1,1,')');
		}

		s.append(" " + macro->getStatement());
		return s;
	};

	std::string xml_str() {
		std::string s;
		if (macro->getArguments().size() > 0) {
			s.append("[");
			for (auto const& value: macro->getArguments()) {
				s.append(value + ",");
			}
			s.replace(s.rfind(','),1,1,']');
		}

		return "<"+T(Cpp::PreProcessor::DirectiveType::DEFINE)
				+" id="+macro->getIdentifier()
				+" arguments="+s
				+" statement="+macro->getStatement()+" />";
	}

private:
	Cpp::PreProcessor::Macro	*macro;	/** Pointer to the macro that this object defines */
};

/** @brief C++ Preprocessor directive specialization for an undef directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type UNDEF that represents an abstract
 *  model of a C++ preprocessor undef directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::UNDEF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:

	/** @brief Creates a model of a C++ undef directive and marks a macro
	 * 	as undefined (destroying it's contents).
	 *  @author FlowerGenius
	 *  @param	macro	Reference to the macro object to undefine.
	 *
	 */
	Directive(Macro &macro) {
		this->macro = &macro;
		this->macro->undefine();
	}

	/** @brief Creates a model of a C++ undef directive and marks a macro
	 * 	as undefined (destroying it's contents).
	 *  @author FlowerGenius
	 *  @param	macro	Pointer to the macro object to undefine.
	 *
	 */
	Directive(Macro *macro) {
		this->macro = macro;
		this->macro->undefine();
	}

	virtual ~Directive();
private:
	Macro	*macro;	/** Pointer to the macro that this object undefines */
};

/** @brief C++ Preprocessor directive specialization for an ifdef directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type IFDEF that represents an abstract
 *  model of a C++ preprocessor ifdef directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IFDEF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:

	/** @brief Creates a model of a C++ ifdef directive
	 *  @author FlowerGenius
	 *  @param	macro	Reference to the macro being tested for existence.
	 *
	 */
	Directive(Macro &macro) {
		this->macro = &macro;
	}

	/** @brief Creates a model of a C++ ifdef directive
	 *  @author FlowerGenius
	 *  @param	macro	Pointer to the macro being tested for existence.
	 *
	 */
	Directive(Macro *macro) {
		this->macro = macro;
	}

	virtual ~Directive();
private:
	Macro    *macro;
};

/** @brief C++ Preprocessor directive specialization for an ifndef directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type IFNDEF that represents an abstract
 *  model of a C++ preprocessor ifndef directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IFNDEF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:
	Macro    *macro;
};

/** @brief C++ Preprocessor directive specialization for an else directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type ELSE that represents an abstract
 *  model of a C++ preprocessor else directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ELSE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:

};

/** @brief C++ Preprocessor directive specialization for an endif directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type ENDIF that represents an abstract
 *  model of a C++ preprocessor endif directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ENDIF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:

};

/** @brief C++ Preprocessor directive specialization for an if directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type IF that represents an abstract
 *  model of a C++ preprocessor if directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:

};

/** @brief C++ Preprocessor directive specialization for an include directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type INCLUDE that represents an abstract
 *  model of a C++ preprocessor include directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::INCLUDE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive() {
		file_ptr = nullptr;
		standard = false;
	}

	Directive(Cpp::Project::File::Header *header_ptr) {
		file_ptr = header_ptr;
		if (file_ptr->isStandard()){
			standard = true;
		} else {
			standard = false;
		}
	}

	Directive(Cpp::Project::File::Header &header) {
		file_ptr = &header;
		if (file_ptr->isStandard()){
			standard = true;
		} else {
			standard = false;
		}
	}

	virtual ~Directive();

	std::string cpp_str() {

		if (file_ptr == nullptr) { return ""; }

		std::string ret;
		const char enclosers[] = {'<','>','\"'};

		if (standard) {

		}

		return ret;
	}

	std::string xml_str() {
		;
	}

private:
	bool        standard;
	Cpp::Project::File::Header   *file_ptr;
};

/** @brief C++ Preprocessor directive specialization for an elif directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type ELIF that represents an abstract
 *  model of a C++ preprocessor elif directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ELIF> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:

};

/** @brief C++ Preprocessor directive specialization for an error directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type ERROR that represents an abstract
 *  model of a C++ preprocessor error directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ERROR> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:
	std::string error_message;
};

/** @brief C++ Preprocessor directive specialization for an line directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type LINE that represents an abstract
 *  model of a C++ preprocessor line directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::LINE> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:
	int line_number;
	std::string new_filename;
};

/** @brief C++ Preprocessor directive specialization for an pragma directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type PRAGMA that represents an abstract
 *  model of a C++ preprocessor pragma directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::PRAGMA> : public Cpp::PreProcessor::Directive_base, public Cpp::Feature {
public:
	Directive();
	virtual ~Directive();
private:
	std::vector<std::string> parameters;
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPP_H_ */
