#ifndef GAME_GAMEMANAGER
#define GAME_GAMEMANAGER
#include "../Engine/Engine.h"
#include "../Engine/Graphics/Sprite.h"

#include "../FlappyGame/Flapper.h"
#include "Pipe.h"
#include "PipeManager.h"
class GameManager {

public:
	enum class State
	{
		START,
		GAMEPLAY,
		GAMEOVER,
		COUNT
	};
public:
	GameManager();
	~GameManager();

	void Start();

private:
	void SetState(State state);
private:
	Engine* mEngine;
	Flapper* mFlapper;
	PipeManager* mPipeManager;
	Sprite mStartSprite;
	Sprite mGameOverSprite;
	State mState;
};
#endif

