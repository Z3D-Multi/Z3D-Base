/*
 * ResourceLoader.h
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#ifndef RESOURCELOADER_H_
#define RESOURCELOADER_H_

#define __RESOURCELOADER_RESOURCE_READ_SIZE 5

#ifndef __RESOURCELOADER_GAME_BASE_PATH
#define __WIDEN2__(x) L ## x
#define __WIDEN__(x) __WIDEN2__(x)
#define __WFILE__ __WIDEN__(__FILE__)
#define __RESOURCELOADER_GAME_BASE_PATH __WFILE__
#endif

#ifdef __unix__
	#define __FILE_ESCAPE_CHARACTER "/"
#elif defined(_WIN32) || defined(WIN32)
	#define __FILE_ESCAPE_CHARACTER "\"
#endif

#include <string>
#include "Mesh.h"
#include "Texture.h"

namespace Z3D_Base {

class ResourceLoader {
public:
	static const char* EngineBasePath;

	ResourceLoader();
	virtual ~ResourceLoader();

	static std::string loadShader(const char* fileName);
	static Mesh *loadMesh(const char* fileName);
	static Texture *loadTexture(const char* fileName);

private:
	static std::string loadFile(const char* fileName);
	static Mesh *loadMeshOBJ(std::string filePath);

	static std::string getFileExtension(const char* fileName);

	//Resource Loader Helping struct://
	struct loaderHelper {
		struct Block {
			Block();
			~Block();
			char block[__RESOURCELOADER_RESOURCE_READ_SIZE];

			void deleteStructure();
			Block *next;
		};
		char ch;
		int pointer, count;
		Block *start, *current;
		bool hasBeenInitialized = false;

		void init(bool maintainLastChar=false);
		void feed();
		std::string done();

	};
	static loaderHelper LoaderHelper;
};

} /* namespace Z3D_Base */

#endif /* RESOURCELOADER_H_ */
