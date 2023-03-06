#ifndef MEMBERVIP_HPP
#define MEMBERVIP_HPP
#include "Member.h"
using namespace std;

class Member;

class MemberVIP : public Member {

public:
	MemberVIP(const char* name, const char* lastname, int identificationNumber, float fee);
	float getFee();

private:
	float fee;
	const int cantMax = 3;
};

#endif#

