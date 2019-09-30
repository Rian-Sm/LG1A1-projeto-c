// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//dados universais
typedef struct  { 
char name[20]; 
char prontuario[20];
}ficha;

//funções externas

//variaveis universais
int i, bi ;

//função main
int main ()
{
	char password[20];
	char choise;
	char binary;
	ficha pessoa;
	
	strcpy(password, "master");
	
	
	for(i=0 ; i <= 1;  ) {
		
		if (i == 0){
			system("cls");
		}
		else {
		}
		
		for(bi = 0 ; bi < 1 ; ){
			
			printf ("\n\n digite seu nome -> ");
			fflush (stdin);
			gets(pessoa.name);
			
			if (strcmp(pessoa.name, password) == 0) //identificação da chave mestra
			{
				i = 2;
				bi++;
			}
			else{ 
				printf ("\n digite seu prontuario -> ");
				fflush (stdin);
				scanf ("%s", &pessoa.prontuario);
				
				printf ("\nseu nome e prontuario -> %s - %s", pessoa.name, pessoa.prontuario);
				
				printf ("\n\n queres salvar o cadastro Y/N -> ");
				fflush (stdin);
				scanf  ("%c", &binary) ;
				
				switch(binary) {
		
					case 'y':
					case 'Y': 
						// abrir arquivo e salvar o breguejonsons
						printf ("\ncadastro feito com sucesso!");
						i = 1;
						bi++;
						break;
					
					case 'n':
					case 'N': 
						printf ("\nfalha no cadastro!");
						i = 1;
						bi++;
						break;
					
					default:
						printf ("\n erro na escolha de opição");
						break;
				}
			}
		}
	}

	do{
		if(i == 3 ){
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
		scanf ("%c", &choise) ;
		i++;
	}
	while(i <=2 );
	
	switch(choise) {
	
		case '1': 
			printf ("\nescolheu a 1\n");	
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
}

//todos direitos reservados ao Rian Santos Macedo
// email "dinamykg10@gmail.com"
