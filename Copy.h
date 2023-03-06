#ifndef COPY_HPP
#define COPY_HPP

#include "Book.h"

using namespace std;

class Book;


class Copy : public Book {

public:
	Copy(const char* name, const char* author, int ISBN,const char* editionNumber, const char* location);
	const char* getEditionNumber();
	const char* getLocation();
private:
	const char* editionNumber;
	const char* location;
};

#endif#
