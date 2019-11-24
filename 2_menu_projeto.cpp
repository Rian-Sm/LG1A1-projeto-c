//menu_projeto
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu(char *choice){
		printf ("\n============================================================================");
		printf ("\n\t\t\tTESTE DOS SISTEMAS REPRESENTACIONIS ");
		printf ("\n============================================================================");
		printf ("\n\t\t\t1. CADASTRAR QUETIONARIO            ");
		printf ("\n\t\t\t2. VISUALIZAR QUESIONARIO           ");
		printf ("\n\t\t\t3. REALIZAR TESTE                   ");
		printf ("\n\t\t\t4. SOBRE O TESTE                    ");
		printf ("\n\t\t\tF. FIM                              ");
		printf ("\n============================================================================");
		printf ("\n\t\t\tescolha ->");
		fflush(stdin);
		scanf("%c", &*choice);
}

int main(){
	char choice;
	menu(&choice);
	
	printf("%c", choice);
	
	return 0;
}
