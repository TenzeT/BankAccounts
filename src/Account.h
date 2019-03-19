/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: The header file for the Account class - includes function declarations
*/

#pragma once

class Account{

public:
	Account();
	Account(double &balance);
	~Account();
	void credit(double &amount);
	bool debit(double &amount);
	double getBalance() const;
	void setBalance(double &amount);
	bool checkBalanceInputValid(double &amount) const;
	virtual void print() const;

private:
	double balance_;

};