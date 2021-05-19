/*
В файле задан текст. Написать функцию, определяющую длину слова. С
помощью этой функции определить, сколько слов в тексте имеют длину,
меньше заданной длины. Найденные слова записать в выходной файл.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int wordLength(char* word);
int main() {
	setlocale(LC_CTYPE, "russian");
	int wordCounter = 0, maxLength;
	char string[256], word[30];
	ifstream in("input7.txt");
	ofstream out("output7.txt");
	cout << "Введите предел длины слов: ";
	cin >> maxLength;
	out << "Слова, в которых меньше " << maxLength << " символов:\n";
	while (!in.eof()) {
		in.getline(string, 256);
		char* pch = strtok(string, " ,.!?;:-");
		while (pch != NULL) {
			strcpy(word, pch);
			pch = strtok(NULL, " ,.!?;:-");
			if (wordLength(word) < maxLength) {
				wordCounter++;
				out << word << endl;
			}
		}
	}
	out << "\nВсего таких слов: " << wordCounter;
	cout << "\nВсего таких слов: " << wordCounter;
	in.close();
	out.close();
	return 0;
}

int wordLength(char* word) {
	int i = 0;
	int len = 0;
	while (word[i]) {
		len++;
		i++;
	}
	return len;
}