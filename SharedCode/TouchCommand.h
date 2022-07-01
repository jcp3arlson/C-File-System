/*
TouchCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the TouchCommand derived class which inherits from AbstractCommand
*/

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* system;
	AbstractFileFactory* factory;

public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	~TouchCommand() = default;
	void displayInfo() override;
	int execute(std::string) override;
};