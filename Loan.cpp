#include "Loan.h"
#include "Copy.h"
#include "Member.h"
#include "MemberVIP.h"
#include<iostream>
#include <string>

Loan::Loan(Copy* copy, Member* member, string date) {
	this->copy = copy;
	this->member = member;
	this->date = date;
}
Loan::Loan(Copy* copy, MemberVIP* memberVIP, string date) {
	this->copy = copy;
	this->memberVIP = memberVIP;
	this->date = date;
}

void Loan::setCopy(Copy* copy) {
	this->copy = copy;
}
void Loan::setMember(Member* member) {
	this->member = member;
}
void Loan::setMember(MemberVIP* memberVIP) {
	this->memberVIP = memberVIP;
}
void Loan::setDate(string date) {
	this->date = date;
}

Copy* Loan::getCopy() {
	return this->copy;
}
Member* Loan::getMember() {
	return this->member;
}
MemberVIP* Loan::getMemberVIP() {
	return this->memberVIP;
}
string Loan::getDate() {
	return this->date;
}