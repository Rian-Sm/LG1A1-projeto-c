// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <iostream>

using namespace std;

#define QTD 5
// variaveis globais
int i, bi, n, j;
FILE *arq, *arq_w;

typedef struct{
	int nroFrase, cines, audi, visu, digi;
	char frase[100], item_1[100], item_2[100], item_3[100], item_4[100];
}questionario;
// funções prototipadas
void menu();
//int cadaster_comp(char *nome);
void cadaster_quest();
void cadaster_default();
void view();
void test();
void info();

//////////		 função principal 		////////////////
int main()
{
	setlocale (LC_ALL, "");
	char password[20], nome[20], prontuario[20], save[50];
	char choice;
	int auxstr;
	i=0, n=0;
//------------ cadaster user na main 	-------------------	
	strcpy(password, "MASTER");
	
	while(i<1){
		system("cls");
		cout << "================= CADASTRO DE USUARIO =================";
		cout << "\n\ndigite seu nome\t\t-> ";
		
		fflush(stdin);
		gets (nome);
		strcpy(nome, strupr(nome));
	
		if(strcmp(password, nome)==0){
			i++;
		}else{
			
			cout << "\ndigite seu prontuario\t-> ";
			cin >> prontuario;
			strcpy(prontuario, strupr(prontuario));
			
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
				cout << "erro na criacao do arquivo!";	getch();
			}
			else {
				cout << "arquivo criado com sucesso!";	getch();
				i++;
			}
			fclose(arq);
			
		}
	}

	do{
		system("cls");
		if(i==2){
			printf ("\n\n Erro na escolha!! Faz de novo, faz direito \n\n");
		}
		
		menu();
		fflush(stdin);
		cin >> choice;
		
		switch(choice) {
		
			case '1':
				n=0;
				while(n<1){
					system("cls");
					printf("\n\n============ TELA DE CADASTRO DE QUESTÕES ============  ");
					printf("\n\n======================================================\n");
					printf("VOCE QUER QUESTOES DEFAULT?\n1-sim || 2-não\t-> "); fflush(stdin); scanf("%d", &bi);
					
					switch(bi){
						case 1:
							cadaster_default();
							n++;
							break;
						
						case 2:
							cadaster_quest();
							n++;
							break;
						
						default:
							printf("\nOpição invalida, tente novamente\n"); getch();
							break;
					}
				}

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
				info();
				i=1;
				break;
			
			case 'f' :
				return 0;
			
			default :
				i=2;
				break;		
	}	
	}while(i <=2 );		
}

///////////	  	menu									///////////
void menu(){
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
}

///////////		cadastro do usuario || senha de acesso	///////////
//int cadaster_comp(char *nome){ 
// 	char password[20];
// 	
// 	st
// 	if(strcmp(nome, password) == 0){
// 		
//}
//}
///////////		cadastro do questionário 			///////////
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

/////////// cadastro default					////////////
void cadaster_default(){
	questionario quest;
	FILE *arq;
	
	arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
	
	system("cls");
	printf("VOCÊ ESCOLHERU FAZER O CADASTRO DEFAULT!!\n");
	
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
	getch();
}

//////////	   	visualizar questionario			////////////
void view(){
	questionario quest[QTD];
	arq = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	arq_w = fopen("TESTE_SISTEMA_REPRESENTACIONAL.TXT", "w");
	
	if(arq==NULL || arq_w==NULL){
		printf("Erro na visualização do cadastro\n"); getch();
	}else{
		printf("Operação inicializada\n");
		
		fprintf(arq_w, "nroFrase|\t\t\tfrase\t\t\t\t\t\t|c|item_1\t\t\t\t\t\t\t\t|a|item_2\t\t\t\t\t\t\t\t|v|item_3\t\t\t\t\t\t\t\t|d|item_4\t\t\t\t\t\t\t\t\t\n");
		
		fread(quest, sizeof(questionario), QTD, arq);
			for(i=0 ; i<QTD ; i++){
			fprintf(arq_w, "%d\t|%-71s|%d|%-69s|%d|%-69s|%d|%-69s|%d|%s\n", quest[i].nroFrase, quest[i].frase, quest[i].cines, quest[i].item_1, quest[i].audi, quest[i].item_2, quest[i].visu, quest[i].item_3, quest[i].digi, quest[i].item_4);	
		}
		fclose(arq);
		fclose(arq_w);	
	}
	printf("feche o arquivo TXT ao terminar a operação\n");
	system("TESTE_SISTEMA_REPRESENTACIONAL.TXT");
}
/////////		 realizar teste				////////////
void test(){
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
				aux++;
				getch();
			}else if(quest[i].cines!=quest[i].audi && quest[i].cines!=quest[i].visu && quest[i].cines!=quest[i].digi && quest[i].audi!=quest[i].visu && quest[i].audi!=quest[i].digi && quest[i].visu!=quest[i].digi){
				aux=2;
			} else{
				
			}
		}while(aux<2);	
	}
	
}
// referencial teorico;
void info(){
	printf("feche o arquivo TXT ao terminar a operação\n");
	system("REFERENCIAL_TEORICO.TXT");
}
