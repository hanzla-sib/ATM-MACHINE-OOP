#pragma once
#include"MyAccount.h"
#include<iostream>
using namespace std;
class MyDataBase
{
private:
	MyAccount *account;
	string* accountnumber;
	string* pin;
	string* balance;
	int lines = 0;
	int trackrecord=0;
public:
	MyDataBase();
	MyDataBase(MyAccount * acc);
	void readdatafromfile();
	void writedataonfile();
	void calclinesinfile();
	int getlines();
	void storingdatainarrays();
	bool checkvalidity();
	int gettrackrecord();

};

