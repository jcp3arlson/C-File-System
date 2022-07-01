/*
MetadataDisplayVisitor.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the MetadataDisplayVisitor derived class which inherits from AbstractFileVisitor
*/

#pragma once

#include "AbstractFileVisitor.h"

// declaration of MetadataDisplayVisitor here
class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	void visit_TextFile(TextFile*) override;
	void visit_ImageFile(ImageFile*) override;
};