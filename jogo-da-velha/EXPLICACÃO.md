Estas são diretivas de pré-processamento que incluem as bibliotecas padrão necessárias para este programa. `stdio.h` para entrada e saída padrão, `stdbool.h` para usar o tipo de dado booleano, `stdlib.h` para funções de alocação de memória, `time.h` para manipulação de tempo e `unistd.h` para algumas funcionalidades relacionadas ao sistema.

```c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
```
Declaração de uma matriz 3x3 chamada `board` que representa o tabuleiro do jogo. Cada posição no tabuleiro pode conter 'X', 'O' ou um espaço em branco ' '.

```c
char board[3][3]; // Tabuleiro do jogo
```
Função para inicializar o tabuleiro do jogo com espaços em branco.

```c
void initialize_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
```
Função para imprimir o tabuleiro do jogo na saída padrão.

```c
void print_board() {
    printf("\n");
    printf("   0   1   2  \n");
    printf("  |---|---|---|\n");
    printf("0 | %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("  |---|---|---|\n");
    printf("1 | %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("  |---|---|---|\n");
    printf("2 | %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("  |---|---|---|\n");
    printf("\n");
}
```
Função para verificar se há um vencedor no jogo.

```c
char check_winner() {
    // Verificar linhas
    for(int i = 0; i < 3; i++) {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    // Verificar colunas
    for(int i = 0; i < 3; i++) {
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Verificar diagonais
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // Se não houver vencedor
}
```
Função para verificar se o tabuleiro está cheio (ou seja, se houve um empate).

```c
bool check_full() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return false; // Ainda há espaços vazios
            }
        }
    }
    return true; // Tabuleiro está cheio
}
```
Função que simula a jogada do computador. Ele escolhe uma posição aleatória no tabuleiro.

```c
void computer_play() {
    printf("O computador está pensando...");
    fflush(stdout);
    usleep(1000000); // Espera 1 segundo (simulação de pensamento)
    printf("\r                        \r"); // Apaga a linha de pensamento
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(board[row][col] != ' ');
    printf("O computador jogou na posição (%d, %d)\n", row, col);
    board[row][col] = 'O';
}
```
Função principal do programa. Inicializa o tabuleiro, define o jogador atual como 'X' e começa o loop principal do jogo.


```c
int main() {
    srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios
    initialize_board();
    char player = 'X';
    int row, col;

    while(true) {
        // ...
    }

    return 0;
}
```
