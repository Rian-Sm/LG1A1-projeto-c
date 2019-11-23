// realizar teste
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define QTD 2

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario;

int main(){
	setlocale(LC_ALL, " ");
	
	questionario quest[QTD];
	FILE *arq;
	int i, ascii, aux=0;
	
	arq = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	
	fread(quest, sizeof(questionario), QTD, arq);
	
	for(i=0; i<QTD ; i++){

		do{
			ascii=97;
			
			system("cls");
			printf("Nas frases a seguir, pontue com:\n");
			printf("[4] -> A que melhor te descreve\n");
			printf("[3] -> A proxima a melhor descrição\n");
			printf("[2] -> A proxima a menos descreve\n");
			printf("[1] -> A que menos te descreve\n\n");
			
			printf("%d. %s:\n", quest[i].nroFrase+1, quest[i].frase);
			printf("a) %s\n", quest[i].item_1);
			printf("b) %s\n", quest[i].item_2);
			printf("c) %s\n", quest[i].item_3);
			printf("d) %s\n", quest[i].item_4);
			if(aux==1){
				printf("erro na leitura do teste!! digite valores entre 4 e 1 que sejam diferentes.\n");
				aux=0;
			}
			
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].cines); ascii++;
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].audi); ascii++;
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].visu); ascii++;
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].digi);
			if(quest[i].cines<0 || quest[i].audi<0 || quest[i].visu<0 || quest[i].digi<0 || quest[i].cines>5 || quest[i].audi>5 || quest[i].visu>5 || quest[i].digi>5 ||  quest[i].cines + quest[i].audi + quest[i].visu + quest[i].digi!=10 ){
				printf("%d \n",quest[i].cines);
				printf("%d \n",quest[i].audi);
				printf("%d \n",quest[i].visu);
				printf("%d \n",quest[i].digi);
				getch();
				aux++;
			}else if(quest[i].cines!=quest[i].audi && quest[i].cines!=quest[i].visu && quest[i].cines!=quest[i].digi && quest[i].audi!=quest[i].visu && quest[i].audi!=quest[i].digi && quest[i].visu!=quest[i].digi){
				aux=2;
			}
		}while(aux<2);	
	}
	return 0;
}

