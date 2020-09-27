#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

static void ErrorCallback(int error, const char* description) {
  std::cout << "Error: " << description << '\n';
}

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}

static int CompileShader(unsigned type, std::string_view data) {
  unsigned id = glCreateShader(type);

  const char* src = data.data();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);

  if (!result) {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

    std::unique_ptr<char[]> message(new char[length]);
    glGetShaderInfoLog(id, length, &length, message.get());

    std::cout << "Failed to compile shader: " << message << '\n';

    glDeleteShader(id);
  }

  return id;
}

int main__() {
  glfwSetErrorCallback(ErrorCallback);

  if (!glfwInit()) return 1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  GLFWwindow* window = glfwCreateWindow(640, 480, "Window Title", nullptr, nullptr);

  if (!window) {
    std::cout << "Error: Failed to create window\n";
    glfwTerminate();
    return 1;
  }

  glfwSetKeyCallback(window, KeyCallback);
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Error: Failed to initialize OpenGL context\n";
    glfwDestroyWindow(window);
    glfwTerminate();
    return 1;
  }

  glfwSwapInterval(1);

  unsigned vertex_array;
  glGenVertexArrays(1, &vertex_array);
  glBindVertexArray(vertex_array);

  unsigned buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);

  std::array<float, 6> data{-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), data.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

  unsigned program = glCreateProgram();

  std::string vertex_shader_data =
    "#version 330 core\n"
    "\n"
    "layout(location = 0) in vec4 position;\n"
    "\n"
    "void main() {\n"
    "  gl_Position = position;\n"
    "}\n";

  std::string fragment_shader_data =
    "#version 330 core\n"
    "\n"
    "layout(location = 0) out vec4 color;\n"
    "\n"
    "void main() {\n"
    "  color = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

  unsigned vertex_shader = CompileShader(GL_VERTEX_SHADER, vertex_shader_data);
  unsigned fragment_shader = CompileShader(GL_FRAGMENT_SHADER, fragment_shader_data);

  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);
  glValidateProgram(program);

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  glUseProgram(program);

  while (!glfwWindowShouldClose(window)) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}

#include "src/import/ifc/parser.h"

int main() {
  ifc::Parser parser("test.ifc");
  return 0;
}
