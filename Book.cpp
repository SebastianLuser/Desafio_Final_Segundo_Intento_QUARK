#include "Book.h"

Book::Book(const char* name, const char* author, int ISBN) {
	this->name = name;
	this->author = author;
	this->ISBN = ISBN;
}

const char* Book::getName() {
	return name;
}

const char* Book::getAuthor() {
	return author;
}

int Book::getISBN() {
	return ISBN;
}