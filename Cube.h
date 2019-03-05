#pragma once
#include<glm/gtx/transform.hpp>
#include "Shader.h"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.h"
class Cube
{
	VAO vao;
	VertexBuffer vbo;
	IndexBuffer ibuff;
	int count = 0;
	Shader shader;
	glm::vec3 pos = glm::vec3(0, 0, 0);
	glm::mat4 model = glm::mat4(1.0f);
public:
	Cube(glm::vec3 p_Pos)
	{
		Vertex vertA;
		Vertex vertB;
		Vertex vertC;
		Vertex vertD;
		Vertex vertE;
		Vertex vertF;
		Vertex vertG;
		Vertex vertH;
		unsigned int indices[] = { 0,1,2,3,0,2,1,3,1,5,0,4,5,4,4,6,5,7,6,7,2,6,3,7 };
		count = sizeof(indices) / sizeof(unsigned int);
		//(0,0,0)
		vertA.x = 0.0f;
		vertA.r = 1.0f;
		vertA.a = 1.0f;
		
		//(1,0,0)
		vertB.x = 1.0f;
		vertB.r = 1.0f;
		vertB.a = 1.0f;
		
		//(0,1,0)
		vertC.y = 1.0f;
		vertC.r = 1.0f;
		vertC.a = 1.0f;

		//(1,1,0)
		vertD.x = 1.0f;
		vertD.y = 1.0f;
		vertD.z = 0.0f;
		vertD.r = 1.0f;
		vertD.a = 1.0f;

		//(0,0,1)
		vertE.x = 0.0f;
		vertE.y = 0.0f;
		vertE.z = 1.0f;
		vertE.r = 1.0f;
		vertE.a = 1.0f;
	
		//(1,0,1)
		vertF.x = 1.0f;
		vertF.z = 1.0f;
		vertF.r = 1.0f;
		vertF.a = 1.0f;

		//(0,1,1)
		vertG.y = 1.0f;
		vertG.z = 1.0f;
		vertG.r = 1.0f;
		vertG.a = 1.0f;

		//(1,1,1)
		vertH.x = 1.0f;
		vertH.y = 1.0f;
		vertH.z = 1.0f;
		vertH.r = 1.0f;
		vertH.a = 1.0f;

		Vertex  GuideVertex[] = { vertA,vertB,vertC,vertD,vertE,vertF,vertG,vertH };
		pos = p_Pos;
		vbo = VertexBuffer(GuideVertex, sizeof(GuideVertex));
		ibuff = IndexBuffer(sizeof(indices), indices);
		model = glm::translate(model, pos);
	}
	void SetShader(Shader p_Shader)
	{
		shader = p_Shader;
		shader.setBool("isTextured", false);
	}
	void Bind()
	{
		shader.Bind();
		vao.Bind();
		vbo.Bind();
		ibuff.Bind();
		glEnableVertexArrayAttrib(vao.GetID(), 0);
		glEnableVertexArrayAttrib(vao.GetID(), 1);
	}
	void Unbind()
	{
		glDisableVertexArrayAttrib(vao.GetID(), 0);
		glDisableVertexArrayAttrib(vao.GetID(), 1);
		ibuff.Bind();
		vbo.Unbind();
		vao.Unbind();

	}
	void Draw()
	{
		Bind();
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(float) * 3));
		shader.setMat4("model", model);
		glDrawElements(GL_LINES, count, GL_UNSIGNED_INT, (void*)0);
		Unbind();
	}
};