#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
class VAO
{
private:
	GLuint m_ID;
public:
	VAO()
	{
		glGenVertexArrays(1, &m_ID);
	}
	void Bind()
	{
		glBindVertexArray(m_ID);
	}
	void Unbind() {
		glBindVertexArray(0);
	}
	GLuint GetID() const
	{
		return m_ID;
	}
};