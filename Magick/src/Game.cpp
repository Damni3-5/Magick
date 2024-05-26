#include "Game.h"

Game::Game(unsigned int width, unsigned int height)
{
	init();
}

Game::~Game()
{

}

void Game::init()
{
	ResourceManager::LoadShader("../shaders/base.vs", "../shaders/base.fs",
		"base");

	ResourceManager::LoadTexture("../textures/pudge.png", true,
		"pudge");

	ResourceManager::GetShader("base").Bind().setInt("image", 0);
	ResourceManager::GetTexture("pudge").Bind();
}

void Game::input(double dt)
{


	//if (this->Keys[GLFW_KEY_W])
	//{
	//
	//}
	//else if (this->Keys[GLFW_KEY_S])
	//{
	//
	//}
	//else if (this->Keys[GLFW_KEY_A])
	//{
	//
	//}
	//else if (this->Keys[GLFW_KEY_D])
	//{
	//
	//}
}

void Game::update(double dt)
{

}

void Game::render()
{

}