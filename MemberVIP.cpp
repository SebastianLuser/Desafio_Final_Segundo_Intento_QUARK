#include "MemberVIP.h"



MemberVIP::MemberVIP(const char* name, const char* lastname, int identificationNumber, float fee) : Member(name, lastname, identificationNumber) {
	this->fee =fee;
}

float  MemberVIP::getFee() {
	return fee;
}