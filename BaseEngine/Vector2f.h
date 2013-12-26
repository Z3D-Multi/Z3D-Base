/*
 * Vector2f.h
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#ifndef VECTOR2F_H_
#define VECTOR2F_H_

namespace Z3D_Base {

class Vector2f {
private:
	float x;
	float y;

public:
	/*
	 * 	Constructors:
	 * =================
	 */
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(const Vector2f &v);
	virtual ~Vector2f();


	/*
	 * 	Mathematical Functions:
	 * =======================
	 */
	float length();
	Vector2f normalize();
	Vector2f rotate(float angle);
	Vector2f rotateToObtainNewVector(float angle);
	static float dotProduct(Vector2f a, Vector2f b);


	/*
	 * 	Getters & Setters
	 * =================
	 */
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	void setXY(float x, float y);


	/*
	 * 	Operator Overloads:
	 * ==================
	 */
	Vector2f 	operator= 	(Vector2f rhs);
	Vector2f 	operator* 	(float rhs);
	Vector2f	operator+ 	(Vector2f rhs);
	Vector2f 	operator+ 	(float rhs);
	Vector2f 	operator- 	(Vector2f rhs);
	Vector2f 	operator- 	(float rhs);
	Vector2f 	operator/ 	(float rhs);
	Vector2f 	operator*= 	(float rhs);
	Vector2f 	operator+= 	(float rhs);
	Vector2f 	operator+= 	(Vector2f rhs);
	Vector2f 	operator-= 	(float rhs);
	Vector2f 	operator-= 	(Vector2f rhs);
	Vector2f 	operator/= 	(float rhs);
	bool		operator==	(const Vector2f& rhs) const;
};

} /* namespace Z3D_Base */

#endif /* VECTOR2F_H_ */
