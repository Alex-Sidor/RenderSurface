#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Input.h>

#include <cstdint>

struct pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Screen {
public:
    Screen(int x, int y, const char* name);
    ~Screen();
    const void updateScreen();
    const void setTexture(const pixel* buffer);
    const bool shouldClose();

    GLFWwindow* window = nullptr;

    Input* inputHandler = nullptr;
private:
    int width, height;
    unsigned int texture = 0;
    unsigned int vao = 0, vbo = 0;
    unsigned int shaderProgram = 0;
};
