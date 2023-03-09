#include "Copy.h"
#include "Book.h"
#include <string>

Copy::Copy(string name, string author, int ISBN, int editionNumber, string location, bool available): Book(name, author, ISBN) {
	this->editionNumber = editionNumber;
	this->location = location;
	this->available = available;
}

int Copy::getEditionNumber() {
	return editionNumber;
}
string Copy::getLocation() {
	return location;
}

int Copy::getAvailable() {
	return available;
}

void Copy::setAvailable(bool available) {
	this->available = available;
};