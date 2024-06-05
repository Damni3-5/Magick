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

	GameObject();
	GameObject(glm::vec3 color, Hitbox hitbox, Texture2D texture);
	virtual void draw(SpriteRenderer& renderer, SpriteRenderer* BoxRenderer, bool show_hitbox);
private:
	VAO vao;
};