#ifndef BOOK_HPP
#define BOOK_HPP
#include <string> 
#include <List>
using namespace std;


class Book {

friend class Copy;

public:
	Book(string name, string author, int ISBN);
	string getName();
	string getAuthor();
	int getISBN();
	list<Copy*> getCopyList();
private:
	string name;
	string author;
	int ISBN;
	list<Copy*> copyList;
};

#endif

