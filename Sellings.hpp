#ifndef _SELLINGS_HPP
#define _SELLINGS_HPP
#include "Storage.hpp"

extern size_t checkSize;
extern unsigned int* idArrCheck;
extern std::string* nameArrCheck;
extern unsigned int* countArrCheck;
extern double* priceArrCheck;
extern double* totalPriceArrCheck;
extern double cashIncome;
extern double nonCashIncome;
extern double cashBox;

void Sellings();
void PrintCheck(double totalSum);
void CheckArrDeleter();


#endif //!_SELLINGS_HPP_
