/*SHEILa========================================================================
 * Name        : CppPPDirective.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 17, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef SRC_CPP_CPPPPDIRECTIVE_CPPPPDIRECTIVE_H_
#define SRC_CPP_CPPPPDIRECTIVE_CPPPPDIRECTIVE_H_

#include "../Cpp.h"
#include "../CppHeader/CppHeader.h"

namespace sheila {
namespace cpp {

enum class CppPPDirectiveType : std::string {
	DEFINE  = "define",
	UNDEF   = "undef",
	IFDEF   = "ifdef",
	IFNDEF  = "ifndef",
	ELSE    = "else",
	ENDIF   = "endif",
	IF      = "if",
	ELIF    = "elif",
	INCLUDE = "include",
	ERROR   = "error",
	LINE    = "line",
	PRAGMA  = "pragma",
	OTHER	= "*"
};


/*
 * Abstract model of a C++ Preprocessor directive;
 */
struct CppPPDirective_base : public CppFeature {

	CppPPDirective_base() {
		before = nullptr;
	}

//	virtual std::string cpp_str();
//	std::string xml_str();

	virtual ~CppPPDirective_base() {
		;
	}

	/* The feature that comes before the directive
	 *
	 */
	CppFeature* before;

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
template<CppPPDirectiveType _Td>
class CppPPDirective : public CppPPDirective_base {
public:
	CppPPDirective(std::vector<std::string> allocator = {});

	std::string cpp_str();

	std::string xml_str();

	virtual ~CppPPDirective();
private:
	std::vector<std::string> parameters;
};

/** @brief C++ Preprocessor directive specialization for a define directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type DEFINE that represents an abstract
 *  model of a C++ preprocessor define directive.
 */
template<>
class CppPPDirective<CppPPDirectiveType::DEFINE> : public CppPPDirective_base {
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
	CppPPDirective(CppFeature &feat, std::string id,
			std::string statement,
			std::vector<std::string> args = {}) {
		before = &feat;
		macro = new CppMacro(id,statement,args);
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
	CppPPDirective(CppFeature *feat, std::string id,
			std::string statement,
			std::vector<std::string> args = {}) {
		before = feat;
		macro = new CppMacro(id,statement,args);
	}

	virtual ~CppPPDirective();

	std::string cpp_str() {
		std::string s = "#"+CppPPDirectiveType::DEFINE+macro->getIdentifier();
		if (macro->getArguments().size > 0) {
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
		if (macro->getArguments().size > 0) {
			s.append("[");
			for (auto const& value: macro->getArguments()) {
				s.append(value + ",");
			}
			s.replace(s.rfind(','),1,1,']');
		}

		return "<"+CppPPDirectiveType::DEFINE
				+" id="+macro->getIdentifier()
				+" arguments="+s
				+" statement="+macro->getStatement()+" />";
	}

private:
	CppMacro    *macro;
};

/** @brief Type definition of the specialization DEFINE for convenience and
 * 	readability.
 * 	@author FlowerGenius
 */
typedef CppPPDirective<CppPPDirectiveType::DEFINE> CppDefineDirective;




/** @brief C++ Preprocessor directive specialization for an undef directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type UNDEF that represents an abstract
 *  model of a C++ preprocessor undef directive.
 */
template<>
class CppPPDirective<CppPPDirectiveType::UNDEF> : public CppPPDirective_base {
public:

	/** @brief Creates a model of a C++ undef directive and destroys a macro
	 * 	object.
	 *  @author FlowerGenius
	 *  @param	macro	Reference to the macro object to destroy.
	 *
	 */
	CppPPDirective(CppMacro &macro) {
		this->macro = &macro;
		delete this->macro;
	}

	/** @brief Creates a model of a C++ undef directive and destroys a macro
	 * 	object.
	 *  @author FlowerGenius
	 *  @param	macro	Pointer to the macro object to destroy.
	 *
	 */
	CppPPDirective(CppMacro *macro) {
		this->macro = macro;
		delete this->macro;
	}

	virtual ~CppPPDirective();
private:
	CppMacro *macro;
};

/** @brief Type definition of the specialization UNDEF for convenience and
 * 	readability.
 * 	@author FlowerGenius
 */
typedef CppPPDirective<CppPPDirectiveType::UNDEF> CppUndefDirective;




/** @brief C++ Preprocessor directive specialization for an ifdef directive.
 *  @author FlowerGenius
 *
 *  An explicit specialization of the type IFDEF that represents an abstract
 *  model of a C++ preprocessor ifdef directive.
 */
template<>
class CppPPDirective<CppPPDirectiveType::IFDEF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:
	CppMacro    *macro;
}; typedef CppPPDirective<CppPPDirectiveType::IFDEF> CppIfdefDirective;

template<>
class CppPPDirective<CppPPDirectiveType::IFNDEF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:
	CppMacro    *macro;
}; typedef CppPPDirective<CppPPDirectiveType::IFNDEF> CppIfndefDirective;

template<>
class CppPPDirective<CppPPDirectiveType::ELSE> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

}; typedef CppPPDirective<CppPPDirectiveType::ELSE> CppElseDirective;

template<>
class CppPPDirective<CppPPDirectiveType::IF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

}; typedef CppPPDirective<CppPPDirectiveType::IF> CppIfDirective;

template<>
class CppPPDirective<CppPPDirectiveType::ELIF> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:

}; typedef CppPPDirective<CppPPDirectiveType::ELIF> CppElifDirective;

/*
 * Abstract model of a C++ Preprocessor include directive
 */
template<>
class CppPPDirective<CppPPDirectiveType::INCLUDE> : public CppPPDirective_base {
public:
	CppPPDirective() { file_ptr = nullptr; standard = false; }

	CppPPDirective(CppHeader *header_ptr) {
		file_ptr = header_ptr;
		if (file_ptr->isStandard()){
			standard = true;
		} else {
			standard = false;
		}
	}

	CppPPDirective(CppHeader &header) {
		file_ptr = header;
		if (file_ptr->isStandard()){
			standard = true;
		} else {
			standard = false;
		}
	}

	virtual ~CppPPDirective();

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
	CppHeader   *file_ptr;
}; typedef CppPPDirective<CppPPDirectiveType::INCLUDE> CppIncludeDirective;

template<>
class CppPPDirective<CppPPDirectiveType::ERROR> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:
	std::string error_message;
}; typedef CppPPDirective<CppPPDirectiveType::ERROR> CppErrorDirective;

template<>
class CppPPDirective<CppPPDirectiveType::LINE> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:
	int line_number;
	std::string new_filename;
}; typedef CppPPDirective<CppPPDirectiveType::LINE> CppLineDirective;

template<>
class CppPPDirective<CppPPDirectiveType::PRAGMA> : public CppPPDirective_base {
public:
	CppPPDirective();
	virtual ~CppPPDirective();
private:
	std::vector<std::string> parameters;
}; typedef CppPPDirective<CppPPDirectiveType::PRAGMA> CppPragmaDirective;

} /* namespace cpp */
} /* namespace sheila */

#endif /* SRC_CPP_CPPPPDIRECTIVE_CPPPPDIRECTIVE_H_ */
