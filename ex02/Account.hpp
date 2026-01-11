/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:30:22 by jmagand           #+#    #+#             */
/*   Updated: 2026/01/11 12:53:13 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Account
{
public:
	Account(int initial_deposit);
	~Account();
	typedef Account t;
	static int getNbAccounts(void);
	static int getTotalAmount(void);
	static int getNbDeposits(void);
	static int getNbWithdrawals(void);
	static void displayAccountsInfos(void);
	void makeDeposit(int deposit);
	bool makeWithdrawal(int withdrawal);
	int checkAmount(void) const;
	void displayStatus() const;

private:
	int _accountIndex;
	int _amount;
	int _nbDeposits;
	int _nbWithdrawals;
	static int _nbAccounts;
	static int _totalAmount;
	static int _totalNbDeposits;
	static int _totalNbWithdrawals;
	static void _displayTimestamp();
	Account();
};