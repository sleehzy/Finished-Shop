#ifndef _LOGIN_HPP
#define _LOGIN_HPP
#include "Accounts.hpp"
#include <Windows.h>
#include "Storage.hpp"
#include "Accounting.hpp"
void Start();
bool Login();
bool Logout();
void SuperAdminMenu();
void AdminMenu();
void UserMenu();
void ShowIncome();
void SetConsoleWindowSize();


#endif //!_LOGIN_HPP_
