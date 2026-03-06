#ifndef _ACCOUNTS_HPP
#define _ACCOUNTS_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include "ServiceFunñtion.hpp"
#include <unordered_set>
#include "Sellings.hpp"



extern size_t userSize ;
extern std::string currentStatus;
extern unsigned int currentId;
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* userStatus;
extern double* awardArr;
extern double* fineArr;
extern unsigned int* userId;

extern std::unordered_set<char> loginSymbols;
extern std::unordered_set<char> passSymbols;
extern unsigned int maxLogin;
extern unsigned int maxPass;
extern unsigned int minLogin;
extern unsigned int minPass;

extern bool isSetCreated;



void ChangeAccounts();
void ChangeLogin();
void ChangePass();
void ChangeStatus();
void CreateNewUser();
void ChangeAwards();
void DeleteUser();
void ShowUsers(int mode = 0);
bool CheckLogin(const std::string& chooseLogin);
bool CheckPass(const std::string& choosePass);

void CreateSet();






#endif //!_ACCOUNTS_HPP_
