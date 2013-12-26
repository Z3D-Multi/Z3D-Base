/*
 * Time.cpp
 *
 *  Created on: 22-Dec-2013
 *      Author: zeneil
 */

#include "../Time.h"
#include <boost/chrono.hpp>

namespace Z3D_Base {

/*
 * Variables
 * =================
 */
double delta;


/*
 * Functions:
 * =================
 */

Time::Time() {
	// TODO Auto-generated constructor stub

}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

long Time::getTime()
{
	static boost::chrono::system_clock::time_point start;
	static bool happened = false;

	if(!happened)
	{
		happened = true;
		start = boost::chrono::system_clock::now();
	}

	boost::chrono::duration<long long, boost::nano> sec = boost::chrono::system_clock::now() - start;
	return sec.count();
}

double Time::getDelta()
{
	return delta;
}

void Time::setDelta(double deltaIn)
{
	delta = deltaIn;
}

} /* namespace Z3D_Base */
