// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
//fotmulario
typedef struct {char name[20]; char prontuario[20];}ficha;

//funções externas
void cadastrar();
void view();
void realizar();
void sobre();

int main () {
	
	char choise;
	ficha pessoa;
	int i;
	for(i=0 ; i < 1 ; ) 
	{
		system("cls");
		
		cout << "\n\ndigite seu nome ->" << " ";
		gets(pessoa.name);
		
		cout << "\n digite seu prontuario ->" << " ";
		cin >> pessoa.prontuario;
		
		cout << "\nseu nome e prontuario -> " << pessoa.name << pessoa.prontuario;
		
		
	}
	int  i = 2;
	do{
		if(i == 2 ){
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
	}
	while(i <=2 );
	
	switch(choise) {
	
		case '1': {
			cout << "\nescolheu a 1\n";	
			break;
		}
		case '2' :{
			break;
		}
		case '3' :{
			break;
		}
		case '4' :{
			break;
		}
		case 'f' :{
			break;
		}
		default :{
			cout << "\n\n erro na escolha \n\n";
			i--;
			cout << "numero = " << i;
		}
	}
		
}

