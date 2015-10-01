#include "src/graphics/window.h"

int main()
{
	using namespace zengine;
	using namespace graphics;

	Window window("Zengine", 960, 540);
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}

	return 0;
}
