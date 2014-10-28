#pragma once
class Enemy
{
public:
	int enemy();

	unsigned int iSpriteID;

	void Move();
	void Draw();
	

	~Enemy();

private:

	float x;
	float y;

	float fWidth;
	float fHeight;
};

