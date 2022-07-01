/*
CatCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the CatCommand derived class which inherits from AbstractCommand
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* system;
public:
	CatCommand(AbstractFileSystem*);
	~CatCommand() = default;
	void displayInfo() override;
	int execute(std::string) override;
};

