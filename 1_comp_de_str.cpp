// comp de str em função
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int comp(char *str, int *n);
int main(){
	char x[20];
	int n;
	strcpy(x, "password");
	comp(x, &n);
	
	printf("%d", n);
}

int comp(char *str, int *n){
	char pass[20], y[20];
	strcpy(pass, "password");
	strcpy(y, str);
	printf("%S", y);
	*n = strcmp(y, pass);
}
