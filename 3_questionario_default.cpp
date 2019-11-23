//cadastrar questionario default
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario;

#define QTD 5

int main(){
	questionario quest;
	FILE *arq;
	
	arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
	
	quest.nroFrase=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;
	strcpy(quest.frase,"Eu tomo decisões importantes baseado em");
	strcpy(quest.item_1, "intuição");
	strcpy(quest.item_2, "o que me soa melhor");
	strcpy(quest.item_3, "o que me parece melhor");
	strcpy(quest.item_4, "um estudo preciso e minucioso do assunto");
	fwrite(&quest, sizeof(questionario), 1, arq);
	if(QTD==1){
		printf("programa salvara %d pergunta\n", QTD);
		fclose(arq);
	}else
	{
		quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0; 					// inicio da segunda pergunta
		strcpy(quest.frase,"Durante uma discussão eu sou mais influenciado por");
		strcpy(quest.item_1, "o tom da voz da outra pessoa");
		strcpy(quest.item_2, "se eu posso ou não ver o argumento da outra pessoa");
		strcpy(quest.item_3, "a lógica do argumento da outra pessoa");
		strcpy(quest.item_4, "se eu entro em contato ou não com os sentimentos reais do outro");
		fwrite(&quest, sizeof(questionario), 1, arq);
		if(QTD==2){
			printf("programa salvara %d perguntas\n", QTD);
			fclose(arq);
		} else
		{
			quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;					// inicio da terceira pergunta
			strcpy(quest.frase,"Eu comunico mais facilmente o que se passa comigo");
			strcpy(quest.item_1, "do modo como me visto e aparento");
			strcpy(quest.item_2, "pelos sentimentos que compartilho");
			strcpy(quest.item_3, "pelas palavras que escolho");
			strcpy(quest.item_4, "pelo tom da minha voz");
			fwrite(&quest, sizeof(questionario), 1, arq);
			if(QTD==3){
				printf("programa salvara %d perguntas\n", QTD);
				fclose(arq);
			}else
			{
				quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;				// inicio da quarta pergunta
				strcpy(quest.frase,"É muito fácil para mim");
				strcpy(quest.item_1, "achar o volume e a sintonia ideais num sistema de som");
				strcpy(quest.item_2, "selecionar o ponto mais relevante relativo a um assunto interessante");
				strcpy(quest.item_3, "escolher os móveis mais confortáveis");
				strcpy(quest.item_4, "escolher as combinações de cores mais ricas e atraentes");
				fwrite(&quest, sizeof(questionario), 1, arq);
				if(QTD==4){
					printf("programa salvara %d perguntas\n", QTD);
					fclose(arq);	
				}else
				{
					quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;			// inicio da quinta pergunta
					strcpy(quest.frase,"Eu me percebo assim");
					strcpy(quest.item_1, "se estou muito em sintonia com os sons dos ambientes");
					strcpy(quest.item_2, "se sou muito capaz de raciocinar com fatos e dados novos");
					strcpy(quest.item_3, "eu sou muito sensível à maneira como a roupa veste o meu corpo");
					strcpy(quest.item_4, "eu respondo fortemente às cores e à aparência de uma sala");
					fwrite(&quest, sizeof(questionario), 1, arq);
				}
			}
		}
	}
	printf("programa salvara %d perguntas\n", QTD);
	fclose(arq);
}
