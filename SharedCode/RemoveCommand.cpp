/*
RemoveCommand.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in RemoveCommand:
RemoveCommand() - default constructor for creating a new removeCommand object has variable system that it updates with an AbstractFileSystem*
displayInfo() - cout<< how to use Remove command
execute() - executes remove command and deletes a file based on a parameter input(string)
*/

#include "RemoveCommand.h"
#include <iostream>

RemoveCommand::RemoveCommand(AbstractFileSystem* system) : system(system) {};

void RemoveCommand::displayInfo() {
	std::cout << "removes a file from the file system" << std::endl;
	std::cout << "rm <filename>" << std::endl;
}

int RemoveCommand::execute(std::string input) {
	return system->deleteFile(input);
}