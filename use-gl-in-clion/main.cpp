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

    glfwMakeContextCurrent(window);

    float vertices[] = {
        -0.5, 0.5, 0.0, // TOP LEFT
        0.5, 0.5, 0.0, // TOP RIGHT
        0.5, -0.5, 0.0, // BOTTOM RIGHT
        -0.5, -0.5, 0.0 // BOTTOM LEFT
    };


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
