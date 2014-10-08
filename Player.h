#pragma once

#include "bullet.h"

const int MAX_BULLETS = 20;
class Player
{
public:
	unsigned int iSpriteID;
	float fWidth;
	float fHeight;
	float x;
	float y;
	unsigned int iMoveLeftKey;
	unsigned int iMoveRightKey;
	unsigned int iMoveUpKey;
	unsigned int iMoveDownKey;
	unsigned int iLeftMovementExtreme;
	unsigned int iRightMovementExtreme;
	unsigned int iUpMovementExtreme;
	unsigned int iDownMovementExtreme;
	
	void SetSize(float a_fWidth, float a_fHeight);
	void SetPosition(float a_x, float a_y); //ylmao
	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_moveUp, unsigned int a_moveDown);

	void SetMovementExtreme(unsigned int a_leftExtreme, unsigned int a_RightExtreme, unsigned int a_UpExtreme, unsigned int a_DownExtreme);
	void Move(float a_fTimeStep, float a_fSpeed);
	
	void SetSpriteID(unsigned int iSpriteID);
	unsigned int GetSpriteID();

	void SetWidth(float fWidth);
	void SetHeight(float fHeight);

	float GetWidth();
	float GetHeight();

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

	bullet bullets[MAX_BULLETS];
	Player();
	~Player();
};

