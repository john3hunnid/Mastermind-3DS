#include <stdio.h>    
#include <stdlib.h>
#include <string.h>

int main(){
    int rounds=0;
    printf("Welcome to mastermind\n");
    // creating the list of options to grab from later
    char options[] = {'X', 'B', 'A', 'Y', 'L', 'R'};
    //initializing the generated random list for opponent
    char sequence[4];
    for(int i=0; i<4; i++){
        int randomIndex=rand()%6;
        while(isInArray(sequence,i+1,options[randomIndex])==1){
            randomIndex=rand()%6;
        }
        sequence[i]=options[randomIndex];
    }
    //running the game
    while(rounds<10){
        //getting a guess and insuring it is a proper guess
        char playerGuess[5];
        printf("Enter your 4-button sequence out of: X, B, A, Y, L, R");
        scanf("%s", playerGuess);
        while(isValidGuess(playerGuess)!=0){
        printf("Please enter a proper guess\n");
            scanf("%s", playerGuess);
            int c;
            while ((c=getchar())!='\n'&& c!=EOF);
        }
        //constructing a print statement to return to player
        char printStatement[4];
        printf("X: correct guess \n");
        printf("O: correct guess wrong spot \n");
        printf("_: incorrect guess \n")
        for(int i=0; i<4;i++){
            if(sequence[i]==playerGuess[i]){
                printStatement[i]='X';
            }
            else if(isInArray(sequence,i+1,playerGuess[i])==1){
                printStatement[i]='O';
            }else{
                printStatement[i]='_'
            }
        }
        printf("Analysis of your guess: %s \n",printStatement);
        rounds++;
    }
    return 0;

}
int isValidGuess(const char* guess){
    for (int i=0; i<4; i++){
        if(strchr(guess+i, guess[i]) != NULL)
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
    for(int i=0; i<size; i++) {
        if(array[i]==value) {
            return 1;
        }
    }
    return 0;
}