#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;


// black hole
// ladder
// snake
class Player
{
	private:
		int x;
		int y;
		int Position;
		bool blackHole;
	public:
		Player(int pos_x,int pos_y,int index,bool bh)
		{
			Position = index - 1;
			x = pos_x;
			y = pos_y;
			blackHole = bh;
		}

		void updatePos(int ind)
		{
			Position += ind;
		}

		int getPos()
		{
			return Position;
		}
		bool returnHole()
		{
			return blackHole;
		}
		void updateHole(bool update)
		{
			blackHole = update;
		}
};

class Ladder // gain position
{
private:
	int pos;
	int length;

public:
	Ladder(int p, int l)
	{
		pos = p-1;
		length = l-p;
	}

	int getPos()
	{
		return pos;
	}
	int getLength()
	{
		return length;
	}
};

class Snake // - position
{
private:
	int pos;
	int length;

public:
	Snake(int p, int head)
	{
		pos = head-1;
		length = head-p;
	}

	int getPos()
	{
		return pos;
	}
	int getLength()
	{
		return length;
	}
};

class blackHole
{
private:
	int pos;
public:
	blackHole(int p)
	{
		pos = p;
	}
	int getPos()
	{
		return pos;
	}

};


void numGenerator(vector<string>&num)
{
	for (int i = 1; i <= 100; i++)
	{
		num.push_back(to_string(i));
	}
}

bool blackCheck(int pos,vector<blackHole>bh)
{
	bool status=false;
	for (int i = 0; i <= 4; i++) 
	{
		if (pos == bh[i].getPos())
		{
			status = true;
		}
	}
	return status;
}




int main()
{
	srand((int)time(0)); // random value initialization
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!"); //sfml window construct



	vector<string>number; // number to hold 
	numGenerator(number); // generate number string 1 to 100


	int left_x = 200;
	int right_x = 1000;
	int top_y = 900;
	int bot_y = 100;
	int pix_step = (right_x - left_x) / 10;


	// create a dice button

	sf::RectangleShape button(sf::Vector2f(120, 50));
	button.setSize(sf::Vector2f(100, 100));
	button.setPosition(1300, 500); //position based on pixel 



	// draw vertical lines
	sf::Vertex verLine[] =
	{
		sf::Vertex(sf::Vector2f(left_x + pix_step,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 2,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 2,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 3,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 3,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 4,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 4,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 5,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 5,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 6,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 6,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 7,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 7,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 8,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 8,bot_y)),

		sf::Vertex(sf::Vector2f(left_x + pix_step * 9,top_y)),
		sf::Vertex(sf::Vector2f(left_x + pix_step * 9,bot_y)),


	};

	// draw horizontal line
	sf::Vertex horLine[] =
	{
		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 2)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 2)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 3)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 3)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 4)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 4)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 5)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 5)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 6)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 6)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 7)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 7)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 8)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 8)),

		sf::Vertex(sf::Vector2f(left_x,bot_y + pix_step * 9)),
		sf::Vertex(sf::Vector2f(right_x,bot_y + pix_step * 9)),

	};

	// Declare and load a font
	sf::Font font;
	font.loadFromFile("arial.ttf");
	
	// Create a text object
	sf::Text text; // number drawing text

	sf::Text message;
	message.setFont(font);
	message.setString("Default with 2 Players, press 3 or 4 to add extra player");
	message.setPosition(1100, 100);
	
	//show current number of player 
	sf::Text numPlayer;
	numPlayer.setFont(font);
	numPlayer.setString("Current # of Player: 2");
	numPlayer.setPosition(1300, 150);
	
	
	//Game legend ------------------------------------------------------------------------
	sf::Text legend;
	legend.setFont(font);
	legend.setString(" P1		P2		P3		P4");
	legend.setPosition(1300, 200);

	sf::CircleShape p1_legend(25.f);
	p1_legend.setFillColor(sf::Color(255, 255, 0));
	p1_legend.setPosition(1300, 250);

	sf::CircleShape p2_legend(25.f);
	p2_legend.setFillColor(sf::Color(0, 128, 0));
	p2_legend.setPosition(1400, 250);

	sf::CircleShape p3_legend(25.f);
	p3_legend.setFillColor(sf::Color(255, 255, 255));
	p3_legend.setPosition(1500, 250);

	sf::CircleShape p4_legend(25.f);
	p4_legend.setFillColor(sf::Color(51, 112, 255));
	p4_legend.setPosition(1600, 250);

	// Player dice text-----------------------------------------
	sf::Text t1;
	sf::Text t2;
	sf::Text t3;
	sf::Text t4;
	sf::Text diceText;

	t1.setFont(font);
	t2.setFont(font);
	t3.setFont(font);
	t4.setFont(font);
	diceText.setFont(font);

	t1.setString("");
	t2.setString("");
	t3.setString("");
	t4.setString("");
	diceText.setString("Dice:");

	diceText.setPosition(1100, 300);
	t1.setPosition(1300, 300);
	t2.setPosition(1400, 300);
	t3.setPosition(1500, 300);
	t4.setPosition(1600, 300);

	// Game status------------
	sf::Text p1_won;
	sf::Text p2_won;
	sf::Text p3_won;
	sf::Text p4_won;
	sf::Text game_won;

	p1_won.setFont(font);
	p2_won.setFont(font);
	p3_won.setFont(font);
	p4_won.setFont(font);
	game_won.setFont(font);
	
	p1_won.setString("");
	p2_won.setString("");
	p3_won.setString("");
	p4_won.setString("");
	game_won.setString("Won:");

	game_won.setPosition(1100, 350);
	p1_won.setPosition(1300, 350);
	p2_won.setPosition(1400, 350);
	p3_won.setPosition(1500, 350);
	p4_won.setPosition(1600, 350);

	// Black hole status text
	sf::Text black_s_1;
	sf::Text black_s_2;
	sf::Text black_s_3;
	sf::Text black_s_4;
	sf::Text b_index;

	black_s_1.setFont(font);
	black_s_2.setFont(font);
	black_s_3.setFont(font);
	black_s_4.setFont(font);
	b_index.setFont(font);

	black_s_1.setString("True");
	black_s_2.setString("True");
	black_s_3.setString("True");
	black_s_4.setString("True");
	b_index.setString("Blackhole:");

	b_index.setPosition(1100, 400);
	black_s_1.setPosition(1300, 400);
	black_s_2.setPosition(1400, 400);
	black_s_3.setPosition(1500, 400);
	black_s_4.setPosition(1600, 400);




	//Player setup--------------------------------------------------------
		// Player #1 object initialization
	Player P1(left_x, top_y - pix_step, 1, true);
	sf::CircleShape shape(30.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setPosition(left_x - pix_step, top_y - pix_step);

	// Player #2 object initialization
	Player P2(left_x, top_y - pix_step, 1, true);
	sf::CircleShape shape_2(30.f);
	shape_2.setFillColor(sf::Color(0, 128, 0));
	shape_2.setPosition(left_x - pix_step, top_y - pix_step);

	// Player #3 object initialization 
	Player P3(left_x, top_y - pix_step, 1, true);
	sf::CircleShape shape_3(30.f);
	shape_3.setFillColor(sf::Color(255, 255, 255));
	shape_3.setPosition(left_x - pix_step, top_y - pix_step);


	// Player #4 object initialization 
	Player P4(left_x, top_y - pix_step, 1, true);
	sf::CircleShape shape_4(30.f);
	shape_4.setFillColor(sf::Color(51, 112, 255));
	shape_4.setPosition(left_x - pix_step, top_y - pix_step);



	//ladder object even row
	vector<Ladder>ladders;
	Ladder ladder_1(7, 21); //7 to 21
	Ladder ladder_2(23, 45); //23 to 45
	Ladder ladder_3(48, 65); //48 to 65
	Ladder ladder_4(61, 78); //61 to 78
	Ladder ladder_5(85, 91);  //85 to 91
	ladders.push_back(ladder_1);
	ladders.push_back(ladder_2);
	ladders.push_back(ladder_3);
	ladders.push_back(ladder_4);
	ladders.push_back(ladder_5);
	sf::Color ladderColor(sf::Color::Green);


	//snake object odd row
	vector<Snake>snakes;
	Snake snake_1(3, 11);
	Snake snake_2(21, 31);
	Snake snake_3(42, 57);
	Snake snake_4(51, 68);
	Snake snake_5(72, 85);
	snakes.push_back(snake_1);
	snakes.push_back(snake_2);
	snakes.push_back(snake_3);
	snakes.push_back(snake_4);
	snakes.push_back(snake_5);
	sf::Color snakeColor(sf::Color::Red);

	vector<blackHole>blackHoles;
	blackHole b1(5);
	blackHole b2(15);
	blackHole b3(55);
	blackHole b4(70);
	blackHole b5(88);
	blackHoles.push_back(b1);
	blackHoles.push_back(b2);
	blackHoles.push_back(b3);
	blackHoles.push_back(b4);
	blackHoles.push_back(b5);





	vector<vector<int>> v2d;
	vector<int> d;

	int count = 0;
	for (int i = 0; i < 10; i++) // draw the grid
	{
		for (int j = 0; j < 10; j++)
		{
			text.setFont(font); //give font to text
			text.setString(number[count]);

			if (i % 2 == 0)
			{
				text.setPosition(left_x + j * pix_step, top_y - i * pix_step - pix_step);
			}
			else

			{
				text.setPosition(right_x - j * pix_step - pix_step, top_y - i * pix_step - pix_step);
			}
			d.push_back(text.getPosition().x); // push x value to holder
			d.push_back(text.getPosition().y); // push y value to holder
			v2d.push_back(d);
			d.clear();
		}
	}

	sf::Vertex drawLadder[] =
	{
		sf::Vertex(sf::Vector2f(v2d[6][0] + 50,v2d[6][1] + 50),ladderColor), //ladder at #7
		sf::Vertex(sf::Vector2f(v2d[21][0] - 50,v2d[20][1] + 50),ladderColor), //ladder at 21

		sf::Vertex(sf::Vector2f(v2d[22][0] + 50,v2d[22][1] + 50),ladderColor), //ladder at #23
		sf::Vertex(sf::Vector2f(v2d[44][0] + 50,v2d[44][1] + 50),ladderColor), // ladder at #45

		sf::Vertex(sf::Vector2f(v2d[47][0] + 50,v2d[47][1] + 50),ladderColor), //ladder 48
		sf::Vertex(sf::Vector2f(v2d[64][0] + 50,v2d[64][1] + 50),ladderColor), //ladder 65

		sf::Vertex(sf::Vector2f(v2d[60][0] + 50,v2d[60][1] + 50),ladderColor), //ladder4 61
		sf::Vertex(sf::Vector2f(v2d[77][0] + 50,v2d[77][1] + 50),ladderColor), //ladder4 78

		sf::Vertex(sf::Vector2f(v2d[84][0] + 50,v2d[84][1] + 50),ladderColor), //ladder 85
		sf::Vertex(sf::Vector2f(v2d[90][0] + 50,v2d[90][1] + 50),ladderColor), // ladder 91
	};

	sf::Vertex drawSnake[] =
	{
		sf::Vertex(sf::Vector2f(v2d[2][0] + 50,v2d[2][1] + 50),snakeColor), //snake at #3
		sf::Vertex(sf::Vector2f(v2d[10][0] + 50,v2d[10][1] + 50),snakeColor), //snake at 11

		sf::Vertex(sf::Vector2f(v2d[21][0] + 50,v2d[21][1] + 50),snakeColor), //snake at #23
		sf::Vertex(sf::Vector2f(v2d[30][0] + 50,v2d[30][1] + 50),snakeColor), // snake at #31

		sf::Vertex(sf::Vector2f(v2d[41][0] + 50,v2d[41][1] + 50),snakeColor), //snake 42
		sf::Vertex(sf::Vector2f(v2d[56][0] + 50,v2d[56][1] + 50),snakeColor), //snake 57

		sf::Vertex(sf::Vector2f(v2d[50][0] + 50,v2d[50][1] + 50),snakeColor), //snake 51
		sf::Vertex(sf::Vector2f(v2d[67][0] + 50,v2d[67][1] + 50),snakeColor), //snake 68

		sf::Vertex(sf::Vector2f(v2d[71][0] + 50,v2d[71][1] + 50),snakeColor), //snake 72
		sf::Vertex(sf::Vector2f(v2d[85][0] + 50,v2d[85][1] + 50),snakeColor), // snake 86
	};



	//for (int i = 0; i < 100; i++) // verify position
	//{
	//	cout << "For number # = " << i + 1 << " " << v2d[i][0] << " " << v2d[i][1] << endl;
	//}


	int dice = 0;

	int P1_index = 0;
	int P2_index = 0;
	int P3_index = 0;
	int P4_index = 0;

	bool won = false; // check game status


	int dice_play = 1; //starting with player #1
	int player_count = 2;



	while (window.isOpen())
	{

		window.clear();



		sf::Event event;
		while (window.pollEvent(event)) // main game logic, event checker
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) //player selection
			{
				player_count = 4;
				numPlayer.setString("Current # of Player: 4");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))//player selection
			{
				player_count = 3;
				numPlayer.setString("Current # of Player: 3");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))//player selection
			{
				player_count = 2;
				numPlayer.setString("Current # of Player: 2");
			}

			// need a player checker to decide which to roll
			if (sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().x < 1400
				&& sf::Mouse::getPosition().y < 650 && sf::Mouse::getPosition().y > 550)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) // if mouse left is clicked
				{
					// do something for player 1
					if (dice_play == 1)
					{
						dice = rand() % 6 + 1;
						cout << "P1 dice value: " << dice << endl;

						// display only the current dice value
						t1.setString(to_string(dice));
						t2.setString("");
						t3.setString("");
						t4.setString("");


						if (P1.returnHole() == true) // case which player stuck in blackhole
						{
							black_s_1.setString("True");

							if (dice == 6) // player leave black hole when draw a 6
							{
								P1.updateHole(false); // set blackhole status to false for player
								cout << "P1 is out of blackhole" << endl;
								black_s_1.setString("False");
							}
						}
						else if (P1.returnHole() == false) // the case which the player isn't in blackhole
						{
							black_s_1.setString("False");
							P1.updatePos(dice);
							P1_index = P1.getPos() - 1;
							if ((P1_index < 100) && won != true)
							{
								//check if snake encounter
								for (int snake_i = 0; snake_i < snakes.size(); snake_i++) // check snake
								{
									if (P1_index == snakes[snake_i].getPos())
									{
										cout << "P1 Encounter snake at position:" << P1.getPos() << endl;
										P1_index -= snakes[snake_i].getLength();
										P1.updatePos(-snakes[snake_i].getLength());
										cout << "P1 Went back to position:" << P1.getPos() << endl;

									}
								}
								//check if ladder encounter
								for (int ladder_i = 0; ladder_i < ladders.size(); ladder_i++)
								{
									if (P1_index == ladders[ladder_i].getPos())
									{
										cout << "P1 Encounter ladder at position:" << P1.getPos() << endl;
										P1_index += ladders[ladder_i].getLength();
										P1.updatePos(ladders[ladder_i].getLength());
										cout << "P1 Went up to position:" << P1.getPos() << endl;
									}

								}
								//set player1's position
								shape.setPosition(v2d[P1_index][0], v2d[P1_index][1]);
							}

							else if (won != true)
							{
								shape.setPosition(v2d[99][0], v2d[99][1]);
								p1_won.setString("Yes");
								cout << "P1 Won" << endl;
								won = true;

							}
							//checking if a player is in a blackhole after diced
							if (blackCheck(P1.getPos(), blackHoles) == true) // check if player's new position is in blackhole
							{
								P1.updateHole(true);
								cout << "P1 stuck in blackhole at position" << P1.getPos() << endl;
								black_s_1.setString("True");
							}

						}


						dice_play++;

					}

					//---------------------------------------------------------Player2
					else if (player_count >= 2 && dice_play == 2) //player2
					{
						dice = rand() % 6 + 1;
						cout << "P2 dice value: " << dice << endl;
						t1.setString("");
						t2.setString(to_string(dice));
						t3.setString("");
						t4.setString("");

						if (P2.returnHole() == true)  // case which player stuck in blackhole
						{
							black_s_2.setString("True");
							cout << P2.returnHole() << endl;
							if (dice == 6)
							{
								P2.updateHole(false);
								black_s_2.setString("False");
								cout << "P2 is out of blackhole" << endl;

							}
						}
						else if (P2.returnHole() == false)
						{
							black_s_2.setString("False");
							P2.updatePos(dice);
							P2_index = P2.getPos() - 1;
							if ((P2_index < 100) && won != true)
							{
								//check if snake encounter
								for (int snake_i = 0; snake_i < snakes.size(); snake_i++) // check snake
								{
									if (P2_index == snakes[snake_i].getPos())
									{
										cout << "P2 Encounter snake at position:" << P2.getPos() << endl;
										P2_index -= snakes[snake_i].getLength();
										P2.updatePos(-snakes[snake_i].getLength());
										cout << "P2 Went back to position:" << P2.getPos() << endl;

									}
								}
								//check if ladder encounter
								for (int ladder_i = 0; ladder_i < ladders.size(); ladder_i++)
								{
									if (P2_index == ladders[ladder_i].getPos())
									{
										cout << "P2 Encounter ladder at position:" << P2.getPos() << endl;
										P2_index += ladders[ladder_i].getLength();
										P2.updatePos(ladders[ladder_i].getLength());
										cout << "P2 Went up to position:" << P2.getPos() << endl;
									}

								}
								//set player2's position
								shape_2.setPosition(v2d[P2_index][0], v2d[P2_index][1]);
							}

							else if (won != true)
							{
								shape_2.setPosition(v2d[99][0], v2d[99][1]);
								p2_won.setString("Yes");
								cout << "P2 Won" << endl;
								won = true;

							}

							if (blackCheck(P2.getPos(), blackHoles) == true)
							{
								P2.updateHole(true);
								cout << "P2 stuck in blackhole at position" << P2.getPos() << endl;
								black_s_2.setString("True");
							}

						}

						if (player_count > 2)
						{
							dice_play++;
						}
						else
						{
							dice_play = 1;
						}



					}

					// Player 3 --------------------------
					else if (player_count >= 3 && dice_play == 3) // player3
					{
						dice = rand() % 6 + 1;
						cout << "P3 dice value: " << dice << endl;
						t1.setString("");
						t2.setString("");
						t3.setString(to_string(dice));
						t4.setString("");
						black_s_3.setString(to_string(P3.returnHole()));
						if (P3.returnHole() == true)
						{
							black_s_3.setString("True");
							if (dice == 6)
							{
								P3.updateHole(false);
								black_s_3.setString("False");
								cout << "P3 is out of blackhole" << endl;
							}
						}
						else
						{
							black_s_3.setString("False");
							P3.updatePos(dice);
							P3_index = P3.getPos() - 1;
							if ((P3_index < 100) && won != true)
							{
								//check if snake encounter
								for (int snake_i = 0; snake_i < snakes.size(); snake_i++) // check snake
								{
									if (P3_index == snakes[snake_i].getPos())
									{
										cout << "P3 Encounter snake at position:" << P3.getPos() << endl;
										P3_index -= snakes[snake_i].getLength();
										P3.updatePos(-snakes[snake_i].getLength());
										cout << "P3 Went back to position:" << P3.getPos() << endl;

									}
								}
								//check if ladder encounter
								for (int ladder_i = 0; ladder_i < ladders.size(); ladder_i++)
								{
									if (P3_index == ladders[ladder_i].getPos())
									{
										cout << "P3 Encounter ladder at position:" << P3.getPos() << endl;
										P3_index += ladders[ladder_i].getLength();
										P3.updatePos(ladders[ladder_i].getLength());
										cout << "P3 Went up to position:" << P3.getPos() << endl;
									}

								}
								//set player3's position
								shape_3.setPosition(v2d[P3_index][0], v2d[P3_index][1]);
							}

							else if (won != true)
							{
								shape_3.setPosition(v2d[99][0], v2d[99][1]);
								cout << "P3 Won" << endl;
								p3_won.setString("Yes");
								won = true;

							}
							if (blackCheck(P3.getPos(), blackHoles) == true)
							{
								P3.updateHole(true);

								cout << "P3 stuck in blackhole at position" << P3.getPos() << endl;
								black_s_3.setString("True");
							}

						}



						if (player_count == 4)
						{
							dice_play++;
						}
						else
						{
							dice_play = 1;
						}



					}

					//------------------------------Player 4
					else if (player_count == 4 && dice_play == 4)
					{
						dice = rand() % 6 + 1;
						cout << "P4 dice value: " << dice << endl;
						t1.setString("");
						t2.setString("");
						t3.setString("");
						t4.setString(to_string(dice));

						if (P4.returnHole() == true)  // case which player stuck in blackhole
						{
							black_s_4.setString("True");
							if (dice == 6)
							{
								P4.updateHole(false);
								black_s_4.setString("False");
								cout << "P4 is out of blackhole" << endl;
							}
						}
						else
						{
							black_s_4.setString("False");
							P4.updatePos(dice);
							P4_index = P4.getPos() - 1;
							if ((P4_index < 100) && won != true)
							{
								//check if snake encounter
								for (int snake_i = 0; snake_i < snakes.size(); snake_i++) // check snake
								{
									if (P4_index == snakes[snake_i].getPos())
									{
										cout << "P1 Encounter snake at position:" << P4.getPos() << endl;
										P4_index -= snakes[snake_i].getLength();
										P4.updatePos(-snakes[snake_i].getLength());
										cout << "P4 Went back to position:" << P4.getPos() << endl;

									}
								}
								//check if ladder encounter
								for (int ladder_i = 0; ladder_i < ladders.size(); ladder_i++)
								{
									if (P4_index == ladders[ladder_i].getPos())
									{
										cout << "P4 Encounter ladder at position:" << P4.getPos() << endl;
										P4_index += ladders[ladder_i].getLength();
										P4.updatePos(ladders[ladder_i].getLength());
										cout << "P4 Went up to position:" << P4.getPos() << endl;
									}

								}
								//set player1's position
								shape_4.setPosition(v2d[P4_index][0], v2d[P4_index][1]);
							}

							else if (won != true)
							{
								shape_4.setPosition(v2d[99][0], v2d[99][1]);
								p4_won.setString("Yes");
								cout << "P4 Won" << endl;
								won = true;

							}
							if (blackCheck(P4.getPos(), blackHoles) == true)
							{
								P4.updateHole(true);
								black_s_4.setString("True");
								cout << "P4 stuck in blackhole at position" << P4.getPos() << endl;
							}

						}

						dice_play = 1;
					}
				}
			}

			// draw grid board
			int count = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					text.setFont(font);
					text.setString(number[count]);
					if (i % 2 == 0)
					{
						text.setPosition(left_x + j * pix_step, top_y - i * pix_step - pix_step);
					}
					else
					{
						text.setPosition(right_x - j * pix_step - pix_step, top_y - i * pix_step - pix_step);
					}
					window.draw(text);
					count++;
				}
			}

			// draw board elements
			window.draw(verLine, 18, sf::Lines);
			window.draw(horLine, 18, sf::Lines);
			window.draw(drawLadder, 10, sf::Lines);
			window.draw(drawSnake, 10, sf::Lines);

			// draw player, button and text
			window.draw(shape);
			window.draw(shape_2);
			window.draw(shape_3);
			window.draw(shape_4);
			window.draw(button);
			window.draw(message);

			// game legends
			window.draw(numPlayer);
			window.draw(legend);
			window.draw(p1_legend);
			window.draw(p2_legend);
			window.draw(p3_legend);
			window.draw(p4_legend);

			// draw the value play dice
			window.draw(diceText);
			window.draw(t1);
			window.draw(t2);
			window.draw(t3);
			window.draw(t4);

			//draw game status
			window.draw(game_won);
			window.draw(p1_won);
			window.draw(p2_won);
			window.draw(p3_won);
			window.draw(p4_won);
			
			// draw blackhole status for player
			window.draw(black_s_1);
			window.draw(black_s_2);
			window.draw(black_s_3);
			window.draw(black_s_4);
			window.draw(b_index);

			window.display();

		}

	}

		return 0;
	}


