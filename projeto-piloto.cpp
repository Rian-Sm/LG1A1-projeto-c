// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct {
	char name[20];
	char prontuario[20];
}ficha;
int main () {
	
	int  i = 0;
	char choise;
	ficha pessoa;
		system("cls");
		
		cout << "\n\ndigite seu nome ->" << " ";
		gets(pessoa.name);
		
		cout << "\n digite seu prontuario ->" << " ";
		cin >> pessoa.prontuario;
		
		cout << "\nseu nome e prontuario -> " << pessoa.name << pessoa.prontuario;
	
	do {
		if(i == 2 )
			system("cls");
		
		cout << "\n=================================================";
		cout << "\n       TESTE DOS SISTEMAS REPRESENTACIONIS";
		cout << "\n=================================================";
		cout << "\n           1. CADASTRAR QUETIONARIO";
		cout << "\n           2. VISUALIZAR QUESIONARIO";
		cout << "\n           3. REALIZAR TESTE";
		cout << "\n           4. SOBRE O TESTE";
		cout << "\n           F. FIM";
		cout << "\n=================================================";
		cout << "\n escolha ->";
		cin >> choise;
	}
		while(i == 1 || i ==2);
		
		switch(choise) 
		{
			
			case '1': {
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
				cout << "\n\n erro na escolha ";
				i=i+2;
				break;
			}
		}

}

