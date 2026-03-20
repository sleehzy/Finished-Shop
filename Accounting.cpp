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
	 std::cout << "5 - Оплата счетов за помещение\n";
	 std::cout << "0 - Выход\n";
	 std::cout << "Ввод: ";
	 Getline(choose);
	 if (choose == "1")
	 {
		 Balance();
	 }
	 if (choose == "2")
	 {
		 DeliveredItems();
	 }
	 if (choose == "3" )
	 {
		 
	 }
	 if (choose == "4" )
	 {
		 
	 }
	 if (choose == "5" )
	 {
		 rentOfPremises();
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

void DeliveredItems()
{

	std::string choose, chooseName, chooseDev, choosePrice, chooseCount;
	double price = 0;
	unsigned int count = 0;
	bool isExit = true, isSame = false;
	while (true)
	{
		isExit = true;
		while (true)
		{
			system("cls");
			isSame = false;
			std::cout << "Введите название нового товара или \"exit\" для выхода \nВвод: ";
			Getline(chooseName);
			if (chooseName == "exit")
			{
				std::cout << "отмена создания нового товара\n";
				isExit = false;
				Sleep(1500);
				break;
			}

			if (chooseName.size() < 1 || chooseName.size() > 60)
			{
				std::cout << "Ошибка длины названия товара\n";
				Sleep(1500);
				continue;
			}

			for (size_t i = 0; i < size; i++)
			{
				if (chooseName == nameArr[i])
				{
					std::cout << "Такой товар уже есть на складе\n";
					isSame = true;
					Sleep(1500);
					break;
				}

			}

			if (isSame)
			{
				continue;
			}

			else
			{
				break;
			}
		}

		while (isExit)
		{
			system("cls");
			std::cout << "Введите количество товара или \"exit\" для выхода \nВвод: ";
			Getline(chooseCount);
			if (chooseName == "exit")
			{
				std::cout << "отмена создания количества товара\n";
				isExit = false;
				Sleep(1500);
				break;
			}
			if (IsNumber(chooseCount))
			{
				count = std::stoi(chooseCount);
				if (count < 0 || count > maxStorageSize - currentStorageSize)
				{
					std::cout << "Ошибка! наскладе осталось " << maxStorageSize - currentStorageSize << "мест\n\n";
					Sleep(1500);
				}
				else
				{
					break;
				}

			}
			else
			{
				Err();
			}
		}

		while (isExit)
		{
			system("cls");
			std::cout << "Введите поставщика товара или \"exit\" для выхода если забыли поставщика\nВвод: ";
			Getline(chooseDev);
			if (chooseName == "exit")
			{
				std::cout << "отмена создания товара\n";
				isExit = false;
				Sleep(1500);
				break;
			}
			if (chooseName.size() < 1 || chooseName.size() > 60)
			{
				std::cout << "Ошибка длины названия товара\n";
				Sleep(1500);
				continue;
			}

			if (isSame)
			{
				continue;
			}

			else
			{
				break;
			}
		}
		


		while (isExit)
		{
			system("cls");
			isSame = false;
			std::cout << "Введите цену нового товара или \"exit\" для выхода \nВвод: ";
			Getline(choosePrice);
			if (choosePrice == "exit")
			{
				std::cout << "отмена создания новой цены\n";
				isExit = false;
				Sleep(1500);
				break;
			}

			if (IsNumber(choosePrice))
			{
				price = std::stod(choosePrice);
				if (price < 0 || price > maxPrice)
				{
					std::cout << "Ошибка! максимальная цена: " << maxPrice << "рублей\n\n";
					Sleep(1500);
				}
				else
				{
					break;
				}

			}
			else
			{
				Err();
			}
		}

		if (!isExit)
		{
			break;
		}

		else
		{
			std::cout << "Новый товар: " << chooseName << "\n";
			std::cout << "Кол-во: " << count << "\n";
			std::cout << "Производитель: "<< chooseDev << "\n";
			std::cout << "Цена: " << price << "\n";
			std::cout << "Подтвердить? \n1 - Да\n2 - Отмена\nВвод: ";
			Getline(choose);
			if (choose == "1")
			{
				ArrPushBack(idArr, size);
				ArrPushBack(nameArr, size);
				ArrPushBack(priceArr, size);
				ArrPushBack(countArr, size);
				size++;
				idArr[size - 1] = size;
				nameArr[size - 1] = chooseName;
				countArr[size - 1] = count;
				priceArr[size - 1] = price;
				currentStorageSize += count;
				CheckExpensiveItem();
				std::cout << "Товар успешно добавлен в основной склад\n\n";
				Sleep(1700);
				break;
			}
			else if (choose == "2")
			{
				std::cout << "Отмена добовление товара!\n";
				Sleep(1500);
			}
			else
			{
				Err();
			}

		}
	}
		


}

void Elecricity()
{


}

void rentOfPremises()
{
	std::string choose, chooseId, chooseCount, chooseCash;
	int id = 0, count = 0, cardChance = 0, sleepTimer = 0;
	double totalSum = 0.0, money = 0.0;
	size_t index = 0;
	checkSize = 0;
	bool isFirst = true;

	while (true)
	{
		srand(time(NULL));
		Elecricity();
		if (!isFirst)
		{
			std::cout << "\n\nВаш чек оплаты счетов\n";
			PrintCheck(totalSum);
		}
		system("cls");
		std::cout << "Выберите способ оплаты\n1 - Наличными\n2 - Безнал\nВвод";
		Getline(choose);
		if (choose == "1")
		{
			std::cout << "Введите кол-во наличных: ";
			Getline(chooseCash);
			if (IsNumber(chooseCash))
			{
				money = std::stod(chooseCash);
				if (money < totalSum)
				{
					std::cout << "Недостаточно средств!!\n";
					Sleep(1500);
					continue;
				}

				else
				{
					std::cout << "Ваши " << money << "\n";
					Sleep(300);
					std::cout << "Оплата прошла успешно. Сдача: " << money - totalSum << " Рублей\n\n";
					Sleep(1400);
					cashBox += totalSum;
					cashIncome += totalSum;
					CheckArrDeleter();
					awardArr[currentId] += totalSum;
					system("cls");
					return;

				}

			}


		}
		else if (choose == "2")
		{


			while (true)
			{
				cardChance = rand() % 100 + 1;
				sleepTimer = 150;
				std::cout << "Приложите карту\n";
				system("pause");
				if (cardChance <= 30)
				{
					for (size_t i = 0; i < 5; i++)
					{
						Sleep(sleepTimer);
						std::cout << i + 1 << "   ";
						sleepTimer -= 20;
						Beep(500, 400);
					}
					std::cout << "\n\nПеревод средств не прошел. Повторите попытку!\n\n";
					Sleep(1500);
				}
				else
				{
					for (size_t i = 0; i < 5; i++)
					{
						Sleep(sleepTimer);
						std::cout << i + 1 << "   ";
						sleepTimer -= 20;
						Beep(500, 400);
					}
					std::cout << "Оплата прошла успешно";
					Sleep(1500);
					nonCashIncome += totalSum;
					CheckArrDeleter();
					awardArr[currentId] += totalSum;
					system("cls");
					return;


				}


			}

		}
	}
}




