#ifndef MEMBER_HPP
#define MEMBER_HPP

#include "Book.h"
#include <List>
#include <iostream>
#include <string>
using namespace std;

class Member {

friend class MemberVIP;
public:
	Member(string name,string lastname,int identificationNumber);
	string getName();
	string getLastname();
	int getIdentificationNumber();
	
protected:
	string name;
	string lastname;
	int identificationNumber;
	list<Book*> retiredBooks;

private :
	const int cantMax = 1;
};

#endif#
