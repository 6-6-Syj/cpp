/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:29:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/12 13:39:21 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts        	= 0;
int Account::_totalAmount       	= 0;
int Account::_totalNbDeposits   	= 0;
int Account::_totalNbWithdrawals	= 0;

Account::Account() {
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
}

Account::Account (int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts() {
	return (_nbAccounts);
}

int Account::getTotalAmount() {
	return (_totalAmount);
}

int Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

int Account::checkAmount() const {
	return (_amount);
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << "total:" << getTotalAmount() 
		<< "deposits:" << getNbDeposits() << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << "p_amount:" << this->_amount 
			<< "deposits:" << deposit << "amount:" << (this->_amount + deposit)
			<< "nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	_totalNbDeposits++;
}

void	Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount 
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp() {
	std::time_t seconds = std::time(NULL);
	std::cout << "[" << seconds << "] ";
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (this->_amount < withdrawal) {
		std::cout << "index:" << this->_accountIndex << "p_amount:" << this->_amount 
			<< "withdrawal:refused" << std::endl;
		return (true);
	}
	else {
		std::cout << "index:" << this->_accountIndex << "p_amount:" << this->_amount 
			<< "withdrawal:" << withdrawal << "amount:" << (this->_amount - withdrawal)
			<< "nb_withdrawals:" << this->_nbDeposits << std::endl;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		return (false);
	}
}