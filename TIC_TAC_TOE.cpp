#include <iostream>
using namespace std;

//Global Declaration

// Creating array according to the Structure of tic-tac-toe game
char space[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

int row;
int column;
char token = 'X';
bool tie = false;
string n1;
string n2;
void functionOne() {

    // creating structure of tic-tac-toe game and Adding elements

    cout<<"     |     |     \n";
    cout<<"  "<<space[0][0]<<"  |  "<<space[0][1]<<"  |  "<<space[0][2]<<"     \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<space[1][0]<<"  |  "<<space[1][1]<<"  |  "<<space[1][2]<<"     \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<space[2][0]<<"  |  "<<space[2][1]<<"  |  "<<space[2][2]<<"     \n";
    cout<<"     |     |     \n";

}
void functionTwo() {
 
    int digit;

    if(token == 'X'){
        cout<<n1<<" please Enter : ";
        cin>>digit;
    }
    if(token == 'O'){
        cout<<n2<<" please Enter : ";
        cin>>digit;
    }

    if(digit == 1){
        row = 0;
        column = 0;
    }
    if(digit == 2){
        row = 0;
        column = 1;
    }
    if(digit == 3){
        row = 0;
        column = 2;
    }
    if(digit == 4){
        row = 1;
        column = 0;
    }
    if(digit == 5){
        row = 1;
        column = 1;
    }
    if(digit == 6){
        row = 1;
        column = 2;
    }
    if(digit == 7){
        row = 2;
        column = 0;
    }
    if(digit == 8){
        row = 2;
        column = 1;
    }
    if(digit == 9){
        row = 2;
        column = 2;
    }
    else if(digit < 1 || digit > 9){
        cout<<"Invalid input !!!"<<endl;
    }

    if(token == 'X' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'X';
        token = 'O';
    }
    else if(token == 'O' && space[row][column] != 'X' && space[row][column] != 'O'){
        space[row][column] = 'O';
        token = 'X';
    }
    // else{
    //     cout<<"There is no empty space!"<<endl;
    // }
}    

bool functionThree() {

    // Checking rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2]) {
            return true; // Row win
        }
        if (space[0][i] == space[1][i] && space[0][i] == space[2][i]) {
            return true; // Column win
        }
    }
    // Checking diagonals for a win
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2]) return true;
    if (space[2][0] == space[1][1] && space[1][1] == space[0][2]) return true;

    // checking wheather the game ends or not
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j] != 'X' && space[i][j] != 'O') return false;
        }
    }

    // If the above two condition not met then the game is draw
    tie = true;
    return true;

}

int main() {

    cout<<endl<<endl<<"TIC TAC TOE GAME"<<endl<<endl;

    // input of number of players
    cout<<"Enter the name of Player 1 : ";
    getline(cin,n1);
    cout<<"Enter the name of Player 2 : ";
    getline(cin,n2);

    cout<<endl<<n1<<" is Player 1 so he/she will play First\n";
    cout<<n2<<" is Player 2 so he/she will play Second\n\n\n";
    
    while(true){ // functionThree() keeps returning false until Player 1 or 2 wins the game
      
        functionOne();
        functionTwo();
        bool flag = functionThree();
        if(flag == true) break;

    }

    if(token == 'X' && tie == false){
        cout<<endl<<n2<<" -> Wins"<<endl;
    }
    else if(token == 'O' && tie == false){
        cout<<endl<<n1<<" -> Wins"<<endl;
    }
    else{
        cout<<endl<<"It's a Draw"<<endl;
    }

    return 0;
}