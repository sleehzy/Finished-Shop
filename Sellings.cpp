#include "Sellings.hpp"
 size_t checkSize = 0;
 unsigned int* idArrCheck = nullptr;
 std::string* nameArrCheck = nullptr;
 unsigned int* countArrCheck = nullptr;
 double* priceArrCheck = nullptr;
 double* totalPriceArrCheck = nullptr;

 double cashIncome = 0.0;
 double nonCashIncome = 0.0;
 double cashBox = rand() % 40000 + 150000;


 void Sellings()
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
		 ShowStorage();
		 if (!isFirst)
		 {
			 std::cout << "\n\nВаш чек\n";
			 PrintCheck(totalSum);
		 }


		 std::cout << "\n Введите ID товара для покупки или \"exit\" для завершения покупок: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 if (isFirst)
			 {
				 std::cout << "Выход без покупок\n";
				 Sleep(1500);
				 break;
			 }
			 else
			 {
				 PrintCheck(totalSum);
				 std::cout << "Подтвердить покупку?\n1 - Да\n2 - Добавить ещё товар\n3 - отмена\nВвод: ";
				 Getline(choose);
				 if (choose == "1")
				 {
					 while (true)
					 {
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
								 else if (money - totalSum > cashBox)
								 {
									 std::cout << "Нет возможности выдать сдачу. Повторите попытку\n";
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
									 std::cout << "\n\nСоединение не установлено. Повторите попытку!\n\n";
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
						 else if (choose == "Limbus" || choose == "limbus")
						 {
							 std::cout << "Чек оплачен\n";
							 Sleep(1500);
							 system("cls");
							 CheckArrDeleter();
							 return;
						 }
						 else
						 {
							 Err();
						 }

					 }

				 }
				 else if (choose == "2")
				 {
					 continue;
				 }
				 else if (choose == "3")
				 {
					 for (size_t i = 0; i < checkSize; i++)
					 {
						 countArr[idArrCheck[i] - 1] += countArrCheck[i];
					 }

					 CheckArrDeleter();
					 std::cout << "Отмена покупки\n";
					 Sleep(1500);
					 system("pause");
					 return;
				 }
				 else
				 {
					 Err();
					 continue;
				 }

				 CheckArrDeleter();
				 awardArr[currentId] += totalSum;

			 }



		 }

		 if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId) - 1;
			 if (id < 0 || id > size)
			 {
				 std::cout << "Ошибка ID\n";
				 Sleep(1500);
				 continue;
			 }

		 }
		 else
		 {
			 continue;
		 }

		 std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара: ";
		 Getline(chooseCount);
		 if (IsNumber(chooseCount))
		 {
			 count = std::stoi(chooseCount);
			 if (count < 1 || count > countArr[id])
			 {
				 std::cout << "Ошибка кол-во. Максимум: " << countArr[id] << "\n";
				 Sleep(1500);
				 continue;
			 }
		 }
		 else
		 {
			 continue;
		 }

		 ArrPushBack(idArrCheck, checkSize);
		 ArrPushBack(nameArrCheck, checkSize);
		 ArrPushBack(countArrCheck, checkSize);
		 ArrPushBack(priceArrCheck, checkSize);
		 ArrPushBack(totalPriceArrCheck, checkSize);
		 idArrCheck[index] = idArr[id];
		 nameArrCheck[index] = nameArr[id];
		 countArrCheck[index] = count;
		 priceArrCheck[index] = priceArr[id];
		 totalPriceArrCheck[index] = priceArr[id] * count;
		 index++;
		 checkSize++;
		 totalSum += priceArr[id] * count;
		 countArr[id] -= count;
		 std::cout << "Товар добавлен в чек\n";
		 if (isFirst)
		 {
			 isFirst = false;
		 }

		 Sleep(1000);
	 }



 }

void PrintCheck(double totalSum)
{
	
	std::cout << "# " << "ID\t" << std::left << std::setw(70) << "Название товара\t" << "Кол-во\t" 
		<< "Цена\t" << "\tИтого\n";
	for (size_t i = 0; i < checkSize; i++)
	{
		std::cout << i + 1 << "  " << idArrCheck[i] << "\t" << std::left << std::setw(60) << nameArrCheck[i] << 
			"\t\t" << countArrCheck[i] << "\t" << priceArrCheck[i] << "\t\t" << totalPriceArrCheck[i] << "\n";
	}
	std::cout << "\n\nИтого к оплате: " << totalSum << "\n\n";
}

void CheckArrDeleter()
{
	delete[] idArrCheck;
	delete[] nameArrCheck;
	delete[] countArrCheck;
	delete[] priceArrCheck;
	delete[] totalPriceArrCheck;
	idArrCheck = nullptr;
	nameArrCheck = nullptr;
	countArrCheck = nullptr;
	priceArrCheck = nullptr;
	totalPriceArrCheck = nullptr;
}


