#include "withdrwal.h"
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<sstream>




void withdrwal::setamount(int a)
{
	amount = a;
}

int withdrwal::getamount()
{
	return amount;
}

int withdrwal::gettotalnotes()
{
	return totalnotes;
}


