/*
chmodCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the chmodCommand derived class which inherits from AbstractCommand
*/

#pragma once
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractFileSystem.h"

class chmodCommand : public AbstractCommand {
private:
	AbstractFileSystem* system;

public:
	chmodCommand(AbstractFileSystem*);
	~chmodCommand() = default;
	void displayInfo() override;
	int execute(std::string) override;
};