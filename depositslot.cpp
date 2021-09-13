#include "depositslot.h"
#include<iostream>

using namespace std;
bool depositslot::checkenvelope()
{
    if (getenvo() == true) {
        cout << "envelope recieved thanks for making deposit through our atm" << endl;
    }
    else {
        cout << "we donot recieved your envelope . sorry we cannot proceed" << endl;
        return false;
    }
    return find;
}

void depositslot::setenvo(bool f)
{
    find = f;
}

bool depositslot::getenvo()
{
    return find;
}

void depositslot::inputamount()
{
    int depo;
    cout << "enter the money u want to deposit" << endl;
    cin >> depo;
    d1.setmoney(depo);

}

int depositslot::getinputedamount()
{
    return d1.getmoney();
}
