/*
CommandPrompt.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Definitions of functions in CommandPrompt:
setFileSystem() - sets the file system for this specific commandprompt
setFileFactory() - sets the file factory for this specific commandprompt
addCommand() - adds a new command (such as TouchCommand, CatCommand, etc.) into this commandprompt
run() - runs the command prompt, awaiting input to create, edit, delete or dislay files
*/
#include "CommandPrompt.h"
#include "AbstractCommand.h"
#include <iostream>
#include <sstream>

CommandPrompt::CommandPrompt() : system(nullptr), factory(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* s) {
	system = s;
};

void CommandPrompt::setFileFactory(AbstractFileFactory* f) {
	factory = f;
};

int CommandPrompt::addCommand(std::string s, AbstractCommand* c) {
	if (map.insert(std::pair<std::string, AbstractCommand*>{s, c}).second) {
		return successs;
	}
	else {
		return insertionError;
	}
	
};

void CommandPrompt::listCommands() {
	for (auto it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
	}
};

std::string CommandPrompt::prompt() {
	std::cout << "$ ";
	std::string s;
	std::getline(std::cin, s);
	return s;
};

int CommandPrompt::run() {
	std::cout << "Enter a command, q to quit, help for a list of commands, help followed by a command name for more information about that command." << std::endl;
	while (1) {
		std::string command = prompt();
		if (command == "q") {
			return quit;
		}
		else if (command == "help") {
			listCommands();
		}
		else if (command.find(" ") == std::string::npos) {
			auto it = map.find(command);
			if (it != map.end()) {
				int i = it->second->execute("");
				if (i != 0) {
					std::cout << "Could not execute command" << std::endl;
				}
			}
			else {
				std::cout << "Command does not exist: " << command.length() << std::endl;
			}
			
		}
		else {
			std::istringstream iss(command);
			std::string one;
			iss >> one;
			if (one == "help") {
				std::string two;
				iss >> two;
				auto it = map.find(two);
				if (it != map.end()) {
					it->second->displayInfo();
				}
				else {
					std::cout << "Command does not exist:" << one.length() << std::endl;
				}
			}
			else {
				std::string rest;
				std::string temp;
				iss >> rest;
				while (iss >> temp) {
					rest.append(" ");
					rest.append(temp);
				};
				auto it = map.find(one);
				if (it != map.end()) {
					int i = it->second->execute(rest);
					if (i != 0) {
						std::cout << "Could not execute command" << std::endl;
					}
				}
				else {
					std::cout << "Command does not exist: " << one.length() << std::endl;
				}
			}
		}


	}
};
