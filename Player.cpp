#include "player.h"
#include "AIE.h"

player::player()
{
}

void player::SetSpriteID(unsigned int iSpriteID)
{
	this->iSpriteID = iSpriteID;
}

unsigned int player::GetSpriteID()
{
	return iSpriteID;
}
void player::SetSize(float a_fWidth, float a_fHeight)
{
	fWidth = a_fWidth;
	fHeight = a_fHeight;
}

void player::SetPosition(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

void player::SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight)
{
	iMoveLeftKey = a_moveLeft;
	iMoveRightKey = a_moveRight;
}

void player::SetMovementExtremes(unsigned int a_leftExtreme, unsigned int a_RightExtreme)
{
	iLeftMovementExtreme = a_leftExtreme;
	iRightMovementExtreme = a_RightExtreme;
}

void player::Move(float a_fTimeStep, float a_fSpeed)
{
	if( IsKeyDown(iMoveLeftKey))
	{
		x -= a_fTimeStep * a_fSpeed;
		if (x > (iRightMovementExtreme - fWidth*5.f))
		{
			x = (iRightMovementExtreme - fWidth*.5f);
		}
	}

	if (IsKeyDown(iMoveRightKey))
	{
		x += a_fTimeStep * a_fSpeed;
		if (x > (iRightMovementExtreme - fWidth * .5f))
		{
			x - (iRightMovementExtreme - fWidth*.5f);
		}
	}
}



player::~player()
{
}
