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
	 *  DOC come up with description
	 */
	class Feature {
	public:

		/** @brief Initializes the @a activated data member by default
		 *  @author FlowerGenius
		 *
		 *  Important Note: This constructor is part of a pure virtual abstract
		 *  base class and as such should never be called excepting that a derived
		 *  class calls it as part of the derivation chain.
		 *
		 */
		Feature() { activated = true; }

		/** @brief Destroys this CppFeature object
		 *  @author FlowerGenius
		 *
		 *  Important Note: This destructor is part of a pure virtual abstract
		 *  base class and as such should never be called excepting that a derived
		 *  class calls it as part of the derivation chain.
		 *
		 */
		virtual ~Feature(){}

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

		/** @brief Represents the commented/uncommented state of the feature */
		bool activated;
	};

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
		struct Macro : public Feature {
			/*
			 * Set the macro located at the address of the pointer to defined
			 */
			static int define_macro(Macro *mptr) { return mptr->define(); }

			/*
			 * Set the macro located at the address of the pointer to undefined
			 */
			static int undefine_macro(Macro *mptr) { return mptr->undefine(); }

			Macro();

			Macro(std::string id, std::string value, std::vector<std::string> = {});

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
			std::string identifier;
			std::vector<std::string> arguments;
			std::string statement;
		};

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
		struct Directive_base : public Feature {

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

			/* The feature that comes before the directive
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
		class Directive : public Directive_base {
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

	}; /* PreProcessor */

	/** @brief A C++ variable.
	 *
	 */
	struct Variable : public Feature {

	};

	/** @brief A C++ Function.
	 *
	 */
	struct Function : public Feature {

	};


//	struct Class_T : public Feature {
//
//		Class_T();
//		virtual ~Class_T();
//
//		virtual std::string cpp_str() = 0;
//		virtual std::string xml_str() = 0;
//	};

	/** @brief Wrapper for C++ Class Types
	 *
	 */
	struct ClassType : public Feature  {

		/** @brief A C++ Data Member
		 *
		 */
		struct DataMember : public Variable {

		};

		/** @brief A C++ Member Function
		 *
		 */
		struct MemberFunction : public Function {

		};

	};

	/** @brief A C++ class.
	 *
	 */
	struct Class : public ClassType{

	};

	/** @brief A C++ struct.
	 *
	 */
	struct Struct : public ClassType {

	};

	/** @brief A C++ union.
	 *
	 */
	struct Union  : public ClassType {

	};

	/** @brief An Instance of a C++ class.
	 *
	 */
	struct Instance : public Feature {


	};

	/** @brief A C++ Enum
	 *
	 */
	struct Enumeration : public Feature {

	};

	/** @brief C++ Type Definition
	 *
	 */
	struct TypeDefinition : public Feature {

	};

	template<typename typ>
	struct Declaration;

	/** @brief C++ namespace
	 *
	 */
	struct Namespace : public Feature {

		Namespace();
		virtual ~Namespace();

		std::string cpp_str();

		std::string xml_str();

	private:

		/** @brief Variable definitions */
		std::vector<Variable> 	 contained_variables;

		/** @brief List of function definitions */
		std::vector<Function> 	 contained_functions;

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



		/** @brief Declarations of variables that are not also definitions */
		std::vector<Declaration<Variable> > contained_declared_variables;

		/** @brief Declarations of prototype functions */
		std::vector<Declaration<Function> > contained_prototypes;

		/** @brief Forward declarations of classes, unions, and structs */
		std::vector<Declaration<ClassType> > contained_forward_declarations;


		// TODO implement understanding of the "using" keyword
	};

	/** @brief A C++ Declaration
	 *
	 */
	template<typename typ>
	struct Declaration {
		Declaration();
		virtual ~Declaration();
	};

	/** @brief A C++ File
	 *
	 */
	struct File {

		/** @brief Creates an object that represents a C++ file.
		 *	@author FlowerGenius
		 *
		 *	This constructor is meant only for initializing members required by
		 *	derived classes and should never be called excepting that the object
		 *	created then be cast to a derived type.
		 *
		 */
		File();

		/** @brief Destroys and object that represents a C++ file.
		 *  @author FlowerGenius
		 *
		 */
		virtual ~File();

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



		/** @brief List of namespace definitions */
		std::map<std::string,Namespace>    contained_namespaces;

	private:

		/** @brief The absolute path location of this file on the disk */
		std::string path;

	};

	/** @brief	An abstract model of a C++ Input File (ie. [source|header])
	 *	@author	FlowerGenius
	 *
	 *	This class represents a file in the C++ build structure model. A CppFile
	 *	can be either a header or a source file. All attributes that are shared
	 *	by both headers and source files is kept here.
	 */
	struct InFile : public File {

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
	};

	/** @brief An abstract model of a header file in C++
	 *  @author FlowerGenius
	 *
	 *  Each instance of this class models a C++ header file. A header file is
	 *  either defined inside of object for the source file that it is first
	 *  included from or has a virtual definition in the case of files outside of
	 *  the project such as those in the C++ standard library and C++STL.
	 */
	struct Header : public InFile {

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

	static Header std_stl_algorithm;
	static Header std_bitset;
	static Header std_complex;
	static Header std_stl_deque;
	static Header std_exception;
	static Header std_fstream;
	static Header std_stl_functional;
	static Header std_iomanip;
	static Header std_ios;
	static Header std_iosfwd;
	static Header std_iostream;
	static Header std_istream;
	static Header std_stl_iterator;
	static Header std_limits;
	static Header std_stl_list;
	static Header std_locale;
	static Header std_stl_map;
	static Header std_stl_memory;
	static Header std_new;
	static Header std_stl_numeric;
	static Header std_ostream;
	static Header std_stl_queue;
	static Header std_stl_set;
	static Header std_sstream;
	static Header std_stl_stack;
	static Header std_stdexcept;
	static Header std_streambuf;
	static Header std_string;
	static Header std_typeinfo;
	static Header std_stl_utility;
	static Header std_valarray;
	static Header std_stl_vector;

	/** @brief An abstract model of a source file in C++
	 *  @author FlowerGenius
	 *
	 *  Each instance of this class models a C++ source file. This file can
	 *  have a physical location on the disk, or exist entirely within memory.
	 *  In either case this model can produce valid C++ code that can be
	 *  written to a file, or valid XML code to be placed inside the definition
	 *  of the object associated with this source file.
	 */
	struct Source : public InFile {

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
		struct Artifact : public File {

			static const std::map<std::string,Artifact>& getAllArtifacts();

			Artifact();
			virtual ~Artifact();

			/** @brief The base for all of the specializations of @c CppClass.
			 *  @author FlowerGenius
			 *
			 *  This struct provides a base object for all of the specializations of
			 *  @c CppClass. This struct is not meant to ever be used in it's own right,
			 *  rather it exists as a wrapper allowing any @c CppObject types to be
			 *  accessed, stored, and used iteratively by upcasting to this base.
			 *
			 */
			struct Object_base : public File {

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


				static std::vector<Header*> this_object_headers;
				static Source*              this_object_source;

			#endif

			private:

				std::vector<std::string> names;
				std::vector<std::string> authors;
				std::vector<std::string> versions;
				std::vector<std::string> copyrights;
				std::vector<std::string> descriptions;
				std::vector<std::string> modules;
				std::string              created;
				std::vector<std::string> modified;


				std::vector<Header*> object_headers;
				Source*              object_source;
				static std::map<std::string,Object> all_objects;

			}; /* Object */

		protected:
			Namespace global_namespace;
			std::string                         artifact_name;
			std::map<std::string,Object_base*>        linked_objects;
			std::map<std::string,SharedLibrary> linked_shared_libs;
			std::map<std::string,StaticLibrary> linked_static_libs;
		private:
			static std::map<std::string,Artifact> all_artifacts;

		}; /* Artifact */

		struct Executable : public Artifact {

		}; /* Executable */

		struct SharedLibrary : public Artifact {

		}; /* Shared Library */

		struct StaticLibrary : public Artifact {

		}; /* Static Library */

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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::DEFINE> : public Cpp::PreProcessor::Directive_base {
public:

	/** @brief	Creates a model of a C++ define directive and a macro object.
	 *	@author	FlowerGenius
	 *	@param	feat		Reference to the C++ feature that comes immediately
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
	Directive(Cpp::Feature &feat, std::string id,
			std::string statement,
			std::vector<std::string> args = {}) {
		before = &feat;
		macro = new Cpp::PreProcessor::Macro(id,statement,args);
	}

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
	Directive(Cpp::Feature *feat, std::string id,
			std::string statement,
			std::vector<std::string> args = {}) {
		before = feat;
		macro = new Cpp::PreProcessor::Macro(id,statement,args);
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::UNDEF> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IFDEF> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IFNDEF> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ELSE> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ENDIF> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::IF> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::INCLUDE> : public Cpp::PreProcessor::Directive_base {
public:
	Directive() {
		file_ptr = nullptr;
		standard = false;
	}

	Directive(Cpp::Header *header_ptr) {
		file_ptr = header_ptr;
		if (file_ptr->isStandard()){
			standard = true;
		} else {
			standard = false;
		}
	}

	Directive(Cpp::Header &header) {
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
	Cpp::Header   *file_ptr;
};

/** @brief C++ Preprocessor directive specialization for an elif directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type ELIF that represents an abstract
 *  model of a C++ preprocessor elif directive.
 */
template<>
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ELIF> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::ERROR> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::LINE> : public Cpp::PreProcessor::Directive_base {
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
class Cpp::PreProcessor::Directive<Cpp::PreProcessor::DirectiveType::PRAGMA> : public Cpp::PreProcessor::Directive_base {
public:
	Directive();
	virtual ~Directive();
private:
	std::vector<std::string> parameters;
};

} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPP_H_ */
