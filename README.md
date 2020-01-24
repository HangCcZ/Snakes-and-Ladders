# Snakes-and-Ladders
This is my final project of my C++ programming course. No other directions were given beside the expected result of the game (Snakes and Ladders https://www.youtube.com/watch?v=GTEsyY6r7w0). I use SFML library to do all the graphics display therefore the user have to install the library in order to run the code properly.

# Object Oriented Programming - Class Definitions:
4 classes total including, player, ladder, snake and blackhole(add on the original game. All player start within blackhole, player cannot escape blackhole unless they draw a 6).
- Player class hold the player’s position and its location on the screen. Player class also have all the functions needed to get and update the player’s information.
- Ladder and snake class both have it’s starting position and ending position.
- Blackhole class only holds the black hole’s position on the board.
- Code initialized 4 players, 5 ladder, 5 snake and 5 blackholes.

# Graphics Display:
SFML is used to draw the following element:
- A 10*10 board
- 4 player tokens with different color
- A white square to represent the dice
- Green lines to represent the ladder
- Red lines to represent the snake
- Legend to show which color represent which player
- Game Status
- Whether if player is inside a blackhole

# Algorithm:
Noticed that the player’s position is always associated with the pixel location on the screen. Therefore, I create a 2-dimensional vector that map the position of the player to the location on the board. That is, each position has its unique x and y value on the screen.
Variable were also used to keep track which player will be the next one to dice.

# Game Play with logic:
This game started default with 2 players, the player can press 3 or 4 (on the keyboard)to introduce 3th and 4th player into the game. At each player’s current position, if statement is used to check 3 different conditions to check if that position contains ladder or snake or blackhole then update the player’s position or status accordingly.
The game ends after one of the player’s position is greater than 100 after dicing. As the game end, no player can be moved to other positions.

# Game Play with result:
Game start status
<img src="/screenshots/initial.png"><br>
Game start with 2 player as default
<img src="/screenshots/gameWith2.png"><br>
Game with 3 players on the board
<img src="/screenshots/gameWith3.png"><br>
Game with 4 players on the board
<img src="/screenshots/gameWith4.png"><br>
Game end status
<img src="/screenshots/gameWith5.png"><br>

