//Florea Alexandru - Ionut
//313CA

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "trie.h"

int main() {
	srand(time(0));
	Trie trie;
	FILE *fin = fopen("date.in", "r");
	FILE *fout = fopen("date.out", "w");
	
	int nrWords; //numarule de linii care contin cuvantul si numarul de aparitii
	fscanf(fin, "%d", &nrWords);
	
	for(int i = 0; i < nrWords; i++) {
		char* word = new char[40];
		int nr;
		int priority =  rand() % 1000;
		fscanf(fin, "%s%d", word, &nr);
		trie.addWord(word, word, nr, priority);
	}
	
	int nrStr; //numarul de linii care contin sirul de taste apasate
	fscanf(fin, "%d", &nrStr);
	
	for(int i = 0; i < nrStr; i++){
		char* str = new char[40];
		fscanf(fin, "%s", str);
		int nr = index(&str);
		int priority =  rand() % 1000;
		fprintf(fout, "%s\n", trie.returnWord(str, nr, priority)); 
	}
	
	fclose(fin);
	fclose(fout);

	return 0;	
}
