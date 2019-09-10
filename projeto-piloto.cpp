// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

//funções adjasentes
void escolha-1();
void escolha_2();
void escolha_3();
void escolha_4();

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
		 	void escolha-1();
			break;
		}
		case 2 :{ printf ("\nvoce escolheu ->2");
			break;
		}
		case 3 :{ printf ("\nvoce escolheu ->3");
			break;
		}
		case 4 :{ printf ("\nvoce escolheu ->4");
			break;
		}
	}
	return 0;
}

void escolha-1() {
	 printf ("\nvoce escolheu ->1");
}
