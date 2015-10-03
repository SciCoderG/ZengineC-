#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


// we're using the glew static library, so we don't have to copy the dll. 
// Keep in mind, that means that we have to define GLEW_STATIC in the c++
// Preprocessor Project-properties
namespace zengine
{
	namespace graphics 
	{

		class Window
		{
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;

		public:
			Window(const char *title, int width, int height);
			~Window();

			void clear() const;
			void update() ;
			bool closed() const;

			int getWidth() const { return m_Width; }
			int getHeight() const { return m_Height; }
		private:
			bool init();
		};

	}
}