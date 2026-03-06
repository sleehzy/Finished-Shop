#include "Storage.hpp"
#include "Login.hpp"

/*
 Система продажи товаров
 Учёьные записи: сотрудник, администратор, супер администратор
 Система авторизации
 Основное меню: показать склад, продажи, пополнить склад, списать со склада
 изменить цену,редактирование склада (изменение названия товара, удаления товара из списка,
 добавления товара)
 Редактор учетных записей: добавление сотрудника, редоктирование сотрудника (пароль логин),
   удалить сотрудника
 Отчёт о прибыли. Премии
 Закрытие смены
 Счётчик покупателей
 Cистема штрафов
 NoIntJanuyary
 Нейминг, деление на файлы и функции, проверка на ввод




 Файлы cpp/hpp
 1)main
 2)Storage.cpp
 3)Accounts.cpp
 4)Sellings.cpp
 5)ServiceFunctions.cpp
 6)Login.cpp


 iostream,Windows.h, iomanip, string, cstdlib



*/





int main()
{
	Start();


	delete[] loginArr; 
	delete[] passArr;
	delete[] userStatus;
	delete[] awardArr;
	delete[] fineArr;
	delete[] userId;
	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;


	return 0;
}













