/*
AbstractFileVisitor.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the AbstractFileVisitor base class
*/

#pragma once

#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <vector>


// declaration of the file visitor interface here
class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile*) = 0;
	virtual void visit_ImageFile(ImageFile*) = 0;
};