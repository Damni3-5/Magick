#include "Game.h"

SpriteRenderer* Renderer;
SpriteRenderer* RenderBox;
GameObject* Player;

Game::Game(unsigned int width, unsigned int height)
	: State(ACTIVE), Keys(), width(width), height(height)
{
	
}

Game::~Game()
{
	delete Renderer;
}

void Game::init()
{
	ResourceManager::LoadShader("../shaders/base.vs", "../shaders/base.fs",
		"base");
	ResourceManager::LoadShader("../shaders/hitbox.vs", "../shaders/hitbox.fs",
		"hitbox");
	
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width),
		static_cast<float>(this->height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("base").Bind().setInt("image", 0);
	ResourceManager::GetShader("base").setMatrix4("projection", projection);
	ResourceManager::GetShader("hitbox").Bind().setInt("image", 0);
	ResourceManager::GetShader("hitbox").setMatrix4("projection", projection);

	ResourceManager::LoadTexture("../textures/pudge.png", true,
		"pudge");
	ResourceManager::LoadTexture("../textures/hand1.png", true,
		"hand");

	Renderer = new SpriteRenderer(ResourceManager::GetShader("base"));
	RenderBox = new SpriteRenderer(ResourceManager::GetShader("hitbox"));
	Hitbox box(glm::vec2(this->width / 2, this->height / 2), glm::vec2(50), 0);
	Player = new GameObject(glm::vec3(1), box, ResourceManager::GetTexture("hand"));
	
	for (size_t i = 0; i < 1; i++)
	{
		mobs.push_back(new GameObject(glm::vec3(1), Hitbox(glm::vec2(Random::getFloat(0, this->width), Random::getFloat(0, this->height)), glm::vec2(50), 0), ResourceManager::GetTexture("pudge")));
	}
}

void Game::input(double dt)
{
	static glm::vec2 pos = { Random::getFloat(0, this->width), Random::getFloat(0, this->height) };

	if (this->Keys[GLFW_KEY_W])
	{
		pos.y -= 5.0;
	}
	if (this->Keys[GLFW_KEY_S])
	{
		pos.y += 5.0;
	}
	if (this->Keys[GLFW_KEY_A])
	{
		pos.x -= 5.0;
	}
	if (this->Keys[GLFW_KEY_D])
	{
		pos.x += 5.0;
		
	}
	//Renderer->DrawSprite2D(ResourceManager::GetTexture("pudge"), pos, glm::vec2(this->width / 2, this->height / 2), 0, glm::vec3(1.0));
	Player->hitbox.pos = { pos };
}

void Game::update(double dt)
{
	DoCollisions();
}

bool CheckCollision(GameObject& one, GameObject& two);

void Game::render()
{
	//Renderer->DrawSprite2D(ResourceManager::GetTexture("hand"), glm::vec2(this->width / 2, this->height / 2), glm::vec2(400.0, 200), 0, glm::vec3(1.0));
	
	for (auto& obj1 : mobs)
	{
		obj1->DrawSprite2D(*Renderer);
		obj1->DrawHitBox2D(*RenderBox);
	}
	std::cout << ".";
	//Player->DrawSprite2D(*Renderer);
	Player->DrawHitBox2D(*RenderBox);
}

void Game::DoCollisions()
{
	for (auto& obj : mobs)
	{
		if (CheckCollision(*obj, *Player)) 
		{
			std::cout << "COL" << std::endl;
		}
	}
}

bool CheckCollision(GameObject& one, GameObject& two)
{
	return one.hitbox.collisionAABB_AABB(two.hitbox);
}