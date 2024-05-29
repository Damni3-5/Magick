#include "Game.h"

SpriteRenderer* Renderer;

Game::Game(unsigned int width, unsigned int height)
	: State(ACTIVE), Keys(), width(width), height(height)
{ }

Game::~Game()
{
	delete Renderer;
}

void Game::init()
{
	ResourceManager::LoadShader("../shaders/base.vs", "../shaders/base.fs",
		"base");

	ResourceManager::LoadTexture("../textures/pudge.png", true,
		"pudge");
	ResourceManager::LoadTexture("../textures/J.jpg", false,
		"J");

	ResourceManager::GetShader("base").Bind().setInt("image", 0);

	Renderer = new SpriteRenderer(ResourceManager::GetShader("base"));

}

void Game::input(double dt)
{


	if (this->Keys[GLFW_KEY_W])
	{
	
	}
	else if (this->Keys[GLFW_KEY_S])
	{
	
	}
	else if (this->Keys[GLFW_KEY_A])
	{
	
	}
	else if (this->Keys[GLFW_KEY_D])
	{
	
	}
}

void Game::update(double dt)
{

}

void Game::render()
{
	Renderer->DrawSprite2D(ResourceManager::GetTexture("pudge"), glm::vec2(1.0), glm::vec2(1.0), 0, glm::vec3(1.0));
	Renderer->DrawSprite2D(ResourceManager::GetTexture("J"), glm::vec2(1.0), glm::vec2(1.0), 0, glm::vec3(1.0));
}