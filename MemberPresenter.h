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
	void setMembers(const char* name, const char* lastname, int identificationNumber, bool vip, float fee);
	void printMemberList();
	void printMember(int x);
	list<Member*> getMembers();
	list<MemberVIP*> getMembersVip();

private:
	IView* m_view = nullptr;
	list<Member*> members;
	list<MemberVIP*> membersVip;
};

#endif
