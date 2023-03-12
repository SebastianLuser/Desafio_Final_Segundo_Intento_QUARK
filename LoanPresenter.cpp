#include "LoanPresenter.h"
#include "Copy.h"
#include <List>
#include "IView.h"
#include <iostream>
#include <string> 

LoanPresenter::LoanPresenter(IView* view) : m_view(view) {
	list<Loan*> loans;
}

void LoanPresenter::setLoan(Copy* copy, Member* member, string date) {
	this->loans.push_back(new Loan(copy, member, date));
}

void LoanPresenter::setLoan(Copy* copy, MemberVIP* memberVIP, string date) {
	this->loans.push_back(new Loan(copy, memberVIP, date));
}

list<Loan*>LoanPresenter::getLoanList() {
	return this->loans;
}

void LoanPresenter::printLoanList() {
	try {
		if (this->checkAvailableLoans() == true) {
			for (Loan* loan : this->loans) {
				string s01 = loan->getCopy()->getName();
				string s02 = loan->getCopy()->getAuthor();
				string s03 = to_string(loan->getCopy()->getISBN());
				string s12 = loan->getCopy()->getLocation();
				string s13;
				if (loan->getStatus() == false) {
					s13 = "Devuelto";
				}
				else {
					s13 = "Retirado";
				}
				string s04 = loan->getDate();
				m_view->showText("-----------------------------------------------");
				m_view->showText("El prestamo ingresado tiene los siguientes datos:");
				m_view->showText("	Ejemplar: ");
				m_view->showText("		Nombre: " + s01);
				m_view->showText("		Autor: " + s02);
				m_view->showText("		ISBN: " + s03);
				m_view->showText("		Posicion: " + s12);
				m_view->showText("		Estado: " + s13);
				m_view->showText("	Fecha: " + s04);
				if (loan->getMember()) {
					string s05 = loan->getMember()->getName();
					string s06 = loan->getMember()->getLastname();
					string s07 = to_string(loan->getMember()->getIdentificationNumber());
					m_view->showText("	Socio Clasico: ");
					m_view->showText("		Nombre: " + s05);
					m_view->showText("		Apellido: " + s06);
					m_view->showText("		ID: " + s07);
				}
				else if(loan->getMemberVIP()) {
					int aa;
					string s08 = loan->getMemberVIP()->getName();
					string s09 = loan->getMemberVIP()->getLastname();
					string s10 = to_string(loan->getMemberVIP()->getIdentificationNumber());
					string s11 = to_string(loan->getMemberVIP()->getFee());
					m_view->showText("	Socio VIP: ");
					m_view->showText("		Nombre: " + s08);
					m_view->showText("		Apellido: " + s09);
					m_view->showText("		ID: " + s10);
					m_view->showText("		Costo Mensual: " + s11);
				}
				m_view->showText("-----------------------------------------------");
			}
		}
		else {
			throw ("No se registraron prestamos hasta el momento");
		}
	}
	catch (const char* txtException) {
		m_view->showText("-----------------------------------------------");
		m_view->showText(txtException);
		m_view->showText("-----------------------------------------------");
	}
}


bool LoanPresenter::checkAvailableLoans() {
	if (this->loans.empty()) {
		return false;
	}
	else {
		return true;
	}
}