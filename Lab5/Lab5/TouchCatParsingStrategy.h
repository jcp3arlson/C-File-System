/*
TouchCatParsingStrategy.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the TouchCatParsingStrategy derived class which inherits from AbstractParsingStrategy
*/

#pragma once

#include "../../SharedCode/AbstractParsingStrategy.h"

class TouchCatParsingStrategy : public AbstractParsingStrategy {
public:
	virtual ~TouchCatParsingStrategy() = default;
	virtual std::vector<std::string> parse(std::string) override;
};