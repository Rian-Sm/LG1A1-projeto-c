//função criar arquivo txt nome
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void gerar_txt(char *n, char *p, char *s){
	int auxstr, i;
	while (i < strlen(n)){
				if (n[i] == ' '){
					n[i] = '_';
				}
			i++;
			}
			printf("%s\n", n); getch();
			
			strcpy(s, "RESULTADO_");
			auxstr = strlen(n);
			strncat(s, n, auxstr);
			strcat(s, "_");
			auxstr = strlen(p);
			strncat(s, p, auxstr);
			strcat(s, ".txt");
			
			printf("%s\n", s); getch();
}
int main(){
	char no[20], pro[20], save[50];
	gets(no);
	gets(pro);
	gerar_txt(no, pro, save);
	printf("%s", save); getch();
	return 0;
}
