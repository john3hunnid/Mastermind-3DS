#include <stdio.h>    
#include <stdlib.h>
#include <string.h>

void main(){
    int rounds=0;
    printf("Welcome to mastermind\n");
    // creating the list of options to grab from later
    char options[] = {'A', 'B', 'X', 'Y', 'L', 'R'};
    //initializing the generated random list for opponent
    char sequence[4];
    for(int i=0; i<4; i++){
        int randomIndex=rand()%6;
        while(isInArray(sequence,i+1,options[randomIndex])==1){
            int randomIndex=rand()%6;
        }
        sequence[i]=options[randomIndex];
    }
    //running the game
    while(rounds<10){
        char playerGuess[5];
        char printStatement[4];
        printf("Enter your 4-button sequence out of: X, B, A, Y, L, R");
        scanf("%s", playerGuess);
        while(isValidGuess(playerGuess)!=0){
        printf("Please enter a proper guess");
            scanf("%s", playerGuess);
            int c;
            while ((c=getchar())!='\n'&& c!=EOF);
        }
        rounds++;
    }

}
int isValidGuess(const str *guess){
    for (int i=0; i<len; i++){
        if(strchr(guess+i+1, guess[i]) != NULL)
            return 0; 
        if(guess[i]!='X'&&guess[i]!='R'&&guess[i]!='A'&&guess[i]!='B'&&guess[i]!='L'&&guess[i]!='Y')
            return 0;
    }
    return 1;
}
int isInArray(char array[], int size, char value) {
    if(size==1){
        return 0;
    }
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}