//SHEILa========================================================================
// Name        : CHeaderFile.h
// Author      : FlowerGenius<justanortherngirl58@gmail.com>
// Version     : 
// Copyright   : 
// Description : 
// Module      : SHEILa
// Created     : Apr 12, 2018
// Modified    :
//==============================================================================

#ifndef C_CHEADER_CHEADER_H_
#define C_CHEADER_CHEADER_H_

namespace sheila {
namespace c {


typedef enum c_standard_library_headers {

} CStandardHeaderFile;

class CHeader {
public:

	enum class CHeaderExtensions {
		H,
		INC
	};

	CHeader();
	virtual ~CHeader();
};

} /* namespace c */
} /* namespace sheila */

#endif /* C_CHEADER_CHEADER_H_ */
