// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 5

//variaveis globais
FILE *arq;
//
typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}formato[MAX];
//declaração de metodos
void cadaster();
//variaveis globais
int i, n;

////////////////////////
int main(){
	cadaster();
}
////////////////////////

void cadaster(){
	formato cadastro;
//	cadastro.nroFrase = 0; cadastro.cines = 0; cadastro.audi = 0; cadastro.visu = 0, cadastro.digi = 0; 
	char interface[200];
	int tamanho;
	char str[20];
	
	arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
	
	if(arq == NULL){
		printf("erro na criação do arquivo");
	} 
	else{
	fprintf(arq, "NroFrase|\t\tfrase\t\t| cinestesico\t|\t\titem_1\t\t| auditivo\t|\t\titem_2\t\t| visual\t|\t\titem_3\t\t| digital\t|\t\titem_4\t\t\n");
	for(i=0 ; i<MAX ; i++ ){
//	printf("\n ================= CADASTRAR QUESTIONARIO =====================");
//    printf("\ndigite a sua digite a pergunta -> "); fflush(stdin); gets(cadastro.frase);
//    printf("\ndigite a alternativa 1 -> ");fflush(stdin); gets(cadastro.item_1);
//    printf("\ndigite a alternativa 2 -> ");fflush(stdin); gets(cadastro.item_2);
//    printf("\ndigite a alternativa 3 -> ");fflush(stdin); gets(cadastro.item_3);
//    printf("\ndigite a alternativa 4 -> ");fflush(stdin); gets(cadastro.item_4);
//    
//    fprintf(arq, "%d\t|%s\t\t|%d\t\t|%s\t\t|%d\t\t|%s\t\t|%d\t\t|%s\t\t|%d\t\t|%s\t\t", cadastro.nroFrase, cadastro.frase, cadastro.cines, cadastro.item_1, cadastro.audi, cadastro.item_2, cadastro.visu, cadastro.item_3 , cadastro.digi, cadastro.item_4);
    }
	fclose(arq);
    }
}
	


