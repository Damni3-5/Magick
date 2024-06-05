#include "GameObject.h"
#include "include.h"

GameObject::GameObject()
	: hitbox({ glm::vec2(0), glm::vec2(0) }), color(0)
{

}

GameObject::GameObject(glm::vec3 color, Hitbox hitbox, Texture2D texture)
	: texture(texture), hitbox(hitbox), color(color)
{
    std::vector<float> vertices = {
        0.5f,  0.5f,	
        0.5f, -0.5f,	
       -0.5f, -0.5f,	
       -0.5f,  0.5f	
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

void GameObject::draw(SpriteRenderer& renderer, SpriteRenderer* BoxRenderer = nullptr, bool show_hitbox = false)
{
    renderer.DrawSprite2D(this->texture, this->hitbox.pos, this->hitbox.size, 0, this->color);

	if (show_hitbox && BoxRenderer)
	{
        //renderer.shader.Bind();
        glm::vec2 pos = this->hitbox.pos;
        glm::vec2 size = this->hitbox.size;

        this->vao.bind();
        BoxRenderer->shader.Bind();
        glm::mat4 model = glm::mat4(1.0);
        model = glm::translate(model, glm::vec3(pos, 0.0));
        
        model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
        //model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
        
        model = glm::scale(model, glm::vec3(size, 1.0));
        
        BoxRenderer->shader.setMatrix4("model", model);
        BoxRenderer->shader.setVector3f("spriteColor", glm::vec3(color.r, color.g, color.b));
        
        glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, 0);
	}
    
}
