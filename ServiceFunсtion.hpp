#ifndef _SERVICEFUNCTION_HPP
#define _SERVICEFUNCTION_HPP
#include <iostream>
#include <string>
#include <windows.h>

bool IsNumber(const std::string& str);

inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int mode = 0)
{
	std::cout << "Некорректный ввод\n";
	if (mode == 1)
	{
		system("cls");
	}


}

template<typename ArrType>
inline void ArrPushBack(ArrType*& arr, int arrSize)
{
	arrSize++;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[]temp;

}
template<typename ArrType>
inline void ArrDeleteByIndex(ArrType*& arr, int arrSize, int index)
{
	arrSize--;
	ArrType* temp = new ArrType[arrSize];
	for (size_t i = 0, j = 0; i < arrSize; i++, j++)
	{
		if (index == j)
		{
			j++;
		}
		temp[i] = arr[j];
	}
	std::swap(arr, temp);
	delete[]temp;
}


#endif //!_SERVICEFUNCTION_HPP_
