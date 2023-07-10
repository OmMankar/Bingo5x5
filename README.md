# Bingo Game 5x5

Introduction:
The objective of this project is to develop a console-based two-player bingo game. Each player will receive a randomly generated 5x5 ticket containing numbers from 1 to 25. The players will take turns calling out numbers, and the first player to mark a combination of five rows, columns, or diagonals with all numbers marked as zero will win the game.

Game Rules:
a. Ticket Generation: At the beginning of the game, each player will be provided with a randomly generated 5x5 ticket. The ticket will contain numbers from 1 to 25, distributed randomly across the grid.

b. Number Calling: The players will take turns calling out numbers from 1 to 25. Once a number is called, it will be replaced by a zero on both players' tickets if it exists.

c. Marking the Ticket: If a called number matches a number on a player's ticket, that number will be replaced by a zero. The players will continue calling numbers until one of them marks a combination of five rows, columns, or diagonals with all numbers marked as zero.

d. Winning Condition: The first player to mark a combination of five rows, columns, or diagonals with all numbers marked as zero on their ticket will be declared the winner of the game.

Implementation Details:
a. Random Ticket Generation: The game will include an algorithm to generate random 5x5 tickets for each player. The algorithm will ensure that each ticket contains unique numbers from 1 to 25 distributed randomly.
b. Game Progress Tracking: The game will keep track of the numbers called and update the players' tickets accordingly. It will verify after each call if either player has marked a combination of five rows, columns, or diagonals with all numbers marked as zero.

c. User Interface: The game will be implemented as a console application, providing a text-based interface for players to interact with. It will display the players' tickets, update them as numbers are called, and announce the winner once the game is over.

Expected Outcomes:
Upon completion, the project will deliver a console-based two-player bingo game. Players will be able to enjoy an interactive gaming experience where they take turns calling out numbers and marking their tickets. The game will accurately track the progress and determine the winner based on the first player to mark a combination of five rows, columns, or diagonals with all numbers marked as zero on their ticket.
This project aims to provide an entertaining and engaging console game for two players, offering a fun way to test luck and strategy while competing against each other.
