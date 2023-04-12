#ifndef GAME_TEXTURE
#define GAME_TEXTURE
#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"
#include <string>
#include<iostream>
using namespace std;
class Texture {
public: 
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();


private:
	bool GetTextureParams();

	int id;
	int width;
	int height;

};
#endif
