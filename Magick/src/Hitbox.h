#pragma once

#include "include.h"

struct Hitbox
{
	glm::vec2 pos;
	glm::vec2 size;

	Hitbox() = default;
	Hitbox(glm::vec2 pos, glm::vec2 size);
	bool collisionAABB_AABB(const Hitbox& other) const;
};