// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
//dados do cadastro
typedef struct {
	char nome[100];
	char prontuario[20];
}ficha;

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
	
	
	 printf ("\nvoce escolheu -> se cadastrar ");
	 
	 FILE *arq_user;
	 
	 ficha usuario;
	
	 //arq_user = fopen ("cadastro/resultado.txt", "w");
	 
	 
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
}

//===================test information==================
void sobre()
{
	printf ("\nvoce escolheu -> saber mais sobre o teste");
}
//=============================================
