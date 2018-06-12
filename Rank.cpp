#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <malloc.h>
using namespace std;
typedef struct rankNode {
	int score;
	int maxCombo;
	int length;
};
rankNode *readRanking() {
	int length=0;
	rankNode node[10];
	ifstream file("a.txt");
	int i=0;
	while (file >> node[i].score) {
		file >> node[i].maxCombo;
//		cout << node[i].score << "#" << node[i].maxCombo << endl;
		length++;
		i++;
	}
	for (i = 0; i < length; i++)
		node[i].length = length;
	file.close();
	return node;
}
void writeRanking(int mode, int score,int maxCombo) {
	int m = mode;
	char *outFile;
	rankNode* node = readRanking();
	rankNode newNode;
	rankNode rankN[10];
	newNode.score = score;
	newNode.maxCombo = maxCombo;
	int length = node[0].length;
	int pos = length;
	for (int i = length - 1; i > 0; i--) {
		if (newNode.score > node[i].score)
			pos--;
		else
			break;
	}
	for (int i = 0; i < pos; i++)
		rankN[i] = node[i];
	if (pos < 10) {
		rankN[pos] = newNode;
		for (int i = pos + 1; (i < length + 1) && i < 10; i++) 
			rankN[i] = node[i - 1];
		if(length<10)
		length++;
	}
	for (int i = 0; i < length+1; i++) {
//		cout << rankN[i].score << "#" << rankN[i].maxCombo << endl;
		rankN[i].length=length;
	}
	switch (m) {
	case 1:outFile = "a.txt"; break;
	case 2:outFile = "b.txt"; break;
	case 3:outFile = "c.txt"; break;
	default:break;
	}
	ofstream out(outFile);
	for (int i = 0; i < length; i++) 
		out << rankN[i].score << "  " << rankN[i].maxCombo << endl;
	out.close();
}
int main()
{
	writeRanking(1, 249, 13);
	system("pause");
    return 0;
}

