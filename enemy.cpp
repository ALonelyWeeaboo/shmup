#include "enemy.h"


enemy::enemy()
{
}
void enemy::Move(float speed, int direction, float delta)
{
	x += speed * direction * delta; 
}

void enemy::Draw()
{
	MoveSprite(iSpriteID, x, y);
	DrawSprite(iSpriteID);
}


enemy::~enemy()
{
}
