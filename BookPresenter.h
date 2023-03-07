#ifndef BOOKPRESENTER_HPP
#define BOOKPRESENTER_HPP

#include "Book.h"
#include "Copy.h"
#include <List>

using namespace std;

class BookPresenter {

public:
	BookPresenter();
	void setBooks(const char* name, const char* author, int ISBN);
	void setCopys(const char* name, const char* author, int ISBN, int editionNumber, const char* location);
	list<Book*> getBooks();
	list<Copy*> getCopys();
private:
	list<Book*> books;
	list<Copy*> copys;
};

#endif