#include "GameManager.h"
#include "../Engine/IO/Mouse.h"
#include "../Engine/IO/Keyboard.h"

GameManager::GameManager() {
	mEngine = new Engine();
	mEngine->Initialise("Game");
	Sprite testSprite = Sprite("Assets/Art/Biplane.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	testSprite.SetScale(0.15f);
	mFlapper = new Flapper(testSprite);
	mPipeManager = new PipeManager();

	mStartSprite = Sprite("Assets/Art/spacetostart.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite = Sprite("Assets/Art/gameover.png", Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	mGameOverSprite.SetScale(0.2f);

	mState = State::START;
}

GameManager::~GameManager() {
	delete mEngine;
	delete mFlapper;
	delete mPipeManager;
}

void GameManager::Start() {
	while (true) {


		mEngine->Update();

		switch (mState) {
		case State::START:
		{
			mEngine->BeginRender();
			mStartSprite.Render();
			mEngine->EndRender();

			if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
				SetState(State::GAMEPLAY);
			}
		}
		break;
		case State::GAMEPLAY:
		{
			mFlapper->Update();
			mPipeManager->Update();
			
			mEngine->BeginRender();
			mFlapper->Render();
			mPipeManager->Render();
			mEngine->EndRender();

			bool isDead = mPipeManager->CheckCollision(*mFlapper);
			if (mFlapper->GetSprite().GetPos()->y < 0 || mFlapper->GetSprite().GetPos()->y > Engine::SCREEN_HEIGHT) {
				isDead = true;
			}

			if (isDead) {
				SetState(State::GAMEOVER);
				cout << "Points: " << mPipeManager->getPoints() << endl;
			}

		}
		break;
		case State::GAMEOVER:
		{
			
			mEngine->BeginRender();
			mFlapper->Render();
			mPipeManager->Render();
			mGameOverSprite.Render();
			mEngine->EndRender();

			if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
				SetState(State::START);
			}
		}
		break;

		default:
			cout << "Unhandled Game State: " << static_cast<int>(mState) << endl;
		}
	}
}

//Private

void GameManager::SetState(State state) {
		
	mState = state;
	if (mState == State::START) {
		mFlapper->Reset();
		mPipeManager->Reset();
	}
}