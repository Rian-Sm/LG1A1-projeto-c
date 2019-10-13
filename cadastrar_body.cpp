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
//funções externas
void inDados(); //em observação...
void cadaster ();
void view ();
void toBuild ();
void info ();
// função de cadastro
int main() {
	
	cadaster();

}

void cadaster(){
	
	char password[20];
	char choice;
	char binary;
	ficha pessoa;
	FILE *arq;
	
	strcpy(password, "master");

	for(i=0 ; i<=2 ; ){
		
		if(i==1){
			system("cls");
			cout << "\n cadastro feito com sucesso!";
		} else if (i==2){
			system("cls");
			cout << "\n falha no cadastro";
		}
		
		for(bi=0 ; bi<1 ;){
			
			cout << "\n\n=================    PREENCHA SEUS DADOS    ================= ";
			cout << "\n\n digite seu nome -> ";
			fflush(stdin);
			gets (pessoa.nome);
			
			if(strcmp(password, pessoa.nome) == 0){
				cout << "\n parabens, saiu do codigo -> cadaster()";
				i=3;
				bi++;
			}
			else{
				cout << "\n digite seu prontuario ->";
				cin >> pessoa.prontuario;
				
				
				system("cls");
				cout << "\nCONFIRME SEUS DADOS:\n" << "nome -> " << pessoa.nome << "\nprontuario -> " << pessoa.prontuario;
				cout << "\n\ngostaria de salvar? Y/N -> ";
				fflush(stdin);
				cin >> binary;
				
				switch(binary){
					case 'y':
					case 'Y':
						
						n=0;
						while (n < strlen(pessoa.nome)){
							if (pessoa.nome[n] == ' '){
								pessoa.nome[n] = '_';
							}
						n++;
						}
						strcpy(pessoa.save, "RESULTADO_");
						pessoa.tamanhoSTR = strlen(pessoa.nome);
						strncat(pessoa.save, pessoa.nome, pessoa.tamanhoSTR);
						strcat(pessoa.save, "_");
						pessoa.tamanhoSTR = strlen(pessoa.prontuario);
						strncat(pessoa.save, pessoa.prontuario, pessoa.tamanhoSTR);
								
						arq = fopen (pessoa.save,"w");
						if (arq == NULL){
							bi++;
							i=2;
						} 
						else {
							bi++;
							i=1;
						}
						fclose(arq);
						break;
					case 'n':
					case 'N':
						bi++;
						i=2;
						break;
					default:
						cout << "erro na escolha, tente de novo!!";
						break;	
				}	
			}
		}	
	}
}
	/*
	OUTRA OPÇÃO PARA A VARIAVEL PASSWORD:
	
	char password[20]; 				<- declaração de variavel.
	strcpy(password, "master");		<- adicinado string a variavel, como uma copia.
	
	*/
