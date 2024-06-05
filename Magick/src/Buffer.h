#pragma once

#include "include.h"

class Buffer
{
public:
	Buffer(GLenum type) : type(type), id(0) 
	{
		glGenBuffers(1, &this->id);
	}

	~Buffer()
	{
		glDeleteBuffers(1, &this->id);
	}

	void bind() const
	{
		glBindBuffer(type, this->id);
	}

	void unbind() const
	{
		glBindBuffer(type, 0);
	}

	template<typename T>
	void setData(const std::vector<T>& data, GLenum usage)
	{
		this->bind();
		glBufferData(type, data.size() * sizeof(T), data.data(), usage);
	}

	template<typename T>
	void updateData(GLintptr offset, const std::vector<T>& data) 
	{
		this->bind();
		glBufferSubData(type, offset, data.size() * sizeof(T), data.data());
	}

	GLuint get_id() const
	{
		return id;
	}

private:
	GLenum type;
	GLuint id;
};

struct VAO
{
	unsigned int ID;

	VAO()
	{
		glGenVertexArrays(1, &this->ID);
	}
	~VAO() { Delete(); }
	void LinkAttrib(unsigned int VBO_ID, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
		glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(layout);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void bind() { glBindVertexArray(this->ID); }
	void unbind() { glBindVertexArray(0); }
	void Delete() { glDeleteVertexArrays(1, &this->ID); }
};