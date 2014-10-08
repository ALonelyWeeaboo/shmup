#include "bullet.h"


bullet::bullet()
{
}

void bullet::Draw()
{
	if (isActive)
	{
		MoveSprite(textureID, x, y);
		DrawSprite(textureID);
	}
}


void bullet::Update(float delta)
{
	if (isActive)
	{
		x += velocityX * delta;
		y + -velocityX * delta;
	}

}

void bullet::InitialiseBullet(float x, float y, float veloctiyX, float velocityY, unsigned int textureID)

{
	this->x = x;
	this->y = y;
	this->velocityX = velocityX;
	this->velocityY = velocityY;

	isActive = true;
}

bullet::~bullet()
{
}
