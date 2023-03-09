#include "Copy.h"
#include "Book.h"
#include <string>

Copy::Copy(Book* book, int editionNumber, string location, bool available) {
	this->book = book;
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