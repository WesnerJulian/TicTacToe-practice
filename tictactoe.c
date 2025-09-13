#include <stdio.h>
#include <stdbool.h>

void render(char *f) {
    printf("\n");
    printf("    A   B   C  \n");
    printf("  .-----------.\n");
    
    for (int row = 0; row < 3; row++) {
        printf("%d |", row + 1);

        for (int col = row * 3; col < (row + 1) * 3; col++) {
            if (f[col] == 0) {
                printf("   |");
            } else {
                printf(" %c |", f[col]);
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

char getWinner(char *f) {
    for (int i = 0; i < 3; i++) {
        if (f[i * 3] == f[i * 3 + 1] && f[i * 3 + 1] == f[i * 3 + 2] && f[i * 3] != 0) {
            return f[i * 3];
        }        
        if (f[i] == f[i + 3] && f[i + 3] == f[i + 6] && f[i] != 0) {
            return f[i];
        }
    }
    for (int i = 0; i < 2; i++) {
        if (f[i * 2] == f[4] && f[4] == f[8 - i * 2] && f[4] != 0) {
            return f[4];
        }
    }

    return 0;
}

void runGame() {
    char fields[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

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

        if (fields[row * 3 + column] != 0) {
            printf("\nBereits belegt!\n");
            continue;
        }

        fields[row * 3 + column] = player;
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
    printf("Tic Tac Toe 1.0\n");


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