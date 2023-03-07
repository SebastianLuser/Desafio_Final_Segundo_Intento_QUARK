#include "Copy.h"
#include "Book.h"

//Copy::Copy(const char* name, const char* author, int ISBN,int editionNumber, const char* location)  : Book(name,author,ISBN) {
//	this->editionNumber = editionNumber;
//	this->location = location;
//}


Copy::Copy(Book* book, int editionNumber, const char* location, int stock) {
	this->book = book;
	this->editionNumber = editionNumber;
	this->location = location;
	this->stock = stock;
}

int Copy::getEditionNumber() {
	return editionNumber;
}
const char* Copy::getLocation() {
	return location;
}

int Copy::getStock() {
	return stock;
}