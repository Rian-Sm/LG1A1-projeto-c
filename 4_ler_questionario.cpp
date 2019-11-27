//ler_questionario
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define QTD 5

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario;

void view_quest(){
	FILE *arq;
	questionario quest[QTD];
	int i=0, aux;
		
	arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	
	if (arq == NULL){
		printf("Erro na abertura de arquivo!!");
	} else {
		printf("Arquivo aberto com sucesso!!\n");
		
		fread(quest, sizeof(questionario), QTD, arq);
		for(i=0 ; i<QTD ; i++){
			printf("%d %s %d %s %d %s %d %s %d %s \n", quest[i].nroFrase, quest[i].frase, quest[i].cines, quest[i].item_1, quest[i].audi, quest[i].item_2, quest[i].visu, quest[i].item_3, quest[i].digi, quest[i].item_4);
			
		}
		fclose(arq);	
	}
}

int main(){
	view_quest(); getch();
}


