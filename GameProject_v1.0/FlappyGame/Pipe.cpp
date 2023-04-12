#include "Pipe.h"
#include "../Engine/Maths/Rect.h"
#include "../Engine/Maths/Math.h"
#include "../Engine/Engine.h"

Sprite* Pipe::pipeSprite = NULL;

void Pipe::Initialise() {
	pipeSprite = new Sprite("Assets/Art/pipe.png");
	pipeSprite->SetScale(Vector3(0.1f, 0.35f, 1));

}

Pipe::Pipe() {
	if (!pipeSprite) {
		cout << "Trying to instatiate a Pipe without having initalised it";
		return;
	}
	topSprite = Sprite(*pipeSprite);
	bottomSprite = Sprite(*pipeSprite);

	gap = 500;
	speed = 200;
}

Pipe::Pipe(Vector3 _pos) : Pipe() {
	pos = _pos + Vector3(GetWidth(),0,0);
	prevPos = pos.x;
	if (!pipeSprite) {
		return;
	}
	UpdatePos();
	topSprite.FlipVertical();

	Rect topRect = Rect();
	topRect.SetSize(Vector3(Math::Abs(topSprite.GetSize()->x * topSprite.GetScale()->x), Math::Abs(topSprite.GetSize()->y * topSprite.GetScale()->y), 1));

	topRB = RigidBody();
	topRB.Initialise(1, 0, topSprite.GetPos(), topSprite.GetRot(), topSprite.GetScale(), topSprite.GetSize(), topRect);


	Rect bottomRect = Rect();
	bottomRect.SetSize(Vector3(Math::Abs(bottomSprite.GetSize()->x * bottomSprite.GetScale()->x), Math::Abs(bottomSprite.GetSize()->y * bottomSprite.GetScale()->y), 1));
	bottomRB = RigidBody();
	bottomRB.Initialise(1, 0, bottomSprite.GetPos(), bottomSprite.GetRot(), bottomSprite.GetScale(), bottomSprite.GetSize(), bottomRect);
	topRB.AddForce(Vector3(-speed, 0, 0));
	bottomRB.AddForce(Vector3(-speed, 0, 0));
}

void Pipe::Update() {
	
	prevPos = topSprite.GetPos()->x;
	topRB.Update();
	bottomRB.Update();

}

void Pipe::Render() {
	topSprite.Render();
	bottomSprite.Render();
	topRB.Render(Vector3(255,0,0));
	bottomRB.Render(Vector3(255, 0, 0));
}

void Pipe::MoveTo(Vector3 to) {
	pos = to;
	UpdatePos();
}

void Pipe::MoveBy(Vector3 by) {
	pos = pos + by;
	UpdatePos();
}

void Pipe::UpdatePos() {
	Vector3 topPos = pos;
	topPos.y += (gap / 2) + Math::Abs(topSprite.GetSize()->y * topSprite.GetScale()->y / 2);
	topSprite.MoveTo(topPos);

	Vector3 bottomPos = pos;
	bottomPos.y -= (gap / 2) + Math::Abs(bottomSprite.GetSize()->y * bottomSprite.GetScale()->y / 2);
	bottomSprite.MoveTo(bottomPos);
}

RigidBody Pipe::GetTopRB() {
	return topRB;
}

RigidBody Pipe::GetBottomRB() {
	return bottomRB;
}

float Pipe::GetX() {
	return GetTopRB().GetPos().x;
}

float Pipe::GetWidth() {
	return topSprite.GetSize()->x * topSprite.GetScale()->x;
}

void Pipe::SetGap(float _gap) {
	gap = _gap;
	UpdatePos();
}

float Pipe::getPrevPos() {
	return prevPos;
}