/*
 * Camera.h
 *
 *  Created on: 31-Dec-2013
 *      Author: zeneil
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector3f.h"

namespace Z3D_Base {

class Camera {
private:
	Vector3f pos;
	Vector3f forward, up;

	static const Vector3f worldUp;

	void init(Vector3f pos, Vector3f forward, Vector3f up);

public:
	/*
	 * 	Constructors:
	 * =================
	 */
	Camera();
	Camera(Vector3f pos, Vector3f forward, Vector3f up);
	virtual ~Camera();

	/*
	 * 	Getters & Setters:
	 * ==================
	 */
	const Vector3f& getForward() const;
	void setForward(const Vector3f& forward);
	const Vector3f& getPos() const;
	void setPos(const Vector3f& pos);
	const Vector3f& getUp() const;
	void setUp(const Vector3f& up);

	/*
	 * 	Camera Functions:
	 * =================
	 */
	void move(Vector3f dir, float amt);
	Vector3f getLeft();
	Vector3f getRight();
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);

	void input();
};

} /* namespace Z3D_Base */

#endif /* CAMERA_H_ */
