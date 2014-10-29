#pragma once
class StateManager
{
public:
	StateManager();

	enum GameState
	{
		INTRODUCTION,
		MAIN_MENU,
		GAMEPLAY,
	};

	void SetState(GameState gameState);
	GameState GetState();
	~StateManager();
private:

	GameState gameState;
};

