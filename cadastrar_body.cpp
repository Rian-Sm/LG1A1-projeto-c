#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
//função da biblioteca iostream
using namespace std;
//dados universais
typedef struct {
	char nome[20]; char prontuario[20];
}ficha;
//variaveis universais
int i, bi;
// função de cadastro
int main() {
	
	char password[]="master";
	char choice;
	char binary = 0;
	ficha pessoa;
	FILE *arq;

	for(i = 0 ; i < 1 ; ){
		
		cout << "\n\n digite seu nome -> ";
		fflush(stdin);
		gets (pessoa.nome);
		
		if(strcmp(password, pessoa.nome) == 0){
			cout << "\n parabens, saiu do codigo";
			i++;
		}
		else{
			cout << "\n digite seu prontuario ->";
			cin >> pessoa.prontuario;	
		}
	}
}

	/*
	OUTRA OPÇÃO PARA A VARIAVEL PASSWORD:
	
	char password[20]; 				<- declaração de variavel.
	strcpy(password, "master");		<- adicinado string a variavel, como uma copia.
	
	*/
