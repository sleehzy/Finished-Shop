#include "Login.hpp"


bool Login()
{
	std::string login, pass;

	while (true)
	{
		system("cls");
		std::cout << "\n\n\n\t\t\t Добро пожаловать!\n\n\t\t\t Дефицит оперативной памяти\n\n\n";
		std::cout << "Введите логин: ";
		Getline(login);
		if (login == "exit")
		{
			return false;
		}
		std::cout << "Введите пароль: ";
		Getline(pass);
		if (pass == "exit")
		{
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "приветствуем вас" << loginArr[i] << "\n";
				std::cout << "Ваш статус: " << userStatus[i] << "\n";
				currentStatus = userStatus[i];
				currentId = userId[i];
				return true;
			}

		}

		std::cout << "Неверный логин или пароль. Повторите попытку\n\n";
		Sleep(1500);

	}
}

	bool Logout()
	{
		std::string choose;
		while (true)
		{
			system("cls");
			std::cout << "Для подтверждения выхода введите свой пароль или \"exit\" для возврата в меню: ";
			Getline(choose);
			if (choose == "exit")
			{
				return false;
			}
			else if (choose == passArr[currentId] || choose == passArr[0])
			{
				return true;
			}
			else 
			{
				Err();
			}

		}


		
	}

	void Start()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		SetConsoleWindowSize();
		

		while (true)
		{
			
			if (Login())
			{
				if (currentStatus == "SuperAdministrator")
				{
					CreateStorage();
					SuperAdminMenu();
					/*
					готовый

					новый склад с нуля */

				}
				else if (currentStatus == "Administrator")
				{
					if (!isStorageCreated)
					{
						CreateStorage();
					}

					AdminMenu();
				}
				else if (currentStatus == "User")
				{
					if (!isStorageCreated)
					{
						CreateStorage();
					}
					UserMenu();
				}
				else
				{
					std::cerr << "CURRENT_STATUS_LOGIN_ERROR_";
				}
			}
			else
			{
				system("cls");
				std::cout << "Хорошего вам дня\n\n";
				Sleep(1500);
				system("cls");
				break;
			}

		}
		
	}

	void SuperAdminMenu()
	{
		std::string choose;
		while (true)
		{
			system("cls");
			std::cout << "1) Начать продажу\n";
			std::cout << "2) Показать склад\n";
			std::cout << "3) Попольнить товары\n";
			std::cout << "4) Списать товары\n";
			std::cout << "5) Изменить цены\n";
			std::cout << "6) Редактировать склад\n";
			std::cout << "7) Редактировать сотрудников\n";
			std::cout << "8) Отчёт о прибыли\n";
			std::cout << "9) Бухгалтерия\n";
			std::cout << "0) Выход\n";
			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			if (choose == "1" && size > 0)
			{
				Sellings();
			}
			if (choose == "2")
			{
				ShowStorage();
				system("pause");
				return;
			}
			if (choose == "3" && size > 0)
			{
				AddProduct();
			}
			if (choose == "4" && size > 0)
			{
				RemoveProduct();
			}
			if (choose == "5" && size > 0)
			{
				ChangePrice();
			}
			if (choose == "6")
			{
				ChangeStorage();
			}
			if (choose == "7")
			{
				ChangeAccounts();
			}
			if (choose == "8")
			{
				ShowIncome();
			}
			if (choose == "9")
			{
				AccountingMenu();
			}
			if (choose == "0")
			{
				if (Logout())
				{
					break;
				}
			}
			else
			{
				if (size < 1)
				{
					std::cout << "Склад пуст\n";
				}
				Err();
			}
		}
	}

	void AdminMenu()
	{
		std::string choose;
		while (true)
		{
			system("cls");
			std::cout << "1) Начать продажу\n";
			std::cout << "2) Показать склад\n";
			std::cout << "3) Попольнить товары\n";
			std::cout << "4) Списать товары\n";
			std::cout << "5) Изменить цены\n";
			std::cout << "6) Редактировать склад\n";
			std::cout << "7) Редактировать сотрудников\n";
			std::cout << "8) Отчёт о прибыли\n";
			std::cout << "9) Бугалтерия\n";
			std::cout << "0) Выход\n";
			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			if (choose == "1" && size > 0)
			{
				Sellings();
			}
			if (choose == "2")
			{
				ShowStorage();
				system("pause");
				return;
			}
			if (choose == "3" && size > 0)
			{
				AddProduct();
			}
			if (choose == "4" && size > 0)
			{
				RemoveProduct();
			}
			if (choose == "5" && size > 0)
			{
				ChangePrice();
			}
			if (choose == "6")
			{
				ChangeStorage();
			}
			if (choose == "7")
			{
				ChangeAccounts();
			}
			if (choose == "8")
			{
				ShowIncome();
			}
			if (choose == "9")
			{

			}
			if (choose == "0")
			{
				if (Logout())
				{
					break;
				}
			}
			else
			{
				if (size < 1)
				{
					std::cout << "Склад пуст\n";
				}
				Err();
			}
		}


	}

	void UserMenu()
	{
		std::string choose;
		while (true)
		{
			system("cls");
			std::cout << "1) Начать продажу\n";
			std::cout << "2) Показать склад\n";
			std::cout << "3) Отчёт о прибыли\n";
			std::cout << "0) Выход\n";
			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			if (choose == "1" && size > 0)
			{
				Sellings();
			}
			if (choose == "2")
			{
				ShowStorage();
				system("pause");
				return;
				
			}	
			if (choose == "3")
			{
				ShowIncome();
			}
			if (choose == "0")
			{
				if (Logout())
				{
					break;
				}
			}
			else
			{
				if (size < 1)
				{
					std::cout << "Склад пуст\n";
				}
				Err();
			}
		}
	}

	void ShowIncome()
	{
		system("cls");
		std::cout << "Наличные в кассе " << cashBox << "\n";
		std::cout << "Доход за безналичный расчёт: " << nonCashIncome << "\n";
		std::cout << "Доход за наличный расчёт: " << cashIncome << "\n";
		std::cout << "Ваши продажи: " << awardArr[currentId] << "\n";
		std::cout << "Ваши штрафы: " << fineArr[currentId] << "\n";
		std::cout << "Общий доход: " << cashIncome + nonCashIncome << "\n";
		system("pause");
	}

	void SetConsoleWindowSize()
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD bufferSize = { 160, 50 };
		SetConsoleScreenBufferSize(consoleHandle, bufferSize);
		SMALL_RECT windowSize = { 0,0,159,49 };
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(consoleHandle, &csbi);

		int width = 9, heght = 16;
		int windowWightPx = (windowSize.Right - windowSize.Left + 1) * width;
		int windowHeghtPx = (windowSize.Bottom - windowSize.Top + 1) * heght;

		HWND hWnd = GetConsoleWindow();
		if (hWnd != nullptr)
		{
			SetWindowPos(hWnd, nullptr, 0, 0, windowWightPx, windowHeghtPx, SWP_NOMOVE);
		}
		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		int targetX = (screenWidth - windowWightPx) / 2;
		int targetY = (screenHeight - windowHeghtPx) / 2;

		if (hWnd != nullptr)
		{
			SetWindowPos(hWnd, nullptr, targetX, targetY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
		}

	}





	//ШТРАФЫ