#pragma once

#include "Screen.h"

#include <algorithm> 

class Input{
public:
    static std::vector<int> inputBuffer;

    Input(Screen& screen);

    glm::vec2 frameMouseDelta();

    void pollInputs();
    void printVector();

    bool keyPressed(int charCode);

private:
    static glm::vec2 mouseDelta;

    static glm::vec2 lastMousePosition;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
};