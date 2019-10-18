// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 
//dados universais
/*typedef struct  { 
char nome[20]; 
char prontuario[20];
}ficha;*/
typedef struct {
    char pegunta[100];
    char item_1[100];
    char item_2[100];
    char item_3[100];
    char item_4[100];
}quest;

//funções externas
void inDados(); //em observação...
void cadaster ();
void view ();
void toBuild ();
void info ();
//variaveis universais
int i, bi, n;

////////////////////////////////////////////////////
int main(){
    char password[20];
	char choise;
	char binary;
	//ficha pessoa;
	
do{
		if(i == 0 ){
			system("cls");
		}
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
		scanf ("%c", &choise) ;
		i++;
	
	switch(choise) {
	
		case '1': 
				cadaster();
				i=0;
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
////////////////////////////////////////////////////////
void cadaster (){
   system("cls");
   
    FILE *arq_cds;
    int perguntas;
    
    quest cadaster;
    
    arq_cds = fopen ("/questionario/TESTE_SISTEMA_REPRESENTACIONAL.DAT", "a");
    
    if(arq_cds == NULL){
        // função de escrever as caracteristicas basicas do arquivo
        }
    printf("quntas perguntas? -> ");
    scanf ("%d", &perguntas);
    
    for(n=0 ; n<perguntas ; n++){   
    printf("\n ================= CADASTRAR QUESTIONARIO =====================");
    printf(" digite a sua digite a pergunta -> "); 
    fflush(stdin); gets (perguntas.)
    printf("digite a alternativa 1 -> ");
    printf("digite a alternativa 2 -> ");
    printf("digite a alternativa 3 -> ");
    printf("digite a alternativa 4 -> ");
    }
    i=0;
}
