#include "StateManager.h"


StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

void StateManager::SetState(GameState gameState)
{
	this->gameState = gameState;
}
