/*
SimpleFileSystem.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the SimpleFileSystem derived class which inherits from AbstractFileSystem
*/

#pragma once
// declaration of SimpleFileSystem class goes here

#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
private:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;

public:
	virtual int addFile(std::string fileName, AbstractFile* file) override;
	virtual int deleteFile(std::string fileName) override;
	virtual AbstractFile* openFile(std::string fileName) override;
	virtual int closeFile(AbstractFile* file) override;
	virtual std::set<std::string> getFileNames() override;
};