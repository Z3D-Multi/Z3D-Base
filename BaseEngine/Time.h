/*
 * Time.h
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#ifndef TIME_H_
#define TIME_H_

#include <ctime>

namespace Z3D_Base {

class Time {

private:
	//std::clockid_t CLOCK_REALTIME;

public:
	static const long SECOND = 1e9L;

	Time();
	virtual ~Time();

	static long getTime();
	static double getDelta();
	static void setDelta(double delta);
};

} /* namespace Z3D_Base */
#endif /* TIME_H_ */
