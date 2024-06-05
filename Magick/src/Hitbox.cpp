#include "Hitbox.h"

Hitbox::Hitbox(glm::vec2 pos, glm::vec2 size) 
	: pos(pos), size(size)
{ }

bool Hitbox::collisionAABB_AABB(const Hitbox& other) const
{
	//return pos.x < other.pos.x + other.size.x &&
    //    pos.x + size.x > other.pos.x &&
    //    pos.y < other.pos.y + other.size.y &&
    //    pos.y + size.y > other.pos.y;

    bool collisionX = this->pos.x + this->size.x >= other.pos.x &&
        other.pos.x + other.size.x >= this->pos.x;
    
    bool collisionY = this->pos.y + this->size.y >= other.pos.y &&
        other.pos.y + other.size.y >= this->pos.y;

    return collisionX && collisionY;
}
