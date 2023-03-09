#ifndef BOOKPRESENTER_HPP
#define BOOKPRESENTER_HPP

#include "Book.h"
#include "Copy.h"
#include <List>
#include <string>
using namespace std;

class IView;

class BookPresenter {

public:
	BookPresenter(IView* view);
	void setBooks(string name, string author, int ISBN);
	void setCopies(int ISBN, int editionNumber, string location, bool available);
	void printBookList();
	void printBook(int x);
	void printCopyList(int ISBN);
	void printCopy(int ISBN, int edNr);
	Book* getBook(int ISBN);
	Copy* getCopy(string location);
	list<Book*> getBooks();
	list<Copy*> getCopies();
private:
	IView* m_view = nullptr;
	list<Book*> books;
	list<Copy*> copies;
};

#endif