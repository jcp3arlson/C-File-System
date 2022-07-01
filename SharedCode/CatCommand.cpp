/*
CatCommand.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in CatCommand:
displayInfo() - prints an explanation of the functionality of CatCommand
execute() - executes cat command -> prompts the user data to either concatenate or append based on the users input which initiated the command
*/

#include "MetadataDisplayVisitor.h"
#include "CatCommand.h"
#include <iostream>
#include <sstream>


CatCommand::CatCommand(AbstractFileSystem* system) : system(system) {};

void CatCommand::displayInfo() {
	std::cout << "cat writes data to a file, -a appends the data instead of overwriting the file" << std::endl;
	std::cout << "cat <filename> [-a]" << std::endl;
};

int CatCommand::execute(std::string input) {
	if (input.find(" ") != std::string::npos) {
		std::istringstream iss(input);
		std::string fileName;
		iss >> fileName;
		std::string flag;
		iss >> flag;
		if (flag == "-a") {
			AbstractFile* filePtr = system->openFile(fileName);
			if (filePtr) {
				std::vector<char> contents = filePtr->read();
				for (char c : contents) {
					std::cout << c;
				}
				std::cout << std::endl;
				std::cout << "Enter data you would like to append to the file. Enter :wq to save and exit; enter :q to exit without saving." << std::endl;
				std::string line;
				std::vector<char> newContents;
				while (true) {
					std::getline(std::cin, line);
					if (line == ":q") {
						return successs;
					}
					else if (line == ":wq") {
						newContents.pop_back();
						int returnVal = filePtr->append(newContents);
						if (returnVal != successs) {
							system->closeFile(filePtr);
							return returnVal;
						}
						else {
							return system->closeFile(filePtr);
						}
					}
					else {
						line.append("\n");
						for (char c : line) {
							newContents.push_back(c);
						}
					}
				}
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
		std::cout << "Enter data you would like to write to the file. Enter :wq to save and exit; enter :q to exit without saving." << std::endl;
		std::vector<char> data;
		std::string line;
		while (true) {
			std::getline(std::cin, line);
			if (line == ":q") {
				return successs;
			}
			else if (line == ":wq") {
				data.pop_back();
				AbstractFile* filePtr = system->openFile(input);
				if (filePtr) {
					int returnVal = filePtr->write(data);
					if (returnVal != successs) {
						system->closeFile(filePtr);
						return returnVal;
					}
					else {
						return system->closeFile(filePtr);
					}
				}
				else {
					return fileDoesNotExist;
				}
			}
			else {
				line.append("\n");
				for (char c : line) {
					data.push_back(c);
				}
			}
		}
	
	}
};