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
	char password[] = "master";
	char choise;
	char binary = 0;
	ficha pessoa;
	
	for(i=0 ; i <= 1 ; ) {
		
		if (i == 0){
			system("cls");
		}
		else {
		}
		
		for(bi = 0 ; bi < 1 ;){
			
			cout << "\n\n digite seu nome ->" << " ";
			gets(pessoa.name);
			
			if (strcmp(pessoa.name, password) == 0) //identificação da chave mestra
			{
				i = 2;
				bi++;
			}
			else{ 
				cout << "\n digite seu prontuario ->" << " ";
				cin >> pessoa.prontuario;
				
				cout << "\nseu nome e prontuario -> " << pessoa.name << pessoa.prontuario;
				
				cout << "\n\n queres salvar o cadastro Y/N ->";
				cin >> binary;
				
				
				switch(binary) {
			
				
					case 'y':
					case 'Y': 
						// abrir arquivo e salvar o breguejonsons
						cout << "\ncadastro feito com sucesso!";
						i = 1;
						bi++;
						break;
					
					case 'n':
					case 'N': 
						cout << "\nfalha no cadastro!";
						i = 1;
						bi++;
						break;
					
					default:
						cout << "\n erro na escolha de opição";
						break;
				}
			}
		}
	}

	do{
		if(i == 3 ){
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
	
		case '1': 
			cout << "\nescolheu a 1\n";	
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

//todos direitos reservados ao Rian Santos Macedo
// email "dinamykg10@gmail.com"
