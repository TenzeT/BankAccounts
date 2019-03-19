/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: File containing definitions for the functions of the Account.h header file
*/

#include "stdafx.h"
#include "Account.h"
#include <iostream>

Account::Account() {
}

Account::Account(double &balance) {
	
	if (checkBalanceInputValid(balance))
		setBalance(balance);
	else
		throw std::invalid_argument("Account::Invalid balance input");
}

Account::~Account() {
}

void Account::credit(double &amount) {
	
	if (amount < 0.0)
		throw std::invalid_argument("Account::Invalid credit input");

	setBalance(amount);
}

bool Account::debit(double &amount) {
	
	if (balance_ < amount)
		throw std::invalid_argument("Account::Balance not sufficient");

	setBalance(amount);
}

double Account::getBalance() const {
	return this->balance_;
}

void Account::setBalance(double &amount) {
	
	if (!checkBalanceInputValid(amount))
		throw std::invalid_argument("Account::Invalid set balance");

	this->balance_ = amount;
}

bool Account::checkBalanceInputValid(double& amount) const {

	if (amount < 0.0)
		return false;
	return true;
}


void Account::print() const {
	std::cout << "\nBalance: " << getBalance() << std::endl;;
}