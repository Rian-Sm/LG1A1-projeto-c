#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <string.h>
//função da biblioteca iostream
using namespace std;
//dados universais
typedef struct {
	char nome[20];
	char prontuario[20];
	char save[100];
	int tamanhoSTR;
}ficha;
//variaveis universais
int i, bi, n;
// função de cadastro
int main() {
	
	char password[]="master";
	char choice;
	char binary = 0;
	ficha pessoa;
	FILE *arq;

	for(i=0 ; i<1 ; ){
		
		cout << "\n\n digite seu nome -> ";
		fflush(stdin);
		gets (pessoa.nome);
		
		n=0;
		while (n < strlen(pessoa.nome)){
			if (pessoa.nome[n] == ' '){
				pessoa.nome[n] = '_';
			}
		n++;
		}
		
		if(strcmp(password, pessoa.nome) == 0){
			cout << "\n parabens, saiu do codigo";
			i++;
		}
		else{
			cout << "\n digite seu prontuario ->";
			cin >> pessoa.prontuario;
			
			strcpy(pessoa.save, "RESULTADO_");
			
			pessoa.tamanhoSTR = strlen(pessoa.nome);
			strncat(pessoa.save, pessoa.nome, pessoa.tamanhoSTR);
			strcat(pessoa.save, "_");
			pessoa.tamanhoSTR = strlen(pessoa.prontuario);
			strncat(pessoa.save, pessoa.prontuario, pessoa.tamanhoSTR);
			
			arq = fopen (pessoa.save,"w");
			
			if (arq == NULL){
				cout << "erro na criacao do arquivo!";
			}
			else {
				cout << "arquivo criado com sucesso!";
				
				fclose(arq);
			}
		}
		
	}
}

	/*
	OUTRA OPÇÃO PARA A VARIAVEL PASSWORD:
	
	char password[20]; 				<- declaração de variavel.
	strcpy(password, "master");		<- adicinado string a variavel, como uma copia.
	
	*/
