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
	int verifyAvailable(int identificationNumber);
	void setMembers(string name, string lastname, int identificationNumber);
	void setMembersVIP(string name, string lastname, int identificationNumber, float fee);
	void setWithdrawnCopies(Copy* copy, int identificationNumber);
	void printMemberList();
	void printMemberVIPList();
	void printMember(int x);
	void printMemberVIP(int x);
	list<Member*> getMembers();
	list<MemberVIP*> getMembersVIP();
	void printWithdrawnCopies(int identificationNumber);
	Member* getMember(int identificationNumber);
	MemberVIP* getMemberVIP(int identificationNumber);
	bool CheckAvailability(int identificationNumber);
	void removeWithdrawnCopies(Copy* copy, int identificationNumber);
	bool checkWithdrawCopy(string location, int identificacionNumber);
	Copy* getWithdrawnCopy(string location, int identificationNumber);
	bool checkAvailableMembers();
	bool checkAvailableMembersVIP();


private:
	IView* m_view = nullptr;
	list<Member*> members;
	list<MemberVIP*> membersVIP;
};

#endif