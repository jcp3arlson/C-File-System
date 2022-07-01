/*
RenameParsingStrategy.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in RenameParsingStrategy:
parse() - accepts a parameter input(stirng) and returns a vector<string> that has the whole user input as vector[0] and just existingName as vector[1]
*/

#include "RenameParsingStrategy.h"
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
	std::istringstream iss(input);
	std::string existingName;
	std::string newName;
	iss >> existingName;
	iss >> newName;
	std::vector<std::string> output;
	output.push_back(input);
	output.push_back(existingName);
	return output;
}