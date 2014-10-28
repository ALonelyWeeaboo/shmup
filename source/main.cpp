﻿#include <iostream>
#include <string>
#include <aie.h>

//screen resolution
const int iScreenWidth = 1040;
const int iScreenHeight = 820;


unsigned int menu;

unsigned int credits;

struct creditscreen
{
	unsigned int SpriteID = CreateSprite("./images/credits.png", 1040, 820, true);

	float x = 2080;
	float y = 1640;

	void Draw()
	{
		DrawSprite(SpriteID);

	}
};

struct ship
{
	unsigned int SpriteID = CreateSprite("./images/ship player.png", 64, 98, true);
public:

	float x = 300;
	float y = 300;
	
	float ShipSpeedX = 0;
	float ShipSpeedY = 0;

	void Draw()
	{
		DrawSprite(SpriteID);
	}

	void Move(float deltatime)
	{
		x += ShipSpeedX * deltatime;
		y += ShipSpeedY * deltatime;
		MoveSprite(SpriteID, x, y);
	}


};

struct bullets
{
	unsigned int SpriteID = CreateSprite("./images/bullet.png", 10, 32, false);

	float x = 0;
	float y = 0;
	float bulletwidth = 10;
	float bulletheight = 32;
	float bulletspeedX = 0;
	float bulletspeedY = 0;

	void Move(float deltatime)
	{
		x += bulletspeedX * deltatime;
			y += bulletspeedY * deltatime;

	}
};


struct alienShips
{
	unsigned int SpriteID = CreateSprite("./images/invaders_1_00.png", 134, 115, true);
	unsigned int enemyShips;
	float x = 900;
	float y = 410;
	float enemyspeedx = 0;
	float enemyspeedy = 0;
	float fEnemyX = 1040 * 0.2f;
	float fEnemyY = 820 * 0.7f;
	

	void Draw()
	{
		DrawSprite(SpriteID);
	}

	void Move(float deltatime)
	{
		x -= enemyspeedx *deltatime / 600;
		y += enemyspeedy *deltatime / 600;
		MoveSprite(SpriteID, x, y);
	}
};




void UpdateMainMenu()
{
	menu = CreateSprite("./images/menuscreen.png", 1040, 820, true);
	MoveSprite(menu, 520, 410);
	DrawSprite(menu);
}


void UpdateCredits()
{
	credits = CreateSprite("./images/credits.png", 1040, 820, true);
	MoveSprite(credits, 520, 410);
	DrawSprite(credits);

	float x = 520;
	float y = 410;
}


enum GAMESTATES
{
	eMAINMENU,
	eGAMEPLAY,
	eCREDITS,
	eEND
};



int main(int argc, char* argv[])
{
	bool IsGameRunning = true;
	Initialise(iScreenWidth, iScreenHeight, false, "I FEEL ASLEEP");
	
	
	ship player1;
	player1.x = iScreenHeight * .5;
	player1.y = 150;
	
	
	unsigned int alienShips[1];
	float fEnemyX = iScreenWidth * 0.2f;
	float fEnemyY = iScreenHeight * 0.7f;
	
	creditscreen credits;
	
	
		GAMESTATES eCurrentState = eMAINMENU;
	
		do
		{

			float deltatime = GetDeltaTime() * 8;
			SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));


			//Exit Game if statement
			if (IsKeyDown(GLFW_KEY_ESCAPE))
			{
				{
					IsGameRunning = false;

				}
			}
			switch (eCurrentState)
			{
			case eMAINMENU:

				UpdateMainMenu();
				ClearScreen();
				if (IsKeyDown(GLFW_KEY_ENTER))
				{
					eCurrentState = eGAMEPLAY;

				}

				break;
				switch (eCurrentState);

						{

					

								case eGAMEPLAY:
									CreateSprite("./images/sea.png", 1040, 820, true);
									ClearScreen();
									player1.Draw();
									player1.Move(deltatime);
									for (int i = 0; i < 5; ++i)
										{
											alienShips[1] = CreateSprite("./images/invaders/invaders_1_00.png", 64, 98, true);
											MoveSprite(alienShips[1], fEnemyX, fEnemyY);
											DrawSprite(alienShips[1]);
											fEnemyX += 0.00012 * 1040, 820;
											if (fEnemyX > 1040 * .8f)
											{
													fEnemyX = 1040 * .2f;
													fEnemyY -= 0.08 * 820;
											}
					
										}

					//exit
					if (IsKeyDown(GLFW_KEY_ESCAPE))
					{
						{
							IsGameRunning = false;

						}
					}


					//controls
					if (IsKeyDown(GLFW_KEY_UP))
					{
						player1.y += deltatime * 35.F;
						if (player1.y > -128.f)
						{
							player1.y > -128.0f;
							player1.Move(player1.y);
						}
					}

					//going down
					if (IsKeyDown(GLFW_KEY_DOWN))
					{
						player1.y -= deltatime * 35.f;
						if (player1.y < -128.f)
						{
							player1.y < -128.0f;
							player1.Move(player1.y);
						}
					}


					//going left
					if (IsKeyDown(GLFW_KEY_LEFT))
					{
						player1.x -= deltatime * 35.f;
						if (player1.x < 128.f)
						{
							player1.x < 128.f;
							player1.Move(player1.x);
						}
					}


					//going right
					if (IsKeyDown(GLFW_KEY_RIGHT))
					{
						player1.x += deltatime * 35.f;
						if (player1.x < 128.f)
						{
							player1.x < 128.f;
							player1.Move(player1.x);
						}
						
					}
					//Displays credits
					if (IsKeyDown(GLFW_KEY_F1))
					{
						eCurrentState = eCREDITS;

					}
					//making it so there are no boundries, like Astroids or Super Mario Brothers 2.
					//also, I made it so when the picture goes beyond the 1080 point
					if (player1.x >= 1090)
					{
						player1.x = -60;
					}
					if (player1.x <= -80)//-60
					{
						player1.x = 1090;
					}

					if (player1.y >= 880)
					{
						player1.y = -40;
					}

					if (player1.y <= -80)//-40
					{
						player1.y = 840;
					}
					
				}
				break;
				case eCREDITS:
					ClearScreen();
				
				credits.Draw();
				credits.x = 840;
				credits.y = 820;
				if (IsKeyDown(GLFW_KEY_BACKSPACE))
				{
					eCurrentState = eGAMEPLAY;
				}
				

				break;
				default:
					break;

			}
		}

		//Ends game,

		while (FrameworkUpdate() == false && IsGameRunning);

		Shutdown();
		return 0;

};