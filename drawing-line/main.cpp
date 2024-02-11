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

    GLfloat lineVertices[] = {
        SCREEN_WIDTH * 0.33, SCREEN_HEIGHT / 2,
        SCREEN_WIDTH * 0.66, SCREEN_HEIGHT / 2 + 100
    };

    GLfloat lineVertices2[] = {
        SCREEN_WIDTH * 0.66, SCREEN_HEIGHT / 2 + 200,
        SCREEN_WIDTH * 0.33, SCREEN_HEIGHT / 2 - 200
    };

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glLineWidth(5);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, lineVertices);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0x00FF);
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, lineVertices2);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisable(GL_LINE_STIPPLE);
        glDisable(GL_LINE_SMOOTH);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
