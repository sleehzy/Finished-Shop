#include "Accounts.hpp"


 size_t userSize = 3;
 std::string currentStatus;
 unsigned int currentId = 0;
 std::string* loginArr = new std::string[userSize]{ "admin", "user1", "user2" };
 std::string* passArr = new std::string[userSize]{ "admin", "user1", "user2" };
 std::string* userStatus = new std::string[userSize]{ "SuperAdministrator"
  ,"Administrator", "User" };
 double* awardArr = new double[userSize] {};
 double* fineArr = new double[userSize] {};
 unsigned int* userId = new unsigned int[userSize] {0, 1, 2};
 bool isSetCreated = false;


  std::unordered_set<char> loginSymbols;
  std::unordered_set<char> passSymbols;
  unsigned int maxLogin = 15;
  unsigned int maxPass = 25;
  unsigned int minLogin = 5;
  unsigned int minPass = 8;

 void ChangeAccounts()
 {
	 if (!isSetCreated)
	 {
		 CreateSet();
	 }

	 std::string choose;
	 while (true)
	 {
		 system("cls");
		 std::cout << "1 - Создать новый аккаунт\n";
		 std::cout << "2 - Показать всех сотрудников\n";
		 std::cout << "3 - Изменить логин\n";
		 std::cout << "4 - изменить пароль\n";
		 std::cout << "5 - Изменить уровни доступа\n";
		 std::cout << "6 - Редактировать премии и штрафы сотрудника\n";
		 std::cout << "7 - Удалить аккаунт\n";
		 std::cout << "0 - Выход\n";
		 std::cout << "Ввод: ";
		 Getline(choose);
		 if (choose == "1")
		 {
			 CreateNewUser();
		 }
		 else if (choose == "2")
		 {
			 if (currentStatus == "Administrator")
			 {
				 ShowUsers();
			 }
			 else if (currentStatus == "SuperAdministrator")
			 {
				 ShowUsers(1);
			 }
			 system("pause");
		 }
		 else if (choose == "3")
		 {
			 ChangeLogin();
		 }
		 else if (choose == "4")
		 {
			 ChangePass();
		 }
		 else if (choose == "5")
		 {
			 if (userSize > 1)
			 {
				 ChangeStatus();
			 }
			 else 
			 {
				 std::cout << "Нет доступных пользователей";
				 Sleep(1500);
			 }
		 }
		 else if (choose == "6")
		 {
			 if (userSize > 1)
			 {
				 ChangeAwards();
			 }
			 else
			 {
				 std::cout << "Нет доступных пользователей";
				 Sleep(1500);
			 }

		 }
		 else if (choose == "7")
		 {
			 if (userSize > 1)
			 {
				 DeleteUser();
			 }
			 else
			 {
				 std::cout << "Нет доступных пользователей";
				 Sleep(1500);
			 }

		 }
		 else if (choose == "0")
		 {
			 std::cout << "Выходи из редактора склада\n";
			 Sleep(1500);
			 break;
		 }
		 else
		 {
			 Err();
		 }
	 }
 }

 void ChangeLogin()
 {
	 std::string chooseId, chooseLogin, choose;
	 int id = 0, isSuperAdmin = 0;
	 while (true) 
	 {
		 if (currentStatus == "Administrator")
		 {
			 ShowUsers();
			 isSuperAdmin = 1;
		 }
		 else if (currentStatus == "SuperAdministrator")
		 {
			 ShowUsers(1);
			 isSuperAdmin = 0;
		 }
 


		 ShowUsers();
		 std::cout << "Введите ID пользователя или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Отмена изменения логина\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId);
			 if (id < isSuperAdmin || id > userSize - 1)
			 {
				 Err();
			 }
			 else 
			 {
				 std::cout << "Придумайте новый логин для пользователя: ";
				 Getline(chooseLogin);
				 if (CheckLogin(chooseLogin))
				 {
					 system("cls");
					 std::cout << loginArr[id] << " ------> " << chooseLogin << "\n\n";
					 std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
					 Getline(choose);
					 if (choose == "1")
					 {
						 loginArr[id] = chooseLogin;
						 std::cout << "Логин успешно изменён\n";
						 Sleep(1500);
						 break;
					 }
					 if (choose == "2")
					 {
						 std::cout << "Отмена\n";
						 Sleep(1500);
					 }
					 else 
					 {
						 Err();
					 }
				 }

			 }

		 }
	 }

 }

 void ChangePass()
 {
	 std::string chooseId, chooseLogin, choosePass, choose, currentPass, verifyPass;
	 int id = 0, isSuperAdmin = 0;
	 while (true)
	 {
		 if (currentStatus == "Administrator")
		 {
			 ShowUsers();
			 isSuperAdmin = 1;
		 }
		 else if (currentStatus == "SuperAdministrator")
		 {
			 ShowUsers(1);
			 isSuperAdmin = 0;
		 }



		 std::cout << "Введите ID пользователя или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Отмена изменения пароля\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId);
			 if (id < isSuperAdmin || id > userSize - 1)
			 {
				 Err();
			 }
			 else
			 {
				 system("cls");
				 std::cout << "Введите старый Пароль для пользователя: ";
				 Getline(currentPass);
				 std::cout << "Придумайте новый Пароль для пользователя: ";
				 Getline(choosePass);
				 std::cout << "Подтвердите новый Пароль для пользователя: ";
				 Getline(verifyPass);
				 if (currentPass != passArr[id])
				 {
					 std::cout << "Ошибка пароля\n";
					 Sleep(1500);
					 continue;
				 }
                if (choosePass == verifyPass)
			    {


				   if (CheckPass(choosePass))
				   {
					  system("cls");
					  std::cout << passArr[id] << " ------> " << choosePass << "\n\n";
					  std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
					  Getline(choose);
					  if (choose == "1")
					  {
						  passArr[id] = choosePass;
						  std::cout << "Пароль успешно изменён\n";
						  Sleep(1500);
						  break;
					  }
					  if (choose == "2")
					  {
						  std::cout << "Отмена\n";
						  Sleep(1500);
					  }
					  else
					  {
						  Err();
					  }
				   }
			    }
				else 
				{
					std::cout << "Пароли не совпадают";
					Sleep(1500);
				}
				 
				 
				
			 }
		 

		 }
	 }

 }

 void ChangeStatus()
 {
	 std::string chooseId, chooseStatus, choose;
	 int id = 0, isSuperAdmin = 0;
	 while (true)
	 {


		 ShowUsers(2);

		 std::cout << "Введите ID пользователя или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Отмена изменения логина\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId);
			 if (id < 1 || id > userSize - 1)
			 {
				 Err();
			 }
			 else
			 {
				 system("cls");
				 std::cout << "Введите новую роль для пользователя или \"exit\" для выхода \nВвод: ";
				 std::cout << "1 - Сотрудник\n";
				 std::cout << "2 - Администратор\n";
				 std::cout << "Ввод: ";
				 Getline(choose);
				 if (choose == "exit")
				 {
					 std::cout << "отмена изменения роли\n";
					 
					 Sleep(1500);
					 break;
				 }
				 if (choose == "1")
				 {
					 chooseStatus = "User";
				 }
				 else if (choose == "2")
				 {
					 std::cout << "Введите пароль супер администратора для подтверждения: ";
					 Getline(choose);
					 if (choose == passArr[0])
					 {
						 chooseStatus = "Administrator";
					 }
					 else
					 {
						 Err();
						 continue;
					 }
				 }

				 else
				 {
					 Err();
					 continue;
				 }
				 std::cout << userStatus[id] << " -------> " << chooseStatus << "\n";
				 std::cout << "Подтвердить?\n";
				 std::cout << "1 - Да\n2 - Нет\n\nВвод: ";
				 Getline(choose);
				 if (choose == "1")
				 {
					 userStatus[id] = chooseStatus;
					 std::cout << "Успешно!\n";
					 Sleep(1500);
					 break;
				 }
				 else if (choose == "2")
				 {
					 std::cout << "Отмена\n";
					 Sleep(1500);
				 }
				 else 
				 {
					 Err();
				 }


			 }
		 }
	 }
 }

 void CreateNewUser()
 {
	 std::string choose, chooseLogin, choosePass, chooseStatus;
	 bool isExit = true;

	 while (true)
	 {
		 
		 while (true)
		 {
			 isExit = true;
			 system("cls");
			 std::cout << "Введите логин или \"exit\" для выхода \nВвод: ";
			 Getline(chooseLogin);
			 if (chooseLogin == "exit")
			 {
				 std::cout << "отмена создания нового пользователя\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }
			 if(CheckLogin(chooseLogin))
			 {
				 break;
			 }
			
		 }

		 while (isExit)
		 {
			 system("cls");
			 std::cout << "Введите пароль или \"exit\" для выхода \nВвод: ";
			 Getline(choosePass);
			 if (choosePass == "exit")
			 {
				 std::cout << "отмена создания нового пользователя\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }
			 if (CheckPass(choosePass))
			 {
				 break;

			 }
		 }

		 while (isExit)
		 {
			 system("cls");
			 std::cout << "Введите роль для нового пользователя или \"exit\" для выхода \nВвод: ";
			 std::cout << "1 - Сотрудник\n";
			 std::cout << "2 - Администратор\n";
			 std::cout << "Ввод: ";
			 Getline(choose);
			 if (choose == "exit")
			 {
				 std::cout << "отмена создания нового пользователя\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }
			 if (choose == "1")
			 {
				 chooseStatus = "User";
				 break;
			 }
			 else if (choose == "2")
			 {
				 std::cout << "Введите пароль супер администратора для подтверждения";
				 Getline(choose);
				 if (choose == passArr[0])
				 {
					 chooseStatus = "Administrator";
					 break;
				 }
				 else
				 {
					 Err();
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
			 std::cout << "Логин: " << chooseLogin << "\n";
			 std::cout << "Пароль: " << choosePass << "\n";
			 std::cout << "Роль: " << chooseStatus << "\n";
			 std::cout << "Подтвердить? \n1 - Да\n2 - Отмена\nВвод: ";
			 Getline(choose);
			 if (choose == "1")
			 {
				 ArrPushBack(loginArr, userSize);
				 ArrPushBack(passArr, userSize);
				 ArrPushBack(userStatus, userSize);
				 ArrPushBack(awardArr, userSize);
				 ArrPushBack(fineArr, userSize);
				 ArrPushBack(userId, userSize);
				 userSize++;
				 userId[userSize - 1] = userSize - 1;
				 awardArr[userSize - 1] = 0;
				 fineArr[userSize - 1] = 0;
				 loginArr[userSize - 1] = chooseLogin;
				 passArr[userSize - 1] = choosePass;
				 userStatus[userSize - 1] = chooseStatus;

				 std::cout << "Пользователь успешно добавлен\n\n";
				 Sleep(1700);
				 break;
			 }
			 else if (choose == "2")
			 {
				 std::cout << "Отмена создания нового пользователя!\n";
				 Sleep(1500);
			 }
			 else
			 {
				 Err();
			 }

		 }
	 }


 }

 void ChangeAwards()
 {
	 std::string chooseId, chooseSum, choose;
	 int id = 0, isSuperAdmin = 0;
	 double sum = 0.0;

	 while (true)
	 {
		 system("cls");

		 if (currentStatus == "SuperAdministrator")
		 {
			 std::cout << "Введите пароль супер администратора для подтверждения: ";
			 Getline(choose);
			 if (choose == passArr[0])
			 {
				 isSuperAdmin = 0;
				 ShowUsers(3);
			 }
			 else
			 {
				 Err();
				 break;
			 }

			
		 }
		 else if (currentStatus == "Administrator")
		 {
			 std::cout << "Введите свой пароль для подтверждения: ";
			 Getline(choose);
			 if (choose == passArr[currentId])
			 {
				 isSuperAdmin = 1;
				 ShowUsers(4);
			 }
			 else
			 {
				 Err();
				 break;
			 }

		 }


		 ShowUsers(3);

		 std::cout << "Введите ID пользователя или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Отмена редактирования штрафов и премий\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId);
			 if (id < 1 || id > userSize - 1)
			 {
				 Err();
			 }
			 else
			 {
				 if (currentStatus == "Administrator" && userStatus[id] != "User")
				 {
					 std::cout << "Некорректный пользователь";
					 Sleep(1500);
					 continue;
				 }


				 system("cls");
				 std::cout << "Выбрите пункт меню или \"exit\" для выхода \nВвод: ";
				 std::cout << "1 - Изменить сумма продаж\n";
				 std::cout << "2 - Изменить сумму штрафов\n";
				 std::cout << "Ввод: ";
				 Getline(choose);
				 if (choose == "exit")
				 {
					 std::cout << "Отмена редактирования штрафов и суммы продаж\n";
					 Sleep(1500);
					 break;
				 }
				 if (choose == "1")//============
				 {
					 while (true)
					 {
						 system("cls");
						 std::cout << "Введите корректную сумму продаж или \"exit\" для выхода \nВвод: ";
						 Getline(chooseSum);
						 if (chooseSum == "exit")
						 {
							 std::cout << "отмена редактирования суммы продаж\n";
							 Sleep(1500);
							 return;
						 }

						 if (IsNumber(chooseSum))
						 {
							 sum = std::stod(chooseSum);
							 if (sum < 0 || sum > MAXINT)
							 {
								 std::cout << "Ошибка! максимальная сумма " << MAXINT << "рублей\n\n";
								 Sleep(1500);
							 }
							 else
							 {
								 awardArr[id] = sum;
								 std::cout << "Успешно\n";
								 Sleep(1500);
								 return;
							 }

						 }
						 else
						 {
							 Err();
						 }
					 }
				 }
				 else if (choose == "2")
				 {
					 while (true)
					 {
						 system("cls");
						 std::cout << "Введите корректную сумму штрафов или \"exit\" для выхода \nВвод: ";
						 Getline(chooseSum);
						 if (chooseSum == "exit")
						 {
							 std::cout << "отмена редактирования штрафов продаж\n";
							 Sleep(1500);
							 return;
						 }

						 if (IsNumber(chooseSum))
						 {
							 sum = std::stod(chooseSum);
							 if (sum < 0 || sum > 15000)
							 {
								 std::cout << "Ошибка! максимальная сумма " << 15000 << "рублей\n\n";
								 Sleep(1500);
							 }
							 else
							 {
								 fineArr[id] = sum;
								 std::cout << "Успешно\n";
								 Sleep(1500);
								 return;
							 }

						 }
						 else
						 {
							 Err();
						 }
					 }
				 }
				 else
				 {
					 Err();
					 continue;
				 }
			 }
		 }
	 }
 }

 void DeleteUser()
 {
	 std::string chooseId, chooseStatus, choose;
	 int id = 0;
	 while (true)
	 {


		 ShowUsers(2);

		 std::cout << "Введите ID пользователя для удаления или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Отмена удаления\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId);
			 if (id < 1 || id > userSize - 1)
			 {
				 Err();
			 }
			 else if (id == currentId)
			 {
				 std::cout << "нельзя удалить себя\n";
				 Sleep(1500);
			 }
			 else
			 {
				 std::cout << "Удалить пользователя" << loginArr[id] << "?";
				 std::cout << "Для подтверждения введите пароль супер администратора или \"exit\" для выхода \nВвод: ";
				 Getline(choose);
				 if (choose == "exit")
				 {
					 std::cout << "Отмена удаления\n\n";
					 Sleep(1500);
				 }
				 else if (choose == passArr[0])
				 {
					 if (id < currentId)
					 {
						 --currentId;
					 }
					 ArrDeleteByIndex(loginArr, userSize, id);
					 ArrDeleteByIndex(passArr, userSize, id);
					 ArrDeleteByIndex(userStatus, userSize, id);
					 ArrDeleteByIndex(awardArr, userSize, id);
					 ArrDeleteByIndex(fineArr, userSize, id);
					 --userSize;
					 for (size_t i = 0; i < userSize; i++)
					 {
						 userId[i] = i;
					 }
					 std::cout << "Идёт процесс удаления....\n";
					 Sleep(1900);
					 std::cout << "Пользователь удалён\n";
					 Sleep(1500);
					 break;
				 }
				 else 
				 {
					 Err();
				 }

			 }
		 }
	 }
 }

 void ShowUsers(int mode)
 {
	 system("cls");
	 std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin - 2)
		 << "\tПароль " << "\tРоль"<< "\t\t\t\tСумма продаж" << "\tШтрафы" << "\n";
	 if (mode == 0)
	 {
		 

		 for (size_t i = 1; i < userSize; i++)
		 {
			 std::cout << userId[i]<< "\t" << std::left << std::setw(maxLogin) << loginArr[i]
				 << "\t" << std::setw(maxPass / 1.5) << passArr[i] << "\t\t" << userStatus[i] << "\n";

		 }


	 }
	 else if (mode == 1)
	 {

		 for (size_t i = 0; i < userSize; i++)
		 {
			 std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << loginArr[i]
				 << "\t" << std::setw(maxPass / 2.5) << passArr[i] << "\t" << std::setw(maxLogin + 2) << userStatus[i]
				 << "\t\t" << awardArr[i] << "\t\t" << fineArr[i] << "\n";

		 }

	 }
	 else if (mode == 2)
	 {
		 system("cls");
		 std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 10)
			 << "\tРоль" << "\n";
		 for (size_t i = 1; i < userSize; i++)
		 {
			 std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << loginArr[i]
				 << "\t" << userStatus[i] << "\n";

		 }

	 }
	 else if (mode == 3)
	 {
		 system("cls");
		 std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 3)
			 << "\tКол-во продаж" << "\tШтрафы" << "\n";
		 for (size_t i = 1; i < userSize; i++)
		 {
			 std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << loginArr[i]
				 << "\t" << awardArr[i] << "\t\t\t" << fineArr[i] << "\n";

		 }


	 }
	 else if (mode == 4)
	 {
		 system("cls");
		 std::cout << "ID" << "\tЛогин\t" << std::left << std::setw(maxLogin + 3)
			 << "\tКол-во продаж" << "\tШтрафы" << "\n";
		 for (size_t i = 0; i < userSize; i++)
		 {
			 if (userStatus[i] == "User")
			 {
				 std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << loginArr[i]
					 << "\t" << awardArr[i] << "\t\t\t" << fineArr[i] << "\n";
			 }
			
		 }


	 }


 }

 bool CheckLogin(const std::string& chooseLogin)
 {
	
	 if (chooseLogin.size() < minLogin || chooseLogin.size() > maxLogin)
	 {
		 std::cout << "Ошибка длины логина! от " << minLogin << " до " << maxLogin << "\n";
		 Sleep(1500);
		 return false;
	 }
	 else
	 {
		 for (size_t i = 0; i < chooseLogin.size(); i++)
		 {
			 if (!loginSymbols.count(chooseLogin[i]))
			 {
				 std::cout << "Некорректные символы логина. Только Допустимые символы A-Z, a-z, 0-9\n\n";
				 Sleep(2000);
				 return false;
			 }
		 }
	 }



	 for (size_t i = 0; i < userSize; i++)
	 {
		 if (chooseLogin == loginArr[i])
		 {
			 std::cout << "Такой пользователь уже создан\n";
			 Sleep(1500);
			 return false;
		 }

	 }
	 return true;
 }

 bool CheckPass(const std::string& choosePass)
 {
	 int symbolCount = 0, maxSymbols = 3, numberCount = 0, maxNumber = 3, letterCount = 0, maxLetter = 3;
	 if (choosePass.size() < minPass || choosePass.size() > maxPass)
	 {

		 std::cout << "Ошибка длины пароля! от " << minPass << " до " << maxPass << "\n";
		 Sleep(1500);
		 return false;
	 }
	 else 
	 {
		 for (size_t i = 0; i < choosePass.size(); i++)
		 {
			 if (!passSymbols.count(choosePass[i]))
			 {
				 std::cout << "Некорректный пароль. Допустимые символы: A-Z, a-z, 0-9 и стандартные символы\n\n";
				 Sleep(2000);
				 return false;
			 }
			 else if (std::isdigit(choosePass[i]))
			 {
				 numberCount++;
			 }
			 else if (choosePass[i] >='A' && choosePass[i] <= 'Z' || choosePass[i] >= 'a' && choosePass[i] <= 'z')
			 {
				 letterCount++;
			 }
			 else 
			 {
				 symbolCount++;
			 }
		 }
		 if (numberCount >= maxNumber && letterCount >= maxLetter && symbolCount >= maxSymbols)
		 {
			 return true;
		 }
		 else 
		 {
			 std::cout << "Слишком простой пароль\n\n";
			 std::cout << "Минимум " << maxLetter << " букв, " << maxNumber << " цифр, " << maxSymbols << " символа в пароле\n";
			 Sleep(2000);
			 return false;
		 }

	 }
	


 }

 void CreateSet()
 {
	 if (isSetCreated)
	 {
		 return;
	 }
	 else 
	 {
		 isSetCreated = true;
		 for (char i = '0'; i <= '9'; i++)
		 {
			 loginSymbols.insert(i);
		 }

		 for (char i = 'A'; i <= 'Z'; i++)
		 {
			 loginSymbols.insert(i);
		 }
		 for (char i = 'a'; i <= 'z'; i++)
		 {
			 loginSymbols.insert(i);
		 }
		 for (char i = '!'; i < '}'; i++)
		 {
			 passSymbols.insert(i);
		 } 



	 }

 }
