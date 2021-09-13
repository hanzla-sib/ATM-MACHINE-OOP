#pragma once
#include<iostream>


using namespace std;

class withdrwal
{
private:
	int totalnotes = 0;
	string* accountnumber;
	string* pin;
	string* balance;
	int lines = 0;
	int amount;
public:
	
	void setamount(int a);

	int getamount();
	int gettotalnotes();

};

