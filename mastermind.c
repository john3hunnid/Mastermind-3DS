#include <stdio.h>    
#include <stdlib.h>

void main(){
    int rounds=0;
    printf("Welcome to mastermind\n");
    // creating the list of options to grab from later
    char options[] = {'A', 'B', 'X', 'Y', 'L', 'R'};
    //initializing
    char sequence[4];
    for(int i=0; i<4; i++){
        int randomIndex=rand()%4;
        while(isInArray(sequene,i+1,options[randomIndex])==1){
            int randomIndex=rand()%4;
        }
        sequence[i]=options[randomIndex];
    }
    while(rounds<10){
        
        
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