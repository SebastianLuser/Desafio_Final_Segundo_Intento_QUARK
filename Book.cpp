#include "Book.h"
#include "Copy.h"
#include<iostream>
#include <string>

Book::Book(string name, string author, int ISBN) {
	this->name = name;
	this->author = author;
	this->ISBN = ISBN;
}

string Book::getName() {
	return this->name;
}

string Book::getAuthor() {
	return this->author;
}

int Book::getISBN() {
	return this->ISBN;
}

list<Copy*> Book::getCopyList() {
	return this->copyList;
}

void Book::setCopyList(int editionNumber, string location, bool available) {
	Copy* copyaux = new Copy(this->name, this->author, this->ISBN, editionNumber, location, available);
	this->copyList.push_back(copyaux);
};

Copy* Book::removeCopy(Copy* copy) {
	Copy* copyaux = new Copy(copy->getName(),copy->getAuthor(),copy->getISBN(), copy->getEditionNumber(), copy->getLocation(), copy->getAvailable() );
	this->copyList.remove(copy);
	return copyaux;
};