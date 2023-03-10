#include "MemberPresenter.h"
#include "Member.h"
#include "Copy.h"
#include "IView.h"
#include <List>
#include <iostream>
#include <string> 

MemberPresenter::MemberPresenter(IView* view) : m_view(view) {
	list<Member*> members;
	list<MemberVIP*> membersVIP;
}

bool MemberPresenter::verifyAvailable(int identificationNumber) {
	for (Member* member : this->members) {
		if (member->getIdentificationNumber() == identificationNumber) {
			return true;
		}
	}
	for (MemberVIP* memberVIP : this->membersVIP) {
		if (memberVIP->getIdentificationNumber() == identificationNumber) {
			return true;
		}
	}
	return false;
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


Member* MemberPresenter::getMember(int identificationNumber) {
	for (Member* member : this->members) {
		if (member->getIdentificationNumber() == identificationNumber) {
			return member;
		}
	}
}

MemberVIP* MemberPresenter::getMemberVIP(int identificationNumber) {
	for (MemberVIP* memberVIP : this->membersVIP) {
		if (memberVIP->getIdentificationNumber() == identificationNumber) {
			return memberVIP;
		}
	}
}

void MemberPresenter::setWithdrawnCopies(Copy* copy , int identificationNumber, int typeM) {
	if (typeM == 1) {
		this->getMember(identificationNumber)->setWithdrawCopyList(copy);
	}
	else if (typeM == 2) {
		this->getMemberVIP(identificationNumber)->setWithdrawCopyList(copy);
	}
}


list<Copy*>MemberPresenter::getWithdrawnCopies() {
	return this->withdrawnCopies;
}

//int MemberPresenter::getTypeMember() {
//
//	return cantMax;
//}
//
//void MemberPresenter::CheckCant(int cantMax) {
//	for (Copy* copy : withdrawnCopies) {
//		if (cantMax <= withdrawnCopies.size()) {
//			
//		}
//
//	}
//}


void MemberPresenter::printWithdrawnCopies() {
	m_view->showText("---------------------------------------------------");
	m_view->showText("Los ejemplares retirados por este Socio son:");
	for (Copy* copy : this->withdrawnCopies) {
		string s01 = copy->getName();
		string s02 = copy->getAuthor();
		string s03 = to_string(copy->getISBN());
		string s04 = to_string(copy->getEditionNumber());
		string s05 = copy->getLocation();
		m_view->showText("El Ejemplar tiene los siguientes datos:");
		m_view->showText("	Nombre: " + s01);
		m_view->showText("	Autor: " + s02);
		m_view->showText("	ISBN: " + s03);
		m_view->showText("	Numero de Edicion: " + s04);
		m_view->showText("	Locacion: " + s05);
	}
	m_view->showText("---------------------------------------------------");
}