#include "MemberVIP.h"
#include <string>


MemberVIP::MemberVIP(string name, string lastname, int identificationNumber, float fee) : Member(name, lastname, identificationNumber) {
	this->fee =fee;
}

float  MemberVIP::getFee() {
	return fee;
}