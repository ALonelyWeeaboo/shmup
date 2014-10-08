#include <AIE.h>
#include <iostream>
#include "bullet.h"
#include "Player.h"

const int iScreenHeight = 1040;
const int iScreenWidth = 820;


struct ship
{
	unsigned int SpriteID = CreateSprite("./images/cannon.png", 64, 98, true);
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

struct opening_menu
{
	unsigned int SpriteID = CreateSprite("./images/background.png", 0, 0, false);
	void Draw()
	{
		DrawSprite(SpriteID);
	}
};





enum GAMESTATES
{
	eMAINMENU,
	eGAMEPLAY,
	eEND
};




int main(int argc, char* argv[])
{
	bool IsGameRunning = true;
	Initialise(iScreenWidth, iScreenHeight, false, "SHMUP");
	GAMESTATES eCurrentState = eMAINMENU;
	opening_menu menu;
		ship player1;
		player1.x = iScreenHeight * .5;
		player1.y = 150;
		
		//game loop
		do
		{
			ClearScreen();
			float deltatime = GetDeltaTime() * 8;
			SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

			switch (eCurrentState)
			{
			case eMAINMENU:
				DrawString("Press Enter to Continue", iScreenWidth * .40, iScreenHeight * .800);
				menu.Draw();
				if (IsKeyDown(GLFW_KEY_ENTER))
				{
					eCurrentState = eGAMEPLAY;
				}

				break;


			case eGAMEPLAY:
				player1.Draw();
				player1.Move(deltatime);

				if (IsKeyDown(GLFW_KEY_UP))
				{
					player1.y += deltatime * 45.f;
					if (player1.y > -128.f)
					{
						player1.y > -128.0f;
						player1.Move(player1.y);
					}
				}

				//going down
				if (IsKeyDown(GLFW_KEY_DOWN))
				{
					player1.y -= deltatime * 45.f;
					if (player1.y < -128.f)
					{
						player1.y < -128.0f;
						player1.Move(player1.y);
					}
				}


				//going left
				if (IsKeyDown(GLFW_KEY_LEFT))
				{
					player1.x -= deltatime * 45.f;
					if (player1.x < 128.f)
					{
						player1.x < 128.f;
						player1.Move(player1.x);
					}
				}

				//going right
				if (IsKeyDown(GLFW_KEY_RIGHT))
				{
					player1.x += deltatime * 45.f;
					if (player1.x < 128.f)
					{
						player1.x < 128.f;
						player1.Move(player1.x);
					}
				}

				//making it so there are no boundries, like Astroids
				//also, I made it so when the picture goes beyond the 1080 point
				if (player1.y >= 1080)
				{
					player1.y =  -20;
				}
				if (player1.y <= -40)
				{
					player1.y = 1060;
				}

				if (player1.x >= 860)
				{
					player1.x = iScreenWidth - iScreenWidth;
				}

				if (player1.x <= -60)
				{
					player1.x = 840;
				}

			}

			if (IsKeyDown('C'))
			{
				DrawString("(/\^O^/\)", iScreenWidth * 0.30f, iScreenHeight * .80f);
			}

			if (IsKeyDown('Z'))
			{
				
			}

			//Ends game,
				if (IsKeyDown(GLFW_KEY_ESCAPE))
				{
					IsGameRunning = false;

				}
				
		}
	while (FrameworkUpdate() == false && IsGameRunning);
	Shutdown();
	return 0;
}
	