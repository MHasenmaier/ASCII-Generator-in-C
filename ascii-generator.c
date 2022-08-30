#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/* *** *** *** *** *** *** *** *** *** Konstanten *** *** *** *** *** *** *** *** *** */

//Standardgr�sse f�r Arrays
#define ARRAYGROSSE 255
//ASCII (Zahlen => 48=0 -> 57=9)
#define OBENZAHL	57
#define UNTENZAHL 48
//ASCII (Gro�buchstaben => A=65 -> Z=90)
#define OBENGROSSBUCHSTABE 90
#define UNTENGROSSBUCHSTABE 65
//ASCII (kleinbuchstaben => a=97 -> z=122)
#define OBENKLEINBUCHSTABE 122
#define UNTENKLEINBUCHSTABE 97
//SuchStringL�nge
#define SSTRLEN 1

//Variablen - Global

/* *** *** *** *** *** *** *** *** *** Funktionen *** *** *** *** *** *** *** *** *** */
char ascii_zeichen_generator(void);
void ascii_array_generator(char* quellString);
int strSrch(char sourceArray[], char searchArray[]);

/* MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN */
int main(void){
	char quellString[ARRAYGROSSE] = {0};
	char suchString[SSTRLEN] = {0};
	//char* trefferPointer;
	unsigned int trefferCounter = 0;
	char erstesZeichen;

	
	ascii_array_generator(&quellString);
	
	strncpy(suchString, quellString, SSTRLEN);
	//suchString[SSTRLEN + 1] = '\0';
	strstr(quellString, suchString);
	
	char* trefferPointer = strstr(quellString, suchString);
	trefferCounter = trefferPointer - quellString;
	char* trefferPointer2 = strstr((quellString + trefferCounter + 1), suchString);
	
	
	while(1) {
		if(strstr(quellString, suchString)){
			trefferPointer = strstr(quellString, suchString) + 1;
			trefferCounter++;
			printf("%ud: Treffer ", trefferCounter);
		} else {
			printf("Fehler! nach: %ud Treffern", trefferCounter);
			break;
		}
	}
	
	
	/*
	for (int i = SSTRLEN; i >= 0; i--){
		strncpy(such_string, quellString, i);
		such_string[i] = '\0';
		while (strstr(array, such_string) != NULL) {
			treffer_counter++;
		}
	}*/
	
	return 0;
}

/* *** void ascii_array_generator(void)
Ein Array wird mit zufalligen ASCII-Zeichen (Zahlen, Gross- und Kleinbuchstaben) beschrieben)
Input: none
Output: none
*** */

void ascii_array_generator(char* quellString) {

	for (int i = 0; i < sizeof(quellString); i++){
		quellString[i] = ascii_zeichen_generator();
		printf("%2c", quellString[i]);
	}	
	
	printf("\n\nquellString gefullt\n");
}

/* *** char ascii_zeichen_generator(void)
Ein zufalliges ASCII-Zeichen (Zahlen, Gross- und Kleinbuchstaben) wird generiert und zuruckgegeben)
Input: none
Output: rnd char (0-9;a-z;A-Z)
*** */

char ascii_zeichen_generator(void) {
	srand(time(NULL));
	int rnd_spalte = (rand() % 3) + 1; // Fur die entsprechende Art der ASCII-Zeichen (Spalten der ASCII-Tabelle)
	int untere_grenze = 0;
	int obere_grenze = 0;
	char ascii = 0;
	
	switch(rnd_spalte){
		case 1:	//Zahlen => 48=0 -> 57=9
			untere_grenze = UNTENZAHL;
			obere_grenze = OBENZAHL;
			break;
		case 2:	//Grossbuchstaben => A=65 -> Z=90
			untere_grenze = UNTENGROSSBUCHSTABE;
			obere_grenze = OBENGROSSBUCHSTABE;
			break;
		case 3:	//kleinbuchstaben => a=97 -> z=122
			untere_grenze = UNTENKLEINBUCHSTABE;
			obere_grenze = OBENKLEINBUCHSTABE;
			break;
		default:
			printf("Da lief was schief im ascii_generator() -> default");
			break;
	}
	
	ascii = (char) ((rand() % (obere_grenze - untere_grenze)) + untere_grenze);
	return ascii;
}

/* *** strSrch(char sourceArray[], char searchArray[])
sucht einen suchstring in einem quellstring
Input: suchstring (char) und quellstring(char)
Output: rnd char (0-9;a-z;A-Z)
*** */

int strSrch(char sourceArray[], char searchArray[]){
	int trefferAnzahl = 0;
	//int langeSuchStrng = strlen(searchArray);
	int lenSearchArray = strlen(searchArray);
	int lenSourceArray = strlen(sourceArray);
	
	for (int j = 0; j < lenSearchArray; j++) {
		for (int i = 0; i < lenSourceArray; i++){
			// searchArray: l�nge �ber Funktion ermitteln und als Alternative Z�hlschleife einbauen
			if ((sourceArray[i] == searchArray[j]) && (sourceArray[i + 1] == searchArray[j + 1]))
			{
				printf("Zeichen gefunden an der %d. Stelle.\n", i);
				trefferAnzahl++;
			}
		}
	}
	return trefferAnzahl;
}
