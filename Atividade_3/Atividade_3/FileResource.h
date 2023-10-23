#pragma once

#include <iostream>

template <class T> class FileResource{

public:
	std::string file;

	FileResource(const std::string& fileName);
	T ReadData();
	T WriteData();
	T MoveTo();
};