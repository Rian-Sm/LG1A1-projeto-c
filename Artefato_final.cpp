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
void cadaster_quest();
void cadaster_default();
void view();
void test(char *str, char *s);
void info();
void comp(char *str, int *n);
void gerar_save(char *n, char *p, char *s);
//////////		 função principal 		////////////////
int main()
{
	setlocale (LC_ALL, "");
	char nome[20], prontuario[20], save[50];
	int auxstr, auxnro;
	char choice;
	
	i=0, n=0;
//------------	cadaster user na main	-------------------	
	while(i<1){
		 n=0;
		system("cls");
		cout << "================= CADASTRO DE USUARIO =================";
		cout << "\n\ndigite seu nome\t\t-> ";
		
		fflush(stdin);
		gets (nome);
		strcpy(nome, strupr(nome));
		
		comp(nome, &auxnro);
		
		if(auxnro == 0){
			strcpy(prontuario, "");
			gerar_save(nome, prontuario, save);
			arq = fopen (save, "w");
			i++;
		}else{
			
			cout << "\ndigite seu prontuario\t-> ";
			cin >> prontuario;
			strcpy(prontuario, strupr(prontuario));
			
			gerar_save(nome, prontuario, save);
			
			do{
				system("cls");
				printf("\n=======================================================");
				printf("\nseu nome\t: %s\nseu prontuario\t: %s\nseu arquivo\t: %s", nome, prontuario, save);
				printf("\n=======================================================\n");
				printf("Gostaria de salvar o seus dados : 1-sim || 2-não -> "); fflush(stdin); scanf("%d", &bi);
				switch(bi){
					case 1:
						arq = fopen (save, "w");
						n++;
						break;
					case 2:
						n++;
						break;
					default:
						printf("erro na escclha de opção!\n"); getch();
						break;		
				}		
			}while(n<1);
			
			if (arq == NULL){
				cout << "erro na criacao do arquivo!\n";	getch();
			}
			else {
				cout << "arquivo criado com sucesso!\n";	getch();
				i++;
				test(nome, save);
			}
			fclose(arq);
		}
	}
//------------	inicio do switch do menu	-------------------
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
					printf("\n\n======================================================");
					printf("\n============ TELA DE CADASTRO DE QUESTÕES ============");
					printf("\n======================================================");
					printf("\nVOCE QUER QUESTOES DEFAULT?\n1-sim || 2-não\t-> "); fflush(stdin); scanf("%d", &bi);
					
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
				test(nome, save);
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

///////////	  	menu										///////////
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

///////////		cadastro do usuario || senha de acesso		///////////
void comp(char *str, int *n){
	char pass[20], y[20];
	strcpy(pass, "MASTER");
	strcpy(y, str);
	printf("%S", y);
	*n = strcmp(y, pass);
}

															///////////
void gerar_save(char *n, char *p, char *s){
	int auxstr, i;
	
	while (i < strlen(n)){
				if (n[i] == ' '){
					n[i] = '_';
				}
			i++;
			}
			strcpy(s, "RESULTADO_");
			auxstr = strlen(n);
			strncat(s, n, auxstr);
			strcat(s, "_");
			auxstr = strlen(p);
			strncat(s, p, auxstr);
			strcat(s, ".txt");

}

///////////		cadastro do questionário 					///////////
void cadaster_quest(){
	
	questionario quest;
	
	arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
	
	if(arq == NULL){
		printf("erro na criação do arquivo");
	}
	else{
		system("cls");
		printf("\n=====================\tCADASTRAR QUESTIONARIO\t=====================");
		
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

///////////		cadastro default							////////////
void cadaster_default(){
	questionario quest;
	FILE *arq;

	system("cls");
	printf("\n\n==================================================");
	printf("\nVOCÊ ESCOLHERU FAZER O CADASTRO DEFAULT!!\n");
	printf("==================================================\n");
	if(QTD>5){
		printf("cadastro default salva até 5 perguntas!\nsalve mais que isso manualmente"); getch();
	} else{
		arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w");
		
		quest.nroFrase=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;
		strcpy(quest.frase,"Eu tomo decisões importantes baseado em");
		strcpy(quest.item_1, "intuição");
		strcpy(quest.item_2, "o que me soa melhor");
		strcpy(quest.item_3, "o que me parece melhor");
		strcpy(quest.item_4, "um estudo preciso e minucioso do assunto");
		fwrite(&quest, sizeof(questionario), 1, arq);
		if(QTD==1){
			fclose(arq);
		}else
		{
			quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0; 					// inicio da segunda pergunta
			strcpy(quest.frase,"Durante uma discussão eu sou mais influenciado por");
			strcpy(quest.item_1, "se eu entro em contato ou não com os sentimentos reais do outro"); 
			strcpy(quest.item_2, "o tom da voz da outra pessoa"); 
			strcpy(quest.item_3, "se eu posso ou não ver o argumento da outra pessoa"); 
			strcpy(quest.item_4, "a lógica do argumento da outra pessoa");
			fwrite(&quest, sizeof(questionario), 1, arq);
			if(QTD==2){
				fclose(arq);
			} else
			{
				quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;					// inicio da terceira pergunta
				strcpy(quest.frase,"Eu comunico mais facilmente o que se passa comigo");
				strcpy(quest.item_1, "pelos sentimentos que compartilho");
				strcpy(quest.item_2, "pelo tom da minha voz");	
				strcpy(quest.item_3, "do modo como me visto e aparento");			
				strcpy(quest.item_4, "pelas palavras que escolho");				
				fwrite(&quest, sizeof(questionario), 1, arq);
				if(QTD==3){
					fclose(arq);
				}else
				{
					quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;				// inicio da quarta pergunta
					strcpy(quest.frase,"É muito fácil para mim");
					strcpy(quest.item_1, "escolher os móveis mais confortáveis"); 
					strcpy(quest.item_2, "achar o volume e a sintonia ideais num sistema de som");
					strcpy(quest.item_3, "escolher as combinações de cores mais ricas e atraentes");
					strcpy(quest.item_4, "selecionar o ponto mais relevante relativo a um assunto interessante");
					fwrite(&quest, sizeof(questionario), 1, arq);
					if(QTD==4){
						fclose(arq);	
					}else
					{
						quest.nroFrase+=1; quest.cines=0; quest.audi=0; quest.visu=0; quest.digi=0;			// inicio da quinta pergunta
						strcpy(quest.frase,"Eu me percebo assim");
						strcpy(quest.item_1, "eu sou muito sensível à maneira como a roupa veste o meu corpo");
						strcpy(quest.item_2, "se estou muito em sintonia com os sons dos ambientes");
						strcpy(quest.item_3, "eu respondo fortemente às cores e à aparência de uma sala");
						strcpy(quest.item_4, "se sou muito capaz de raciocinar com fatos e dados novos");
						fwrite(&quest, sizeof(questionario), 1, arq);
					}
				}
			}
		}
		printf("\nO PROGRAMA SALVOU %d PERGUNTAS\n", QTD);
		printf("aperte algo para continuar...");
		fclose(arq);
		getch();
	}
}

///////////		visualizar questionario						////////////
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

///////////realizar teste									////////////
void test(char *str, char *s){
	questionario quest[QTD];
	int i, ascii, aux=0 , soma_c=0, soma_a=0, soma_v=0, soma_d=0;
	
	arq = fopen("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "r");
	arq_w = fopen (s, "w");
	
	fread(quest, sizeof(questionario), QTD, arq);

	for(i=0; i<QTD ; i++){
		aux=0;
		do{
			ascii=97;
			
			system("cls");
			printf("Nas frases a seguir, pontue com:\n");
			printf("[4] -> A que melhor te descreve\n");
			printf("[3] -> A proxima a melhor descrição\n");
			printf("[2] -> A proxima a menos descreve\n");
			printf("[1] -> A que menos te descreve\n");
			
			if(aux==1){
				printf("\n%d, %d, %d, %d não são valores validos!", quest[i].cines, quest[i].audi, quest[i].visu, quest[i].digi);
				printf("\nerro na leitura do teste!! digite valores entre 4 e 1 que sejam diferentes.\n\n");
				aux=0;
			}
			
			printf("%d. %s:\n", quest[i].nroFrase, quest[i].frase);
			printf("a) %s\n", quest[i].item_1);
			printf("b) %s\n", quest[i].item_2);
			printf("c) %s\n", quest[i].item_3);
			printf("d) %s\n", quest[i].item_4);
			
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].cines); ascii++;
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].audi); ascii++;
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].visu); ascii++;
			printf("[%c] -> ", ascii ); fflush(stdin); scanf("%d", &quest[i].digi);
			if(quest[i].cines<0 || quest[i].audi<0 || quest[i].visu<0 || quest[i].digi<0 || quest[i].cines>5 || quest[i].audi>5 || quest[i].visu>5 || quest[i].digi>5 ||  quest[i].cines + quest[i].audi + quest[i].visu + quest[i].digi!=10 ){
				aux++;
			}else if(quest[i].cines!=quest[i].audi && quest[i].cines!=quest[i].visu && quest[i].cines!=quest[i].digi && quest[i].audi!=quest[i].visu && quest[i].audi!=quest[i].digi && quest[i].visu!=quest[i].digi){
				aux=2;
			} else{
				aux++;
			}
		}while(aux<2);
	}
	for(i=0 ; i<QTD ; i++){		
		soma_c += quest[i].cines;
		soma_a += quest[i].audi;
		soma_v += quest[i].visu;
		soma_d += quest[i].digi;
	}
	fprintf(arq_w,"============================================\t\tPERFIL REPRESENTACIONAL DE %-20s================================================", str);
	fprintf(arq_w,"\n %d%c - CINESTÉSICO\t\t%d%c - AUDITIVO\t\t%d%c - VISUAL\t\t%d%c - DIGITAL\t\t", soma_c*2, 37, soma_a*2, 37, soma_v*2, 37, soma_d*2,37);
	fprintf(arq_w,"\n=======================================================================================================================================================\n", str);
	
	fprintf(arq_w,"\nAlgumas pessoas captam melhor as mensagens do mundo exterior através da audição, são as pessoas chamadas auditivas.");
	fprintf(arq_w,"\nOutras pessoas sentem necessidade de perguntar muito, necessitam de muitas informações e fatos. Estas são as digitais.");
	fprintf(arq_w,"\nAs cinestésicas aprendem melhor por meio das sensações táteis, como o tato, a temperatura, a umidade, as sensações internas e as emoções.");
	fprintf(arq_w,"\nJá as pessoas visuais aprendem melhor quando se valendo da visão.\n");
	
	if(soma_c>soma_a && soma_c>soma_v && soma_c>soma_d){
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
		fprintf(arq_w,"\nSeu perfil é CINESTÉSICO\n");
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
	} else if(soma_a>soma_c && soma_a>soma_v && soma_a>soma_d){
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
		fprintf(arq_w,"Seu perfil é AUDITIVO\n");
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
	} else if(soma_v>soma_c && soma_v>soma_a && soma_v>soma_d){
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
		fprintf(arq_w,"\nSeu perfil é VISUAL\n");
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
	} else if(soma_d>soma_c && soma_d>soma_a && soma_d>soma_v){
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
		fprintf(arq_w,"\nSeu perfil é digital\n");
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
	} else{
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
		fprintf(arq_w,"\nSeu perfil é indescritivel!!!!");
		fprintf(arq_w,"\n=======================================================================================================================================================", str);
	}
	fclose(arq);
	fclose(arq_w);
}

///////////		referencial teorico							////////////
void info(){
	printf("feche o arquivo TXT ao terminar a operação\n");
	system("REFERENCIAL_TEORICO.TXT");
}
