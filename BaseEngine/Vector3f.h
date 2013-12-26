/*
 * Vector3f.h
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#ifndef VECTOR3F_H_
#define VECTOR3F_H_

namespace Z3D_Base {


class Vector3f {
private:
	float x, y, z;

public:
	/*
	 * 	Constructors:
	 * =================
	 */
	Vector3f();
	Vector3f(float x, float y, float z);
	Vector3f(const Vector3f &v);
	virtual ~Vector3f();

	/*
	 * 	Mathematical Functions:
	 * =======================
	 */
	float length();
	Vector3f normalize();
	Vector3f rotate(float angle,Vector3f axis);
	Vector3f rotateToObtainNewVector(float angle,Vector3f axis);
	static float dotProduct(Vector3f a,Vector3f b);
	static Vector3f crossProduct(Vector3f a,Vector3f b);

	/*
	 * 	Getters & Setters:
	 * ==================
	 */
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	float getZ() const;
	void setZ(float z);
	void setXYZ(float x=0.0f, float y=0.0f, float z=0.0f);

	/*
	 * 	Operator Overloads:
	 * ==================
	 */
	Vector3f operator=(const Vector3f& rhs);
	Vector3f operator*(float rhs);
	Vector3f operator*(const Vector3f& rhs);
	Vector3f operator+(const Vector3f& rhs);
	Vector3f operator+(float rhs);
	Vector3f operator-(const Vector3f& rhs);
	Vector3f operator-(float rhs);
	Vector3f operator/(float rhs);
	Vector3f operator*=(float rhs);
	Vector3f operator+=(float rhs);
	Vector3f operator+=(const Vector3f& rhs);
	Vector3f operator-=(float rhs);
	Vector3f operator-=(const Vector3f& rhs);
	Vector3f operator/=(float rhs);
	bool operator==(const Vector3f& rhs) const;
};

} /* namespace Z3D_Base */

#endif /* VECTOR3F_H_ */
