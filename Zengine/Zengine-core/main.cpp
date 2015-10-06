#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main()
{
	using namespace zengine;
	using namespace graphics;
	using namespace maths;

	Window window("Zengine", 960, 540);
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec3 a(1.0f, 2.0f, 2.0f);
	vec3 b(12.0f, 2.0f, 2.0f);

	vec3 c = a + b;
	std::cout << a << std::endl;

	while (!window.closed())
	{
		window.clear();
		
		
		
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif

		
		window.update();
	}
	return 0;
}
