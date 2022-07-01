/*
RemoveCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the RemoveCommand derived class which inherits from AbstractCommand
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* system;
public:
	RemoveCommand(AbstractFileSystem*);
	~RemoveCommand() = default;
	void displayInfo() override;
	int execute(std::string) override;
};

