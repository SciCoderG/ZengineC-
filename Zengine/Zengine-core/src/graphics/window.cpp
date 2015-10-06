#include "window.h"	

namespace zengine
{
	namespace graphics
	{

		void window_resize(GLFWwindow *window, int width, int height); // declaring for later use

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Error initializing GLFW." << std::endl;
				return false;
			}
		

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this); // put the instance of the currently used window here
			// needed to access the currently used window in key_callback
			glfwSetWindowSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback); // sets the key callback
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback); // sets the mouse button callback
			glfwSetCursorPosCallback(m_Window, cursor_position_callback); // cursor position callback


			// do this, after the window context was created, otherwise GLEW can't be initialized!
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		bool Window::isKeyPressed(unsigned int keyCode) const
		{

			// TODO: log this
			if (keyCode >= MAX_KEYS)
				return false;
			return m_Keys[keyCode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const
		{

			// TODO: log this
			if (button >= MAX_BUTTONS)
				return false;
			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double & y) const
		{
			x = mx;
			y = my;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}


		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}


		// C-Style functions that are not part of the class itself!
		// Difference to methods: using "_" instead of camelCase

		// callback function for window resizing
		void window_resize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*) glfwGetWindowUserPointer(window);
			
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}

	}
}