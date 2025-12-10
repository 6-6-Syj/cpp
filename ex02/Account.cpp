/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:29:02 by jmagand           #+#    #+#             */
/*   Updated: 2025/12/10 15:03:43 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account () {}

Account::Account (int initial_deposit) {
	this->_amount = initial_deposit;
}

Account::~Account() {}

void	Account::displayAccountsInfos() {
	
}

void	Account::makeDeposit(int deposit) {
	this->_amount += deposit;
}

void	Account::displayStatus() const {
	
}

void	Account::_displayTimestamp() {
	
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal)
		return (true);
	return (false);
}