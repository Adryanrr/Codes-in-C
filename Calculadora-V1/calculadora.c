#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    int num1, num2, op, resultado;

    do
    {
        printf("Digite dois numeros e em seguida selecione a operacao a ser realizada: \n");

        printf("Digite o primeiro numero: \n");
        scanf("%d", &num1);

        printf("Digite o segundo numero \n");
        scanf("%d", &num2);

        printf("Selecione a operação a ser realizada:\n");
        printf("selecione 1 para soma.\n");
        printf("selecione 2 para subtracao\n");
        printf("selecione 3 para divisao\n");
        printf("selecione 4 para multiplicacao\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            resultado = num1 + num2;
            printf("O resultado da soma e: %d\n", resultado);
            break;
        case 2:
            resultado = num1 - num2;
            printf("O resultado da subtracao e: %d\n", resultado);
            break;
        case 3:
            if (num2 != 0)
            {
            resultado = num1 / num2;
            printf("O resultado da divisao e: %d\n", resultado);
            } else{
                printf("Operação invalida! \n");
                printf("Erro: não é possivel dividir por zero.");
            }
            break;
        case 4:
            resultado = num1 * num2;
            printf("O resultado da multiplicacao e: %d\n", resultado);
            break;

        default:
            printf("operacao invalida!\n");
        }

        printf("Deseja fazer outra consulta? 1-Sim ou 2-Nao\n");
        scanf("%d", &op);

    } while (op == 1);

    return 0;
}