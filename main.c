#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
//Faça um programa que monte um tabuleiro de tamanho N x N (usando #define). Você irá simular o jogo entre dois jogadores,
//que no seu turno coloca uma peça sua no tabuleiro em quealquer espaço vazio. O objetivo do jogo é fazer três peça em sequência: horizontal, veritcal ou diagonal
//O prgrama deverá ser feito sem a criação de funções e usando matriz. a exibição do tabuleiro (para #define N 5);

#define N 5

int main()
{
    int tabuleiro[N][N], linha, condicao = 0, ganhador;
    int jogador = 1;
    char coluna;
    setlocale(LC_ALL, "portuguese");

    // Coloca zero em todas as posições da matriz
    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            tabuleiro[a][b] = 0;
        }
    }

    printf("Bem vindo ao jogo da velha maluca 5x5... Esse é o tabuleiro do jogo... \n\n\n");

    while(condicao == 0){
        for(int c = 0; c < N; c++){

            for(int l = 0; l < N; l++){
                if(l == 4){
                    printf("+---+");
                }
                else{
                    printf("+---");
                }
            }
            printf("\n");
            for(int l = 0; l < N; l++){
                if(l == 4){
                    if(tabuleiro[c][l] == 0){
                        printf("|   |");
                        printf(" %i ", c+1);
                    }
                    else if(tabuleiro[c][l] == 1){
                        printf("| x |");
                        printf(" %i ", c+1);
                    }
                    else{
                        printf("| o |");
                        printf(" %i ", c+1);
                    }
                }
                else{
                    if(tabuleiro[c][l] == 0){
                        printf("|   ");
                    }
                    else if(tabuleiro[c][l] == 1){
                        printf("| x ");
                    }
                    else{
                        printf("| o ");
                    }
                }
            }
            printf("\n");
        }

        for(int l = 0; l < N; l++){
            if(l == 4){
                printf("+---+");
            }
            else{
                printf("+---");
            }
        }
        printf("\n");
        for(int l = 0; l < N; l++){
            if(l == 4){
                printf("  %c  ", l + 97);
            }
            else{
                printf("  %c ", l + 97);
            }
        }

        printf("\n\n");
        printf("////////////////////////////////\n");
        printf("///// Jogada do jogador %i: /////\n", jogador);
        printf("////////////////////////////////\n\n");
        scanf("%c %i", &coluna, &linha);


        linha--;
        int colunaIndex = (int)(coluna - 'a');
        system("clear");

        if (linha >= 0 && linha < N && colunaIndex >= 0 && colunaIndex < N) {
            if (tabuleiro[linha][colunaIndex] == 0) {
                tabuleiro[linha][colunaIndex] = jogador;
                jogador = (jogador == 1) ? 2 : 1;
            } else {
                printf("//////////////////////////////////////////////////////////\n");
                printf("///// Essa posição já está ocupada. Tente novamente. /////\n");
                printf("//////////////////////////////////////////////////////////\n\n");
            }
        } else {
            printf("/////////////////////////////////////////////////\n");
            printf("///// Movimento inválido, tente novamente. //////\n");
            printf("/////////////////////////////////////////////////\n\n");
        }

        for(int l = 0; l <= N; l++){
            for(int j = 0; j < N; j++){
                if(tabuleiro[l][j] != 0){
                    int jogador_marcado = tabuleiro[l][j];

                    // Verifica horizontalmente
                    if(j + 2 < N && tabuleiro[l][j] == jogador_marcado && tabuleiro[l][j+1] == jogador_marcado && tabuleiro[l][j+2] == jogador_marcado){
                        ganhador = jogador_marcado;
                        condicao = 1;
                    }

                    // Verifica verticalmente
                    if(l + 2 < N && tabuleiro[l][j] == jogador_marcado && tabuleiro[l+1][j] == jogador_marcado && tabuleiro[l+2][j] == jogador_marcado){
                        ganhador = jogador_marcado;
                        condicao = 1;
                    }

                    // Verifica diagonal principal
                    if(l + 2 < N && j + 2 < N && tabuleiro[l][j] == jogador_marcado && tabuleiro[l+1][j+1] == jogador_marcado && tabuleiro[l+2][j+2] == jogador_marcado){
                        ganhador = jogador_marcado;
                        condicao = 1;
                    }

                    // Verifica diagonal secundária
                    if(l + 2 < N && j - 2 >= 0 && tabuleiro[l][j] == jogador_marcado && tabuleiro[l+1][j-1] == jogador_marcado && tabuleiro[l+2][j-2] == jogador_marcado){
                        ganhador = jogador_marcado;
                        condicao = 1;
                    }
                }
            }
        }
    }

    system("clear");

    printf("///////////////////////////////////////\n");
    printf("///// O ganhador foi o jogador %i /////\n", ganhador);
    printf("///////////////////////////////////////\n\n");

    return 0;
}
