//tela_login
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void login (){
	char nome[20], prontuario[20], password[20], save[50];
	int auxSTR, i=0, n=0;
	FILE *arq;
	
	strcpy(password, "MASTER");
	
	while(i<1){
		system("cls");
		printf("==================== cadastro de usuario ======================\n");
		printf("digite seu nome completo\t-> "); fflush(stdin); gets(nome);
		strcpy(nome, strupr(nome));
		
		if(strcmp(nome, password)==0){
			i++;
		} else {
			printf("digite seu printuario\t-> "); fflush(stdin); scanf("%s", &prontuario);
			strcpy(prontuario, strupr(prontuario));
			
			while(n<strlen(nome)){
				if(nome[n] == ' '){
					nome[n] = '_';
				}
				n++;
			}
			strcpy(save, "RESULTADO_");
			auxSTR = strlen(nome);
			strncat(save, nome, auxSTR);
			strcat(save, "_");
			auxSTR = strlen(prontuario);
			strncat(save, prontuario, auxSTR);
			strcat(save, ".txt");
			
			arq = fopen(save, "w");
			
			if(arq == NULL){
				printf("\n\n erro na abertura do arquivo!!");
				getch ();
			} else {
				printf("\n\n arquivo criado com sucusso!!");
				getch();
			}
		}
	}
}
//função main
int main(){
	login();
	return 0;
}
