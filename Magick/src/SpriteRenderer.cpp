#include "SpriteRenderer.h"

#include "ResourceManager.h"

SpriteRenderer::SpriteRenderer(const Shader& shader)
{
	this->shader = shader;

	std::vector<float> vertices = {
		1.0f,  1.0f,   1.0f, 0.0f,
		1.0f, -1.0f,   1.0f, 1.0f,
		-1.0f, -1.0f,  0.0f, 1.0f,
		-1.0f,  1.0f,  0.0f, 0.0f
	};
	std::vector<GLuint> indices = {
		0, 1, 3,
		1, 2, 3
	};

	Buffer EBO(GL_ELEMENT_ARRAY_BUFFER);
	Buffer VBO(GL_ARRAY_BUFFER);
	EBO.setData(indices, GL_STATIC_DRAW);
	VBO.setData(vertices, GL_STATIC_DRAW);

	this->vao.bind();
	this->vao.LinkAttrib(VBO.get_id(), 0, 2, GL_FLOAT, 4 * sizeof(float), (void*)0);
	this->vao.LinkAttrib(VBO.get_id(), 1, 2, GL_FLOAT, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	EBO.bind();

	VBO.unbind();
	this->vao.unbind();
}

SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &this->vao.ID);
}

void SpriteRenderer::DrawSprite2D(const Texture2D& texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
{
	this->vao.bind();
	this->shader.Bind();

	glm::mat4 model = glm::mat4(1.0);
	model = glm::translate(model, glm::vec3(position, 0.0));

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	model = glm::scale(model, glm::vec3(size, 1.0));
	
	this->shader.setMatrix4("model", model);
	this->shader.setVector3f("spriteColor", glm::vec3(color.r, color.g, color.b));
	
	texture.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	this->vao.unbind();
}