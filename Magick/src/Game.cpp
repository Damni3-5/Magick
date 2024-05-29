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
	ResourceManager::LoadTexture("../textures/owl.png", true,
		"owl");

	Renderer = new SpriteRenderer(ResourceManager::GetShader("base"));
}

void Game::input(double dt)
{
	static glm::vec2 pos = {0,0};

	if (this->Keys[GLFW_KEY_W])
	{
		pos.y += 0.01;
	}
	if (this->Keys[GLFW_KEY_S])
	{
		pos.y -= 0.01;
	}
	if (this->Keys[GLFW_KEY_A])
	{
		pos.x -= 0.01;
	}
	if (this->Keys[GLFW_KEY_D])
	{
		pos.x += 0.01;
		
	}
	Renderer->DrawSprite2D(ResourceManager::GetTexture("pudge"), pos, glm::vec2(0.5), 0, glm::vec3(1.0));

}

void Game::update(double dt)
{

}

void Game::render()
{
	Renderer->DrawSprite2D(ResourceManager::GetTexture("owl"), glm::vec2(1.0), glm::vec2(1.0), 0, glm::vec3(1.0));

}