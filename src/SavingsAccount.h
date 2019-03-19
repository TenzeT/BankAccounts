/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: The header file for the Savings Account class - includes function declarations
*/

#pragma once
#include "Account.h"

class SavingsAccount : public Account {
	
public:
	SavingsAccount();
	SavingsAccount(double &balance, double &rate);
	~SavingsAccount();
	double calculateInterest();
	void setInterestRate(double &rate);
	double getInterestRate() const;
	virtual void print() const override;

private:
	double interestRate_;

	bool checkInterestRate(double &rate) const;
};