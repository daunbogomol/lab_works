/*
f(x) = ln(x); (x - 1)^n / (n * x^n), n = 1, 2, ... ;
1. ������ �������� ����������� ���� ������� ����� s - ��� delta, �� ���� |f(x) �
s| < delta. ���������� ��������, ������� ������ ���� ����� ��������������, ����� ����
���������� ��� ��������. ������� ���� �����������, ���������� �������, ��� ��� �����
��������� �������� �������� �������� ���������� ������ ���� ������ ������������
�����������  �������� ������� ���� ��� ����� ����������� ������ ��������� ���������
����������� ��������. �������� ������������, ��� ����� ����������� ������
������� �� �������� �������� ����������� �������.
2. ������ �������� ����� ����������� ������ � ������� �����������
������������� ������� f(x) �������� ������ ����� ����.
*/


#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "russian");
	int i, n, m;
	double s, a, a0, delta, f, x;

	// 1
	do
	{
		cout << "������� ����� ���������� ";
		cin >> m;
	} while (m <= 0);
	cout << "������� x ";
	cin >> x;
	f = log(x);
	a0 = (x - 1) / x;
	delta = 0.1;
	cout << " delta   n \n";
	for (i = 0; i < m; i++)
	{
		n = 1;
		s = a0;    //��������� �������� ��� n = 1
		a = a0;
		while (fabs(s - f) >= delta && fabs(a) > DBL_MIN)
		{
			n++;
			a *= (n - 1) * (x - 1) / (n * x);
			s += a;
		}
		cout.width(7);
		cout << delta;
		cout.width(6);
		cout << n << '\n';
		delta /= 10;
	}

	// 2
	do
	{
		cout << "������� ���������� �������� n ";
		cin >> m;
	} while (m <= 0);
	cout << "   delta        n \n";
	// ������� �������� ��� n = 1
	n = 1;
	delta = fabs(f - a0);
	cout.precision(3);
	cout.width(11);
	cout << delta;
	cout.width(6);
	cout << n << '\n';
	// ������� � ��������� ��������, ���� m > 1
	for (n = 2; n <= m; n++)
	{
		s = a0;
		a = a0;
		for (i = 2; i <= n; i++)
		{
			a *= (i - 1) * (x - 1) / (i * x);
			s += a;
		}
		delta = fabs(f - s);
		cout.width(11);
		cout << delta;
		cout.width(6);
		cout << n << '\n';
	}
	system("pause");
	return 0;
}