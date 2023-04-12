#ifndef GAME_PIPE
#define GAME_PIPE

#include "../Engine/Graphics/Sprite.h"
#include "../Engine/Physics/RigidBody.h"
#include "../Engine/Maths/Vector3.h"

class Pipe {
public:
	static Sprite* pipeSprite;
	static void Initialise();

	float getPrevPos();

	Pipe();
	Pipe(Vector3 _pos);

	void Update();
	void Render();

	void MoveTo(Vector3 to);
	void MoveBy(Vector3 by);

	RigidBody GetTopRB();
	RigidBody GetBottomRB();

	float GetX();
	float GetWidth();

	void SetGap(float _gap);


private:
	void UpdatePos();
	Sprite topSprite;
	Sprite bottomSprite;
	RigidBody topRB;
	RigidBody bottomRB;
	float gap;
	float speed;
	Vector3 pos;
	float prevPos;

};

#endif
