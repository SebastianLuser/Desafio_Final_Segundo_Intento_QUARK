#include "Member.h"

using namespace std;

Member::Member(const char* name, const char* lastname, int identificationNumber){
	this->name = name;
	this->lastname = lastname;
	this->identificationNumber = identificationNumber;
}

const char* Member::getName() {
	return name;
}

const char* Member::getLastname() {

	return lastname;
}

int Member::getIdentificationNumber(){
	return identificationNumber;
}
