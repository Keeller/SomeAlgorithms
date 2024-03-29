// ConsoleApplication19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<vector>

template<typename T> 
class heap_node
{
	private:
		T*data;
		int key_;
	public:
		heap_node(T*d, int key)
		{
			this->data = data;
			this->key_=key;
		}
		~heap_node()
		{
			delete data;
		}

		heap_node (const heap_node<T>& h)
		{
			this->data = h.get_data();
			this->key_ = h.key();
			
		}

		heap_node& operator =(const heap_node<T>&  h)
		{
			this->data = h.get_data();
			this->key_ = h.key();
			return *this;
		}

		T* get_data() const
		{
			return this->data;
		}

		int key() const
		{
			return this->key_;
		}

		void set_data(T* d)
		{
			this->data = d;
		}

		void set_key(int new_key)
		{
			this->key = new_key;
		}


};


template<typename U> 
class Heap {
private:
	std::vector<heap_node<U>> heap;
public:
	Heap()
	{

	}



	void add(U* const data, int const key)
	{
		heap_node<U> hn = heap_node<U>(data, key);
		heap.push_back(hn);
		int i = heap.size()-1;
		int parent = (i - 1) / 2;
		while (i > 0 && heap[i].key() > heap[parent].key())
		{
			heap_node<U> temp = heap[i];
			heap[i] = heap[parent];
			heap[parent] = temp;
			i = parent;
			parent = (i - 1) / 2;

		}

	}

	void heapfily( const U*data, int i)
	{
		int leftChild;
		int rightChild;
		int largestChild;

		for (; ; )
		{
			leftChild = 2 * i + 1;
			rightChild = 2 * i + 2;
			largestChild = i;

			if (leftChild < heap.size() && heap[leftChild].key() > heap[largestChild].key())
			{
				largestChild = leftChild;
			}

			if (rightChild < heap.size() && heap[rightChild].key() > heap[largestChild].key())
			{
				largestChild = rightChild;
			}

			if (largestChild == i)
			{
				break;
			}

			heap_node<U> temp = heap[i];
			heap[i] = heap[largestChild];
			heap[largestChild] = temp;
			i = largestChild;
		}


	}

	heap_node<U>& extract_max()
	{
		heap_node<U> result = heap[0];
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		this->heapfily(heap[0].get_data(),heap[0].key());
		return result;
	}


	void print()
	{

		for (int i=0;i<heap.size();i++)
			std::cout << heap[i].key()<<" idx "<<i<< std::endl;
	}


};

template<typename ATD>
class priori_que
{
private:
	Heap<ATD> heap = Heap<ATD>();
public:
	priori_que()
	{}

	void q(ATD* el, int prior) 
	{
		heap.add(el, prior);
	}

	ATD* dq()
	{
		return (heap.extract_max()).get_data();
	}

	void print()
	{
		heap.print();
	}
};

int main()
{
	int*p = new int[5];
	int p1[12] = { 20, 11, 15, 7, 8, 6, 1, 3 ,9, 5, 17 };
	Heap<int> a = Heap<int>();
	for (int i = 0; i < 5; i++)
		p[i] = i;
	for (int i = 0; i < 12; i++)
		a.add(&i,p1[i]);
	a.extract_max();
	a.print();
	priori_que<int> pq = priori_que<int>();
	delete p;
	for (int i = 0; i < 12; i++)
		pq.q(&i, p1[i]);
	pq.dq();
	pq.print();
	return 0;
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
