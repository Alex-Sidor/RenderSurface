#pragma once

#include "vector"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <algorithm> 
#include <iostream>

struct MPos {
    float x, y;
};

class Input{
public:
    static std::vector<int> inputBuffer;

    Input(GLFWwindow* window);

    MPos frameMouseDelta();

    void pollInputs();
    void printVector();

    bool keyPressed(int charCode);

private:
    static MPos mouseDelta;

    static MPos lastMousePosition;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};