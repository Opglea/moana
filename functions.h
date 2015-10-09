//Funktionen functions.h
#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Funktion überprüft ob die config file vorhanden ist.
 * file exists = -1
 * file not ex = 0
*/
int file_existing(const char *filename)
{
	FILE *pDatei;
	int res=0;
	pDatei = fopen(filename,"r");
	
	if(pDatei != NULL){
		res = -1;
		fclose(pDatei);
		printf("erroe");
	}else{
		 res = 0;}
	
	return res;
}
