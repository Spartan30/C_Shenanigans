# C_Shenanigans
I was feeling nostalgic and wanted to get back into some C programming.
I created this repo to create some C programs to get used to writing C again.

Go into one of the below directories and run:
  - 'make' to compile all programs in directory
  - 'make run' to compile and run the program
  - 'make clean' to remove compiled files


/HelloWorld
  - Simple Hello World program

/Add
  - Has the user enter 2 numbers and adds them together

/RPS
  - Rock Paper Scissors game
  - User chooses rock, paper, or scissors by picking a number between 1-3
  - AI randomly picks an option
  - Game outputs the reults of the game and asks if the user wants to play again
  - After the user ends the game a tally of wins, loses, and draws is displayed

/TTT
  - Tic Tac Toe game
  - 2 users play a game of tic tac toe against eachother
  - X goes first
  - Positions on board are represented by an integer between 1 - 9 (inclusive)
  - Game will show which positions are available
  - Game ends when there is a winner or no more possible moves (draw)
  - Board with positions:
      1|2|3
      -----
      4|5|6
      -----
      7|8|9
