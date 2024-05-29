#pragma once

#include "include.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"

#include "Buffer.h"
#include "Random.h"

#include <GLFW/glfw3.h>


enum GameState
{
	ACTIVE, MENU, WIN
};

class Game
{
public:
	GameState State;
	bool Keys[1024];

	Game(unsigned int width, unsigned int height);
	~Game();
	void init();
	void input(double dt);
	void update(double dt);
	void render();

private:
	unsigned int width, height;
};