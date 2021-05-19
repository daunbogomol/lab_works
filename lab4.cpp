/*
Получить все простые делители числа N
*/


#include <iostream>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "russian");
	int n, d, dd;

	cout << "Введите N: ";
	cin >> n;
	cout << "Простые делители числа N: ";
	for (d = 2; d <= n/2; d++) {
		if (n%d == 0) {
			if (d == 2 || d == 3) {
				cout << d << " ";
				continue;
			}
			for (dd = 2; dd*dd < d && d%dd != 0; dd++);
			if (dd*dd > d) {
				cout << d << " ";
				continue;
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}