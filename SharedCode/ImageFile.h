/*
ImageFile.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the ImageFile derived class which inherits from AbstractFile
*/

#pragma once
// Image file class declaration here

#include "AbstractFile.h"
#include <vector>
#include <string>

class ImageFile : public AbstractFile {
private:
	std::vector<char> contents;
	std::string name;
	char size;

public:
	ImageFile(std::string);
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* copy(std::string) override;
};