#include <stdio.h>
#include <string.h>

char masculino, feminino;

float altura, peso;

int main(){
    
    system("cls || clear");

    printf("Qual o seu sexo? Ex: masculino, feminino: \n");
    scanf("%s", &masculino, &feminino);
  
    printf("Qual a sua altura? \n");
    scanf("%f", &altura);

    if (masculino)
    {
        peso = (72.7 * altura) - 58;
    }
    else if (feminino)
    {
        peso = (62.1 * altura) - 47;
    }

    printf("O seu peso ideal e : %.2f \n", peso);

    return 0;
}
