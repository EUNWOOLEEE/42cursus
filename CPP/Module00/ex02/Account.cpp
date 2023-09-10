/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunwolee <eunwolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:04:21 by eunwolee          #+#    #+#             */
/*   Updated: 2023/09/10 18:41:56 by eunwolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	std::cout << "index:" << _accountIndex << \
		";amount:" << _amount << ";created" << \
		std::endl;
}

Account::Account(void){
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
		";amount:" << _amount << ";closed" << \
		std::endl;
	//destroy
}

int	Account::getNbAccounts(void){
	return (_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (_totalAmount);
}

int	Account::getNbDeposits(void){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << \
		";total:" << _totalAmount << \
		";deposits:" << _totalNbDeposits << \
		";withdrawals:" << _totalNbWithdrawals << \
		std::endl;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << \
		";p_amount:" << _amount << \
		";deposit:" << deposit << \
		";amount:" << _amount + deposit << \
		";nb_deposits:" << ++_nbDeposits << \
		std::endl;
		
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();

	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex << \
			";p_amount:" << _amount << \
			";withdrawal:refused" <<
			std::endl;
		return false;
	}

	std::cout << "index:" << _accountIndex << \
		";p_amount:" << _amount << \
		";withdrawal:" << withdrawal << \
		";amount:" << _amount - withdrawal << \
		";nb_withdrawals:" << ++_nbWithdrawals << \
		std::endl;
	
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	
	return true;
}

int	Account::checkAmount(void) const{
	return 0;
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << \
		";amount:" << _amount << \
		";deposits:" << _nbDeposits << \
		";withdrawals:" << _nbWithdrawals << \
		std::endl;
}

void Account::_displayTimestamp(void){
	time_t		timer = time(NULL);
	struct tm	*time = localtime(&timer);
	int			year = time->tm_year + 1900;
	int			mon = time->tm_mon + 1;
	int			day = time->tm_mday;
	int			hour = time->tm_hour;
	int			min = time->tm_min;
	int			sec = time->tm_sec;

	std::cout << "[" << year << mon << day << "_" \
		<< hour << min << sec << "] ";
}