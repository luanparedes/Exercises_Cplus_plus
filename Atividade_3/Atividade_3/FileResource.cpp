#include <iostream>
#include "FileResource.h"

using namespace std;

template<class T> inline FileResource<T>::FileResource(const std::string& fileName)
{
	FileResource::file = fileName;
}

template<class T> T FileResource<T>::ReadData()
{
	return T();
}

template<class T> T FileResource<T>::WriteData()
{
	return T();
}

template<class T> T FileResource<T>::MoveTo()
{
	unique_ptr<FileResource> file = move(this);

	return file;
}