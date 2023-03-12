#ifndef BOOK_HPP
#define BOOK_HPP
#include <string> 
#include <List>
using namespace std;

class Copy;

class Book {

public:
	Book(string name, string author, int ISBN);
	string getName();
	string getAuthor();
	int getISBN();
	void setCopyList(int editionNumber, string location, bool available);
	list<Copy*> getCopyList();
	Copy* removeCopy(Copy* copy);
protected:
	string name;
	string author;
	int ISBN;
private:
	list<Copy*> copyList;
};

#endif

