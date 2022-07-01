/*
LSCommand.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in LSCommand:
displayInfo() - prints an explanation of the functionality of LSCommand
execute() - executes list command -> prints a list of the file names of the files in our system, along with the metadata if the user specifies.
*/

#include "LSCommand.h"
#include "MetadataDisplayVisitor.h"
#include <iostream>

LSCommand::LSCommand(AbstractFileSystem* system) : system(system) {};

void LSCommand::displayInfo() {
	std::cout << "ls displays the files in the file system, -m displays each file's associated metadata" << std::endl;
	std::cout << "ls [-m]" << std::endl;
}

int LSCommand::execute(std::string string) {
	std::set<std::string> s = system->getFileNames();
	if (string == "-m") {
		for (auto it = s.begin(); it != s.end(); ++it) {
			std::string fileName = *it;
			AbstractFile* filePtr = system->openFile(fileName);
			if (!filePtr) {
				return fileDoesNotExist;
			}
			MetadataDisplayVisitor display;
			filePtr->accept(&display);
			int returnVal = system->closeFile(filePtr);
			if (returnVal != successs) {
				return returnVal;
			}
		}
	}
	else {
		int counter = 0;
		for (auto it = s.begin(); it != s.end(); ++it) {
			std::string fileName = *it;
			int length = fileName.length();
			for (int i = 0; i < maxLength - length; ++i) {
				fileName.append(" ");
			}
			std::cout << fileName;
			++counter;
			if (counter == 2) {
				std::cout << std::endl;
				counter = 0;
			}

		}
		if (counter == 1) {
			std::cout << std::endl;
		}

	}
	return successs;
}