/*
 * ResourceLoader.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>							//atoi
#include "../ResourceLoader.h"
#include "../Debug.h"
namespace Z3D_Base {

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
	std::string filePath(fileName);
	std::string slash(__FILE_ESCAPE_CHARACTER);

	Mesh *temp;

	unsigned found = filePath.rfind(slash);
	if (found == std::string::npos) {
		Debug::error("Invalid Path specification while loading model");
		throw 10;
	}

	std::string ext = filePath.substr(found + 1, filePath.length());
	ext = ext.substr(ext.find(".") + 1, ext.length());

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

} /* namespace Z3D_Base */
