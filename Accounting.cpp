#include "Accounting.hpp"

void AccountingMenu()
{
	std::string choose;

 while (true)
 {
	 system("cls");
	 std::cout << "1 - Общий баланс\n";
	 std::cout << "2 - Поставка товаров\n";
	 std::cout << "3 - Выдать зарплату сотруднику\n";
	 std::cout << "4 - Аренда помещения(Здания)\n";
	 std::cout << "5 - Оплата Налогов за помещение\n";
	 std::cout << "0 - Выход\n";
	 std::cout << "Ввод: ";
	 Getline(choose);
	 if (choose == "1")
	 {
		 Balance();
	 }
	 if (choose == "2")
	 {
		 
	 }
	 if (choose == "3" )
	 {
		 
	 }
	 if (choose == "4" )
	 {
		 
	 }
	 if (choose == "5" )
	 {
		
	 }
	 if (choose == "0")
	 {
		 std::cout << "Выходим из меню бухгалтерии\n";
		 Sleep(1500);
		 break;

	 }

 }

}

void Balance()
{
	double StoreBalance = 200000.0;
	system("cls");
	std::cout << "Ваш баланс в магазине составляет: " << StoreBalance << "\n\n";
	system("pause");
}




