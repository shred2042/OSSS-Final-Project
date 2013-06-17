//Florea Alexandru - Ionut
//313CA 

#ifndef __TREAP_H
#define __TREAP_H

#include <iostream>
#include <cstring>

template <typename T> class Treap {

	private:
		T key;
		int priority;
		Treap<T> *left, *right;
		bool nil;
		int nr_nodes;

	public:
	
		//Constructor care creaza un nod nil
		Treap() : priority(-1), left(NULL), right(NULL), nil(true), nr_nodes(0) {}
	
		// Adaugam date, transformand un nod nil intr-un nod obisnuit
		void addData(T key, int priority) {
			this->nil = false;
			memcpy(&(this->key), &key, sizeof(T));
			this->priority = priority;
			this->nr_nodes = 1;
			this->left = new Treap();
			this->right = new Treap();
		}

	 	// Stergem un nod obisnuit, transformandu-l intr-unul nil
		void delData() {
			this->nil = true;
			this->priority = -1;
			delete this->left;
			delete this->right;
			this->nr_nodes = 0;
		}

		//Verifica daca un  od este nil
		bool isNil() {
			return this->nil;
		}

		//cauta cheia in treap si intoarce true daca se afla, false altfel
		bool find(T key) {
			if(this->isNil())
				return false;
			if(key == this->key)
				return true;
			if(key < this->key) 
				return this->left->find(key);
			else 
				return this->right->find(key);
		}

		//face o rotatie la dreapta
		void rotateRight(Treap<T> *&nod) {
			Treap<T> *aux = nod->left;
		
			nod->nr_nodes = 1 + nod->right->nr_nodes + aux->right->nr_nodes;
			aux->nr_nodes = 1 + aux->left->nr_nodes + nod->nr_nodes;
		
			nod->left = aux->right;
			aux->right = nod;
			nod = aux;
		}

		//face o rotatie la stanga
		void rotateLeft(Treap<T> *&nod) {
			Treap<T> *aux = nod->right;
		
			nod->nr_nodes = 1 + nod->left->nr_nodes + aux->left->nr_nodes;
			aux->nr_nodes = 1 + aux->right->nr_nodes + nod->nr_nodes;
		
			nod->right = aux->left;
			aux->left = nod;
			nod = aux;
		}

		//adauga un nod in treap
		void insert(Treap<T> *&fatherPointer, T key, int priority) {
			if(this->isNil()) {
				this->addData(key, priority);
			}

			else {
				if(key < this->key) {
					this->left->insert(fatherPointer->left, key, priority);
					nr_nodes++;
				} 
				else {
					this->right->insert(fatherPointer->right, key, priority);
					nr_nodes++;
				}

				if(this->left->priority > this->priority) {
					this->rotateRight(fatherPointer);
				} 
				else if(this->right->priority > this->priority) {
					this->rotateLeft(fatherPointer);
				}
			}
		}

		//sterge un nod din treap
		void erase(Treap<T> *&fatherPointer, T key) {
			if(this->isNil()) {
				return ;
			}

			if(key < fatherPointer->key) {
				erase(fatherPointer->left,key);
				fatherPointer->nr_nodes--;
			}
		 	else {
				if(key > fatherPointer->key) {
					erase(fatherPointer->right,key);
					fatherPointer->nr_nodes--;
				} else 
					if(fatherPointer->left->isNil() && 
						fatherPointer->right->isNil()) {
						fatherPointer->delData();
					} 
					else if(fatherPointer->left->priority > 
							fatherPointer->right->priority) {
						rotateRight(fatherPointer);
						erase(fatherPointer,key);
					} 
					else {
						rotateLeft(fatherPointer);
						erase(fatherPointer,key);
					}
			}
		}

		//intoarce a k-a cheie din treap
		T& findKey(int k) {
			if(k == this->right->nr_nodes + 1) {
				return this->key;
			}
			else if(k < this->right->nr_nodes + 1) {
				this->right->findKey(k);
			}
			else {	
				this->left->findKey(k - this->right->nr_nodes - 1);
			}
		}
	
		//intoarce nodul cel mai din dreapta din treap
		T& returnRightMostKey() {
			Treap<T>* paux = this;
			while(paux->right != NULL && !paux->right->nil) {
				paux = paux->right;
			}
		
			return paux->key;
		}
		
		//intoarce nodul cel mai din stanga din treap
		T& returnLeftMostKey() {
			Treap<T>* paux = this;
			while(paux->left != NULL && !paux->left->nil) {
				paux = paux->left;
			}
		
			return paux->key;
		}
		
		//intoarce numarul notal de noduri din treap
		int nrNodes() {
			return this->nr_nodes;
		}
};

#endif //__TREAP_H


