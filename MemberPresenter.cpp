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

	//MEMBER
	//string s01 = "Gaspar";
	//string s02 = "O";
	//int s03 = 1;
	//this->setMembers(s01, s02, s03);

	//MEMBER VIP
	//string s04 = "Sebastian";
	//string s05 = "L";
	//int s06 = 2;
	//float s07 = 200.1;
	//this->setMembersVIP(s04, s05, s06, s07);
}

int  MemberPresenter::verifyAvailable(int identificationNumber) {
	for (Member* member : this->members) {
		if (member->getIdentificationNumber() == identificationNumber) {
			return 1;
		}
	}
	for (MemberVIP* memberVIP : this->membersVIP) {
		if (memberVIP->getIdentificationNumber() == identificationNumber) {
			return 2;
		}
	}
	return 0;
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
	try {
		if (this->checkAvailableMembers()==true) {

			for (Member* member : this->members) {
				string s01 = member->getName();
				string s02 = member->getLastname();
				string s03 = to_string(member->getIdentificationNumber());
				m_view->showText("El socio Clasico ingresado tiene los siguientes datos:");
				m_view->showText("	Nombre: " + s01);
				m_view->showText("	Apellido: " + s02);
				m_view->showText("	Numero de identificacion: " + s03);
			}
		}
		else {
			throw ("No hay Miembros existentes");
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
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
	try {
		if (this->checkAvailableMembers() == true) {
			for (MemberVIP* memberVIP : this->membersVIP) {
				if (memberVIP->getIdentificationNumber() == x) {
					string s01 = memberVIP->getName();
					string s02 = memberVIP->getLastname();
					string s03 = to_string(memberVIP->getIdentificationNumber());
					string s04 = to_string(memberVIP->getFee());
					string s05 = to_string(memberVIP->getCantMax());
					m_view->showText("El socio VIP ingresado tiene los siguientes datos:");
					m_view->showText("	Nombre: " + s01);
					m_view->showText("	Apellido: " + s02);
					m_view->showText("	Numero de identificacion: " + s03);
					m_view->showText("	Costo mensual: $" + s04);
				}
			}
		}
		else {
			throw ("No hay Miembros VIP existentes");
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
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

void MemberPresenter::setWithdrawnCopies(Copy* copy , int identificationNumber) {
	if (verifyAvailable(identificationNumber) == 1) {
		this->getMember(identificationNumber)->setWithdrawCopyList(copy);
	}
	else if (verifyAvailable(identificationNumber) == 2) {
		this->getMemberVIP(identificationNumber)->setWithdrawCopyList(copy);
	}
}


bool MemberPresenter::checkWithdrawCopy(string location, int identificationNumber) {
	if (verifyAvailable(identificationNumber) == 1) {
		for (Copy* copy : this->getMember(identificationNumber)->getWithdrawCopyList()) {
			if (copy->getLocation() == location) {
				return true;
			}
		}
	}
	else if (verifyAvailable(identificationNumber) == 2) {
		for (Copy* copy : this->getMemberVIP(identificationNumber)->getWithdrawCopyList()) {
			if (copy->getLocation() == location) {
				return true;
			}
		}
	}
	return false;
}

bool MemberPresenter::CheckAvailability(int identificationNumber) {
	try {
		if (verifyAvailable(identificationNumber) == 1) {
			if (this->getMember(identificationNumber)->CheckCant()) {
				return true;
			}
			else {
				throw ("El Socio ya retiro su cantidad maxima de libros");
			}
		}
		else if (verifyAvailable(identificationNumber) == 2) {
			if (this->getMemberVIP(identificationNumber)->CheckCant()) {
				return true;
			}
			else {
				throw ("El Socio VIP ya retiro su cantidad maxima de libros");
			}
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
		return false;
	}
}


void MemberPresenter::printWithdrawnCopies(int identificationNumber) {
	m_view->showText("Los Ejemplares retirados por este Socio son:");
	m_view->showText("---------------------------------------------------");
	list<Copy*> listAux;
	try {
		if (this->verifyAvailable(identificationNumber) == 1) {
			if (this->getMember(identificationNumber)->checkAvailableWithdrawnCopies() == true) {
				listAux =  this->getMember(identificationNumber)->getWithdrawCopyList();
			}
			else {
				throw ("No hay Ejemplares Retirados disponibles");
			}
		}
		if (this->verifyAvailable(identificationNumber) == 2) {
			if (this->getMemberVIP(identificationNumber)->checkAvailableWithdrawnCopies() == true) {
				listAux = this->getMemberVIP(identificationNumber)->getWithdrawCopyList();
			}
			else {
				throw ("No hay Ejemplares Retirados disponibles");
			}
		}
		for (Copy* copy : listAux) {
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
			m_view->showText("---------------------------------------------------");
		}
	}
	catch (const char* txtException) {
		m_view->showText(txtException);
		m_view->showText("---------------------------------------------------");
	}
}


void MemberPresenter::removeWithdrawnCopies(Copy* copy, int identificationNumber) {

	if (verifyAvailable(identificationNumber) == 1) {
		this->getMember(identificationNumber)->removeWithdrawCopyList(copy);
	}
	else if (verifyAvailable(identificationNumber) == 2) {
		this->getMemberVIP(identificationNumber)->removeWithdrawCopyList(copy);
	}
}

Copy* MemberPresenter::getWithdrawnCopy(string location, int identificationNumber) {
	if (verifyAvailable(identificationNumber) == 1) {
		for (Member* member : this->members) {
			for (Copy* copy : member->getWithdrawCopyList()) {
				if (copy->getLocation() == location) {
					return copy;
				}
			}
		}
	}
	else if (verifyAvailable(identificationNumber) == 2) {
		for (MemberVIP* memberVIP: this->membersVIP) {
			for (Copy* copy : memberVIP->getWithdrawCopyList()) {
				if (copy->getLocation() == location) {
					return copy;
				}
			}
		}
	}
	return 0;
}


bool MemberPresenter::checkAvailableMembers() {
	if (this->members.empty()) {
		return false;
	}
	else {
		return true;
	}
}
bool MemberPresenter::checkAvailableMembersVIP(){
	if (this->membersVIP.empty()) {
		return false;
	}
	else {
		return true;
	}
}

