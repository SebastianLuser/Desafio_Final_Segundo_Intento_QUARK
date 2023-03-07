#ifndef COPY_HPP
#define COPY_HPP

#include "Book.h"

using namespace std;

class Book;


class Copy : public Book {

public:
	Copy(const char* name, const char* author, int ISBN,int editionNumber, const char* location);
	int getEditionNumber();
	const char* getLocation();
private:
	int editionNumber;
	const char* location;
};

#endif#
