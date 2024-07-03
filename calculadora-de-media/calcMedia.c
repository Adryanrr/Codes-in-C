#include <stdio.h>
#include <stdlib.h>

int i, soma;
float media, notas;

int main(){
    for (i = 0; i < 5; i++){
        printf("Digite um numero: ");
        scanf("%f", &notas);

        soma += notas;
    }
    media = (float)soma/5;
    printf("A media e: %.2f", media);
}