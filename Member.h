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
	int getCantMax();
	int getIdentificationNumber();
	void setWithdrawCopyList(Copy* copy);
	void removeWithdrawCopyList(Copy* copy);
	list<Copy*>getWithdrawCopyList();
	bool CheckCant();
	
protected:
	string name;
	string lastname;
	int identificationNumber;
	list<Copy*> withdrawCopies;
	int cantMax;

};

#endif#
