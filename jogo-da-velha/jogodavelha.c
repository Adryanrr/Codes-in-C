#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char board[3][3]; // Tabuleiro do jogo

// Função para inicializar o tabuleiro
void initialize_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Função para imprimir o tabuleiro
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

// Função para verificar se houve um vencedor
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

// Função para verificar se o tabuleiro está cheio (empate)
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

// Função para a jogada do computador (aleatória)
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

int main() {
    srand(time(NULL)); // Inicializar a semente do gerador de números aleatórios
    initialize_board();
    char player = 'X';
    int row, col;

    while(true) {
        print_board();
        if(player == 'X') {
            printf("Vez do jogador %c. Digite a linha (0-2) e coluna (0-2) separadas por espaço: ", player);
            scanf("%d %d", &row, &col);
            // Verificar se a posição é válida
            if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("Posição inválida. Tente novamente.\n");
                continue;
            }
            // Marcar a posição com o símbolo do jogador atual
            board[row][col] = player;
        } else {
            computer_play();
        }
        
        // Verificar se houve um vencedor
        char winner = check_winner();
        if(winner != ' ') {
            print_board();
            if(winner == 'X')
                printf("Parabéns! Você venceu!\n");
            else
                printf("O computador venceu!\n");
            break;
        }

        // Verificar se o tabuleiro está cheio (empate)
        if(check_full()) {
            print_board();
            printf("Empate!\n");
            break;
        }

        // Alternar entre jogadores
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
