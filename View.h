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
	void memberLoginMenu();
	void memberMenu(int x);
	void bookMenu();
	virtual ~View() = default;
private:
	int inputI;
	
	MemberPresenter* memberPresenter;
	BookPresenter* bookPresenter;
};
#endif