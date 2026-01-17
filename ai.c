#include "ai.h"

int minimax(int depth,int isMax){
    int score=evaluate();
    if(score==10 || score==-10) return score;
    if(!isMovesLeft()) return 0;
    if(isMax){
        int best=-1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j]=AI;
                    int val=minimax(depth+1,0);
                    best=(val>best)?val:best;
                    board[i][j]=' ';
                }
            }
        }
        return best;
    }else{
        int best=1000;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j]=PLAYER;
                    int val=minimax(depth+1,1);
                    best=(val<best)?val:best;
                    board[i][j]=' ';
                }
            }
        }
        return best;
    }
}

struct Move findBestMove(){
    int bestVal=-1000;
    struct Move bestMove;
    bestMove.row=-1; bestMove.col=-1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j]=AI;
                int moveVal=minimax(0,0);
                board[i][j]=' ';
                if(moveVal>bestVal){
                    bestMove.row=i; bestMove.col=j;
                    bestVal=moveVal;
                }
            }
        }
    }
    return bestMove;
}
