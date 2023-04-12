#ifndef GAME_SPRITE
#define GAME_SPRITE
#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Maths/Vector3.h"
#include <iostream>
#include <string>
using namespace std;
class Sprite {
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _pos);

	void Update();
	void Render();

	void MoveTo(Vector3 v);
	void MoveBy(Vector3 v);
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();


	void SpeedTo(float x);
	void SpeedBy(float x);

	void RotateTo(float x);
	void RotateBy(float x);

	void SetScale(float x);
	void SetScale(Vector3 v);

	Vector3* GetPos();
	float* GetRot();
	Vector3* GetScale();
	Vector3* GetSize();

	void FlipHorizontal();
	void FlipVertical();

private:
	Texture texture;
	Vector3 pos;
	float rot;
	Vector3 scale;
	float speed;
	Vector3 size;

};


#endif
