/*
CommandPrompt.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the CommandPrompt class
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>
#include <map>

class CommandPrompt {
private:
	std::map<std::string, AbstractCommand*> map;
	AbstractFileSystem* system;
	AbstractFileFactory* factory;

public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(std::string, AbstractCommand*);
	int run();

protected:
	void listCommands();
	std::string prompt();

};