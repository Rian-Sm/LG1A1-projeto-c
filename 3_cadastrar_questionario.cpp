//cadastrar questionario
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario;

#define QTD 2

void cadastrar(){
	questionario quest;
	FILE *arq;
	int i;
	
	arq = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT" ,"w");
	
	for(i=0 ; i<QTD ; i++){
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

int main (){
	cadastrar();
}
