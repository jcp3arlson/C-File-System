/*
chmodCommand.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in chmodCommand:
displayInfo() - cout<< a message showing a user how to use chmodCommand
execute() - executes chmodCommand (making a file either read only or writable) on a parameter of a fileName(string) returns 0 if sucessful and nonzero value if not
*/

#include "chmodCommand.h"
#include "chmodProxy.h"
#include <iostream>
#include <sstream>

chmodCommand::chmodCommand(AbstractFileSystem* system) : system(system) {};

void chmodCommand::displayInfo() {
	std::cout << "chmod makes a file either read only (-) or writable (+)" << std::endl << "chmod <filename> [+/-]" << std::endl;
}

int chmodCommand::execute(std::string fileName) {
	if (fileName.find(" ") != std::string::npos) {
		std::istringstream iss(fileName);
		std::string one;
		iss >> one;
		std::string two;
		iss >> two;
		AbstractFile* filePtr = system->openFile(one);
		if (!filePtr) {
			return fileDoesNotExist;
		}
		else if (two == "-") {// makes file read only
			AbstractFile* newFile = new chmodProxy(filePtr, false);
			system->closeFile(filePtr);
			if (system->deleteFile(filePtr->getName()) != successs) {
				return fileOpen;
			}

			if (system->addFile(newFile->getName(), newFile) != successs) {
				delete newFile;
				return insertionError;
			}
			else {
				return successs;
			}
		}
		else if (two == "+") {// makes file writeable again
			AbstractFile* newFile = new chmodProxy(filePtr, true);
			system->closeFile(filePtr);
			if (system->deleteFile(filePtr->getName()) != successs) {
				return fileOpen;
			}

			if (system->addFile(newFile->getName(), newFile) != successs) {
				delete newFile;
				return insertionError;
			}
			else {
				return successs;
			}
		}
		else {
			return badChar;
		}
	}
	else {
		return wrongNumArgs;
	}

}