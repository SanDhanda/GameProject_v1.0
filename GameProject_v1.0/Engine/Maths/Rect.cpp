#include "Rect.h"

Rect::Rect() {
	pos = Vector3(0);
	size = Vector3(0);
	UpdateVertices();
}

Rect::Rect(Vector3 _size):Rect() {
	pos = Vector3(0);
	size = _size;
	UpdateVertices();

}

Rect::Rect(Vector3 _size, Vector3 _pos) :Rect(_size) {
	pos = _pos;
	UpdateVertices();

}

void Rect::MoveBy(Vector3 by) {
	pos = pos + by;
	UpdateVertices();


}

void Rect::MoveTo(Vector3 to) {
	pos = to;
	UpdateVertices();

}

void Rect::SetSize(Vector3 _size) {
	size = _size;
	UpdateVertices();

}

void Rect::UpdateVertices() {
	lowerLeftVertex		= Vector3(pos.x - (size.x / 2), pos.y - (size.y / 2), 0);
	lowerRightVertex	= Vector3(pos.x + (size.x / 2), pos.y - (size.y / 2), 0);
	upperLeftVertex		= Vector3(pos.x - (size.x / 2), pos.y + (size.y / 2), 0);
	upperRightVertex	= Vector3(pos.x + (size.x / 2), pos.y + (size.y / 2), 0);
}