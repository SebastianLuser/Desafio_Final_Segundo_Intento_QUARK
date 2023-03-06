#include "Copy.h"
#include "Book.h"

Copy::Copy(const char* name, const char* author, int ISBN,const char* editionNumber, const char* location)  : Book(name,author,ISBN) {
	this->editionNumber = editionNumber;
	this->location = location;

}
const char* Copy::getEditionNumber() {
	return editionNumber;
}
const char* Copy::getLocation() {
	return location;
}