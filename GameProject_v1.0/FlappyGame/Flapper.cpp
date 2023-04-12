#include "Flapper.h"
#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "../Engine/IO/Mouse.h"

Flapper::Flapper() {
	flapForce = 400;
	maxRot = 30;
	minRot = -maxRot;
}
Flapper::Flapper(Sprite _sprite) : Flapper() {
	sprite = _sprite;
	Rect boundingRect = Rect();
	Vector3 sizeOffset(0.8, 0.3, 1);
	boundingRect.SetSize(*sprite.GetSize() * *sprite.GetScale() * sizeOffset);
	rb.Initialise(0.8f,10,sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize(), boundingRect);
	
}

void Flapper::Update() {

	HandleInput();
	sprite.Update();
	rb.Update();
	float yVel = rb.GetVel().y;
	if (flapForce == 0) {
		cout << "Error. FlapForce Cannot be 0. Setting to default: 400";
		flapForce = 400;
	}
	float newRot = (maxRot / flapForce) * yVel;
	sprite.RotateTo(newRot);
}

void Flapper::Render() {
	sprite.Render();
	rb.Render(Vector3(0, 0, 0));

}
Sprite& Flapper::GetSprite() {
	return sprite;
}

RigidBody& Flapper::GetRB() {
	return rb;
}


void Flapper::Flap() {
	rb.SetVel(Vector3(0, flapForce, 0));
	sprite.RotateTo(maxRot);
}

void Flapper::Reset() {
	sprite.MoveTo(Vector3(Engine::SCREEN_WIDTH / 2, Engine::SCREEN_HEIGHT / 2, 0));
	sprite.RotateTo(0);
	rb.SetVel(Vector3(0, 0, 0));

}

//Private
void Flapper::HandleInput() {
	if (Keyboard::Key(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
		Flap();
	}
}