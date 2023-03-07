#include "BookPresenter.h"
#include "Copy.h"
#include "Book.h"
#include <List>
#include <iostream>

BookPresenter::BookPresenter() {
	list<Book*> books;
	list<Copy*> copys;
}
void BookPresenter::setBooks(const char* name, const char* author, int ISBN) {
	books.push_back(new Book(name, author, ISBN));
}

void BookPresenter::setCopys(const char* name, const char* author, int ISBN, int editionNumber, const char* location) {

	this->copys.push_back(new Copy(name, author, ISBN, editionNumber, location));
}

list<Book*>BookPresenter::getBooks() {
	return this->books;
}

list<Copy*>BookPresenter::getCopys() {
	return this->copys;
}