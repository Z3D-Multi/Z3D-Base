/*
 * Debug.cpp
 *
 *  Created on: 30-Dec-2013
 *      Author: zeneil
 */

#include "../Debug.h"

namespace Z3D_Base {

Debug::Debug() {
	// TODO Auto-generated constructor stub

}

Debug::~Debug() {
	// TODO Auto-generated destructor stub
}

void Debug::log(char* debugInfo) {

	__EXECUTE_DEBUG_CHECK
	__EXECUTE_DEBUG_WRITE("LOG: ");

}

void Debug::log(std::string debugInfo) {
	__EXECUTE_DEBUG_CHECK
	__EXECUTE_DEBUG_WRITE("LOG: ");
}

void Debug::error(char* debugInfo) {
	__EXECUTE_DEBUG_CHECK
	__EXECUTE_DEBUG_WRITE("ERROR: ");
}

void Debug::error(std::string debugInfo){
	__EXECUTE_DEBUG_CHECK
	__EXECUTE_DEBUG_WRITE("ERROR: ");
}

} /* namespace Z3D_Base */
