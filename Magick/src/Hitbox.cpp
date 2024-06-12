#include "Hitbox.h"

Hitbox::Hitbox(glm::vec2 pos, glm::vec2 size, float rotate)
    : pos(pos), size(size), rotate(rotate)
{
    this->shader = shader;

    std::vector<float> vertices = {
        1.0f, 1.0f,
        1.0f, -1.0f,
        -1.0f, -1.0f,
        -1.0f,  1.0f
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

void Hitbox::DrawHitbox2D(SpriteRenderer& BoxRenderer)
{
    this->vao.bind();
    BoxRenderer.shader.Bind();
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, glm::vec3(pos, 0.0));

    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    //model = glm::rotate(model, glm::radians(this->rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

    model = glm::scale(model, glm::vec3(size, 1.0));

    BoxRenderer.shader.setMatrix4("model", model);

    glDrawElements(GL_POINTS, 6, GL_UNSIGNED_INT, 0);
    this->vao.unbind();
}

bool Hitbox::collisionAABB_AABB(const Hitbox& other) const
{
	return pos.x < other.pos.x + other.size.x &&
        pos.x + size.x > other.pos.x &&
        pos.y < other.pos.y + other.size.y &&
        pos.y + size.y > other.pos.y;
}
