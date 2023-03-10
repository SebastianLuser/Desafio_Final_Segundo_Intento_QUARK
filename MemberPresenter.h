#ifndef MEMBERPRESENTER_HPP
#define MEMBERPRESENTER_HPP

#include "Member.h"
#include "MemberVIP.h"
#include "Copy.h"
#include <List>
#include <string>

using namespace std;

class IView;
class MemberPresenter {

public:
	MemberPresenter(IView* view);
	bool verifyAvailable(int identificationNumber);
	void setMembers(string name, string lastname, int identificationNumber);
	void setMembersVIP(string name, string lastname, int identificationNumber, float fee);
	void setWithdrawnCopies(Copy* copy, int identificationNumber, int typeM);
	void printMemberList();
	void printMemberVIPList();
	void printMember(int x);
	void printMemberVIP(int x);
	list<Member*> getMembers();
	list<MemberVIP*> getMembersVIP();
	list <Copy*> getWithdrawnCopies();
	void printWithdrawnCopies();
	int getTypeMember();
	void CheckCant(int cantMax);
	Member* getMember(int identificationNumber);
	MemberVIP* getMemberVIP(int identificationNumber);

private:
	IView* m_view = nullptr;
	list<Member*> members;
	list<MemberVIP*> membersVIP;
	list <Copy*> withdrawnCopies;
};

#endif