/*
RenameParsingStrategy.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the RenameParsingStrategy derived class which inherits from AbstractParsingStrategy
*/

#pragma once

#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual ~RenameParsingStrategy() = default;
	virtual std::vector<std::string> parse(std::string) override;
};