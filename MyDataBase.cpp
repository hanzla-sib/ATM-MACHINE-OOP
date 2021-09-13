#include "MyDataBase.h"
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<sstream>





MyDataBase::MyDataBase()
{
}

MyDataBase::MyDataBase(MyAccount *acc)
{
	account = acc;
}

void MyDataBase::readdatafromfile()
{
	calclinesinfile();
	storingdatainarrays();
	
	
	
}

void MyDataBase::writedataonfile()
{
	ofstream myfile("mytxt.txt");
	for (int i = 0; i < lines; i++) {
		myfile << accountnumber[i] << "." << pin[i] << "." << balance[i] << "." << endl;
	}
	
	myfile.close();
}

void MyDataBase::calclinesinfile()  // this function is for calculating total number of lines in the file for our implemntation
{

	string line;
	//opening the file
	ifstream myfile("mytxt.txt");
	while (getline(myfile, line))//getting each line one by one the calculate total number of lines
	{
		lines++;
	}
	
	
}

int MyDataBase::getlines()
{
	return lines;
}

void MyDataBase::storingdatainarrays()
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
		getline(convo,accountnumber[i],'.');
		//store the data in account number from file
		getline(convo,pin[i], '.');
		//store the data in pin from file
		getline(convo,balance[i], '.');
		//store the data in balance from file

	}
	
}

bool MyDataBase::checkvalidity()  // this function is to check account number and pin in the txt file data base

{

	bool validity = false;
	
		readdatafromfile();   // this is to read all the lines and store it in arrays
		//this stringstream function is used to convert int account number and pin to string type for comaprig the 2 strings
		
		
		stringstream ss;
		
		ss << account->getacc_number();
		string s;
		ss >> s;
		
		stringstream p;
		p << account->getpin_code();
		string ac;
		p >> ac;
		for (int i = 0; i < getlines(); i++) {
			
			if (s == accountnumber[i]) {
				if (ac == pin[i]) {
					validity = true;
					return validity;
				}
				else
					validity = false;
			}
			trackrecord++;
	}

	
	return validity;
}

int MyDataBase::gettrackrecord()
{
	return trackrecord;
}

