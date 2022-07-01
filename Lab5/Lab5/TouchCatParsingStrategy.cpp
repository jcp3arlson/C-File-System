/*
TouchCatParsingStrategy.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in TouchCatParsingStrategy:
parse() - accepts a parameter input(stirng) and returns a vector<string> that has fileName +"  " + flag as vector[0] and just fileName as vector[1]
*/

#include "TouchCatParsingStrategy.h"
#include <sstream>

std::vector<std::string> TouchCatParsingStrategy::parse(std::string input) {
	std::istringstream iss(input);
	std::string fileName;
	std::string flag;
	std::vector<std::string> output;
	iss >> fileName;
	if (iss >> flag) {
		output.push_back(fileName + " " + flag);
	}
	else {
		output.push_back(fileName);
	}
	output.push_back(fileName);
	return output;
}