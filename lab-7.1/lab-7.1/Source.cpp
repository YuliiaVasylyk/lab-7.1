// Lab_07_1.cpp
// <Василик Юлія>
// Лабораторна робота №7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці
// Варіант 2


#include <iostream>
#include <cmath>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

void Create(int** T, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			T[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** T, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << T[i][j];
		cout << endl;
	}
	cout << endl;
}

void Change(int** T, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = T[row1][j];
		T[row1][j] = T[row2][j];
		T[row2][j] = tmp;
	}
}

void Sort(int** T, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((T[i1][0] > T[i1 + 1][0])
				||
				(T[i1][0] == T[i1 + 1][0] &&
					T[i1][1] > T[i1 + 1][1])
				||
				(T[i1][0] == T[i1 + 1][0] &&
					T[i1][1] == T[i1 + 1][1] &&
					T[i1][2] < T[i1 + 1][2]))
				Change(T, i1, i1 + 1, colCount);
}

void Calc(int** T, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!(T[i][j] > 0 && (i % 2 != 0 || j % 2 != 0)))
			{
				S += T[i][j];
				k++;
				T[i][j] = 0;
			} 
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((unsigned)time(NULL));
	int Low = -41;
	int High = 23;

	int rowCount = 7;
	int colCount = 9;

	int** T = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		T[i] = new int[colCount];
	Create(T, rowCount, colCount, Low, High);
	cout << "T[" << rowCount << "][" << colCount << "] =" << endl;
	Print(T, rowCount, colCount);

	Sort(T, rowCount, colCount);
	cout << "Посортована матриця T[" << rowCount << "][" << colCount << "] =" << endl;
	Print(T, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(T, rowCount, colCount, S, k);
	cout << "Кількість елементів, які задовільняють вказаному критерію = " << k << endl;
	cout << "Сума елементів, які задовільняють вказаному критерію = " << S << endl;
	cout << "T[" << rowCount << "][" << colCount << "] =" << endl;
	Print(T, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] T[i];
	delete[] T;

	return 0;
}
