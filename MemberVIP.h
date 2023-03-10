#ifndef MEMBERVIP_HPP
#define MEMBERVIP_HPP
#include "Member.h"
#include <string>
using namespace std;

class Member;

class MemberVIP : public Member {

public:
	MemberVIP(string name, string lastname, int identificationNumber, float fee);
	float getFee();

private:
	float fee;
};

#endif

