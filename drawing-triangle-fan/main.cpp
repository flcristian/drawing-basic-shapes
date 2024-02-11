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

    GLfloat triangles[] = {
        320, 240,
        370, 290,
        420, 240,
        370, 190
    };

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, triangles);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
