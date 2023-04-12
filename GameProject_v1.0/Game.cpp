#include <iostream>
#include "FlappyGame/GameManager.h"
#include <time.h>
using namespace std;

int main() {
	cout << "hello world" << endl;
	srand(time(NULL));
	GameManager gameManager;
	gameManager.Start();
	return 0;
	 
}