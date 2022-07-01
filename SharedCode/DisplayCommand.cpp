/*
DisplayCommand.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in DisplayCommand:
displayInfo() - prints an explanation of the functionality of DisplayCommand
execute() - executes display command -> displays the file formatted as it should be given its file type, or raw if the user specifies.
*/
#include "DisplayCommand.h"
#include <iostream>
#include "BasicDisplayVisitor.h"
#include <sstream>

DisplayCommand::DisplayCommand(AbstractFileSystem* system) : system(system) {};

void DisplayCommand::displayInfo() {
	std::cout << "ds displays a file, -d leaves the data unformatted" << std::endl << "ds <filename> [-d]" << std::endl;
}

int DisplayCommand::execute(std::string input) {
	if (input.find(" ") != std::string::npos) {
		std::istringstream iss(input);
		std::string fileName;
		std::string tag;
		iss >> fileName;
		iss >> tag;
		if (tag == "-d") {
			AbstractFile* file = system->openFile(fileName);
			if (file) {
				std::vector<char> contents = file->read();
				for (char c : contents) {
					std::cout << c;
				}
				std::cout << std::endl;
				return system->closeFile(file);
			}
			else {
				return fileDoesNotExist;
			}

		}
		else {
			return commandDNE;
		}
	}
	else {
		AbstractFile* file = system->openFile(input);
		if (file) {
			BasicDisplayVisitor visitor;
			file->accept(&visitor);
			return system->closeFile(file);
		}
		else {
			return fileDoesNotExist;
		}

	}
}
