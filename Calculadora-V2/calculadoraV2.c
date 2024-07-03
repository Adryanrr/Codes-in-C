#include <stdio.h>
#include <stdlib.h>

int resultado, operacao, numero1, numero2;

void MenuCalculadora(){
  printf("|-------------------------------| \n");
  printf("|       Calculadora Simples     | \n");
  printf("|===============================| \n");
  printf("|   1-Somar       | 2-Subtrair  | \n");
  printf("|-------------------------------| \n");
  printf("|   3-Multiplicar | 4-Dividir   | \n");
  printf("|===============================| \n");
  printf("|             0-Sair            | \n");
  printf("|-------------------------------| \n");
  printf("  O que voce deseja realizar?  \n");
  scanf("%d", &operacao);
}
void Entrada(){
  printf("Digite o primeiro numero: \n");
  scanf("%d", &numero1);
  printf("Digite o segundo numero: \n");
  scanf("%d", &numero2);
}

void Somar(){
  resultado = numero1 + numero2;
  Saida(resultado);
}

void Subtrair(){
  resultado = numero1 - numero2;
  Saida(resultado);
}

void Multiplicar(){
  resultado = numero1 * numero2;
  Saida(resultado);
}

void Dividir(){
  numero2 != 0 ? (resultado = numero1 / numero2, Saida(resultado)) : printf("impossivel dividir por 0 \n");
}

void Saida(resultadoRecebido){
  printf("O resultado é : %d \n", resultadoRecebido);
}

int main(){
  do
  {
    MenuCalculadora();
    switch (operacao)
    {
    case 1:
      Entrada();
      Somar();
      break;

    case 2:
      Entrada();
      Subtrair();
      break;

    case 3:
      Entrada();
      Multiplicar();
      break;

    case 4:
      Entrada();
      Dividir();
      break;

    case 0:
      printf("Fechando aplicação \n");
      return;

    default:
      printf("Essa foi a v3 da minha calculadora! \n");
    }

    printf("Deseja fazer outra consulta? [1] Yes [2] Not \n");
    scanf("%d", &operacao);

  } while (operacao == 1);
}
