/*
TouchCommand.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in TouchCommand:
displayInfo() - cout<< a message showing a user how to use touchCommand
execute() - executes touch command on a parameter of a fileName(string) returns 0 if sucessful and nonzero value if not
*/

#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <iostream>
#include <sstream>

TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory) : system(system), factory(factory) {};

void TouchCommand::displayInfo() {
	std::cout << "touch creates a file" << std::endl << "touch <filename>" << std::endl;
}

int TouchCommand::execute(std::string fileName) {
	if (fileName.find(" ") != std::string::npos) {
		std::istringstream iss(fileName);
		std::string one;
		iss >> one;
		std::string two;
		iss >> two;
		AbstractFile* filePtr = factory->createFile(one);
		if (!filePtr) {
			return creationFailed;
		}
		else if (two == "-p") {
			std::cout << "Choose a password for this file:\n";
			std::string pword;
			std::getline(std::cin, pword);
			AbstractFile* prot = new PasswordProxy(filePtr, pword);
			if (system->addFile(one, prot) != successs) {
				delete prot;
				return insertionError;
			}
			else {
				return successs;
			}
		}
		else {
			return creationFailed;
		}
	}
	else {
		AbstractFile* filePtr = factory->createFile(fileName);
		if (!filePtr) {
			return creationFailed;
		}
		else {
			if (system->addFile(fileName, filePtr) != successs) {
				delete filePtr;
				return insertionError;
			}
			else {
				return successs;
			}
		}
	}
	
}