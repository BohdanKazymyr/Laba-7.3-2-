#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int i, const int rowCount, const int Low,
	const int High, int j);
void CreateRows(int** a, const int colCount, const int Low, const int High, int i);
void PrintRow(int** a, const int rowNo, const int rowCount, int colNo);
void PrintRows(int** a, const int colCount, int rowNo);
void Calc(int** a, const int rowCount, const int colCount, int& k);
int Sum(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int rowCount = 6;
	int colCount = 8;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	CreateRows(a, rowCount, Low, High, 0);
	PrintRows(a, rowCount, 0);
	int k = 0;
	Calc(a, rowCount, colCount, k);
	cout << "k = " << k << endl;
	cout << "Sum = " << Sum(a, rowCount, colCount) << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRow(int** a, const int rowNo, const int rowCount, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < rowCount - 1)
		CreateRow(a, rowNo, rowCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int colCount, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < colCount - 1)
		CreateRows(a, colCount, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int rowCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < rowCount - 1)
		PrintRow(a, rowNo, rowCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < colCount - 1)
		PrintRows(a, colCount, rowNo + 1);
	else
		cout << endl;
}
void Calc(int** a, const int rowCount, const int colCount, int& k)
{
	k = 0;
	for (int i = 1; i < rowCount - 1; i++)
		for (int j = 1; j < colCount - 1; j++)
			if (a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j + 1])
			{
				k++;
				a[i][j] = 0;
			}
}
int Sum(int** a, const int rowCount, const int colCount)
{
	int sum = 0;
	for (int i = 0; i < rowCount - 1; ++i)
	{
		for (int j = i + 1; j < rowCount; ++j)
		{

			sum += a[i][j];


		}

	}
	return sum;
}