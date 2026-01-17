#include <stdio.h>
#include "board.h"

char board[3][3];

void initBoard(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';
}

void printBoard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %c ", board[i][j]);
            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("---|---|---\n");
    }
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
