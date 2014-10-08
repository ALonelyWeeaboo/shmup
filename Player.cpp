#include "Player.h"
#include"AIE.h"

Player::Player()
{
}

void Player::SetSize(float a_fWidth, float a_fHeight)
{
	fWidth = a_fWidth;
	fHeight = a_fHeight;
}

void Player::SetPosition(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

void Player::SetMovementKeys(unsigned int a_moveLeft, unsigned int a_moveRight, unsigned int a_moveUp, unsigned int a_moveDown)
{
	iMoveLeftKey = a_moveLeft;
	iMoveRightKey = a_moveRight;
	iMoveUpKey = a_moveUp;
	iMoveDownKey = a_moveDown;

}

void Player::SetMovementExtreme(unsigned int a_leftExtreme, unsigned int a_RightExtreme, unsigned int a_UpExtreme, unsigned int a_DownExtreme)
{
	iLeftMovementExtreme = a_leftExtreme;
	iRightMovementExtreme = a_RightExtreme;
	iUpMovementExtreme = a_UpExtreme;
	iDownMovementExtreme = a_DownExtreme;

}


void Player::Move(float a_fTimeStep, float a_fSpeed)
{
	if (IsKeyDown(iMoveLeftKey))
	{
		x -= a_fTimeStep * a_fSpeed;
		if (x < (iLeftMovementExtreme + fWidth*.5f))
		{
			x = (iLeftMovementExtreme + fWidth*.5f);
		}
	}

	if (IsKeyDown(iMoveRightKey))
	{
		x += a_fTimeStep * a_fSpeed;
		if (x >(iRightMovementExtreme - fWidth*.5f))
		{
			x = (iRightMovementExtreme - fWidth*.5f);
		}
	}
	MoveSprite(iSpriteID, x, y);
}

Player::~Player()
{
}
