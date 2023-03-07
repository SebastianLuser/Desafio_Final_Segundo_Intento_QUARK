#ifndef BOOK_HPP
#define BOOK_HPP

using namespace std;

class Book {
	/*friend class Copy;*/
public:
	Book(const char* name, const char* author, int ISBN);
	const char* getName();
	const char* getAuthor();
	int getISBN();
private:
	const char* name;
	const char* author;
	int ISBN;
};

#endif

