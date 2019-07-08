// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<list>
#include<vector>

template<typename T>
class HashTabel 
{
private:
	std::vector<std::vector<T>> base;
public:
	HashTabel() 
	{
		for (int i = 0; i < 21; i++)
		{
			std::vector<T> added;
			base.push_back(added);
		}
	}
	double convert(double value, double From1, double From2, double To1, double To2)
	{
		return (value - From1) / (From2 - From1)*(To2 - To1) + To1;
	}
	int some_hash_func(T arg)
	{
		return static_cast<int>(arg % 2);
	}
	void add(T arg)
	{
		(base[some_hash_func(arg)]).push_back(arg);
	}

	void search(T arg)
	{
		for (int i = 0; i < (base[some_hash_func(arg)]).size(); i++)
		{
			if ((base[some_hash_func(arg)])[i] == arg)
				std::cout << arg << std::endl;
		}

	}
	
};

int main()
{
	HashTabel<int> hs = HashTabel<int>();
	for (int i = 0; i < 5; i++)
		hs.add(i);
	hs.search(2);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
