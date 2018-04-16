/*SHEILa========================================================================
 * Name        : CppInputFile.h
 * Author      : FlowerGenius<justanortherngirl58@gmail.com>
 * Version     : 
 * Copyright   : 
 * Description : 
 * Module      : SHEILa
 * Created     : Apr 14, 2018
 * Modified    :
 *==============================================================================
 */
#ifndef CPP_CPPINPUTFILE_CPPINPUTFILE_H_
#define CPP_CPPINPUTFILE_CPPINPUTFILE_H_

#include <string>
#include <vector>

#include "../Cpp.h"
#include "../CppMacro/CppMacro.h"
#include "../CppSymbol/CppSymbol.h"

namespace sheila {
namespace cpp {

class CppHeaderFile;

class CppInputFile {
public:

	enum extensions {
		CPP,
		CXX,
		Cplusplus,
		CC
	};

	CppInputFile();
	/* Preprocessor Cpp Standard Library Includes */

	bool hasInclude(cpp::CppStandardHeaderFile);
	int addInclude(cpp::CppStandardHeaderFile);
	int removeInclude(cpp::CppStandardHeaderFile);
	const std::vector<cpp::CppStandardHeaderFile>& _getCppIncludes() const;

	/* Preprocessor C Standard Library Includes */

	bool hasInclude(c::CStandardHeaderFile);
	int addInclude(c::CStandardHeaderFile);
	int removeInclude(c::CStandardHeaderFile);
	const std::vector<c::CStandardHeaderFile>& _getCIncludes() const;

	/* Preprocessor Included files */

	bool hasInclude(cpp::CppHeaderFile);
	int addInclude(cpp::CppHeaderFile);
	int removeInclude(cpp::CppHeaderFile);
	const std::vector<cpp::CppHeaderFile>& _getIncludes() const;

	/* Preprocessor Macros */

	bool hasMacro(cpp::CppMacro);
	int addMacro(cpp::CppMacro);
	int editMacro(cpp::CppMacro);
	int removeMacro(cpp::CppMacro);
	const std::vector<cpp::CppMacro>& _getMacros() const;

	/* Preprocessor Symbols */

	bool hasSymbol(cpp::CppSymbol);
	int addSymbol(cpp::CppSymbol);
	int editSymbol(cpp::CppSymbol);
	int removeSymbol(cpp::CppSymbol);
	const std::vector<cpp::CppSymbol>& _getSymbols() const;

	virtual ~CppInputFile();

};
} /* namespace cpp */
} /* namespace sheila */

#endif /* CPP_CPPINPUTFILE_CPPINPUTFILE_H_ */
