#include "Member.h"
#include <string>

using namespace std;

Member::Member(string name, string lastname, int identificationNumber){
	this->name = name;
	this->lastname = lastname;
	this->identificationNumber = identificationNumber;
	this->cantMax = 1;
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
	this->withdrawCopies.push_back(copy);
};

void Member::removeWithdrawCopyList(Copy* copy) {
	this->withdrawCopies.remove(copy);
};

list<Copy*> Member::getWithdrawCopyList() {
	return this->withdrawCopies;
}

bool  Member::checkAvailableWithdrawnCopies() {
	if (this->withdrawCopies.empty()) {
		return false;
	}
	else {
		return true;
	}
}

bool Member::CheckCant() {
	if (cantMax > withdrawCopies.size()) {
		return true;
	}
	else {
		return false;
	}
}

int Member::getCantMax() {
	return cantMax;
}