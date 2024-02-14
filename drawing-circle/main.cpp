#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides);

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

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        drawCircle(300, 300, 0, 100, 100);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides) {
    GLint numberOfVertices = numberOfSides + 2;

    GLfloat doublePi = 2.0f * M_PI;

    std::vector<GLfloat> circleVerticesX(numberOfVertices);
    std::vector<GLfloat> circleVerticesY(numberOfVertices);
    std::vector<GLfloat> circleVerticesZ(numberOfVertices);

    circleVerticesX[0] = x;
    circleVerticesY[0] = y;
    circleVerticesZ[0] = z;

    for(int i = 1;i<numberOfVertices;i++) {
        circleVerticesX[i] = x + radius * cos(i * doublePi / numberOfSides);
        circleVerticesY[i] = y + radius * sin(i * doublePi / numberOfSides);
        circleVerticesZ[i] = z;
    }

    std::vector<GLfloat> allCircleVertices(numberOfVertices * 3);

    for(int i = 0; i < numberOfVertices; i++) {
        allCircleVertices[i * 3] = circleVerticesX[i];
        allCircleVertices[i * 3 + 1] = circleVerticesY[i];
        allCircleVertices[i * 3 + 2] = circleVerticesZ[i];
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, allCircleVertices.data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
    glDisableClientState(GL_VERTEX_ARRAY);
}