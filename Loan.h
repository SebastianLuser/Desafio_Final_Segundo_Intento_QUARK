#pragma once
#ifndef LOAN_HPP
#define LOAN_HPP
#include <string> 
#include "Copy.h"
#include "Member.h"
#include "MemberVIP.h"
using namespace std;

class Copy;
class Member;
class MemberVIP;
class Loan {
public:
	Loan(Copy* copy, Member* member, string date);
	Loan(Copy* copy, MemberVIP* memberVIP, string date);

	void setCopy(Copy* copy);
	void setMember(Member* member);
	void setMember(MemberVIP* memberVIP);
	void setDate(string date);

	Copy* getCopy();
	Member* getMember();
	MemberVIP* getMemberVIP();
	string getDate();
	bool getStatus();
private:
	Copy* copy;
	Member* member;
	MemberVIP* memberVIP;
	string date;
	bool status;
};

#endif

