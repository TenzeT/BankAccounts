/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: File containing definitions for the functions of the SavingsAccount.h header file
*/

#include "stdafx.h"
#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {
}

SavingsAccount::SavingsAccount(double &balance, double &rate) {
	
	setBalance(balance);

	if (checkInterestRate(rate))
		this->interestRate_ = rate;
	else
		throw std::invalid_argument("SavingsAccount::Invalid rate input");

}

SavingsAccount::~SavingsAccount() {
}

double SavingsAccount::calculateInterest() {

	double currBalance = getBalance();
	double newBalance = currBalance * getInterestRate() + currBalance;
	setBalance(newBalance);
	return newBalance;
}

void SavingsAccount::setInterestRate(double &rate) {
	if (checkInterestRate(rate))
		this->interestRate_ = rate;
	else
		throw std::invalid_argument("SavingsAccount::Invalid interest rate");
}

double SavingsAccount::getInterestRate() const {
	return this->interestRate_;
}

bool SavingsAccount::checkInterestRate(double &rate) const {
	
	if (rate > 0 && rate < 100)
		return true;
	return false;

}

void SavingsAccount::print() const {
	std::cout << "\nSavings Account: \nBalance: " << getBalance()
		<< " Interest rate: " << getInterestRate() << std::endl;
}