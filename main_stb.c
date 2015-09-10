#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main( void) {
   MYSQL *conn;
   
   char *server = "192.168.178.43";
   char *user = "monty";
   char *password = "wert12345"; /* set me first */
   char *database = "mysql";
   conn = mysql_init(NULL);
   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
   

	printf("Mysql client version: %s\n", mysql_get_client_info());
	        
	        
   return 0;
  }
