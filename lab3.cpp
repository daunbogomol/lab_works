/*
���������� k-� ����� ������������������ 123456789101112131415...,
� ������� ������ �������� ��� ����������� �����
*/


#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "russian");
	int k;                   //������� ������� �����
	int number = 1;          //������ �������� �������� �����
	int tempNumber;          //��������������� ���������� ��� ���������� �������� � ������
	int totalCounter = 0;    //������� ������� ������� ���� � ������������������
	int totalDigitCounter;   //���������� ���� � ������� ����� ������������������
	int digitCounter = 0;    //������� ������� ����� � ������� �����
	int digitCounterEnd;     //������� ������� ����� � ����� �����
	int result = number;

	cout << "������� k: ";
	cin >> k;

	while (totalCounter < k) {
		tempNumber = number;
		totalDigitCounter = 0;
		while (tempNumber > 0) {                                //������� ���������� ���� � �����
			tempNumber /= 10;
			totalDigitCounter++;
			if (totalCounter + totalDigitCounter == k) {        //���� � ���. ����� ����������� ������� ������� k,
				digitCounter = totalDigitCounter;               //���������� ����� ���� ������� � ����� �����
			}
		}                                                       //�� ����� �������, ����� ������ ����� ���������� ���� � �����
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