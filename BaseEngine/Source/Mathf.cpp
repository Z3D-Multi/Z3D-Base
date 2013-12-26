/*
 * Mathf.cpp
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#include "../Mathf.h"
#include <iostream>

namespace Z3D_Base {

float Mathf::CoerceCoefficient = __STANDARD_COERCE_COEFFICIENT;

Mathf::Mathf() {

}

Mathf::~Mathf() {

}

float Mathf::getCoerceCoefficient() {
	return CoerceCoefficient;
}

void Mathf::setCoerceCoefficient(float coerceCoefficient) {
	CoerceCoefficient = coerceCoefficient;
}

/*
float Mathf::round(float toRound)
{
	float accuracy=CoerceCoefficient;
	return (toRound-fmod(toRound,accuracy));
}
*/

inline float Mathf::fmod(float numerator, float denominator)
{
	//Check for inverse condition:
	if(numerator<denominator)
		return numerator;

	//Check for very large difference:
	if(denominator/numerator < Mathf::CoerceCoefficient)
		return 0.0f;

	return ((numerator/denominator) - float((long long)(numerator/denominator)))*denominator;
}

float Mathf::round(float toRound, float accuracy)
{
	return (toRound-Mathf::fmod(toRound,accuracy));
}

} /* namespace Z3D_Base */
