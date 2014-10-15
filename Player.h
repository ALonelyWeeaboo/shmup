#pragma once
#include <AIE.h>
class player
{
public:
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

	unsigned int iSpriteID;
	float fWidth;
	float fHeight;
	float x;
	float y;
	unsigned int iMoveLeftKey;
	unsigned int iMoveRightKey;
	unsigned int iLeftMovementExtreme;
	unsigned int iRightMovementExtreme;

	void SetSize(float a_fWidth, float a_fHeight);
	void SetPosition(float a_x, float a_y);
	void SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight);
	void SetMovementExtremes(unsigned int a_leftExtreme, unsigned int a_RightExtreme);
	void Move(float a_fTimeStep, float a_fSpeed);


	player(void);
	~player(void);
};

