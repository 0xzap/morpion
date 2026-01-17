#include <stdio.h>
#include "board.h"
#include "ai.h"

int main(){
    initBoard();
    int turn = 0, gameOver = 0;

    while(1){
        printf("\n   0   1   2\n");
        for(int i=0;i<3;i++){
            printf("%d ", i);
            for(int j=0;j<3;j++){
                printf(" %c ", board[i][j]);
                if(j<2) printf("|");
            }
            printf("\n");
            if(i<2) printf("  ---|---|---\n");
        }

        int score = evaluate();
        if(score==10){ printf("IA gagne !\n"); break; }
        if(score==-10){ printf("Vous gagnez !\n"); break; }
        if(!isMovesLeft()){ printf("Match nul !\n"); break; }

        if(turn%2==0){
            int r,c;
            while(1){
                printf("Votre coup (ligne colonne 0-2): ");
                int valid = scanf("%d %d",&r,&c);
                while(getchar() != '\n'); // vider le buffer
                if(valid != 2 || r<0 || r>2 || c<0 || c>2){
                    printf("Entrée invalide, utilisez deux chiffres 0-2.\n");
                    continue;
                }
                if(board[r][c]!=' '){
                    printf("Case déjà prise, réessayez.\n");
                    continue;
                }
                board[r][c] = PLAYER;
                break;
            }
        }else{
            struct Move m = findBestMove();
            board[m.row][m.col] = AI;
            printf("IA joue: %d %d\n", m.row, m.col);
        }

        turn++;
    }

    printf("\nPartie terminée !\n");
    return 0;
}
