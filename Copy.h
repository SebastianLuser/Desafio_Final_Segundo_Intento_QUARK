#ifndef COPY_HPP
#define COPY_HPP

#include "Book.h"
#include <string>
using namespace std;

class Copy {

public:
	Copy(Book* book, int editionNumber, string location, int stock);
	int getEditionNumber();
	int getStock();
	string getLocation();
private:
	int stock;
	Book* book;
	int editionNumber;
	string location;
};

#endif#
