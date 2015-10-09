#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
//#######################
//## moana.conf als Mysql Config file wird benötigt im selben Ordner wie
//## das Main Programm

int main(void) {

	
	MYSQL *conn;
	char inputLine[6][50];
	const char *configFilename="moana.conf";
	FILE *configFile;
	int c,i=0;
	long int mysqlPort;
	
	//Datenbankconnection und splitten der Strings
	char *pch;
	char mysqlConfig[6][50];
	char *pserver, *puser, *ppassword, *pdatabase, *pport;
	char *errorStringtoPort;
	
	printf("tewt");
	
	if(!file_existing(configFilename))
		{return 10;}
	else{
	
	configFile = fopen("moana.conf","r");
		while((c=fgetc(configFile)) != EOF){							//Solange fortsetzen wie das Ende Der File erreicht ist
			for(i=0;i<7;i++){											//Zeilenweisen einlesen der Config #Problem:Ersteszeichen 
				fgets(inputLine[i],50,configFile);		
				if(inputLine[i][(int)strlen(inputLine[i])-1]==10)		//Löschen des CR(\n)
					inputLine[i][(int)strlen(inputLine[i])-1]= 0 ;		
			}
		}
	
	
		
	pserver = mysqlConfig[0];
	puser = mysqlConfig[1];
	ppassword = mysqlConfig[2];
	pdatabase = mysqlConfig[3];
	pport = mysqlConfig[4];
	
	mysqlPort = strtol(mysqlConfig[4],&errorStringtoPort,10);
	
	//Die Config Strings trennen und neu speichern
	for(i=0;i<5;i++){
		pch = strtok(inputLine[i+1],"=");
		pch=strtok(NULL, "=");
		strncpy(mysqlConfig[i],pch,sizeof(mysqlConfig[i]));
		}	
	
	/*for(i=0;i<6;i++)
		puts(mysqlConfig[i]);
	*/
			
	fclose(configFile);
	
	
	//***************************************************
	//****************MySQL CONNECTION*******************
	//***************************************************
	exit(1);
	conn = mysql_init(NULL);
		
	// Connect to database 
	if(!mysql_real_connect(conn, pserver,
			 puser, ppassword, pdatabase, mysqlPort, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	   }
   

	printf("Mysql client version: %s\n", mysql_get_client_info());
	}       
	
   return 0;
  }
