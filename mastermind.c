#include <stdio.h>    
#include <stdlib.h>

void main(){
    int rounds=0;
    printf("Welcome to mastermind\n");
    // creating the list of options to grab from later
    char options[] = {'A', 'B', 'X', 'Y', 'L', 'R'};
    //initializing the generated random list for opponent
    char sequence[4];
    for(int i=0; i<4; i++){
        int randomIndex=rand()%4;
        while(isInArray(sequene,i+1,options[randomIndex])==1){
            int randomIndex=rand()%4;
        }
        sequence[i]=options[randomIndex];
    }
    //running the game
    while(rounds<10){
        printf("Enter your 4-button sequence out of: X, B, A, Y, L, R");
        char playerGuess[];
        scanf("%4[XYRABL], playerGuess")
        
        rounds++;
    }

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