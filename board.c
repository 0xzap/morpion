#include <stdio.h>
#include "board.h"

char board[3][3];

void initBoard(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
}

void printCell(char c){
    if(c == PLAYER) printf("\033[31mX\033[0m");
    else if(c == AI) printf("\033[34mO\033[0m");
    else printf(" ");
}

void printBoard(){
    printf("    0   1   2\n");
    for(int i=0;i<3;i++){
        printf(" %d ", i);
        for(int j=0;j<3;j++){
            printf(" ");
            printCell(board[i][j]);
            printf(" ");
            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("   ---|---|---\n");
    }
    printf("\n");
}

int isMovesLeft(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ') return 1;
    return 0;
}

int evaluate(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if(board[i][0]==AI) return 10;
            if(board[i][0]==PLAYER) return -10;
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            if(board[0][i]==AI) return 10;
            if(board[0][i]==PLAYER) return -10;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][0]==AI) return 10;
        if(board[0][0]==PLAYER) return -10;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if(board[0][2]==AI) return 10;
        if(board[0][2]==PLAYER) return -10;
    }
    return 0;
}
