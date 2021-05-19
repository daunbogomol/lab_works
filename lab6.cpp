/*
В файле задан список слов. Составить список слов, встречающихся в
списке более одного раза.
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
		while (tmpW[k]) {                         //каждое слово приводим к одному нижнему регистру
			tmpW[k] = tolower(tmpW[k]);
			k++;
		}
		for (i = 0; i <= n; i++) {                //просматриваем список уже встречавшихся слов
			if (i == n) {                         //если слово не совпадает ни с одним из всех предыдущих,
				word[n] = _strdup(tmpW);          //оно заносится в список
				wordCounter[n++] = 1;
				break;
			}
			if (strcmp(word[i], tmpW) == 0) {     //если текущее слово повторяется с одним из предыдущих,
				wordCounter[i] += 1;              //увеличиваем количество повторений на 1 для этого слова
				break;                            //переходим к новому слову
			}
		}
	}

	out << "Повторяющиеся слова: \n";
	for(i = 0; i < n; i++)
		if (wordCounter[i] > 1) {
			out.setf(ios::left);
			out << word[i] << endl;
		}
	in.close();
	out.close();
	return 0;
}