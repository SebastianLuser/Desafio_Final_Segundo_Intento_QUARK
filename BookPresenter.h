#ifndef BOOKPRESENTER_HPP
#define BOOKPRESENTER_HPP

#include "Book.h"
#include "Copy.h"
#include <List>

using namespace std;

class IView;

class BookPresenter {

public:
	BookPresenter(IView* view);
	void setBooks(const char* name, const char* author, int ISBN);
	void setCopys(int ISBN, int editionNumber, const char* location, int stock);
	void printBookList();
	void printBook(int x);
	void printCopyList(int ISBN);
	void printCopy(int ISBN, int edNr);
	Book* getBook(int ISBN);
	list<Book*> getBooks();
	list<Copy*> getCopys();
private:
	IView* m_view = nullptr;
	list<Book*> books;
	list<Copy*> copies;
};

#endif