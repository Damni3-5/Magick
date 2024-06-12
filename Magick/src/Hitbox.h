#pragma once

#include "include.h"
#include "Buffer.h"
#include "Shader.h"

#include "SpriteRenderer.h"

class Hitbox
{
public:
	glm::vec2 pos;
	glm::vec2 size;

	float rotate;

	Shader shader;
	VAO vao;
public:
	Hitbox(glm::vec2 pos, glm::vec2 size, float rotate);

	void DrawHitbox2D(SpriteRenderer& BoxRenderer);

	bool collisionAABB_AABB(const Hitbox& other) const;
};