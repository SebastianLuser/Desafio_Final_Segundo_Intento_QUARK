#pragma once
#ifndef LOANPRESENTER_HPP
#define LOANPRESENTER_HPP

#include "Loan.h"
#include "Copy.h"
#include <List>
#include <string>
using namespace std;

class IView;

class LoanPresenter {

public:
	LoanPresenter(IView* view);
	void setLoan(Copy* copy, Member* member, string date);
	void setLoan(Copy* copy, MemberVIP* memberVIP, string date);
	void printLoanList();
	list<Loan*> getLoanList();
	bool checkAvailableLoans();
private:
	IView* m_view = nullptr;
	list<Loan*> loans;
};

#endif