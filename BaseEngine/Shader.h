/*
 * Shader.h
 *
 *  Created on: 25-Dec-2013
 *      Author: zeneil
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <map>
#include "Vector3f.h"
#include "Matrix4f.h"

namespace Z3D_Base {

class Shader {
private:
	int program;
	std::map<const char*,int> uniformMap;

	void addShaderProgram(const char* text, int type);

public:
	Shader();
	virtual ~Shader();

	void addVertexShader(const char* text);
	void addFragmentShader(const char* text);
	void addGeometryShader(const char* text);

	void compileShader();
	void bind();
	void addUniform(const char* uniform);

	void setUniform(const char* uniformName, int value);
	void setUniform(const char* uniformName, float value);
	void setUniform(const char* uniformName, Vector3f value);
	void setUniform(const char* uniformName, Matrix4f value);
};

} /* namespace Z3D_Base */

#endif /* SHADER_H_ */
