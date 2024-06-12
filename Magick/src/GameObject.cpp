#include "GameObject.h"
#include "include.h"

GameObject::GameObject(glm::vec3 color, Hitbox hitbox, Texture2D texture)
	: texture(texture), hitbox(hitbox), color(color)
{
    std::vector<float> vertices = {
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };
    std::vector<GLuint> indices = {
        0, 1, 2,
        2, 3, 0
    };

    Buffer EBO(GL_ELEMENT_ARRAY_BUFFER);
    Buffer VBO(GL_ARRAY_BUFFER);
    EBO.setData(indices, GL_STATIC_DRAW);
    VBO.setData(vertices, GL_STATIC_DRAW);

    this->vao.bind();
    this->vao.LinkAttrib(VBO.get_id(), 0, 2, GL_FLOAT, 2 * sizeof(float), (void*)0);
    EBO.bind();

    VBO.unbind();
    this->vao.unbind();
}

void GameObject::DrawSprite2D(SpriteRenderer& renderer)
{
    renderer.DrawSprite2D(this->texture, this->hitbox.pos, this->hitbox.size, 0, this->color);
}

void GameObject::DrawHitBox2D(SpriteRenderer& renderer)
{
    hitbox.DrawHitbox2D(renderer);
}
