#include <iostream>
#include <vector>

using namespace std;
char board[3][3] = { 
		                 { ' ', ' ', ' '}, 
		                 { ' ', ' ', ' '}, 
		                 { ' ', ' ', ' '} 
};
// tic-tac-toe 
void draw() {
 
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    std::cout << "     |     |      \n";
};



int main() {
  char winner = ' ';
  const char playerX = 'X';
  const char playerO = 'O';
  char currentPlayer = playerX;
  int r = -1, c = -1;
  //Main Game Loop
  for(int i = 0; i < 9; i++){
    draw();

    if (winner != ' ') {
      break;
    }

    std::cout << "Current Player is " << currentPlayer << "\n";
    std::cout << "Enter Row and Column from 0-2:\n";
    while (true) {
      cin >> r >> c;
      if(r < 0 || r > 2 || c < 0 || c > 2) {
        std::cout << "Invalid Input Try Again: \n";
      }
      else if (board[r][c] != ' ') {
        std::cout << "Tile is full, try again: \n";
      }
      else {
        break;
      }
      r= -1;
      c= -1;
      cin.clear(); // Clear error flags
      cin.ignore(10000, '\n'); //discard values
    }
    
    board[r][c] = currentPlayer;
    currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

    //check winners

    //rows - horizontal
    for(int r = 0;r < 3; r++) {
      if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2]) {
        winner = board[r][0];
        break;
      }
    }
    //vertical columns
    for(int c = 0; c<3; c++) {
      if(board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]){
        winner = board[0][00];
        break;
      }
    }
    //left diagnoles
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        winner = board[0][2];
    }

  }

  if (winner != ' ') {
    std::cout << "Player " << winner << " Wins!\n";
  } else {
    std::cout << "There was a Tie!\n";
  }

}