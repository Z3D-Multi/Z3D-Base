/*
 * Debug.h
 *
 *  Created on: 30-Dec-2013
 *      Author: zeneil
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <iostream>
#include <string>

#define __ENABLE_DEBUG_MODE true
#define __EXECUTE_DEBUG_CHECK if(!__ENABLE_DEBUG_MODE) return;
#define __EXECUTE_DEBUG_WRITE(x) std::cout << x << debugInfo << std::endl;

namespace Z3D_Base {

class Debug {
public:
	Debug();
	virtual ~Debug();

	static void log(char *debugInfo);
	static void log(std::string debugInfo);

	static void error(char *debugInfo);
	static void error(std::string debugInfo);
private:
};

} /* namespace Z3D_Base */

#endif /* DEBUG_H_ */
