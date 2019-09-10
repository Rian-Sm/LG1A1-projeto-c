// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

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

//=============================================

void cadastrar() 
{
	 printf ("\nvoce escolheu -> se cadastrar ");
}

//=============================================

void view()
{
	printf ("\nvoce escolheu -> visualizar testes ja feitos\n\n");
	
}

//=============================================

void test()
{
	printf ("\nvoce escolheu -> fazer o teste");
}

//=============================================
void sobre()
{
	printf ("\nvoce escolheu -> saber mais sobre o teste");
}
//=============================================
