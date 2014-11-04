#pragma once
#include "AIE.h"
#include "player.h"

class enemy
{
public:
	enemy();
		unsigned int iSpriteID;
		void Move();
		void Draw();
	~enemy();

private:

	float x;

	float y;

	float fWidth;
	float fHeight;
};

