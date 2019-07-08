// ConsoleApplication23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<vector>
#include <climits>
#include<cmath>
#include<algorithm>
#include<utility>
#include<tuple>
#include<stack>
using G = std::vector<std::vector<int>>;
class Graph 
{
	G Mat;
	G H;


	auto floid()
	{
		for (int k = 0; k < Mat.size(); ++k)
			for (int i = 0; i < Mat.size(); ++i)
				for (int j = 0; j < Mat.size(); ++j)
					if (Mat[i][k] < INFINITY && Mat[k][j] < INFINITY)
					{
						Mat[i][j] = std::min(Mat[i][j], Mat[i][k] + Mat[k][j]);
						H[i][j] = (Mat[i][j] < Mat[i][k] + Mat[k][j]) ? H[i][j] : H[i][k];
					}
		return std::make_tuple(Mat,H);
	}
};

int main()
{
	std::stack<int> s;
	s.push(4);
	std::cout << (s.top()) << std::endl;
    std::cout << "Hello World!\n"; 
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
