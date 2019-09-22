// bibliotecas
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;



int main () {
	
	char name[20];
	char prontuario[20];
	int  i = 0;
	
	do{
		system("cls");
		
		cout << "\n\ndigite seu nome ->" << " ";
		gets (name);
		
		cout << "\n digite seu prontuario ->" << " ";
		cin >> prontuario ; 
		
		cout << "\nseu nome e prontuario -> " << name << prontuario;
	}
	while (i == 1) ;
	
	
	
}
