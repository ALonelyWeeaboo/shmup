#include "player.h"


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

void Player::SetMovementKeys(unsigned int a_MoveLeft, unsigned int a_MoveRight, unsigned int a_MoveUp, unsigned int a_MoveDown)
{
	iMoveLeftKey = a_MoveLeft;
	iMoveRightKey = a_MoveRight;
	iMoveUpKey = a_MoveUp;
	iMoveDownKey = a_MoveDown;
}


void Player::SetMovementExtremes(unsigned int a_leftExtreme, unsigned int a_RightExtreme, unsigned int a_UpExtreme, unsigned int a_DownExtreme)
{
	iLeftMovementExtreme = a_leftExtreme;
	iRightMovementExtreme = a_RightExtreme;
	iUpMovementExtreme = a_UpExtreme;
	iDownMovementExtreme = a_DownExtreme;
}

void Player::SetSpriteID(unsigned int iSpriteID)
{
	this->iSpriteID = iSpriteID;
}

unsigned int Player::GetSpriteID()
{
	return iSpriteID;
}


void Player::Move(float a_fTimeStep, float a_fSpeed)
{
	if (IsKeyDown(iMoveLeftKey))
		
		x -= a_fTimeStep * a_fSpeed;
			if (x < (iLeftMovementExtreme + fWidth*.5f))
				{
				x = (iLeftMovementExtreme + fWidth*.5f);
				}
	

				if (IsKeyDown(iMoveRightKey))
						{
				x += a_fTimeStep * a_fSpeed;
				if (x >(iRightMovementExtreme - fWidth*.5f))
					{
					x = (iRightMovementExtreme - fWidth*.5f);
					}
						}
					
							if (IsKeyDown(iMoveUpKey))

									y -= a_fTimeStep * a_fSpeed;
										if (y < (iUpMovementExtreme + fHeight*.5f))
												{
													y = (iUpMovementExtreme + fHeight*.5f);
												}

													if (IsKeyDown(iMoveDownKey))
													x += a_fTimeStep * a_fSpeed;
													if (x >(iDownMovementExtreme - fHeight *.5f))
														{
															x = (iDownMovementExtreme - fHeight * .5f);
														}

															MoveSprite(iSpriteID, x, y);
														}

Player::~Player()
{
}
