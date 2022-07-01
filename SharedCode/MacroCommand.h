/*
MacroCommand.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the MacroCommand derived class which inherits from AbstractCommand
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand : public AbstractCommand {
private:
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strategy;

public:

	MacroCommand() = default;
	MacroCommand(AbstractFileSystem*);
	virtual void displayInfo() override;
	virtual int execute(std::string) override;
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);

};
