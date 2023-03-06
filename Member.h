#ifndef MEMBER_HPP
#define MEMBER_HPP

#include "Book.h"
#include <List>
#include <iostream>
using namespace std;

class Member {

friend class MemberVIP;
public:
	Member(const char* name,const char* lastname,int identificationNumber);
	const char* getName();
	const char* getLastname();
	int getIdentificationNumber();
	
protected:
	const char* name;
	const char* lastname;
	int identificationNumber;
	list<Book*> retiredBooks;

private :
	const int cantMax = 1;
};

#endif#
