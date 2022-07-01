/*
BasicDisplayVisitor.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in CopyCommand:
displayInfo() - prints an explanation of the functionality of CopyCommand
execute() - executes copy command -> copies the given file into a new file with the name provided by the user
*/

#include "TouchCommand.h"
#include "MetadataDisplayVisitor.h"
#include "CopyCommand.h"
#include "SimpleFileFactory.h"
#include <iostream>
#include <sstream>


CopyCommand::CopyCommand(AbstractFileSystem* system) : system(system) {};

void CopyCommand::displayInfo() {
	std::cout << "copy copies a file from file_to_copy to new_name_with_no_extension" << std::endl << "cp <file_to_copy> <new_name_with_no_extension>" << std::endl;
}

int CopyCommand::execute(std::string input) {
	if (input.find(" ") != std::string::npos) {
		std::istringstream iss(input);
		std::string origFile;
		iss >> origFile;
		std::string newFile;
		iss >> newFile;

		AbstractFile* filePtr = system->openFile(origFile);
		if (!filePtr) {
			return fileDoesNotExist;
		}
		else {
			AbstractFile* newFilePtr = filePtr->copy(newFile);
			if (!newFilePtr) {
				system->closeFile(filePtr);
				return creationFailed;
			}
			else if (system->addFile(newFilePtr->getName(), newFilePtr) != successs) {
				system->closeFile(filePtr);
				return insertionError;
			}
			else {
				system->closeFile(filePtr);
				return successs;
			}
		}
		
	}
	else {
		return wrongNumArgs;
	}
}