#pragma once

#include "include.h"

#include "Texture2D.h"
#include "Hitbox.h"

#include "SpriteRenderer.h"

class GameObject
{
public:
	Texture2D texture;
	Hitbox hitbox;

	glm::vec3 color;

	GameObject(glm::vec3 color, Hitbox hitbox, Texture2D texture);
	virtual void DrawSprite2D(SpriteRenderer& renderer);
	virtual void DrawHitBox2D(SpriteRenderer& renderer);
private:
	VAO vao;
};