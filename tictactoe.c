#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

void onevone(char *p1, char *p2, int round);
void game(char *p1, char *p2);
void dummyboard();
void board(char b[]);
int isGameOver(char b[], char *p1, char *p2);

int main(){
//Intro Panel
int ch,round, diff;
char p1[20];
char p2[20];
printf (">>>>>>>>>>>TIC TAC TOE<<<<<<<<<<<<<\n");
while(1){
    printf("\nMENU\n");
    printf("1. 1v1\n");
    printf("2. vs BOT\n");
    printf("3. Other games\n");
    printf("4. Patreon\n");
    printf("5. Exit\n\n");
    printf("Choose an option : ");
    scanf("%d", &ch);
    //Switch
    switch(ch){
    case 1: 
        printf("Enter Name\n");
        printf("Player 1 : ");
        scanf("%s", p1);
        printf("Player 2: ");
        scanf("%s", p2);
        printf("%s got X and %s got O\n", p1,p2);
        printf("Select No. of rounds: ");
        scanf("%d", &round);
        printf("Lets Begin!! \n %s vs %s\n" , p1, p2);
        onevone(p1, p2, round);
        printf("Thanks for Playing!\n");
        break;
    case 2: 
        printf("Choose Difficulty:\n");
        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");
        break;
    case 3: 
        printf("Will be added soon\n");
        break;
    case 4: 
        printf("Redirecting to the Patreon...\n");
        break;
    case 5: 
        printf("\nThanks for playing\n");
        exit(1);
    default: 
        printf("Invalid choice\n");
    }
}
return 0;
}

void onevone(char *p1, char *p2, int round){
    for(int i=1; i<=round; i++){
        printf(" Round %d BEGINS !!\n", i);
        game(p1,p2);
    }
}

void game(char *p1, char *p2){
    char boardArr[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int turn = 0, pos, over = 0;
    dummyboard();
    while(!over){
        if(turn % 2 == 0){
            printf("%s's turn\n",p1);
            printf("Enter the position for X: ");
            scanf("%d", &pos);
            if(pos < 1 || pos > 9 || boardArr[pos-1] != ' '){
                printf("Invalid move, try again.\n");
                continue;
            }
            boardArr[pos-1] = 'X';
        } else {
            printf("%s's turn\n",p2);
            printf("Enter the position for O: ");
            scanf("%d", &pos);
            if(pos < 1 || pos > 9 || boardArr[pos-1] != ' '){
                printf("Invalid move, try again.\n");
                continue;
            }
            boardArr[pos-1] = 'O';
        }
        board(boardArr);
        over = isGameOver(boardArr, p1, p2); // Pass player names
        turn++;
    }
}

void dummyboard(){
    printf ("  1  |  2  |  3  \n");
    printf ("-----|-----|-----\n");
    printf ("  4  |  5  |  6  \n");
    printf ("-----|-----|-----\n");
    printf ("  7  |  8  |  9  \n");
}

void board(char b[]){
    printf ("  %c |  %c |  %c \n", b[0], b[1], b[2]);
    printf ("----|----|----\n");
    printf ("  %c |  %c |  %c \n", b[3], b[4], b[5]);      
    printf ("----|----|----\n");
    printf ("  %c |  %c |  %c \n", b[6], b[7], b[8]);
}

int isGameOver(char b[], char *p1, char *p2){
    // Check rows
    for(int i=0; i<9; i+=3){
        if(b[i] != ' ' && b[i] == b[i+1] && b[i+1] == b[i+2]){
            printf("%s wins!\n", b[i] == 'X' ? p1 : p2);
            return 1;
        }
    }
    // Check columns
    for(int i=0; i<3; i++){
        if(b[i] != ' ' && b[i] == b[i+3] && b[i+3] == b[i+6]){
            printf("%s wins!\n", b[i] == 'X' ? p1 : p2);
            return 1;
        }
    }
    // Check diagonals
    if(b[0] != ' ' && b[0] == b[4] && b[4] == b[8]){
        printf("%s wins!\n", b[0] == 'X' ? p1 : p2);
        return 1;
    }
    if(b[2] != ' ' && b[2] == b[4] && b[4] == b[6]){
        printf("%s wins!\n", b[2] == 'X' ? p1 : p2);
        return 1;
    }
    // Check draw
    int draw = 1;
    for(int i=0; i<9; i++){
        if(b[i] == ' '){
            draw = 0;
            break;
        }
    }
    if(draw){
        printf("It's a draw\n");
        return 1;
    }
    return 0;
}