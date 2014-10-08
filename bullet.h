#include "AIE.h"
#pragma once
class bullet
{
public:
	bullet();
	~bullet();

	float x;
	float y;
	float width;
	float height;

	unsigned int textureID;
	
	float velocityX;
	float velocityY;

	void Update(float delta);
	void Draw();
	void InitialiseBullet(float x, float y, float velocityX, float velocityY, unsigned int textureID);

	bool isActive;
};

