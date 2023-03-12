#include "Loan.h"
#include "Copy.h"
#include "Member.h"
#include "MemberVIP.h"
#include<iostream>
#include <string>

#include <chrono>
#include <ctime>
#include <stdio.h>

Loan::Loan(Copy* copy, Member* member, string date) {
	time_t value = time(NULL);
	char buff[26];
	ctime_s(buff, sizeof buff, &value);

	this->copy = copy;
	this->member = member;
	this->date = buff;
	if (this->copy->getAvailable()) {
		this->status = false;
	}else {
		this->status = true;
	}
}
Loan::Loan(Copy* copy, MemberVIP* memberVIP, string date) {
	time_t value = time(NULL);
	char buff[26];
	ctime_s(buff, sizeof buff, &value);

	this->copy = copy;
	this->memberVIP = memberVIP;
	this->date = buff;
	if (this->copy->getAvailable()) {
		this->status = false;
	}
	else {
		this->status = true;
	}

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

bool Loan::getStatus() {
	return this->status;
};