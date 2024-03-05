#include <stdio.h>
#include <string.h>
#include <3ds.h>
#include <stdlib.h>

//function prototypes:
int isValidGuess(char* guess);
int isInArray(char array[], int size, char value);
char getInput();
void getPlayerGuess(char *guess);

int main()
{
  // Initializations
  srvInit();        // services
  aptInit();        // applets
  hidInit(NULL);    // input
  gfxInitDefault(); // graphics
  gfxSet3D(false);  // stereoscopy (true == on / false == off)
  u32 kDown;        // keys down
  u32 kHeld;        // keys pressed
  u32 kUp;          // keys up
  u8* fbTopLeft;    // top left screen's framebuffer
  u8* fbTopRight;   // top right screen's framebuffer
  u8* fbBottom;     // bottom screen's framebuffer
    

  //initializing the screen
  gfxInitDefault();
  consoleInit(GFX_TOP, NULL);
  //start of game(out of loop)

    int rounds=0;
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
  // Main loop
  while (aptMainLoop() & rounds<11)
  {

    // Wait for next frame
    gspWaitForVBlank();

    // Read which buttons are currently pressed or not
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
    kUp = hidKeysUp();

    // If START button is pressed, break loop and quit
    if (kDown & KEY_START){
      break;
    }
    
    // Reset framebuffers
    fbTopLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    fbTopRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
    fbBottom = gfxGetFramebuffer(GFX_BOTTOM, 0, NULL, NULL);
    memset(fbTopLeft, 0, 240 * 400 * 3);
    memset(fbTopRight, 0, 240 * 400 * 3);
    memset(fbBottom, 0, 240 * 320 * 3);


    /** Your code starts here **/


    //printing to first line
    printf("\x1b[0;0H[Current guesses: %d]",rounds);
    printf("\x1b[0;1H[Welcome to mastermind]");
    printf("\x1b[0;2H[Press Start to exit]");
    //getting a guess and insuring it is a proper guess
    char playerGuess[5];
    //clear the screen and bring back guess tracker, 
    consoleClear();
    printf("\x1b[0;0H[Current guesses: %d]",rounds);
    printf("\x1b[0;1H[Enter your 4-button sequence out of: X, B, A, Y, L, R]");

    getPlayerGuess(playerGuess);
    while(isValidGuess(playerGuess)!=0){
        consoleClear();
        printf("\x1b[0;0H[Please enter a proper guess\n]");
        getPlayerGuess(playerGuess);
        int c;
        while ((c=getchar())!='\n'&& c!=EOF);
    }
    //clear the screen and bring back guess tracker
    //print key for response form
    consoleClear();
    printf("\x1b[0;0H[Current guesses: %d]",rounds);
    printf("\x1b[0;1H[X: correct guess ]");
    printf("\x1b[0;2H[O: correct guess wrong spot ]");
    printf("\x1b[0;3H[_: incorrect guess ]");

    //constructing a print statement to return to player
    char printStatement[]={'_','_','_','_'};

    int numCorrect=0;
    for(int i=0; i<4;i++){
        if(sequence[i]==playerGuess[i]){
            printStatement[i]='X';
            numCorrect++;
        }
        else if(isInArray(sequence,i+1,playerGuess[i])==1){
            printStatement[i]='O';
        }else{
            printStatement[i]='_';
        }
    }
    consoleClear();
    printf("\x1b[0;0H[Current guesses: %d]",rounds);
    printf("\x1b[0;0H[Analysis of your guess: %s]",printStatement);
    if(numCorrect==4){
        consoleCLear();
        printf("\x1b[0;0H[Congratulations, You WON!!!!!!]");
        break;
    }
    rounds++;
    /** End of your code **/

    
    // Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();
  }

  // Exit
  gfxExit();
  hidExit();
  aptExit();
  srvExit();

  // Return to hbmenu
  return 0;
}
int isValidGuess(char* guess){
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
char getInput(){
    hidScanInput();
    kDown = hidKeysDown();
    if(kDown & KEY_R){
        return 'R';
    }
    if(kDown & KEY_L){
        return 'L';
    }
    if(kDown & KEY_A){
        return 'A';
    }
    if(kDown & KEY_B){
        return 'B';
    }
    if(kDown & KEY_X){
        return 'X';
    }
    if(kDown & KEY_Y){
        return 'Y';
    }
    return '\0';
}
void getPlayerGuess(char *guess){
    for(int i=0; i<4;i++){
        guess[i]=getInput();
    }
    guess[4]='\0';
    return guess;
}