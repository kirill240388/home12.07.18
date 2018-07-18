#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	int task;
	cin >> task;
	if(task==1)
		{
			// *�������� ���������, ������� �������� ��� ���� � ���������� ������� �� -1.

			int a[10][10] = { { 1, 2, 3 }, 4, 5, 6, 7, 8, 9 };

			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (a[i][j] == 0) a[i][j] = -1;
					cout << right << setw(2) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		
		if(task==2)
		{
			// ***�������� ���������� ������. ��������� ��� ���������� ������� � �������� �� �����.
			// ������������ �������� ���������� ������� � ���������(�����, ������, �����, ����).
			// ��������� ����� ������� � �������� �� ����� ���������� ���������.
			// ����� �����������.
			// ��������, ���� �� ����� ��������� ������
			// 1 2 0 4 5 3
			// 4 5 3 9 0 1
			// � ������������ ������ ����� �� 2 ������� ������, �� �� �������
			// 5 3 1 2 0 4
			// 0 1 4 5 3 9

			const int n = 5;
			const int m = 10;
			int i, j;
			int k = 0;

			int a[n][m];
			int b[n][m];

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					/*a[i][j] = rand() % 10;*/
					k += 1;
					a[i][j] = k;
					cout << left << setw(2) << a[i][j] << " "; // �� ������� ��������� �����, �� ��� ��������� ������
				}
				cout << endl;
			}
			cout << endl << endl;

			int updown;
			int move;
			cout << "�������� ���������� ������� �����-���� (������������� ����� - ����� ����, ������������� - ����� �����): ";
			cin >> updown;
			cout << endl << endl;

			if (abs(updown) > n) updown = updown%n; //����� ���������� ������� ������, ��� ��������
			if (updown < 0) updown = n + updown; //����� �������� ������������� �����, �.�. ����� ����� �����

			if (updown != 0)
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < m; j++)
					{
						if (i + updown < n)
							b[i + updown][j] = a[i][j];
						else
							b[abs(n - updown - i)][j] = a[i][j];
					}
				}

				for (i = 0; i < n; i++) // �������������� ������ "a" � ������ ������� ��������
					for (j = 0; j < m; j++)
						a[i][j] = b[i][j];
			}

			cout << "�������� ���������� ������� �����-������ (������������� ����� - ����� ������, ������������� - ����� �����): ";
			cin >> move;
			cout << endl << endl;

			if (abs(move) > m) move = move%m; //����� ���������� ������� ������, ��� ��������� � ������
			if (move < 0) move = m + move; //����� �������� ������������� �����, �.�. ����� ����� �����

			if (move != 0)
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < m; j++)
					{
						if (j + move < m)
							b[i][j + move] = a[i][j];
						else
							b[i][abs(m - move - j)] = a[i][j];
					}
				}
			}

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << left << setw(2) << b[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		
		if(task==3)
		{
			// **�������� ���������� ������.��������� ��� ���������� ������� � �������� �� �����.
			// ��������� ���������� ��������� � ������ ������ �������.
			// ���������� ��������� �������� �� �����.

			int a[100][100];
			int n = 10;
			/*cout << "������� ����������� ������� ������� (1 ��������): ";
			cin >> n;*/
			int i, j;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = rand() % 100;
					cout << right << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;

			for (int k = 0; k < n; k++)
			{
				for (i = 1; i < n; i++)
				{
					j = i;
					while ((a[k][j] < a[k][j - 1]) && j > 0)
					{
						swap(a[k][j], a[k][j - 1]);
						j--;
					}
				}
			}

			cout << "SORTED:" << endl;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					cout << right << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		
	
	
}
