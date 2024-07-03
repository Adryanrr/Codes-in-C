// 1. Sabendo que 100 quilowatts de energia custam um sétimo do salário mínimo, faça um
// algoritmo em que, dado o valor do salário mínimo e a quantidade de quilowatts gastos por uma
// residência, exiba: valor de cada quilowatt, valor da conta de energia e novo valor da conta de
// energia após um desconto de 10%.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inteiros
int main(){

    // declaração

    float valorKw, valConteEnergia, contaComDesconto,salarioMin, quantidadeKwGasto;

    // input de valores
    
    printf("Informe o salario minimo: \n");
    scanf("%f", &salarioMin);
    printf("Informe o consumo de Kw \n");
    scanf("%f", &quantidadeKwGasto);

    // calculos 

    valorKw = salarioMin / 700;

    valConteEnergia = valorKw * quantidadeKwGasto;

    contaComDesconto = valConteEnergia * 0.9;

    // print na tela

    printf("O valor de cada Quilowatt e: %2.f\n", valorKw);
    printf("O valor de conta de Energia e: %2.f\n", valConteEnergia);
    printf("O valor da conta pos desconto e: %2.f\n", contaComDesconto);

}