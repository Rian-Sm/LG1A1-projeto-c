// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <iostream>

using namespace std;

#define QTD 2
// variaveis globais
int i, bi, n, j;
FILE *arq, *arq_w;

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario;
// funções externas
void menu(char *choice);
int cadaster_user(char *nome[], prontuario[], save[]);
void cadaster_quest();
void view();
void test();
void info();

////////// função principal ////////////////
int main()
{
	setlocale (LC_ALL, "");
	char nome[20], prontuario[20], save[50];
	char choice;
	i=0;
	
	n = cadaster_user();
	
	do{
			system("cls");
		if(i==2){
			printf ("\n\n Erro na escolha!! Faz de novo, faz direito \n\n");
		}
		menu(&choice);
			
		switch(choice) {
		
			case '1':
				 system("cls");
				cadaster_quest();
				i=1;
				break;
			
			case '2' :
				view();
				i=1;
				break;
			
			case '3' :
				test();
				i=1;
				break;
			
			case '4' :
				break;
			
			case 'f' :
				return 0;
			
			default :
				i=2;
				printf ("numero =  %i", i);	
				break;		
	}	
	}while(i <=2 );		
}
///////////	  	menu									///////////
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
///////////		cadastro do usuario || senha de acesso	///////////
int cadaster_user (char *nome[], prontuario[], save[]){ 
	char password[20];
	int auxstr;
	
	n = 0;
	i = 0;
	strcpy(password, "MASTER");
	
	while(i<1){
		system("cls");
		cout << "================= CADASTRO DE USUARIO =================";
		cout << "\n\n digite seu nome -> ";
		fflush(stdin);
		gets (nome);
		strcpy(nome, strupr(nome));
	
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
///////////		cadastro do questionário				///////////
void cadaster_quest(){
	
	questionario quest;
	
	arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
	
	if(arq == NULL){
		printf("erro na criação do arquivo");
	}
	else{
		printf("\n ================= CADASTRAR QUESTIONARIO =====================");
		
		for(i=0 ; i<QTD ; i++ ){
			quest.nroFrase=i; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;
		
		    printf("\ndigite a sua digite a pergunta -> "); fflush(stdin); gets(quest.frase);
		    printf("\ndigite a alternativa 1 -> ");fflush(stdin); gets(quest.item_1);
		    printf("\ndigite a alternativa 2 -> ");fflush(stdin); gets(quest.item_2);
		    printf("\ndigite a alternativa 3 -> ");fflush(stdin); gets(quest.item_3);
		    printf("\ndigite a alternativa 4 -> ");fflush(stdin); gets(quest.item_4);
		    
		    fwrite(&quest, sizeof(questionario), 1, arq);
	    }
	fclose(arq);
    }	
}
/////////    	visualizar questionario			////////////
void view(){
	questionario quest[QTD];
	arq = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	arq_w = fopen("TESTE_SISTEMA_REPRESENTACIONAL.TXT", "w");
	
	if(arq==NULL || arq_w==NULL){
		printf("Erro na visualização do cadastro\n"); getch();
	}else{
		printf("Operação inicializada\n");
		
		fprintf(arq_w, "nroFrase|\t\tfrase\t\t\t\t|c|item_1\t\t\t\t\t|a|item_2\t\t\t\t\t|v|item_3\t\t\t\t\t|d|item_4\n");
		
		fread(quest, sizeof(questionario), QTD, arq);
			for(i=0 ; i<QTD ; i++){
			fprintf(arq_w, "%d\t|%-47s|%d|%-45s|%d|%-45s|%d|%-45s|%d|%s\n", quest[i].nroFrase, quest[i].frase, quest[i].cines, quest[i].item_1, quest[i].audi, quest[i].item_2, quest[i].visu, quest[i].item_3, quest[i].digi, quest[i].item_4);	
		}
		fclose(arq);
		fclose(arq_w);	
	}
	printf("feche o arquivo TXT ao terminar a operação\n");
	system("TESTE_SISTEMA_REPRESENTACIONAL.TXT");
}
/////////		 realizar teste				////////////
void test(){
	
}
