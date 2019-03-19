/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: The header file for the Checking Account class - includes function declarations
*/

#pragma once
#include "Account.h"

class CheckingAccount : public Account {

public: 
	CheckingAccount();
	CheckingAccount(double &balance, double &fee);
	~CheckingAccount();
	
	void credit(double& amount);
	void debit(double& amount);
	double getFee() const;
	virtual void print() const override;

private:
	double fee_;

	bool checkFeeValid(double &rate) const;
};