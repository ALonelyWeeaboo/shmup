#include <AIE.h>
#include <iostream>
#include <string>
#include "player.h"
const int iScreenWidth = 1040;
const int iScreenHeight = 820;


unsigned int menu;

unsigned int credits;

	
struct ship
{
	unsigned int SpriteID = CreateSprite("./images/cannon.png", 64, 98, true);
public:

	float x = 300;
	float y = 300;
	float ShipWidth = 64;
	float ShipHeight = 98;
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




struct alienShips
{
	unsigned int SpriteID = CreateSprite("./images/invaders_1_00.png", 134, 115, true);
	unsigned int enemyShips;
	float x = 900;
	float y = 410;
	float enemyspeedx = 0;
	float enemyspeedy = 0;
	float fEnemyX = iScreenWidth * 0.2f;
	float fEnemyY = iScreenHeight * 0.7f;
	

	void Draw()
	{
		DrawSprite(SpriteID);
	}

	void Move(float deltatime)
	{
		x -= enemyspeedx *deltatime;
		y += enemyspeedy *deltatime;
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
	GAMESTATES eCurrentState = eMAINMENU;
	bool GamePause = false;
	ship player1;
	player1.x = iScreenHeight * .5;
	player1.y = 150;

	alienShips enemyship;

	float fPlayerWidth = iScreenWidth * 0.2f;
	float fPlayerHeight = iScreenHeight *.7f;

	//game loop
	do
	{

		float deltatime = GetDeltaTime() * 8;
		SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
		
		switch (eCurrentState)
		{
		case eMAINMENU:

			UpdateMainMenu();
			ClearScreen();


			if (IsKeyDown(GLFW_KEY_ENTER))
			{
				eCurrentState = eGAMEPLAY;
			}
			if (IsKeyDown(GLFW_KEY_ESCAPE))
			{
				IsGameRunning = false;

			}
			if (IsKeyDown(GLFW_KEY_F1))
			{
				eCurrentState = eCREDITS;
			}
			break;



		case eGAMEPLAY:
			player1.Draw();
			player1.Move(deltatime);
			ClearScreen();
			//controls
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
		
		

		//for loop
	
				//green line from space invaders, I might make use of it
			DrawLine(0, 40, iScreenWidth, 40, SColour(0x00, 0xFC, 0x00, 0xFF));
			
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