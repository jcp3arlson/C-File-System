/*
CopyCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the CopyCommand derived class which inherits from AbstractCommand
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* system;
public:
	CopyCommand(AbstractFileSystem*);
	~CopyCommand() = default;
	void displayInfo() override;
	int execute(std::string) override;
};

