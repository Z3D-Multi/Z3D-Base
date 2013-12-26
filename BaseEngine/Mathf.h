/*
 * Mathf.h
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#ifndef MATHF_H_
#define MATHF_H_

#ifndef PI
#define PI 3.141592653589793f
#endif

#define __STANDARD_COERCE_COEFFICIENT 1e-6
#define __MATHF_RADIAN_CONVERSION_FACTOR PI/180.0f

#include <cmath>

namespace Z3D_Base {

class Mathf {
private:
	static float CoerceCoefficient;

	inline static float fmod(float numerator, float denominator);

public:
	Mathf();
	virtual ~Mathf();

	/*
	 * 	Getters & Setters:
	 * ==================
	 */
	static float getCoerceCoefficient();
	static void setCoerceCoefficient(float coerceCoefficient);

	/*
	 * 	Mathematical Functions:
	 * =======================
	 */
	static float round(float toRound, float accuracy=CoerceCoefficient);
	static inline float fastSin(float angleInDegrees){return sin(__MATHF_RADIAN_CONVERSION_FACTOR*angleInDegrees);};
};



} /* namespace Z3D_Base */

#endif /* MATHF_H_ */
