//Florea Alexandru - Ionut
//313CA

#pragma once

#include <cstdio>
#include <cstring>

//clasa asemanatoare cu cea din STL
class Pair {
	private:
		int value;
		char* str;
	
	public:
	
		//constructor care construieste perechea
		Pair(int value, char* str) {
			this->value = value;
			this->str = strdup(str);
		}
		
		//constructor fara parametri
		Pair() {}
		
		//returneaza primul element din pair
		int first() {
			return value;
		}
		
		//returneaza al doilea element din pair
		char* second() {
			return str;
		}
		
		//incrementeaza valoarea primului element din pair
		void incrementValue() {
			value ++;
		}
		
		//am supraincarcat operatorii de comparatie pentru simplitate
		
		bool operator<(const Pair& p) {
			if(value < p.value)
				return true;
			else if(value == p.value && strcmp(str, p.str) > 0)
				return true;
			else
				return false;
		}
		
		bool operator>(const Pair& p) {
			if(value > p.value)
				return true;
			else if(value == p.value && strcmp(str, p.str) < 0)
				return true;
			else
				return false;
		}
		
		bool operator==(const Pair& p) {
			if((value == p.value) && (strcmp(str, p.str) == 0))
				return true;
			else
				return false;
		}
};














