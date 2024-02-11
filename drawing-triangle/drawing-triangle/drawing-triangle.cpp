#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main()
{
    GLFWwindow* window;
    
    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(640, 480, "OpenGL Project", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
