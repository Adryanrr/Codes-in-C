#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char name[40];
char surname[40];

int main(){
    /*Entrada de Dados*/
    printf("informe o seu primeiro nome\n");
    scanf("%s", &name);
    printf("informe o seu sobrenome\n");
    scanf("%s", &surname);

    /*Impressão de Dados*/
    printf("completo nome: %s %s\n", name, surname);
    

    return 0;   
}
