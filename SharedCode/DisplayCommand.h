/*
DisplayCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the DisplayCommand derived class which inherits from AbstractCommand
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {

private:
	AbstractFileSystem* system;

public:
	DisplayCommand(AbstractFileSystem*);
	~DisplayCommand() = default;
	void displayInfo() override;
	int execute(std::string) override;
};