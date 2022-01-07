#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void zero(int** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = 0;
		}
	}
}

void output(int** mas, int n, int p)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j] == 10)
			{
				cout <<setw(4)<< "*" ;
			}
			else cout << setw(4) << "0";
		}
		cout << endl;
	}
	cout << "Количество ферзей : " << p;
}

void out(int** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

void sort1(int** mas, int n, int i, int j)
{
	for (int k = 1;; k++)
	{
		int e = 0;
		if ((i + k) < n) mas[i + k][j] = 1;
		else e++;
		if ((i - k) >= 0) mas[i - k][j] = 1;
		else e++;
		if ((j + k) < n) mas[i][j + k] = 1;
		else e++;
		if ((j - k) >= 0) mas[i][j - k] = 1;
		else e++;
		if ((j + k) < n && i + k < n) mas[i + k][j + k] = 1;
		else e++;
		if (j - k >= 0 && i - k >= 0) mas[i - k][j - k] = 1;
		else e++;
		if ((j + k) < n && i - k >= 0) mas[i - k][j + k] = 1;
		else e++;
		if ((j - k) >= 0 && i + k < n) mas[i + k][j - k] = 1;
		else e++;
		if (e == 8)break;
	}
}

void sort(int** mas, int n, int m, int& p1, int& p2, int** mas1)
{
	int i1, j1;
	int flag1 = 0;
	bool flag = false;
	bool a = false;
	while (m != p1)
	{
		for (int f = 0; f < n; f++)
		{
			int fl = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i == 0 and j == 0 and fl == 0)
					{
						fl++;
						j = -1;
						p1++;
						i1 = rand() % 8;
						j1 = rand() % 8;
						mas[i1][j1] = 10;
						sort1(mas, n, i1, j1);
						continue;
					}
					if (p1 == m)
					{
						flag = true;
						output(mas, n, p1);
						break;
					}
					if (i == 0 and flag1 == 0)
					{
						j = f;
						flag1++;
					}
					if (mas[i][j] == 1 or mas[i][j] == 10)continue;
					if (mas[i][j] == 0)
					{
						mas[i][j] = 10;
						p1++;
						sort1(mas, n, i, j);
						/*out(mas, n);
						system("pause");*/
						if (p1 == m)
						{
							flag = true;
							output(mas, n, p1);
							break;
						}
					}
					if (flag)break;
				}
				if (flag)break;
			}
			if (flag)break;
			flag1 = 0;
			if (m != p1)
			{
				zero(mas, n);
				p1 = 0;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int p1 = 0, p2 = 0;
	int n = 8;
	int** mas1 = new int*[n];
	int** mas = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mas1[i] = new int[n];
		mas[i] = new int[n];
	}
	zero(mas, n);
	zero(mas1, n);
	int m;
	cout << "Введите количество ферзей : ";
	cin >> m;
	if (m >= 9)m = 8;
	sort(mas, n, m, p1, p2, mas1);
	for (int i = 0; i < n; i++)
	{
		delete [] mas[i];
	}
	delete [] mas;
}