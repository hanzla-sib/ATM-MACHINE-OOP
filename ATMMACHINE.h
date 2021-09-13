#pragma once
#include"MyDataBase.h"
#include"MyAccount.h"
#include"SCREEN.h"
#include"KEYPAD.h"
#include"withdrwal.h"
#include"depositslot.h"
class ATMMACHINE
{
private:
	
	withdrwal WITHDRAWL;
	MyDataBase data;
	MyAccount account;
	int trackingaccountid;
	SCREEN screen;
	KEYPAD keypad;
	string* accountnumber;
	string* pin;
	string* balance;
	int lines = 0;
	int trackdepo = 0;
	depositslot d2;
	
public:

	void readdatafromfile();
	void writedataonfile();
	void calclinesinfile();
	int getlines();
	void storingdatainarrays();
	

	ATMMACHINE(MyDataBase d);
	void starttheprogram();
	
	int gettrackingfromdata();
	void functionwithdrwal();
	void functionreading();
	void functiondepositamount();
	bool findingdepositaccount();
	void printtranscript();
	void printfordeposit();
};

