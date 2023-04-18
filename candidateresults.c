#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	FILE *ptrread;
	FILE *ptrwrite;
	char strread[500];
	char strwrite[500];
	char *tokenname;
	char *tokenplace;
	char filename[50] = "Congress.txt";
	char filename2[50] = "Candidateresults.html";
	int i = 1;
	ptrread = fopen("Congress.txt","r");
	if (ptrread == NULL) {
		printf("Cannot open file to read %s",filename);
		return 1;
	}
	ptrwrite = fopen(filename2,"w");
	if (ptrwrite == NULL) {
		printf("no read file %s",filename2);
		return 1;
	}
	fprintf(ptrwrite,"<html>\n");
	fprintf(ptrwrite,"<table>\n");
	fprintf(ptrwrite,"<tr>\n");
	fprintf(ptrwrite,"<td>");
	fprintf(ptrwrite,"SL no.");
	fprintf(ptrwrite,"</td>\n");
	fprintf(ptrwrite,"<td>");
	fprintf(ptrwrite,"Constituency");
	fprintf(ptrwrite,"</td>\n");
	fprintf(ptrwrite,"<td>");
	fprintf(ptrwrite,"Candidate");
	fprintf(ptrwrite,"</td>\n");
	fprintf(ptrwrite,"</tr>\n");
	while (fgets(strread,500,ptrread) != NULL) {
		strread[strlen(strread) -1] ='\0';
		tokenplace = strtok(strread,"|");
		tokenname = strtok(NULL,"|");
		fprintf(ptrwrite,"<tr>\n");
		fprintf(ptrwrite,"<td>");
		fprintf(ptrwrite,"%d ",i);
		fprintf(ptrwrite,"</td>\n");
		fprintf(ptrwrite,"<td>");
		fprintf(ptrwrite,"%s",tokenplace);
		fprintf(ptrwrite,"</td>\n");
		fprintf(ptrwrite,"<td>");
		fprintf(ptrwrite,"%s",tokenname);
		fprintf(ptrwrite,"</td>\n");
		fprintf(ptrwrite,"</tr>\n");
		i++;
	}
	fprintf(ptrwrite,"</table>\n");
	fprintf(ptrwrite,"</html>\n");
	fclose(ptrread);
	fclose(ptrwrite);
return 0;
}

