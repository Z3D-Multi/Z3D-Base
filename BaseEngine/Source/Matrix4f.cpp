/*
 * Matrix4f.cpp
 *
 *  Created on: 23-Dec-2013
 *      Author: zeneil
 */

#include "../Matrix4f.h"
#include "../Mathf.h"

#include <string.h>

namespace Z3D_Base {
Matrix4f::Matrix4f(bool identity) {
	init(identity);
}

Matrix4f::Matrix4f(const Matrix4f& rhs) {
	for (register int i = 0; i < 4; ++i)
		for (register int j = 0; j < 4; ++j)
			this->m[i][j] = rhs.m[i][j];
}

Matrix4f::~Matrix4f() {
}

void Matrix4f::loadIdentity() {
	init(true);
}

float Matrix4f::get(int x, int y) const {
	if (x < 4 && y < 4)
		return this->m[x][y];

	return -1.0f;
}

void Matrix4f::set(int x, int y, float val) {
	if (x < 4 && y < 4)
		this->m[x][y] = val;
}

Matrix4f Matrix4f::operator*(const Matrix4f& rhs) {
	Matrix4f temp;
	temp.m[3][3]=0.0f;

	for (register int i = 0; i < 4; ++i)
		for (register int j = 0; j < 4; ++j)
			for (register int k = 0; k < 4; ++k)
				temp.m[i][j] += this->m[i][k] * rhs.m[k][j];

	return temp;
}

Matrix4f Matrix4f::operator=(const Matrix4f& rhs) {
	for (register int i = 0; i < 4; ++i)
		for (register int j = 0; j < 4; ++j)
			this->m[i][j] = rhs.m[i][j];

	return *this;
}

Matrix4f::Matrix4f(float x, float y, float z, int type) {

	Vector3f temp(x,y,z);
	Matrix4f(temp,(int)type);

/*
	switch (type) {
	case MATRIX4F_INIT_WITH_TRANSLATION:
		Matrix4f(false);
		this->m[0][3] = x;
		this->m[1][3] = y;
		this->m[2][3] = z;
		this->m[3][3] = 1;
		break;

	case MATRIX4F_INIT_WITH_ROTATION:
		Vector3f axis(x, y, z);
		float theta = axis.length() * __MATHF_RADIAN_CONVERSION_FACTOR;

		axis.normalize();

		float cT = cos(theta);
		float sT = sin(theta);
		float cC = (1 - cT);
		float temp[4][4] = { { cT + pow(axis.getX(), 2) * cC, axis.getX()
				* axis.getY() * cC - axis.getZ() * sT, axis.getX() * axis.getZ()
				* cC + axis.getY() * sT, 0 }, { axis.getY() * axis.getX() * cC
				+ axis.getZ() * sT, cT + pow(axis.getY(), 2) * cC, axis.getZ()
				* axis.getY() * cC - axis.getX() * sT, 0 }, { axis.getZ()
				* axis.getX() * cC - axis.getY() * sT, axis.getY() * axis.getZ()
				* cC + axis.getX() * sT, cT + pow(axis.getZ(), 2) * cC, 0 }, {
				0, 0, 0, 1 } };

		memcpy(this->m, temp, 4 * 4 * sizeof(float));
		break;

	case MATRIX4F_INIT_WITH_SCALE:
		Matrix4f();
		this->m[0][0] = 1.0f;
		this->m[1][1] = 1.0f;
		this->m[2][2] = 1.0f;
		break;

	}
*/
}

Matrix4f::Matrix4f(Vector3f &axis, int type) {

	switch (type) {
	case MATRIX4F_INIT_WITH_TRANSLATION:
		this->init(true);
		this->m[0][3] = axis.getX();
		this->m[1][3] = axis.getY();
		this->m[2][3] = axis.getZ();
		break;

	case MATRIX4F_INIT_WITH_ROTATION: {
		float theta = axis.length() * __MATHF_RADIAN_CONVERSION_FACTOR;
		Vector3f temp = axis;
		temp.normalize();

		float cT = cos(theta);
		float sT = sin(theta);
		float cC = (1 - cT);
		float temp1[4][4] = { { cT + pow(temp.getX(), 2) * cC, temp.getX()
				* temp.getY() * cC - temp.getZ() * sT, temp.getX() * temp.getZ()
				* cC + temp.getY() * sT, 0 }, { temp.getY() * temp.getX() * cC
				+ temp.getZ() * sT, cT + pow(temp.getY(), 2) * cC, temp.getZ()
				* temp.getY() * cC - temp.getX() * sT, 0 }, { temp.getZ()
				* temp.getX() * cC - temp.getY() * sT, temp.getY() * temp.getZ()
				* cC + temp.getX() * sT, cT + pow(temp.getZ(), 2) * cC, 0 }, {
				0, 0, 0, 1 } };
		memcpy(this->m, temp1, 4 * 4 * sizeof(float));
	}
		break;

	case MATRIX4F_INIT_WITH_SCALE:
			this->init(false);
			this->m[0][0] = axis.getX();
			this->m[1][1] = axis.getY();
			this->m[2][2] = axis.getZ();
			break;

	default:
		init(true);
		break;
	}
}

void Matrix4f::init(bool identity) {
	for (register int i = 0; i < 4; ++i)
			for (register int j = 0; j < 4; ++j)
				if (i == j)
					this->m[i][j] = identity * 1.0f;
				else
					this->m[i][j] = 0.0f;

		this->m[3][3] = 1.0f;
}

Vector3f Matrix4f::operator*(const Vector3f& rhs) {
	float rtnVec3[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float arriveVec3[] = { rhs.getX(), rhs.getY(), rhs.getZ(), 1.0f };

	for (register int i = 0; i < 4; ++i)
		for (register int j = 0; j < 4; ++j)
			rtnVec3[i] += arriveVec3[j] * this->m[i][j];

	return Vector3f(rtnVec3[0], rtnVec3[1], rtnVec3[2]);
}

bool Matrix4f::operator==(const Matrix4f& rhs) const {
	for (register int i = 0; i < 4; ++i)
		for (register int j = 0; j < 4; ++j)
			if (this->m[i][j] != rhs.m[i][j])
				return false;

	return true;
}

} /* namespace Z3D_Base */

float* Z3D_Base::Matrix4f::getValueList() const {

	float rtn[16];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			rtn[i * 4 + j] = m[i][j];

	return rtn;
}
