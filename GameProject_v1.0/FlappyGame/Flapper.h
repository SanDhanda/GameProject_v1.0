#ifndef GAME_FLAPPER
#define GAME_FLAPPER
#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/RigidBody.h"
class Flapper {
public:
	Flapper();
	Flapper(Sprite _sprite);

	void Update();
	void Render();

	Sprite& GetSprite();
	RigidBody& GetRB();

	void Flap();
	void Reset();

private:
	void HandleInput();
private:
	Sprite sprite;
	RigidBody rb;

	float maxRot;
	float minRot;
	float flapForce;
};

#endif