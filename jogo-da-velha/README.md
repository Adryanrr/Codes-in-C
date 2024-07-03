# Jogo da Velha

## Descrição

Este é um jogo simples de Jogo da Velha feito pelo chat GPT para estudo da linguagem. Esse jogo permite que um jogador jogue contra o computador. O jogador é representado por 'X' e o computador por 'O'. O jogador pode inserir suas jogadas especificando os números da linha e coluna (0-2) onde deseja colocar seu 'X'. O computador faz suas jogadas aleatoriamente.

## Conceitos Abordados:

- Declaração e uso de funções.
- Uso de arrays multidimensionais para representar o tabuleiro do jogo.
- Uso de estruturas de controle, como loops e condicionais.
- Entrada e saída de dados usando `printf()` e `scanf()`.
- Geração de números aleatórios usando `rand()` e `srand()`.
- Manipulação de strings e caracteres.
- Simulação de espera usando `usleep()` para criar uma animação de carregamento.

## Objetivos de Aprendizado:

- Compreender como implementar um jogo simples em C.
- Familiarizar-se com a utilização de arrays multidimensionais para representar um tabuleiro.
- Praticar o uso de funções para organizar o código.
- Entender como implementar lógica de jogo, incluindo verificação de vencedor e empate.
- Aprender sobre simulação de espera para melhorar a experiência do usuário.

Este código é adequado para estudantes iniciantes em C que desejam consolidar os conceitos básicos da linguagem, como variáveis, estruturas de controle, funções e arrays, enquanto constroem um projeto prático. Ele também oferece a oportunidade de explorar conceitos mais avançados, como geração de números aleatórios e manipulação de caracteres.

## Como Usar

1. **Pré-requisitos**: Certifique-se de ter um compilador C instalado em seu sistema.

2. **Instruções de Compilação e Execução**:
   
   - Abra um terminal.
   - Navegue até o diretório onde o código-fonte está localizado.
   - Compile o código usando o seguinte comando:
     ```bash
     gcc seu_codigo.c -o jogo_da_velha
     ```
   - Execute o programa compilado:
     ```bash
     ./jogo_da_velha
     ```

3. **Jogabilidade**:
   
   - O jogo solicitará ao jogador que insira suas jogadas especificando os números da linha e coluna (0-2) separados por espaço.
   - As jogadas do computador são geradas aleatoriamente.
   - O jogo continuará até que haja um vencedor ou um empate.

## Exemplo

```
   0   1   2  
  |---|---|---|
0 | X |   |   |
  |---|---|---|
1 |   | O |   |
  |---|---|---|
2 |   |   |   |
  |---|---|---|

Vez do jogador X. Digite a linha (0-2) e coluna (0-2) separadas por espaço: 0 1
O computador está pensando...
O computador jogou na posição (2, 2)

   0   1   2  
  |---|---|---|
0 | X |   | X |
  |---|---|---|
1 |   | O |   |
  |---|---|---|
2 |   |   | O |
  |---|---|---|

Vez do jogador X. Digite a linha (0-2) e coluna (0-2) separadas por espaço: 0 2

   0   1   2  
  |---|---|---|
0 | X |   | X |
  |---|---|---|
1 |   | O |   |
  |---|---|---|
2 | X |   | O |
  |---|---|---|

Jogador X vence!
```
