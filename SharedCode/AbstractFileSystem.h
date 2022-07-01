/*
AbstractFileSystem.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the AbstractFileSystem base class
*/

#pragma once
// declaration of the interface all file systems provide goes here

#include <string>
#include "AbstractFile.h"
#include <set>

class AbstractFileSystem {
public:
	virtual int addFile(std::string fileName, AbstractFile *file) = 0;
	virtual int deleteFile(std::string fileName) = 0;
	virtual AbstractFile* openFile(std::string fileName) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};