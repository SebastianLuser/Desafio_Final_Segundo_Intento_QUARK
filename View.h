#ifndef VIEW_H
#define VIEW_H
#include<iostream>
#include <string>
#include "IView.h"

using namespace std;
class Member;
class MemberPresenter;
class BookPresenter;
class View : public IView
{
public:
	View();
	void showText(const char* text) override;
	void showText(const string& text) override;
	void startMenu();
	void memberCreateMenu();
	void bookCreateMenu();
	void copyCreateMenu();
	void memberLoginMenu();
	void memberMenu(int input, int ID);
	void bookMenu();
	virtual ~View() = default;
private:
	int inputI;
	
	MemberPresenter* memberPresenter;
	BookPresenter* bookPresenter;
};
#endif