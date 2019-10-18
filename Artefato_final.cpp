// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//funções externas
void cadaster_user();
void cadaster_quest();
void view ();
void toBuild ();
void info ();
//variaveis globais
int i, bi, n;

////////// função principal ////////////////
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
				cadaster_quest();
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
////////////cadastro do questionário////////////////
void cadaster_quest (){ 
}
