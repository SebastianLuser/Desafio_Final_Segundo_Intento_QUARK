#ifndef IVIEW_H
#define IVIEW_H

#include <string>

using namespace std;

class IView
{
public:
	virtual ~IView() = default;
	virtual void showText(const char* text) = 0;
	virtual void showText(const string& text) = 0;
};
#endif // IVIEW_H
