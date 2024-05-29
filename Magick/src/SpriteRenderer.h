#pragma once

#include "Shader.h"
#include "Texture2D.h"
#include "Buffer.h"

class SpriteRenderer
{
public:
	SpriteRenderer(const Shader& shader);
	~SpriteRenderer();

	void DrawSprite2D(const Texture2D& texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color);
private:
	Shader shader;
	VAO vao;
};