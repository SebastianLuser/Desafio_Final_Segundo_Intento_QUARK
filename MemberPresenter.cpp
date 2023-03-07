#include "MemberPresenter.h"
#include "Member.h"
#include "IView.h"
#include <List>
#include <iostream>
#include <string> 

MemberPresenter::MemberPresenter(IView* view) : m_view(view) {
	list<Member*> members;
	list<MemberVIP*> membersVIP;
}
void MemberPresenter::setMembers(string name, string lastname, int identificationNumber) {
	this->members.push_back(new Member(name, lastname,  identificationNumber));
}

void MemberPresenter::setMembersVIP(string name, string lastname, int identificationNumber, float fee) {
	this->membersVIP.push_back(new MemberVIP(name, lastname, identificationNumber, fee));
}

list<Member*>MemberPresenter::getMembers() {
	return this->members;
}
void MemberPresenter::printMemberList() {
	for (Member* member : this->members) {
		string s01 = member->getName();
		string s02 = member->getLastname();
		string s03 = to_string(member->getIdentificationNumber());
		m_view->showText("El socio Clasico ingresado tiene los siguientes datos:");
		m_view->showText("	Nombre: " + s01);
		m_view->showText("	Apellido: " + s02);
		m_view->showText("	Numero de identificacion: " + s03);
	}
};
void MemberPresenter::printMember(int x) {
	for (Member* member : this->members) {
		if (member->getIdentificationNumber() == x) {
			string s01 = member->getName();
			string s02 = member->getLastname();
			string s03 = to_string(member->getIdentificationNumber());
			m_view->showText("El socio Clasico ingresado tiene los siguientes datos:");
			m_view->showText("	Nombre: " + s01);
			m_view->showText("	Apellido: " + s02);
			m_view->showText("	Numero de identificacion: " + s03);
		}
	}
};

list<MemberVIP*>MemberPresenter::getMembersVIP() {
	return this->membersVIP;
}
void MemberPresenter::printMemberVIPList() {
	for (MemberVIP* memberVIP : this->membersVIP) {
		string s01 = memberVIP->getName();
		string s02 = memberVIP->getLastname();
		string s03 = to_string(memberVIP->getIdentificationNumber());
		string s04 = to_string(memberVIP->getFee());
		m_view->showText("El socio VIP ingresado tiene los siguientes datos:");
		m_view->showText("	Nombre: " + s01);
		m_view->showText("	Apellido: " + s02);
		m_view->showText("	Numero de identificacion: " + s03);
		m_view->showText("	Costo mensual: $" + s04);
	}
};
void MemberPresenter::printMemberVIP(int x) {
	for (MemberVIP* memberVIP : this->membersVIP) {
		if (memberVIP->getIdentificationNumber() == x) {
			string s01 = memberVIP->getName();
			string s02 = memberVIP->getLastname();
			string s03 = to_string(memberVIP->getIdentificationNumber());
			string s04 = to_string(memberVIP->getFee());
			m_view->showText("El socio VIP ingresado tiene los siguientes datos:");
			m_view->showText("	Nombre: " + s01);
			m_view->showText("	Apellido: " + s02);
			m_view->showText("	Numero de identificacion: " + s03);
			m_view->showText("	Costo mensual: $" + s04);
		}
	}
};