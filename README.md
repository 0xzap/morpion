## Description :
- Simple implémentation du Morpion en C

## Pour compiler le projet :

```bash
gcc main.c board.c ai.c -o morpion
```

## Pour exécuter le jeu :

```bash
./morpion
```

## Règles du jeu

1. Le joueur c'est le X  
2. L'IA c'est le O
3. Le plateau c'est une grille 3x3 avec les lignes et colonnes numérotées de 0 à 2  
4. À chaque tour le joueur entre deux chiffres séparé par un espace : Exemple : `1 2` pour jouer à la ligne 1 & colonne 2.  

## IA 
L'IA utilise l'algorithme Minimax :
- Elle explore toutes les positions possibles du plateau.  
- Elle choisit le coup qui maximise ses chances de gagner tout en minimisant celles de l'adversaire.  


## Références : 

- https://www.geeksforgeeks.org/dsa/minimax-algorithm-in-game-theory-set-1-introduction/
- https://www.geeksforgeeks.org/c/tic-tac-toe-game-in-c/
