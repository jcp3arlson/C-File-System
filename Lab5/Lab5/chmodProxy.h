/*
chmodProxy.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the chmodProxy derived class which inherits from AbstractFile
*/
#pragma once

#include "../../SharedCode/AbstractFile.h"


class chmodProxy : public AbstractFile {
private:
	AbstractFile* file;
	bool isWriteable;

public:
	chmodProxy(AbstractFile*, bool);
	~chmodProxy();
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* copy(std::string name) override;
};