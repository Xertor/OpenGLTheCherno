#include "Renderer.h"

#include <iostream>

void GLClearError()
{
	while (glGetError());
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")" << function << " " << file << ": " << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::Clear() const
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	// the shader program
	// shader tells what to do with the data
	shader.Bind();

	// the data
	// contains all vertex data 
	// like positions of each point to render, 
	// texture coords, vertex colors, normals, binormals, tangents, etc.
	va.Bind();

	// contains indices into the vb to know 
	// which vertices to render and how to assemble them
	ib.Bind();

	// using that ib, access the vb and call the 
	// shader program on all the vertices individually, to draw and rasterize the object
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
