#ifndef MEMBERRESENTER_HPP
#define MEMBERPRESENTER_HPP

#include "Member.h"
#include "MemberVIP.h"
#include <List>
#include <string>

using namespace std;

class IView;
class MemberPresenter {

public:
	MemberPresenter(IView* view);
	void setMembers(string name, string lastname, int identificationNumber);
	void setMembersVIP(string name, string lastname, int identificationNumber, float fee);
	void printMemberList();
	void printMemberVIPList();
	void printMember(int x);
	void printMemberVIP(int x);
	list<Member*> getMembers();
	list<MemberVIP*> getMembersVIP();

private:
	IView* m_view = nullptr;
	list<Member*> members;
	list<MemberVIP*> membersVIP;
};

#endif
