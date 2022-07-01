/*
MetadataDisplayVisitor.cpp

Brendan Long b.d.long@wustl.edu
Austin Bick a.bick@wustl.edu
Josh Pearlson jcpearlson@wustl.edu

Defintions of functions in MetadataDisplayVisitor:
visit_TextFile() - retrieves and prints the: name, filetype, filesize (for a text file)
visit_ImageFile() - retrieves and prints the: name, filetype, filesize (for an image file)
*/

#include "MetadataDisplayVisitor.h"
#include <iomanip>

void MetadataDisplayVisitor::visit_TextFile(TextFile* tFile) {
	std::string name = tFile->getName();
    int namelength = name.length();
    char size = tFile->getSize();
    for (int i = 0; i < maxFileName - namelength; ++i) {
        name.append(" ");
    }
    std::string type = "text";
    int typelength = type.length();
    for (int i = 0; i < maxFileType - typelength; ++i) {
        type.append(" ");
    }
    std::cout << name << type << std::setw(4) << +size << std::endl;

}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {

	std::string name = file->getName();
    int namelength = name.length();
    char size = file->getSize();
    for (int i = 0; i < maxFileName - namelength; ++i) {
        name.append(" ");
    }
    std::string type = "image";
    int typelength = type.length();
    for (int i = 0; i < maxFileType - typelength; ++i) {
        type.append(" ");
    }
    std::cout << name << type << std::setw(4) << +size << std::endl;
    
}