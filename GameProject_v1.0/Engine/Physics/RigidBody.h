#ifndef GAME_RIGIDBODY
#define GAME_RIGIDBODY
#include "../Maths/Vector3.h"
#include "../Maths/Rect.h"

class RigidBody {
public:

	static bool IsColliding(const RigidBody& rbA, const RigidBody& rbB);

	RigidBody();
	void Initialise(float _friction, float _gravity, Vector3* _pos, float* _rot, Vector3* _scale, Vector3* _size, Rect _boundingRect);

	void Update();
	void Render(Vector3 c);

	void AddForce(Vector3 f);
	void SetVel(Vector3 _vel);

	Vector3 GetVel();
	Vector3 GetPos();


private:
	Vector3* pos;
	Vector3* scale;
	float* rot;
	float lastRot;
	Vector3* size;

	float gravity;
	float friction;
	Vector3 vel;

	Rect boundingRect;

};

#endif
