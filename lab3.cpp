/*
Определить k-ю цифру последовательности 123456789101112131415...,
в которой подряд записаны все натуральные числа
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "russian");
	int k;                   //позиция искомой цифры
	int number = 1;          //хранит значение текущего числа
	int tempNumber;          //вспомогательная переменная для выполнения операций с числом
	int totalCounter = 0;    //счетчик текущей позиции цифр в последовательности
	int totalDigitCounter;   //количество цифр в текущем числе последовательности
	int digitCounter = 0;    //позиция искомой цифры в текущем ЧИСЛЕ
	int digitCounterEnd;     //позиция искомой цифры с конца числа
	int result = number;

	cout << "Введите k: ";
	cin >> k;

	while (totalCounter < k) {
		tempNumber = number;
		totalDigitCounter = 0;
		while (tempNumber > 0) {                                //считаем количество цифр в числе
			tempNumber /= 10;
			totalDigitCounter++;
			if (totalCounter + totalDigitCounter == k) {        //если в тек. числе встречается искомая позиция k,
				digitCounter = totalDigitCounter;               //записываем номер этой позиции в самом числе
			}
		}                                                       //из цикла выходим, когда найдем общее количество цифр в числе
		totalCounter += totalDigitCounter;
		number++;
	}
	digitCounterEnd = totalDigitCounter - digitCounter + 1;
	tempNumber = number - 1;
	for (int i = 1; i <= digitCounterEnd; i++) {
		result = tempNumber % 10;
		tempNumber /= 10;
	}
	cout << result << endl;
	system("PAUSE");
	return 0;
}