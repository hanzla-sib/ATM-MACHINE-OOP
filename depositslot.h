#pragma once
#include"depositmoney.h"
class depositslot
{
private:
	bool find=false;
	depositmoney d1;
public:
	bool checkenvelope();
	void setenvo(bool f);
	bool getenvo();
	void inputamount();
	int getinputedamount();
};

