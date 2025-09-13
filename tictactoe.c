#include <stdio.h>
#include <stdbool.h>

void render(char f[3][3]) {
    printf("\n");
    printf("    A   B   C  \n");
    printf("  .-----------.\n");
    
    for (int row = 0; row < 3; row++) {
        printf("%d |", row + 1);

        for (int col = 0; col < 3; col++) {
            if (f[row][col] == 0) {
                printf("   |");
            } else {
                printf(" %c |", f[row][col]);
            }
        }

        printf("\n");
        if (row < 2) {
            printf("  |---|---|---|\n");
        } else {
            printf("  '-----------'\n");
        }
    }
}

char getWinner(char f[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (f[i][0] == f[i][1] && f[i][1] == f[i][2] && f[i][0] != 0) {
            return f[i][0];
        }        
        if (f[0][i] == f[1][i] && f[1][i] == f[2][i] && f[0][i] != 0) {
            return f[0][i];
        }
    }
    if (f[0][0] == f[1][1] && f[1][1] == f[2][2] && f[0][0] != 0) {
        return f[0][0];
    }
    if (f[0][2] == f[1][1] && f[1][1] == f[2][0] && f[0][2] != 0) {
        return f[0][2];
    }

    return 0;
}

void runGame() {
    char fields[3][3] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 }
    }; 

    render(fields);

    char column;
    int row;
    char player = 'X';

    for (int moves = 0; moves < 9; moves++) {
        printf("\nEingabe: ");

        char buffer[4];
        fgets(buffer, 4, stdin);

        column = buffer[0] - 65;
        row = buffer[1] - 49;

        if (fields[row][column] != 0) {
            printf("\nBereits belegt!\n");
            continue;
        }

        fields[row][column] = player;
        render(fields);

        char winner = getWinner(fields);
        if (winner != 0) {
            printf("\nGewinner: %c\n", winner);
            return;
        }

        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }

    printf("\nUnentschieden!\n");
}

int main() {
    printf("Tic Tac Toe 1.1\n");


    bool keepPlaying;
    do {
        runGame();

        printf("\nNeues Spiel? [Y/N] ");
        
        char buffer[3];
        fgets(buffer, 3, stdin);

        keepPlaying = buffer[0] == 'y' || buffer[0] == 'Y';
    } while (keepPlaying);

    printf("Danke fürs Spielen!\n");
}