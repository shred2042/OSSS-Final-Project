//Florea Alexandru - Ionut
//313CA

#pragma once

#include <cstdio>

//functie care intoarce tasta asociata unei litere
int charToInt(char c) {
	switch(c) {
		case 'a':
			return 2;
		case 'b':
			return 2;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'e':
			return 3;
		case 'f':
			return 3;
		case 'g':
			return 4;
		case 'h':
			return 4;
		case 'i':
			return 4;
		case 'j':
			return 5;
		case 'k':
			return 5;
		case 'l':
			return 5;
		case 'm':
			return 6;
		case 'n':
			return 6;
		case 'o':
			return 6;
		case 'p':
			return 7;
		case 'q':
			return 7;
		case 'r':
			return 7;
		case 's':
			return 7;
		case 't':
			return 8;
		case 'u':
			return 8;
		case 'v':
			return 8;
		case 'w':
			return 9;
		case 'x':
			return 9;
		case 'y':
			return 9;
		case 'z':
			return 9;
	}
}
	
//functie care intoarce numarul care urmeaza dupa '*' si modifica sirul astefel
//incat sa ramana doar tastele apasate
int index(char** str) {
	for(int i = 0; i < strlen(*str); i++) {
		if((*str)[i] == '*') {
			int nr = atoi(&((*str)[i + 1]));
			(*str)[i] = '\0';
			return nr;
		}
	}
	return 0;
}




















