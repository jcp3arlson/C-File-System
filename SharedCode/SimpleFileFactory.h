/*
SimpleFileFactory.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the SimpleFileFactory derived class which inherits from AbstractFileFactory
*/

#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string s) override;
};