/*
* Написать функцию, заменяющую n битов с позиции p числа x на n правых битов числа y.
* Провести вычисление для заданных чисел x и y. Результат записать в файл
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
		cout << "\nпозиция p: ";
		cin >> dec >> p;
	} while (!(p <= m));
	do
	{
		cout << "\nчисло битов для замены n: ";
		cin >> dec >> n;
	} while (!(n <= p));

	strcpy(xStr, print_bit(x));        //пришлось добавить, т.к. напрямую при использовании функции печатаются непонятные символы
	strcpy(yStr, print_bit(y));

	cout << "x: " << xStr << "\ny: " << yStr << endl;   //вывод на экран x и y в двоичной сч
	yn = y;
	yn = (yn << m - n) >> m - n;                 //в переменной хранится n последних битов числа y
	sh = ~0;
	sh = ((sh << m - p) >> m - n) << p - n;      //шаблон с единицами на месте заменяемых символов в x
	sh = ~sh;
	x = x & sh;          //заменяем изменяемые биты в x на нули
	yn <<= p - n;         //переносим биты, на которые заменяем, в нужную позицию (на место заменяемых в x)
	x = x | yn;

	ofstream out("output8.txt");   //выводим результаты в файл
	strcpy(xStr, print_bit(x));
	strcpy(yStr, print_bit(y));
	out << "Результаты\nx: " << xStr << "\ny: " << yStr << endl;
	out << "позиция p = " << p << "\nчисло битов n = " << n << endl;
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