#include "MyAccount.h"

MyAccount::MyAccount() {
    acc_number = 0;
    pin_code = 0;
}
MyAccount::MyAccount(int a,int p) {
    acc_number = a;
    pin_code = p;
}
int MyAccount::getacc_number()
{
    return acc_number;
}

int MyAccount::getpin_code()
{
    return pin_code;
}
