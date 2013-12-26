/*
 * Shader.cpp
 *
 *  Created on: 25-Dec-2013
 *      Author: zeneil
 */

#include "../Shader.h"
#include "../Util.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>
#include <string>
namespace Z3D_Base {

Shader::Shader() {

#ifdef glCreateProgram
	this->program = glCreateProgram();
#else
#error Load Shaders
#endif

	if (this->program == 0)
		throw 10;
}

Shader::~Shader() {
#ifdef glCreateProgram
	glDeleteShader(this->program);
#else
#error Load Shaders
#endif

}

void Shader::addVertexShader(const char* text) {
	this->addShaderProgram(text, GL_VERTEX_SHADER);
}

void Shader::addFragmentShader(const char* text) {
	this->addShaderProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::addGeometryShader(const char* text) {
	this->addShaderProgram(text, GL_GEOMETRY_SHADER);
}

void Shader::addShaderProgram(const char* text, int type) {
#ifdef glCreateProgram

	int shader = glCreateShader(type);
	if (shader == 0)
	throw 10;
#else
#error Load Shaders
#endif

#ifdef glCreateProgram
	glShaderSource(shader,1,&text,NULL);
	glCompileShader(shader);
#else
#error Load Shaders
#endif

#ifdef glCreateProgram
	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS,&result);
	if(result==0)
	{
		int i;
		char *err = new char[1024];
		glGetShaderInfoLog(shader,1024,0,(GLchar*) err);
		std::cout << "Error occurred" << err << std::endl;
		delete(err);
		throw 10;

	}

	glAttachShader(program,shader);
#else
#error Load Shaders
#endif
}

void Shader::compileShader() {
#ifdef glCreateProgram
	glLinkProgram(program);
	int result;
	char *err = new char[1024];
	glGetProgramiv(program, GL_LINK_STATUS,&result);
	if(result==0)
	{
		int i;
		glGetProgramInfoLog(program,1024,&i,err);
		std::cout << "Error occurred" << err << std::endl;
		throw 10;
	}

	glValidateProgram(program);
	glGetProgramiv(program, GL_COMPILE_STATUS,&result);
	if(result==0)
	{
		int i;
		glGetProgramInfoLog(program,1024,&i,err);
		std::cout << "Error occurred" << err << std::endl;
		throw 10;
	}
	delete(err);
#else
#error Load Shaders
#endif
}

void Shader::bind() {
#ifdef glCreateProgram
	glUseProgram(program);
#else
#error Load Shaders
#endif
}

void Shader::addUniform(const char* uniform) {
#ifdef glCreateProgram
	int uniformLocation = glGetUniformLocation(this->program, uniform);

	if (uniformLocation < 0) {
		throw 10;
	}

	this->uniformMap[uniform] = uniformLocation;
	if(this->uniformMap[uniform]!=uniformLocation)
		throw 10;
#else
#error Load Shaders
#endif

}

void Shader::setUniform(const char* uniformName, int value) {
#ifdef glCreateProgram
	glUniform1i(this->uniformMap[uniformName], value);
#else
#error Load Shaders
#endif
}

void Shader::setUniform(const char* uniformName, float value) {
#ifdef glCreateProgram
	glUniform1f(this->uniformMap[uniformName], value);
#else
#error Load Shaders
#endif
}

void Shader::setUniform(const char* uniformName, Vector3f value) {
#ifdef glCreateProgram
	glUniform3f(this->uniformMap[uniformName], value.getX(), value.getY(),
			value.getZ());
#else
#error Load Shaders
#endif
}

void Shader::setUniform(const char* uniformName, Matrix4f value) {
#ifdef glCreateProgram
	glUniformMatrix4fv(this->uniformMap[uniformName], 1,true,Util::createFlippedBuffer(value));
#else
#error Load Shaders
#endif
}

} /* namespace Z3D_Base */
