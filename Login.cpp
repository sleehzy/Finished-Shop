#include "Login.hpp"


    bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');

		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "приветствуем вас" << loginArr[i] << "\n";
				std::cout << "Ваш статус: " << userStatus[i] << "\n";
				currentStatus = userStatus[i];
				currentId = i;
				return true;
			}

		}

		std::cout << "Неверный логин или пароль. Повторите попытку\n\n";
		//sleep
		// to do exit from the programm

	}
}

	void Start()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		std::cout << "\n\n\n\t\t\t Добро пожаловать!\n\n\t\t\t Дефицит оперативной памяти\n\n\n";
		if (Login())
		{
			if (currentStatus == "SuperAdministrator")
			{
				CreateStorage();
				SuperAdminMenu();
				//новый склад с нуля

			}
			else if (currentStatus == "Administrator")
			{
				std::cout << "2\n\n";
			}
			else if (currentStatus == "User")
			{
				std::cout << "3\n\n";
			}
			else
			{
				std::cerr << "CURRENT_STATUS_LOGIN_ERROR_";
			}
		}
		else
		{
			// exit
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
			std::cout << "0) Выход\n";
			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
			if (choose == "1")
			{
				Sellings();
			}
			if (choose == "2")
			{

				std::cout << "Какой склад вы хотите выбрать \n1 - Основной\n2 - Пустой\nВвод: ";


				Getline(choose);
				if (choose == "1")
				{
					ShowStorage();
					system("pause");
					return;
				}
				else if (choose == "2")
				{
					EmptyStorage();

					system("pause");
					return;
				}


			}
			if (choose == "3")
			{
				AddProduct();
			}
			if (choose == "4")
			{
				RemoveProduct();
			}
			if (choose == "5")
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

			}
			if (choose == "0")
			{

			}
			else
			{

			}
		}
	}