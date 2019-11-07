// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <iostream>

using namespace std;

#define QTD 1
// variaveis globais
int i, bi, n;
FILE *arq;

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario[QTD];

// funções externas
void menu(char *choice);
void cadaster_user();
void cadaster_quest();
void view ();
void toBuild ();
void info ();

////////// função principal ////////////////
int main()
{
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
void cadaster_user (){ 
	char password[20], nome[20], prontuario[20], save[50];
	int auxstr;
	
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
///////////		cadastro do questionário				///////////
void cadaster_quest(){
	
	char interface[200];
	int tamanho;
	char str[20];
	questionario quest;
	//quest.nroFrase = 0; quest.cines = 0; quest.audi = 0; quest.visu = 0, quest.digi = 0; 
	
	arq = fopen ("cadastro_sistema_representacional/TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
	
	if(arq == NULL){
		printf("erro na criação do arquivo");
	}
	else{
		fprintf(arq, "NroFrase|\t\tfrase\t\t| cinestesico\t|\t\titem_1\t\t| auditivo\t|\t\titem_2\t\t| visual\t|\t\titem_3\t\t| digital\t|\t\titem_4\t\t\n");
		printf("\n ================= CADASTRAR QUESTIONARIO =====================");
		
		for(i=0 ; i<QTD ; i++ ){
			quest[i].nroFrase=0; quest[i].cines=0; quest[i].audi=0; quest[i].visu=0; quest[i].digi=0;
		
		    printf("\ndigite a sua digite a pergunta -> "); fflush(stdin); gets(quest[i].frase);
		    printf("\ndigite a alternativa 1 -> ");fflush(stdin); gets(quest[i].item_1);
		    printf("\ndigite a alternativa 2 -> ");fflush(stdin); gets(quest[i].item_2);
		    printf("\ndigite a alternativa 3 -> ");fflush(stdin); gets(quest[i].item_3);
		    printf("\ndigite a alternativa 4 -> ");fflush(stdin); gets(quest[i].item_4);
		    
		    fwrite(&quest, sizeof(questionario), 1, arq);
	    }
	fclose(arq);
    }
	
}
