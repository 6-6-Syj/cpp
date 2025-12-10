/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:29:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/10 17:01:29 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account () {}

Account::Account (int initial_deposit) {
	this->_amount = initial_deposit;
}

Account::~Account() {}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	// std::cout << "index:" << _accountIndex << ";amount:" << _amount << std::endl;
	// std::cout << "accounts:" << "total:" << "deposits:" << "withdrawals:" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_amount += deposit;
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
	if (withdrawal)
		return (true);
	return (false);
}