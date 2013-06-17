//Florea Alexandru - Ionut
//313CA

#pragma once

#include <cstdio>
#include <string.h>

#include "functions.h"
#include "treap.h"
#include "pair.h"

class Trie
{
	private:
		bool isWord;	//aceasta valoare va fi setata pe true daca un cuvant se 
							//termina in nod
		Trie *sons[10];	//vectorul de fii
		Treap<Pair> *container;	//structura in care vor fi adaugate cuvintele
	
	public:
	
		//constructor care seteaza toti fii nodului radacina pe NULL
		Trie() {
			isWord = false;
			container = NULL;
			for(int i = 2; i < 10; i++) {
				sons[i] = NULL;
			}
		}
		
		//adauga un cuvant in container
		void addWord(char* word1, char* word2, int nr, int priority) {
			if(word1[0] == '\0') { //conditia de iesire din recursivitate
				Pair pair(nr, word2);
				if(container == NULL) {
					container = new Treap<Pair>(); //creaza container-ul daca nu exista
					container->insert(container, pair, priority); //adauga cuvantul
					this->isWord = true;
				}
				else {
					container->insert(container, pair, priority);
					this->isWord = true;
				}
				return;
			}
			else {	//extrage primul caracter din cuvant si se duce pe fiul
						//corespunzator	
				int x = charToInt(word1[0]);
				if(sons[x] == NULL) {
					
					sons[x] = new Trie();
					isWord = false;
					word1 = word1 + 1;
					//operatia descrisa mai sus se intampla recursiv
					sons[x]->addWord(word1, word2, nr, priority);
																				
				}
				else {
					word1 += 1;
					sons[x]->addWord(word1, word2, nr, priority);
				}
			}
		}
		
		//primeste ca parametru sirul de taste apasate si returneaza cuvantul
		//corespunzator
		char* returnWord(char* word, int k, int priority) {
			if(word[0] == '\0' && this->isWord == true) {
				Pair p;
				if(k == 0) {
					p = container->returnRightMostKey();
				}
				else {
					k = (k + 1) % container->nrNodes();
					if(k == 0)
						p = container->returnLeftMostKey();
					else
						p = container->findKey(k);
				}
				//dupa ce gaseste pereche corecta o sterge din container,
				//incrementeaza valoarea din pereche si o adauga inapoi
				char* wordFound = p.second();
				container->erase(container, p);
				p.incrementValue();
				container->insert(container, p, priority);
				return wordFound;
			}
			else {
				char c = word[0];
				int x = c - '0';
				word+=1;
				sons[x]->returnWord(word, k, priority); //cauta cuvantul recursiv
			}
		}
		
};
