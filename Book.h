#ifndef BOOK_HPP
#define BOOK_HPP
#include <string> 
using namespace std;

class Book {
public:
	Book(string name, string author, int ISBN);
	string getName();
	string getAuthor();
	int getISBN();
private:
	string name;
	string author;
	int ISBN;
};

#endif

