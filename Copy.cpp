#include "Copy.h"
#include "Book.h"
#include <string>
//Copy::Copy(string name, string author, int ISBN,int editionNumber, string location)  : Book(name,author,ISBN) {
//	this->editionNumber = editionNumber;
//	this->location = location;
//}


Copy::Copy(Book* book, int editionNumber, string location, int stock) {
	this->book = book;
	this->editionNumber = editionNumber;
	this->location = location;
	this->stock = stock;
}

int Copy::getEditionNumber() {
	return editionNumber;
}
string Copy::getLocation() {
	return location;
}

int Copy::getStock() {
	return stock;
}