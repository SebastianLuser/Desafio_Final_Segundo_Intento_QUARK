#ifndef COPY_HPP
#define COPY_HPP

#include "Book.h"
#include <string>
using namespace std;

class Copy : public Book {

public:
	Copy(string name, string author, int ISBN, int editionNumber, string location, bool available);
	int getEditionNumber();
	int getAvailable();
	string getLocation();
	void setAvailable(bool available);
private:
	bool available = true;
	int editionNumber;
	string location;
};

#endif#
