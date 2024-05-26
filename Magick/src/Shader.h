#pragma once

#include "include.h"

class Shader
{
public:
	GLuint id;

	Shader(const char* vertexPath, const char* fragmentPath);
	Shader() = default;
	~Shader();
	
	Shader& Bind();

	void Compile(const char* vertexPath, const char* fragmentPath);

	void setBool(const char* name, bool value, bool useShader = false) const;
	void setInt(const char* name, int value, bool useShader = false) const;
	void setFloat(const char* name, float value, bool useShader = false) const;

	void setVector2f(const char* name, float value, float value2, bool useShader = false) const;
	void setVector2f(const char* name, const glm::vec2& value, bool useShader = false) const;

	void setVector3f(const char* name, float value, float value2, float value3, bool useShader = false) const;
	void setVector3f(const char* name, const glm::vec3& value, bool useShader = false) const;

	void setVector4f(const char* name, float value, float value2, float value3, float value4, bool useShader = false) const;
	void setVector4f(const char* name, const glm::vec4& value, bool useShader = false) const;

	void setMatrix4(const char* name, const glm::mat4& matrix, bool useShader = false) const;

private:
	void compileErrors(GLuint shader, const char* type);
};