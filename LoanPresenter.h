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
	void setLoans(Copy* copy, Member* member, string date);
	void setLoans(Copy* copy, MemberVIP* memberVIP, string date);
	void printLoanList();
	void printLoan(int x);
	/*Loan* getLoan(int ISBN);*/
	list<Loan*> getLoanList();
private:
	IView* m_view = nullptr;
	list<Loan*> loans;
};

#endif