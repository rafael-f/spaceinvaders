#include "GameEngine.h"
#include "IMGUI/imgui.h"
#include "IMGUI/imgui_impl_glfw.h"
#include "IMGUI/imgui_impl_opengl3.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <cstdlib>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

GameEngine::GameEngine()
{
	m_Resolution.x = GetSystemMetrics(SM_CXSCREEN);
	m_Resolution.y = GetSystemMetrics(SM_CYSCREEN);
	m_Window = glfwCreateWindow(m_Resolution.x, m_Resolution.y, "Space Invaders++", nullptr, nullptr);
	
	if (!m_Window)
	{
		glfwTerminate();
		std::exit(-1);
	}

	glfwMaximizeWindow(m_Window);
	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		std::exit(-1);
	}

	m_ScreenManager = unique_ptr<ScreenManager>(new ScreenManager(Vector2i(m_Resolution.x, m_Resolution.y)));
}

void GameEngine::run()
{
	const int size = 6;
	{
		// TODO remove opengl learning
		float positions[] = {
			-0.5f, -0.5f, 0.0f, 0.0f,
			 0.5f, -0.5f, 1.0f, 0.0f,
			 0.5f,  0.5f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 1.0f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		unsigned int vao;
		GLCall(glGenVertexArrays(1, &vao));
		GLCall(glBindVertexArray(vao));

		VertexArray(va);
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

		ShaderProgram shader;
		shader.AddShader(GL_VERTEX_SHADER, "VertexShader.hlsl");
		shader.AddShader(GL_FRAGMENT_SHADER, "PixelShader.hlsl");
		shader.CreateShader();
		shader.Bind();

		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
		shader.SetUniformMat4f("u_MVP", proj);

		Texture texture("graphics/background.png");
		int textureSlot = 0;
		texture.Bind(textureSlot);
		shader.SetUniform1i("u_Texture", textureSlot);

		va.Unbind();
		shader.Unbind();
		vb.Unbind();
		ib.Unbind();

		Renderer renderer;

		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		const char* glsl_version = "#version 130";
		ImGui_ImplOpenGL3_Init(glsl_version);

		float r = 0;
		float increment = 0.05f;

		bool show_demo_window = true;

		while (!glfwWindowShouldClose(m_Window))
		{
			//	m_DT = m_Clock.restart();
			//	m_FPS = m_DT.asSeconds();
			//	handleInput();
			//	update();
			//draw(shader, location, r);

			renderer.Clear();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			shader.Bind();
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ib, shader);

			if (r > 1.0f)
			{
				increment = -0.05f;
			}
			else if (r < 0.0f)
			{
				increment = 0.05f;
			}

			r += increment;

			ImGui::ShowDemoWindow(&show_demo_window);

			ImGui::Render();
			//int display_w, display_h;
			//glfwGetFramebufferSize(window, &display_w, &display_h);
			//glViewport(0, 0, display_w, display_h);
			//glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
			//glClear(GL_COLOR_BUFFER_BIT);
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
}

void GameEngine::handleInput()
{
	//m_ScreenManager->handleInput(m_Window);
}

void GameEngine::update()
{
	//m_ScreenManager->update(m_FPS);
}

void GameEngine::draw(const unsigned int& shader, const unsigned int& location, const float& r)
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shader);
	GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));

	//GLCall(glBindVertexArray(vao));
	//va.Bind();
	//ib.Bind();

	/* Swap front and back buffers */
	glfwSwapBuffers(m_Window);

	/* Poll for and process events */
	glfwPollEvents();

	//m_Window.clear(Color::Black);
	//m_ScreenManager->draw(m_Window);
	//m_Window.display();
}
