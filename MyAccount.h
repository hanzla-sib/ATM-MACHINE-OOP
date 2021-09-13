#pragma once
class MyAccount
{
private:
	int acc_number;
	int pin_code;
public:
	MyAccount();
	MyAccount(int a, int p);
	int getacc_number();
	int getpin_code();
};

