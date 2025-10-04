#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstdint>

class Screen {
public:
    Screen(int x, int y, const char* name);
    ~Screen();
    void updateScreen();
    void setTexture(const uint32_t* buffer);
    bool shouldClose();

private:
    int width, height;
    GLFWwindow* window = nullptr;
    unsigned int texture = 0;
    unsigned int vao = 0, vbo = 0;
    unsigned int shaderProgram = 0;
};
