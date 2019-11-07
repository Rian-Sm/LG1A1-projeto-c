// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <iostream>

using namespace std;

// funções externas
void menu(char *choice);
void cadaster_user();
void cadaster_quest();
void view ();
void toBuild ();
void info ();

// variaveis globais
int i, bi, n;



////////// função principal ////////////////
int main(){
	setlocale (LC_ALL, "");
	
	char choice;

	cadaster_user();
do{
		
	menu(&choice);
		
	switch(choice) {
	
		case '1': 
				cadaster_quest();
			break;
		
		case '2' :
			break;
		
		case '3' :
			break;
		
		case '4' :
			break;
		
		case 'f' :
			return 0;
		
		default :
			printf ("\n\n erro na escolha \n\n");
			i--;
			printf ("numero =  %i", i);	
			break;		
	}	
	}while(i <=2 );		
}
///////////		menu						///////////
void menu(char *choice){
		printf ("\n=================================================");
		printf ("\n       TESTE DOS SISTEMAS REPRESENTACIONIS");
		printf ("\n=================================================");
		printf ("\n            1. CADASTRAR QUETIONARIO");
		printf ("\n            2. VISUALIZAR QUESIONARIO");
		printf ("\n            3. REALIZAR TESTE");
		printf ("\n            4. SOBRE O TESTE");
		printf ("\n            F. FIM");
		printf ("\n=================================================");
		printf ("\n escolha ->");
		fflush(stdin);
		cin >> *choice;
}
///////////		cadastro do questionário	///////////
void cadaster_user (){ 
	char password[20], nome[20], prontuario[20], save[50];
	int auxstr;
	FILE *arq;
	
	n = 0;
	i = 0;
	strcpy(password, "master");
	
	while(i<1){
		cout << "\n\n digite seu nome -> ";
		fflush(stdin);
		gets (nome);
	
		if(strcmp(nome, password) == 0){
			i++;
		}else {
			
			cout << "\n digite seu prontuario ->";
			cin >> prontuario;
			
			while (n < strlen(nome)){
				if (nome[n] == ' '){
					nome[n] = '_';
				}
			n++;
			}
		
			strcpy(save, "RESULTADO_");
			auxstr = strlen(nome);
			strncat(save, nome, auxstr);
			strcat(save, "_");
			auxstr = strlen(prontuario);
			strncat(save, prontuario, auxstr);
			strcat(save, ".txt");
			
			arq = fopen (save ,"w");
			
			if (arq == NULL){
				cout << "erro na criacao do arquivo!";
			}
			else {
				cout << "arquivo criado com sucesso!";
			}
		}
	}
}
void cadaster_quest(){
	printf("vc logou no case1");
//	system("cadaster_case1.exe");

}
