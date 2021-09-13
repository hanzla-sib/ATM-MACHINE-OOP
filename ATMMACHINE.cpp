#include "ATMMACHINE.h"

#include<iostream>
using namespace std;
#include<fstream>
#include<sstream>

ATMMACHINE::ATMMACHINE(MyDataBase d)
{
	data = d;
}

void ATMMACHINE::starttheprogram()
{
	if (data.checkvalidity() == 1) {
		cout << "account number and pin is found " << endl;
		cout << "now u can access the menu" << endl;
		cout << endl;
		againmenu:
		screen.printmenu();
		againinput:
		int input;
		cin >> input;
		if (input > 5) {
			cout << "enter the input again" << endl;
			goto againinput;
		}
		keypad.setkeyinput(input);
		//start of program from 4 inputs menu
		if (keypad.getkeyinput() == 1) {
			functionreading();
			cout << endl;
			goto againmenu;
		}
		else if (keypad.getkeyinput() == 2) {
			
			functionwithdrwal();
			char a;
			cout << "would u like to recieve transaction reciept" << endl;
			cout << "press y to recieve it or press any other kay if u dont want" << endl;
			cin >> a;
				if (a == 'y') {
					printtranscript();
				}
				cout << endl;
				goto againmenu;
				
			}


		else if (keypad.getkeyinput() == 3) {
			functiondepositamount();
			cout << endl;
			goto againmenu;
		}
		
		
		else if (keypad.getkeyinput() == 4) {
			cout << "THANKS FOR CHOOSING OUR BANK" << endl;
			exit(0);

		}
		
			
		

		

	}
	else {
		cout << "either your account numeber is not valid or pic" << endl;
	}
	
}
int ATMMACHINE::gettrackingfromdata() {
	return data.gettrackrecord();
}

void ATMMACHINE::functionwithdrwal()
{
	readdatafromfile();
	int amo;
	//-------------------------------------------------------------------[

	stringstream g(balance[data.gettrackrecord()]);

	//convert string to int x
	// it to the integer x 
	int x = 0;
	g >> x;
againamount:
	cout << "enter the amount u want to withdrwal in the time of 20$" << endl;
	cin >> amo;
	WITHDRAWL.setamount(amo);
	if (WITHDRAWL.getamount() > x) {
		cout << "not suficiecnt balance in account" << endl;
		cout << "enter again less amount then" << ": " << balance[data.gettrackrecord()] << endl;
		goto againamount;
	}

	int reaminingnotes = (WITHDRAWL.gettotalnotes() - (amo / 20));
	if (reaminingnotes <= 0) {
		cout << "not enough money in the bank" << endl;
		cout << "sorry for that" << endl;
		exit(0);
	}
	else {
		int aftersub;
		aftersub = x - WITHDRAWL.getamount();
		stringstream ss;
		ss << aftersub;
		string s;
		ss >> s;
		//to again store teh int balance to string array 
		balance[data.gettrackrecord()] = s;
		writedataonfile();
		cout << "thanks for making transaction" << endl;
		cout << "the total notes remaining in the bank are  :" << reaminingnotes << endl;

		//-----------------------------------------------------------------------
	}
}
void ATMMACHINE::functionreading()
{
	readdatafromfile();
	cout << "your account balance is" << " : " << balance[data.gettrackrecord()] << endl;
	cout << "thanks for visiting" << endl;
}
void ATMMACHINE::functiondepositamount()
{
	
	if (findingdepositaccount() == true) {
		char c;
		d2.inputamount();
		cout << "press y if u deposited the envelope in the deposit slot" << endl;
		cout << endl;
		cin >> c;
		if (c == 'y') {
			 d2.setenvo(true) ;
			 d2.checkenvelope();
			stringstream g(balance[trackdepo]);

			//convert string to int x
			// it to the integer x 
			int x = 0;
			g >> x;

			int addamount = x + d2.getinputedamount();
			stringstream ss;
			ss << addamount;
			string s;
			ss >> s;
			balance[trackdepo] = s;
			writedataonfile();
			cout << "if u want to recieve reciept of deposit press y if u dont want it press any other key" << endl;
			char r;
			cin >> r;
			if (r == 'y') {
				printfordeposit();
				
			}
		}
		else  {
			d2.setenvo(false);
			d2.checkenvelope();
		}
		
	}
	else {
		cout << "your entered account not found" << endl;
	}

}
bool ATMMACHINE::findingdepositaccount()
{
	 
	string depoaccount;
	cout << "enter account number in which u wnat to deposit" << endl;
	cin >> depoaccount;
	readdatafromfile();
	for (int i = 0; i < data.getlines(); i++) {

		if (depoaccount == accountnumber[i]) {
			return true;
		}
		trackdepo++;
	}
	
}
void ATMMACHINE::printtranscript()
{
	cout << "HERE IS YOUR TRANSCRIPT" << endl;
	cout << "your remaining balance is :" << balance[data.gettrackrecord()] << endl;
	cout << "you make a transaction of :" << WITHDRAWL.getamount() << endl;
	cout << "             ******Take care Allah HAFIZ*******                  " << endl;
}
void ATMMACHINE::printfordeposit()
{
	cout << "here is your transcript of deposit " << endl;
	cout << "you have transfered :  " << d2.getinputedamount() << " amount to " << accountnumber[trackdepo] << endl;
}
void ATMMACHINE::readdatafromfile()
{
	calclinesinfile();
	storingdatainarrays();
}

void ATMMACHINE::writedataonfile()
{
	ofstream myfile("mytxt.txt");
	for (int i = 0; i < lines; i++) {
		myfile << accountnumber[i] << "." << pin[i] << "." << balance[i]  << endl;
	}

	myfile.close();
}

void ATMMACHINE::calclinesinfile()
{
	string line;
	//opening the file
	ifstream myfile("mytxt.txt");
	while (getline(myfile, line))//getting each line one by one the calculate total number of lines
	{
		lines++;
	}
	
}

int ATMMACHINE::getlines()
{
	return lines;
}

void ATMMACHINE::storingdatainarrays()
{
	accountnumber = new string[getlines()];
	pin = new string[getlines()];
	balance = new string[getlines()];
	string line;
	ifstream myfile;    // opening the file for reading purpose.....................
	myfile.open("mytxt.txt");
	for (int i = 0; i < lines; i++) {
		getline(myfile, line);
		stringstream convo(line);    // this string stream is used to seperate each word in file when found full stop
		getline(convo, accountnumber[i], '.');
		//store the data in account number from file
		getline(convo, pin[i], '.');
		//store the data in pin from file
		getline(convo, balance[i], '.');
		//store the data in balance from file

	}
}
