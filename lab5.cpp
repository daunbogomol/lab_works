/*
Задан список студентов с указанием их среднего балла за текущую сессию.
Упорядочить список студентов по убыванию балла, а в случае равенства баллов,
упорядочить список студентов в алфавитном порядке.
*/
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "russian");
	int n, i, f;
	double *score, stmp;
	char** name, * ntmp, fam[30];
	ifstream In("input5.txt");
	ofstream Out("output5.txt");
	In >> n;
	name = new char* [n];
	score = new double [n];
	for (i = 0; i < n; i++) {
		In >> fam >> score[i];
		name[i] = _strdup(fam);
	}

	//сортировка пузырьком
	do {
		f = 0;
		for (i = n - 1; i > 0; i--) {
			if (score[i] > score[i-1] || (score[i] == score[i-1] && strcmp(name[i-1], name[i]) > 0)) {
				stmp = score[i];
				score[i] = score[i-1];
				score[i-1] = stmp;
				ntmp = name[i];
				name[i] = name[i-1];
				name[i-1] = ntmp;
				f = 1;
			}
		}
	} while (f);
	Out << "Отсортированный список по убыванию среднего балла:\n";
	for (i = 0; i < n; i++) {
		Out << name[i] << ' ';
		Out << score[i] << endl;
	}
	In.close();
	Out.close();
	system("pause");
	return 0;
}