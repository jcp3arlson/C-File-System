/*
AbstractParsingStrategy.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the AbstractParsingStrategy base class
*/

#pragma once
#include <string>
#include <vector>

class AbstractParsingStrategy {
public:
	virtual ~AbstractParsingStrategy() = default;
	virtual std::vector<std::string> parse(std::string) = 0;
};