/*
SimpleFileFactory.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in SimpleFileFactory:
createFile() - takes in a parameter s (string) and returns a new file of based on the extension in s (.txt or .img) or a nullptr
*/

#include "SimpleFileFactory.h"
#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"

AbstractFile* SimpleFileFactory::createFile(std::string s) 
{
	int i = s.find_last_of('.');
	std::string ext = s.substr(i + 1, std::string::npos);
	AbstractFile* file;
	if (ext == "txt") {
		return new TextFile(s);
	}
	else if (ext == "img") {
		return new ImageFile(s);
	}
	else {
		return nullptr;
	}
};