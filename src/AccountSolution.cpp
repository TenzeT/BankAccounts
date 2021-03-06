/*
Author: T
Contact: demo@gmail.com
Date Modified: 03-18-2019
Description: The driver class for inheritance bank accounts example
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"


int main()
{
	double startBalance = 5000;
	double checkFee = .023;
	double savingsRate = .05;
	double toCredit = 200;

	try {
		CheckingAccount checking(startBalance, checkFee);
		checking.credit(toCredit);
		checking.print();

		SavingsAccount savings(startBalance, savingsRate);
		savings.calculateInterest();
		savings.print();

		// Polymorphic behavior
		Account *accountPtr;
		accountPtr = &checking;
		accountPtr->print();
		
		accountPtr = &savings;
		accountPtr->print();
	}
	catch (std::invalid_argument &e) { std::cout << e.what() << std::endl; }
	

	std::string stopper = "";
	std::cin >> stopper;

    return 0;
}

