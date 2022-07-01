/*
AbstractFile.h

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Declaration of the AbstractFile base class
*/

#pragma once

#include <vector>
#include <string>

class AbstractFileVisitor;
enum ReturnVals { successs, wrongSize, badChar, illegalProccess, fileExists, nullFile, invalidExtension, fileNotOpen, fileDoesNotExist, fileOpen, passwordFail, insertionError, quit, creationFailed, commandDNE, wrongNumArgs, fileOnlyReadable};
enum constants { maxFileName = 20, maxFileType = 10};

class AbstractFile {
public:
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char>) = 0;
	virtual int append(std::vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* copy(std::string) = 0;
};