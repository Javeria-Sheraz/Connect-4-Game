#include<stdio.h>
#include<stdlib.h>
void displayGrid(char grid[6][7]);
int isWinner(char grid[6][7]);
int turn(char grid[6][7], int slot, char symbol);
int checks(char grid[6][7], int slot);

int main(){
char board[6][7];
int slot;
int pturn =0, win=0;

for (int i = 0; i < 6; i++){ //intializing the grid
    for (int j = 0; j < 7; j++){
        board[i][j]= ' ';
    }  
}

printf("Welcome to Connect-4 Game! It will be fun, so let's begin.\n");
displayGrid(board);

while (pturn < 42 && win == 0) {
//PLAYER1
system("COLOR 04");
while(1){
        printf("Player 1 Turn (X) : Select the slot (0-6): ");
        scanf("%d", &slot);
        if(checks(board, slot)) //if valid input
           break;  //get out of while loop
        } 

if (turn(board, slot, 'X')){
    pturn++;
}  

system("cls");
//
displayGrid(board);

if(isWinner(board)){
    win = 1;
    printf("Player 1 is the winner");
    break;
    }

if (win == 1)
{
    break;
}
        
//PLAYER 2 
system("COLOR 06");
while(1){
    printf("Player 2 Turn (O) : Select the slot (0-6): ");
    scanf("%d", &slot);
    if(checks(board, slot)) //if valid input
        break;  //get out of while loop
} 

if (turn(board, slot, 'O')){
    pturn++;
}  

system("cls");
//
displayGrid(board);

if(isWinner(board)){
    win = 1;
    printf("Player 2 is the winner");
    break;
    }      
}//first while loop ending
if (win == 0) {
    printf("Game Drawn\n");
    }
    return 0; 
}

//FUNCTIONS
void displayGrid(char grid[6][7]){
    printf("==Connect 4 game==\n");
    printf("|0|1|2|3|4|5|6|\n");
    printf("---------------\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
        printf("|");
            printf("%c", grid[i][j]);
        }
            printf("|\n");
    }
}
int isWinner(char grid[6][7]){
//horizontal
for (int r = 0; r <=5 ; r++) {  //through rows
    for (int j = 0; j < 4; j++) {  
        if (grid[r][j] != ' ' && grid[r][j] == grid[r][j+1] && 
            grid[r][j] == grid[r][j+2] && grid[r][j] == grid[r][j+3]) {
            return 1;  
        }
    }
}
//vertical
for (int c = 0; c <= 6; c++){ //through columns
    for (int j = 0; j < 4; j++) {  
        if (grid[j][c] != ' ' && grid[j][c] == grid[j+1][c] && 
            grid[j][c] == grid[j+2][c] && grid[j][c] == grid[j+3][c]) {
                return 1; 
        }
    }
}
//diagonal
for (int i = 5; i >= 3; i--) {  //to allow upward movement //at 3 it can form maximun 4s upward
    for (int j = 0; j < 4; j++) {  //moves through 4 columns
        if (grid[i][j] != ' ' &&
            grid[i][j] == grid[i-1][j+1] &&     //. . . X
            grid[i][j] == grid[i-2][j+2] &&     //. . X . 
            grid[i][j] == grid[i-3][j+3]) {     //. X . .
            return 1; 
        }
    }
}
for (int i = 0; i <= 2 ; i++) {  //Start from 0 to allow downward movement //at 2 it can form maximum 4s downward
    for (int j = 0; j < 4; j++) {  // Only check first 4 columns
        if (grid[i][j] != ' ' &&
            grid[i][j] == grid[i+1][j+1] &&    //X . . .
            grid[i][j] == grid[i+2][j+2] &&    //. X . .
            grid[i][j] == grid[i+3][j+3]) {    //. . X .
            return 1; 
        }
    }
}
return 0;
}

int turn(char grid[6][7], int slot, char symbol){
    for (int i = 5; i >= 0; i--) { 
        if (grid[i][slot] == ' ') { 
        switch (slot) {
            case 0:
            grid[i][0] = symbol;  break;
            case 1:
            grid[i][1] = symbol;  break;
            case 2:
            grid[i][2] = symbol;  break;
            case 3:
            grid[i][3] = symbol;  break;
            case 4:
            grid[i][4] = symbol;  break;
            case 5:
            grid[i][5] = symbol;  break;
            case 6:
            grid[i][6] = symbol;  break;
            default:
            printf("Enter valid slot\n");
        }
        break; // Stop after placing in the first empty row
        }
    }
}
int checks(char grid[6][7], int slot){
    //2 checks for valid input
    if (slot < 0 || slot > 6) {
        printf("Invalid slot! Enter a number between 0 and 6.\n");
        return 0; //invalid slot
    }
    if (grid[0][slot] != ' '){ //check if topmost row of that col is empty
        printf("Column is full! Choose another slot.\n");
        return 0;
    }
    return 1;  // If input is valid, exit the loop
}
