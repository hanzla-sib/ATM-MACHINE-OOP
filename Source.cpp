#include"MyAccount.h"
#include"MyDataBase.h"
#include"ATMMACHINE.h"
#include<iostream>
using namespace std;

int main() {
	cout << "********** Welcome to our ATM BRANCH **************" << endl;
	int acc, pin;
	cout << "enter your account number " << endl;
	cin >> acc;
	cout << "enter your pin code" << endl;
	cin >> pin;
	MyAccount a(acc, pin);
	MyDataBase data(&a);
	ATMMACHINE atm(data);
	atm.starttheprogram();
	//data.checkvalidity();
	
}
