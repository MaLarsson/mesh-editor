#include <GLFW/glfw3.h>
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

  GLFWwindow* window = glfwCreateWindow(640, 480, "Window Title", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    return 1;
  }

  glfwSetKeyCallback(window, KeyCallback);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
