#include "PipeManager.h"
#include"../Engine/Engine.h";
#include "Flapper.h"
#include "../Engine/Physics/RigidBody.h"

PipeManager::PipeManager() :
	xStartSeparation(800),
	yStartSeparation(500),
	xSeparation(xStartSeparation),
	ySeparation(yStartSeparation),
	minXSeparation(200),
	minYSeparation(200),
	xSeparationSpeed(10),
	ySeparationSpeed(10),
	minSpawnY(284),
	maxSpawnY(Engine::SCREEN_HEIGHT-284),
	totalPipes(0),
	points(0)
{
	Pipe::Initialise();
	CreatePipe();
}



PipeManager::~PipeManager() {

	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}

}

void PipeManager::Update() {
	vector<int> pipesToDelete;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->Update();
		if (pipes[i]->GetX() < -pipes[i]->GetWidth() /2) {
			pipesToDelete.push_back(i);
		}
		if (i == pipes.size() - 1) {
			if (pipes[i]->GetX() < Engine::SCREEN_WIDTH - xSeparation) {
				CreatePipe();
			}
		}

		if (pipes[i]->GetX() < Engine::SCREEN_WIDTH / 2 && pipes[i]->getPrevPos() > Engine::SCREEN_WIDTH / 2) {
			points++;
		}
	}

	for (unsigned int i = 0; i < pipesToDelete.size(); i++) {
		delete pipes[pipesToDelete[i]];
		pipes.erase(pipes.begin() + pipesToDelete[i]);

	}
}

void PipeManager::Render() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		pipes[i]->Render();
	}
}

bool PipeManager::CheckCollision(Flapper& flapper) {
	bool isColliding = false;
	for (unsigned int i = 0; i < pipes.size(); i++) {
		isColliding =	RigidBody::IsColliding(flapper.GetRB(), pipes[i]->GetTopRB()) ||
						RigidBody::IsColliding(flapper.GetRB(), pipes[i]->GetBottomRB());
		if (isColliding) break;
	}
	return isColliding;
}

void PipeManager::Reset() {
	for (unsigned int i = 0; i < pipes.size(); i++) {
		delete pipes[i];
	}
	pipes.clear();

	xSeparation = xStartSeparation;
	ySeparation = yStartSeparation;
	totalPipes = 0;
	points = 0;
	CreatePipe();
}

void PipeManager::CreatePipe() {
	float spawnY = (rand() % (maxSpawnY - minSpawnY)) + minSpawnY;
	Pipe* pipe = new Pipe(Vector3(Engine::SCREEN_WIDTH + 100, spawnY, 0));
	pipe->SetGap(ySeparation);
	pipes.push_back(pipe);
	totalPipes++;

	if (totalPipes % 5 == 0) {
		if (xSeparation > minXSeparation + xSeparationSpeed) {
			xSeparation -= xSeparationSpeed;
		}
		if (ySeparation > minYSeparation + ySeparationSpeed) {
			ySeparation -= ySeparationSpeed;
		}

	}
}

int PipeManager::getPoints() {
	return points;
}