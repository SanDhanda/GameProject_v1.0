#ifndef GAME_RECT
#define GAME_RECT
#include "Vector3.h"
class Rect {
public:
	Rect();
	Rect(Vector3 _size);
	Rect(Vector3 _pos, Vector3 _size);

	void MoveBy(Vector3 by);
	void MoveTo(Vector3 to);

	void SetSize(Vector3 _size);

	Vector3 upperLeftVertex;
	Vector3 upperRightVertex;
	Vector3 lowerLeftVertex;
	Vector3 lowerRightVertex;

private:
	Vector3 pos;
	Vector3 size;

	

	void UpdateVertices();

};

#endif

