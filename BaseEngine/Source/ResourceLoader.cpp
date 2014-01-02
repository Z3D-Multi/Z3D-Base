/*
 * ResourceLoader.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>//atoi
#include <gli/gli.hpp>
#include <gli/core/storage.hpp>
#include <gli/core/texture.hpp>
#include <gli/core/clear.hpp>
#include <gli/core/comparison.hpp>
#include <gli/core/copy.hpp>
#include <gli/core/load_dds.hpp>
#include <gli/core/view.hpp>
#include <gli/core/gl.hpp>
#include <gli/core/dx.hpp>
#include <GL/glew.h>
#include "../ResourceLoader.h"
#include "../Debug.h"
namespace Z3D_Base {

#ifdef GLI_INCLUDED

#endif

/*
 * Static Variables:
 * =================
 */
ResourceLoader::loaderHelper ResourceLoader::LoaderHelper;
const char* ResourceLoader::EngineBasePath =
		std::string(
				std::string("../") + std::string(__FILE__)
						+ std::string("/../../../")).c_str();

ResourceLoader::ResourceLoader() {
	// TODO Auto-generated constructor stub

}

ResourceLoader::~ResourceLoader() {
	// TODO Auto-generated destructor stub
}

std::string ResourceLoader::loadShader(const char* fileName) {
	return ResourceLoader::loadFile(fileName);
}

//LoaderHelper Methods://
void ResourceLoader::loaderHelper::init(bool maintainLastChar) {
	if (hasBeenInitialized)
		return;

	current = start = new Block();
	pointer = count = 0;

	if (!maintainLastChar)
		ch = (char) 0;

	hasBeenInitialized = true;
}

void ResourceLoader::loaderHelper::feed() {

	if (!hasBeenInitialized)
		init(true);

	if (pointer == __RESOURCELOADER_RESOURCE_READ_SIZE) {
		current->next = new Block();
		current = current->next;
		count++;
		pointer = 0;
	}

	current->block[pointer++] = ch;
	ch = (char) 0;
}

std::string ResourceLoader::loaderHelper::done() {
	if (!hasBeenInitialized)
		return 0x0;

	hasBeenInitialized = false;

	int length = count * __RESOURCELOADER_RESOURCE_READ_SIZE + pointer;
	char temp[length];

	int j = 0;
	for (current = start;; current = current->next) {
		for (register int i = 0;
				i < __RESOURCELOADER_RESOURCE_READ_SIZE && j < length; i++)
			temp[j++] = current->block[i];
		if (current->next == 0x0 || j >= length)
			break;
	}
	current = 0x0;
	start->deleteStructure();
	delete (start);

	return std::string(temp, length);
}

ResourceLoader::loaderHelper::Block::Block() {
	next = 0x0;
}

ResourceLoader::loaderHelper::Block::~Block() {
}

void ResourceLoader::loaderHelper::Block::deleteStructure() {
	if (next != 0x0) {
		next->deleteStructure();
		delete (next);
	}
}

Mesh *ResourceLoader::loadMesh(const char* fileName) {

	//Find the string extension place://

	Mesh *temp;
	std::string filePath(fileName);
	std::string ext = ResourceLoader::getFileExtension(fileName);

	if (ext.compare(std::string("obj")) == 0)
		temp = ResourceLoader::loadMeshOBJ(filePath);
	else {
		Debug::error(
				std::string("Unsupported File Type for model Load:") + (ext));
		throw 10;
	}

	Debug::log("Finished loading mesh: " + filePath);

	return temp;
}

std::string ResourceLoader::loadFile(const char* fileName) {

	//const char *fileName = (const char*)temp;//(std::string(ResourceLoader::EngineBasePath)+std::string(temp)).c_str();

	std::ifstream in(fileName, std::ios::in | std::ios::binary);

	if (!in)
		return 0x0;

	ResourceLoader::LoaderHelper.init();

	while (in) {
		in.get(ResourceLoader::LoaderHelper.ch);
		if (in)
			ResourceLoader::LoaderHelper.feed();
	}

	in.close();

	return ResourceLoader::LoaderHelper.done();

}

Mesh *ResourceLoader::loadMeshOBJ(std::string filePath) {
	Mesh *temp = new Mesh();

	Debug::log("Loading mesh(OBJ loader)...");

	std::vector<Vertex> vertices;
	std::vector<int> indices;

	std::ifstream in(filePath.c_str(), std::ios::in | std::ios::binary);

	if (!in) {
		Debug::error(
				"Could not find mesh file while loading mesh: " + filePath);
		throw 10;
		return temp;
	}

	while (in) {
		char ch;
		static char prevChar;
		in.get(ch);
		if (in) {
			//Ignore if not v or f://
			if ((ch == 'v' || ch == 'f') && prevChar == '\n') {
				//Process byte://
				bool storeAsVertex = ch == 'v';

				float fToStore[3];

				//Skip the space://
				in.get(ch);
				if (!in) {
					Debug::error("Unexpected EOF while loading mesh");
					throw 10;
				}

				for (register int countedOccurences = 0; ch != '\n';
						++countedOccurences) {
					//Create temporary storage://
					std::string strTemp = "";
					bool isNumberNegative = false;
					while (true) {
						//Fetch the number://
						in.get(ch);
						if (!in) {
							Debug::error("Unexpected EOF while loading mesh");
							throw 10;
						}
						//Check for end of number://
						if (ch != ' ' && ch != '\n') {
							if (ch == '-') {
								isNumberNegative = true;
								continue;
							}
							strTemp = strTemp + std::string(1, ch);

						} else {
							//Check if the entry is a face://
							if (storeAsVertex)
								if (isNumberNegative)
									fToStore[countedOccurences] = (-1.0f)
											* atof(strTemp.c_str());
								else
									fToStore[countedOccurences] = atof(
											strTemp.c_str());
							else
								//Add the index into the index array://
								indices.push_back(atoi(strTemp.c_str()) - 1);
							break;
						}
					} //END of while
				} //END of outer for

				//Add if vertex://
				if (storeAsVertex)
					vertices.push_back(
							Vertex(
									Vector3f(fToStore[0], fToStore[1],
											fToStore[2])));

			}
		}
		prevChar = ch;
	}
	in.close();

	//Create Mesh://
	temp->addVertices((Vertex *) &vertices[0], vertices.size(),
			(unsigned int *) &indices[0], indices.size());

	return temp;
}

Texture* ResourceLoader::loadTexture(const char* fileName) {

	std::string ext = ResourceLoader::getFileExtension(fileName);
	Texture *temp;

	if (ext.compare("dds") == 0) {
		//Load DDS://
		gli::storage Storage(gli::load_dds(fileName));
		if (Storage.empty()) {
			Debug::error(
					"Could not load storage for file: " + std::string(fileName));
			throw 10;
		}
		GLenum Target =
				Storage.layers() > 1 ? GL_TEXTURE_2D_ARRAY : GL_TEXTURE_2D;
		temp = new Texture();
		unsigned int *idp = temp->getID();
		glGenTextures(1, idp);
		glBindTexture(Target, *idp);
		glTexParameteri(Target, GL_TEXTURE_BASE_LEVEL, 0);
		glTexParameteri(Target, GL_TEXTURE_MAX_LEVEL,
				static_cast<GLint>(Texture::levels() - 1));
		glTexParameteri(Target, GL_TEXTURE_MIN_FILTER,
				Texture::levels() > 1 ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR);
		glTexParameteri(Target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (Storage.layers() > 1) {
			gli::texture2DArray Texture(Storage);
#ifdef glTexStorage3D
			glTexStorage3D(Target, static_cast<GLint>(Texture.levels()),
					static_cast<GLenum>(gli::internal_format(Texture.format())),
					static_cast<GLsizei>(Texture.dimensions().x),
					static_cast<GLsizei>(Texture.dimensions().y),
					static_cast<GLsizei>(Texture.layers()));
#else
#error Need to include texture librarires
#endif
			if (gli::is_compressed(Texture.format())) {
				for (gli::texture2DArray::size_type Layer = 0;
						Layer < Texture.layers(); ++Layer)
					for (gli::texture2DArray::size_type Level = 0;
							Level < Texture.levels(); ++Level) {
						glCompressedTexSubImage3D(Target,
								static_cast<GLint>(Level), 0, 0,
								static_cast<GLint>(Layer),
								static_cast<GLsizei>(Texture[Layer][Level].dimensions().x),
								static_cast<GLsizei>(Texture[Layer][Level].dimensions().y),
								static_cast<GLsizei>(1),
								static_cast<GLenum>(gli::external_format(
										Texture.format())),
								static_cast<GLsizei>(Texture[Layer][Level].size()),
								Texture[Layer][Level].data());
					}
			} else {
				for (gli::texture2DArray::size_type Layer = 0;
						Layer < Texture.layers(); ++Layer)
					for (gli::texture2DArray::size_type Level = 0;
							Level < Texture.levels(); ++Level) {
						glTexSubImage3D(Target, static_cast<GLint>(Level), 0, 0,
								static_cast<GLint>(Layer),
								static_cast<GLsizei>(Texture[Layer][Level].dimensions().x),
								static_cast<GLsizei>(Texture[Layer][Level].dimensions().y),
								static_cast<GLsizei>(1),
								static_cast<GLenum>(gli::external_format(
										Texture.format())),
								static_cast<GLenum>(gli::type_format(
										Texture.format())),
								Texture[Layer][Level].data());
					}
			}
		} else {
			gli::texture2D Texture(Storage);
#ifdef glTexStorage2D
			glTexStorage2D(Target, static_cast<GLint>(Texture.levels()),
					static_cast<GLenum>(gli::internal_format(Texture.format())),
					static_cast<GLsizei>(Texture.dimensions().x),
					static_cast<GLsizei>(Texture.dimensions().y));
#else
#error Need to include texture librarires
#endif
			if (gli::is_compressed(Texture.format())) {
				for (gli::texture2D::size_type Level = 0;
						Level < Texture.levels(); ++Level) {
					glCompressedTexSubImage2D(Target, static_cast<GLint>(Level),
							0, 0,
							static_cast<GLsizei>(Texture[Level].dimensions().x),
							static_cast<GLsizei>(Texture[Level].dimensions().y),
							static_cast<GLenum>(gli::external_format(
									Texture.format())),
							static_cast<GLsizei>(Texture[Level].size()),
							Texture[Level].data());
				}
			} else {
				for (gli::texture2D::size_type Level = 0;
						Level < Texture.levels(); ++Level) {
					glTexSubImage2D(Target, static_cast<GLint>(Level), 0, 0,
							static_cast<GLsizei>(Texture[Level].dimensions().x),
							static_cast<GLsizei>(Texture[Level].dimensions().y),
							static_cast<GLenum>(gli::external_format(
									Texture.format())),
							static_cast<GLenum>(gli::type_format(
									Texture.format())), Texture[Level].data());
				}
			}
		}

	} else {
		Debug::error(
				std::string("Unsupported File Type for model Load:") + (ext));
		throw 10;
	}

	return temp;
}

std::string ResourceLoader::getFileExtension(const char* fileName) {
	std::string filePath(fileName);
	std::string slash(__FILE_ESCAPE_CHARACTER);

	unsigned found = filePath.rfind(slash);
	if (found == std::string::npos) {
		Debug::error("Invalid Path specification while loading model");
		throw 10;
	}

	std::string ext = filePath.substr(found + 1, filePath.length());
	ext = ext.substr(ext.find(".") + 1, ext.length());

	return ext;
}

} /* namespace Z3D_Base */

