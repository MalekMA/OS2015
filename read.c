#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
	FILE *fp = fopen("processes.txt", "r");
	const char s[2] = ",";
	char *token;

	char *name;
	int priority;
	int pid;
	int runtime;

	if(fp != NULL) {
		for(int i=0;i<10;i++){
			token = strtok(NULL,s);
			name = token;
			token = strtok(NULL,s);
			priority = atoi(token);
			token = strtok(NULL,s);
			pid = atoi(token);
			token = strtok(NULL, s);
			runtime = atoi(token);
			printf("%s %d %d %d", name, priority, pid, runtime);
		}
	}








	/**char name[256];
	int priority;


	for(int i=0;i<10;i++){
		for(int i=0;i<4;i++){

		}
	}
	**/

	fclose(fp);
	return 0;
}
