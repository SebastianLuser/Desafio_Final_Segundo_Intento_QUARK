#include "Member.h"
#include <string>

using namespace std;

Member::Member(string name, string lastname, int identificationNumber){
	this->name = name;
	this->lastname = lastname;
	this->identificationNumber = identificationNumber;
}

string Member::getName() {
	return name;
}

string Member::getLastname() {

	return lastname;
}

int Member::getIdentificationNumber(){
	return identificationNumber;
}

void Member::setWithdrawCopyList(Copy* copy) {
	this->retiredCopies.push_back(copy);
};