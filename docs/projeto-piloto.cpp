// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

//dados universais
typedef struct {char name[20]; char prontuario[20];}ficha;

//funções externas
void cadastrar();
void view();
void realizar();
void sobre();
//variaveis universais
int i, bi ;

//função main
int main ()
{	
	i = 0;
	char choise;
	// falta referenciar cadastro externo aqui
	do{
		if(i==0){
		system("cls");
		}
		
		cout << "\n=================================================";
		cout << "\n       TESTE DOS SISTEMAS REPRESENTACIONIS";
		cout << "\n=================================================";
		cout << "\n            1. CADASTRAR QUETIONARIO";
		cout << "\n            2. VISUALIZAR QUESIONARIO";
		cout << "\n            3. REALIZAR TESTE";
		cout << "\n            4. SOBRE O TESTE";
		cout << "\n            F. FIM";
		cout << "\n=================================================";
		cout << "\n escolha ->";
		cin >> choise;
		i++;
		switch(choise) {
		
			case '1': 
				cout << "\nescolheu a 1\n";
				i++	;
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
				cout << "\n\n erro na escolha \n\n";
				i--;
				cout << "numero = " << i;	
				break;		
		}
	}
	while(i <=2 );			
}

//todos direitos reservados ao Rian Santos Macedo
// email "dinamykg10@gmail.com"
