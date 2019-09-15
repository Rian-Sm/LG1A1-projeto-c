// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
//listas de dados
typedef struct {
	char nome[100];
	char prontuario[20];
	int choise;
}ficha;
// --- 


//funções adjasentes
void cadastrar();
void view();
void test();
void sobre();

//função principal
int main () {
	
	int choise;
	
	printf ("\n TESTE DOS SISTEMAS REPRESENTACIONAIS");
	printf ("\n ====================================");
	printf ("\n                menu");
	printf ("\n ====================================");
	printf ("\n   cadastrar questionario     -->1");
	printf ("\n   visualizar questionario    -->2");
	printf ("\n   realizar teste             -->3");
	printf ("\n   sobre o teste              -->4");
	printf ("\n ====================================\n\n");
	
	printf ("escolha -> ");
	scanf ("%i", &choise);
	
	switch (choise) {
		case 1 :{
		 	cadastrar();
			break;
		}
		case 2 :{
			view();
			break;
		}
		case 3 :{
			test();
			break;
		}
		case 4 :{
			sobre();
			break;
		}
	}
	return 0;
}

//=================user register==================

void cadastrar() 
{
	ficha user;
	FILE *arq_user;
	
	arq_user = fopen ("cadastro/resultado.txt", "w");
	
	printf ("\n voce escolheu -> se cadastrar ");
	
	if (arq_user = NULL){
		
	printf ("\num novo arquivo foi criado com sucesso!!");
	
	printf ("\n digite seu nome -> ");
	gets (user.nome);
	 
	printf ("\n agora digite seu prontuario -> ");
	scanf ("%s", &user.prontuario);
	
	fprintf (arq_user, "%s %s", user.nome, user.prontuario);
	 
	fclose (arq_user); 
	
	}
	
	else {
		
		printf ("\nerro na criação de arquivo!!");
		
		printf ("\ngostaria de rescrever?");
		printf ("\nsim ->1");
		printf ("\nnão ->0");
		
		scanf ("%i", &user.choise);
		
		switch (user.choise){
			case 1 :{	
				
				
				arq_user = fopen ("cadastro/resultado.txt", "w");
				
				printf ("\n o arquivo vai ser rescrito");
				printf ("\n digite seu nome -> ");
				gets (user.nome);
	 
				printf ("\n agora digite seu prontuario -> ");
				scanf ("%s", &user.prontuario);
				
	 			
	 			
				fclose (arq_user); 
				
				break;
			}
			case 2 : {
				
				printf ("o arquivo não vai ser modificado!");
				
				// como retornar a pagina??? DUVIDA PRINCIPAL
				break;
			}
		}
	}
}

//==================user view=====================

void view()
{
	printf ("\nvoce escolheu -> visualizar testes ja feitos\n\n");
	
}

//==================user test=====================

void test()
{
	printf ("\nvoce escolheu -> fazer o teste");
	
	// ???
}

//===================test information==================
void sobre()
{
	printf ("\nvoce escolheu -> saber mais sobre o teste");
	
	//como retornar a pagina??? DUVIDA PRINCIPAL
}
//====================================== the end
