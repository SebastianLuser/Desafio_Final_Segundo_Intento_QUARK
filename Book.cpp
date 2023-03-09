#include "Book.h"
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