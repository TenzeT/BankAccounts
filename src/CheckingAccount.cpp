/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: File containing definitions for the functions of the CheckingAccount.h header file
*/

#include "stdafx.h"
#include <iostream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {
}

CheckingAccount::CheckingAccount(double &balance, double &fee) {

	setBalance(balance);

	if (checkFeeValid(fee))
		this->fee_ = fee;
	else
		throw std::invalid_argument("CheckingAccount::Invalid fee amount");
}

CheckingAccount::~CheckingAccount() {
}

bool CheckingAccount::checkFeeValid(double &fee) const {
	
	if (fee < 0 || fee > 100)
		return false;
	return true;
}

void CheckingAccount::credit(double &amount) {

	double temp = amount * getFee() + amount + getBalance();
	setBalance(temp);
}

void CheckingAccount::debit(double &amount) {
	
	double temp = amount * getFee() - amount + getBalance();
	setBalance(temp);
}

double CheckingAccount::getFee() const {
	return this->fee_;
}

void CheckingAccount::print() const {
	std::cout << "\nChecking Account: \nBalance: " << getBalance()
		<< " Fee: " << getFee() << std::endl;
}