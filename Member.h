#ifndef MEMBER_HPP
#define MEMBER_HPP

#include "Book.h"
#include <List>
#include <iostream>
#include <string>
using namespace std;

class Member {

public:
	Member(string name,string lastname,int identificationNumber);
	string getName();
	string getLastname();
	int getIdentificationNumber();
	void setWithdrawCopyList(Copy* copy);
	
protected:
	string name;
	string lastname;
	int identificationNumber;
	list<Copy*> retiredCopies;

private :
	const int cantMax = 1;
};

#endif#
