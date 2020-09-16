#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>

static void ErrorCallback(int error, const char* description) {
  std::cout << "Error: " << description << '\n';
}

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}

int main() {
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


  while (!glfwWindowShouldClose(window)) {

    // main loop ...

    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
