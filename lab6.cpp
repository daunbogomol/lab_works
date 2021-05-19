/*
� ����� ����� ������ ����. ��������� ������ ����, ������������� �
������ ����� ������ ����.
*/

#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "russian");
	char** word, tmpW[30];
	int *wordCounter, i, N, n = 0;
	ifstream in("input6_reg.txt");
	ofstream out("output6.txt");
	in >> N >> ws;
	word = new char* [N];
	wordCounter = new int [N];

	while (!in.eof()) {
		in.getline(tmpW, 256, ',');
		in >> ws;
		int k = 0;
		while (tmpW[k]) {                         //������ ����� �������� � ������ ������� ��������
			tmpW[k] = tolower(tmpW[k]);
			k++;
		}
		for (i = 0; i <= n; i++) {                //������������� ������ ��� ������������� ����
			if (i == n) {                         //���� ����� �� ��������� �� � ����� �� ���� ����������,
				word[n] = _strdup(tmpW);          //��� ��������� � ������
				wordCounter[n++] = 1;
				break;
			}
			if (strcmp(word[i], tmpW) == 0) {     //���� ������� ����� ����������� � ����� �� ����������,
				wordCounter[i] += 1;              //����������� ���������� ���������� �� 1 ��� ����� �����
				break;                            //��������� � ������ �����
			}
		}
	}

	out << "������������� �����: \n";
	for(i = 0; i < n; i++)
		if (wordCounter[i] > 1) {
			out.setf(ios::left);
			out << word[i] << endl;
		}
	in.close();
	out.close();
	return 0;
}