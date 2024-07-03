
#include <stdio.h> 

int main (){

    system("cls || clear");

    int  numero, centena, dezena, unidade, numero_reverso;

    printf("Digite um numero no formato CDU (Centena, Dezena, Unidade): \n");
    scanf("%d", &numero);

    centena = numero / 100;
    dezena = (numero % 100) / 10;
    unidade = numero %10; 

    numero_reverso = unidade * 100 + dezena * 10 + centena;

 

    printf("O numero reverso e: %d\n", numero_reverso);

    return 0;
}