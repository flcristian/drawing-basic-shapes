#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;

int main()
{
    GLFWwindow* window;
    
    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Project", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat pointVertex[] = {
        SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2
    };

    GLfloat pointVertex2[] = {
        SCREEN_WIDTH * 0.75, SCREEN_HEIGHT / 2
    };

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_POINT_SMOOTH);
        glPointSize(100);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, pointVertex);
        glDrawArrays(GL_POINTS, 0, 1);
        glDisableClientState(GL_VERTEX_ARRAY);

        glPointSize(50);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, pointVertex2);
        glDrawArrays(GL_POINTS, 0, 1);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisable(GL_POINT_SMOOTH);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
