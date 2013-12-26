/*
 * ResourceLoader.cpp
 *
 *  Created on: 24-Dec-2013
 *      Author: zeneil
 */

#include <iostream>
#include <fstream>
#include "../ResourceLoader.h"

namespace Z3D_Base {

/*
 * Static Variables:
 * =================
 */
ResourceLoader::loaderHelper ResourceLoader::LoaderHelper;
const char* ResourceLoader::EngineBasePath =  std::string(std::string("../") + std::string(__FILE__) + std::string("/../../../")).c_str();

ResourceLoader::ResourceLoader() {
	// TODO Auto-generated constructor stub

}

ResourceLoader::~ResourceLoader() {
	// TODO Auto-generated destructor stub
}

std::string ResourceLoader::loadShader(const char* fileName)
{
	//const char *fileName = (const char*)temp;//(std::string(ResourceLoader::EngineBasePath)+std::string(temp)).c_str();

	std::ifstream in (fileName,std::ios::in | std::ios::binary);

	if(!in)
		return 0x0;

	ResourceLoader::LoaderHelper.init();

	while(in)
	{
		in.get(ResourceLoader::LoaderHelper.ch);
		if(in) ResourceLoader::LoaderHelper.feed();
	}

	in.close();

	return ResourceLoader::LoaderHelper.done();
}

//LoaderHelper Methods://
void ResourceLoader::loaderHelper::init(bool maintainLastChar)
{
	if(hasBeenInitialized)
		return;

	current = start = new Block();
	pointer = count = 0;

	if(!maintainLastChar)
		ch = (char)0;

	hasBeenInitialized = true;
}

void ResourceLoader::loaderHelper::feed()
{

	if(!hasBeenInitialized)
		init(true);

	if(pointer==__RESOURCELOADER_RESOURCE_READ_SIZE)
	{
		current->next = new Block();
		current=current->next;
		count++;
		pointer = 0;
	}

	current->block[pointer++]=ch;
	ch = (char)0;
}

std::string ResourceLoader::loaderHelper::done()
{
	if(!hasBeenInitialized)
		return 0x0;

	hasBeenInitialized = false;

	int length = count*__RESOURCELOADER_RESOURCE_READ_SIZE + pointer;
	char temp[length];

	int j=0;
	for(current = start;; current=current->next)
	{
		for(register int i=0;i<__RESOURCELOADER_RESOURCE_READ_SIZE && j<length;i++)
				temp[j++] = current->block[i];
		if(current->next==0x0 || j>=length)
			break;
	}
	current=0x0;
	start->deleteStructure();
	delete(start);

	return std::string(temp,length);
}

ResourceLoader::loaderHelper::Block::Block()
{
	next=0x0;
}

ResourceLoader::loaderHelper::Block::~Block()
{
}

void ResourceLoader::loaderHelper::Block::deleteStructure()
{
	if(next!=0x0)
	{
		next->deleteStructure();
		delete(next);
	}
}



} /* namespace Z3D_Base */
