#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** Z, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** Z, const int rowCount, const int colCount);
void Sort(int** Z, const int rowCount, const int colCount);
void Change(int** Z, const int col1, const int col2, const int rowCount);


int Calc(int** Z, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!(Z[i][j] % 2 != 0 || (Z[i][j] % 7 == 0)))
			{
				S += Z[i][j];
				k++;
				Z[i][j] = 0;
			}
	return S;
	return k;
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = 18;
	int High = 74;
	int rowCount = 9;
	int colCount = 6;
	int** Z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		Z[i] = new int[colCount];
	Create(Z, rowCount, colCount, Low, High);
	Print(Z, rowCount, colCount);
	Sort(Z, rowCount, colCount);
	Print(Z, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(Z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(Z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] Z[i];
	delete[] Z;
	return 0;
}
void Create(int** Z, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			Z[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** Z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << Z[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** Z, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
			if ((Z[0][j1] > Z[0][j1+1])
				||
				(Z[0][j1] == Z[0][j1+1] &&
					
					Z[1][j1] < Z[1][j1+1])
				||
				(Z[0][j1] == Z[0][j1+1] &&
					Z[1][j1] == Z[1][j1+1] &&
					Z[2][j1] < Z[2][j1+1]))
				Change(Z, j1, j1 + 1, colCount);
}
void Change(int** Z, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = Z[i][col1];
		Z[i][col1] = Z[i][col2];
		Z[i][col2] = tmp;
	}
}

