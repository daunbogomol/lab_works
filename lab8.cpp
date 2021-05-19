/*
* �������� �������, ���������� n ����� � ������� p ����� x �� n ������ ����� ����� y.
* �������� ���������� ��� �������� ����� x � y. ��������� �������� � ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
char* print_bit (unsigned int x);
int main() {
	setlocale(LC_CTYPE, "russian");
	unsigned int x, y, m, sh, p, n, yn;
	char xStr[40], yStr[40];
	m = sizeof(unsigned int) * 8;
	do {
		cout << "x: ";
		cin >> hex >> x;
	} while (x < 0);
	do
	{
		cout << "\ny: ";
		cin >> hex >> y;
	} while (y < 0);
	do
	{
		cout << "\n������� p: ";
		cin >> dec >> p;
	} while (!(p <= m));
	do
	{
		cout << "\n����� ����� ��� ������ n: ";
		cin >> dec >> n;
	} while (!(n <= p));

	strcpy(xStr, print_bit(x));        //�������� ��������, �.�. �������� ��� ������������� ������� ���������� ���������� �������
	strcpy(yStr, print_bit(y));

	cout << "x: " << xStr << "\ny: " << yStr << endl;   //����� �� ����� x � y � �������� ��
	yn = y;
	yn = (yn << m - n) >> m - n;                 //� ���������� �������� n ��������� ����� ����� y
	sh = ~0;
	sh = ((sh << m - p) >> m - n) << p - n;      //������ � ��������� �� ����� ���������� �������� � x
	sh = ~sh;
	x = x & sh;          //�������� ���������� ���� � x �� ����
	yn <<= p - n;         //��������� ����, �� ������� ��������, � ������ ������� (�� ����� ���������� � x)
	x = x | yn;

	ofstream out("output8.txt");   //������� ���������� � ����
	strcpy(xStr, print_bit(x));
	strcpy(yStr, print_bit(y));
	out << "����������\nx: " << xStr << "\ny: " << yStr << endl;
	out << "������� p = " << p << "\n����� ����� n = " << n << endl;
	out.close();
	return 0;
}

char* print_bit(unsigned int x) {
	unsigned int sh = ~0, i = 0, k = 0;
	char count[40];
	sh = ~(sh >> 1);
	while (sh > 0) {
		count[i++] = sh & x ? '1' : '0';
		k++;
		if (k == 8) {
			count[i++] = ' ';
			k = 0;
		}
		sh >>= 1;
	}
	count[i] = '\0';
	return count;
}