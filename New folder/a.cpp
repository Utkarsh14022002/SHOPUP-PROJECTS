// IMPLEMENTING CONWAYS GAME OF LIFE WITH C++ 
#include<bits/stdc++.h>
using namespace std;
// GLOBALLY DECLARING ROWS AND COLUMNS INPUT
// '*' CHARACHTER REPRESENT A CELL IS ALIVE
// '.' CHARACHTER REPRESENT A CELL IS DEAD
int row,column;
/*
    GIVEN FUNCTIONS-> checkCurrentRowCurrentColumnValidation: Checks the 
    neigbouring coordiantes of row and column exits in the grid or not and return a 
    boolean value.
*/
bool checkCurrentRowCurrentColumnValidation(int row1,int column1){
    if(row1<0||row1>=10||column1<0||column1>=10){
        return false;
    }
    return true;
} 
/*
    GIVEN FUNCTIONS-> countAliveNeighbours: It counts the number of neighbours 
    who are alive and then compare it to give a boolean result for the 
    current cell if it lives or die.
*/
bool countAliveNeighbours(char grid[10][10],int row1,int column1){
    int count=0; // STORE VALUE FOR ALIVE NEIGHBOURS
    if(checkCurrentRowCurrentColumnValidation(row1+1,column1)){
        if(grid[row1+1][column1]=='*'){
            count++;
        }
    }
    if(checkCurrentRowCurrentColumnValidation(row1-1,column1)){
        if(grid[row1-1][column1]=='*'){
            count++;
        }
    }
    if(checkCurrentRowCurrentColumnValidation(row1,column1+1)){
        if(grid[row1][column1+1]=='*'){
            count++;
        } 
    }
    if(checkCurrentRowCurrentColumnValidation(row1,column1-1)){
         if(grid[row1][column1-1]=='*'){
            count++;
        }   
    }
    if(checkCurrentRowCurrentColumnValidation(row1+1,column1+1)){
         if(grid[row1+1][column1+1]=='*'){
            count++;
        }   
    }
    if(checkCurrentRowCurrentColumnValidation(row1-1,column1+1)){
         if(grid[row1-1][column1+1]=='*'){
            count++;
        }   
    }
    if(checkCurrentRowCurrentColumnValidation(row1-1,column1-1)){
         if(grid[row1-1][column1-1]=='*'){
            count++;
        }   
    }
    if(checkCurrentRowCurrentColumnValidation(row1+1,column1-1)){
         if(grid[row1+1][column1-1]=='*'){
            count++;
        }   
    }
    if(count<2||count>3){  // CHECK FOR LESS POPULATION OR OVER POPULATION
        return false;
    }
    else{
        return true;
    }
}
/*
    GIVEN FUNCTIONS-> liveOrDie: This functions simply specifies if the 
    current cell is going to live or die and return charachter value for it.
*/
char liveOrDie(char grid[10][10],int row1,int column1){
    if(countAliveNeighbours(grid,row1,column1)==false){
        return '.';
    }
    else{
        return '*';
    }
}
/*
    MAIN FUNCTION
*/
int main(){
    char grid[10][10]; // ASSIGNING VALUE OF 10 FOR ROW AND COLUMN IN THE GRID 
    for(row=0;row<10;row++){  // INPUT FOR THE VALUES
        for(column=0;column<10;column++){
            cin>>grid[row][column];
        }
    }
    while(1){ // RUNNING THE INFINITE LOOP
        cout<<"after 1 second"<<endl;
        char grid1[10][10];        // CREATING A NEW GRID
        for(row=0;row<10;row++){
            for(column=0;column<10;column++){
                grid1[row][column]=liveOrDie(grid,row,column); // CHECKING IF CELL LIVES OR DIES
            }
        }
        for(row=0;row<10;row++){
            for(column=0;column<10;column++){
                cout<<grid1[row][column]<<" "; // PRINTING THE OUTPUT
                grid[row][column]=grid1[row][column]; // STORING IN THE OTHER GRID
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
