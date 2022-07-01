/*
PasswordProxy.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the PasswordProxy derived class which inherits from AbstractFile
*/
#pragma once

#include "AbstractFile.h"


class PasswordProxy : public AbstractFile {
private:
	AbstractFile* file;
	std::string password;

public:
	PasswordProxy(AbstractFile*, std::string);
	~PasswordProxy();
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
	virtual int write(std::vector<char>) override;
	virtual int append(std::vector<char>) override;
	virtual std::vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* copy(std::string name) override;
protected:
	std::string passwordPrompt();
};