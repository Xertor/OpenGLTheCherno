#pragma once

#include <GL/eglew.h>

#define ASSERT(x) if (!(x)) __debugbreak(); //MSVC intrinsic
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);