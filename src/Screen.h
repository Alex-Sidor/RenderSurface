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
    void updateScreen();
    void setTexture(const pixel* buffer);
    bool shouldClose();

    Input* inputHandler = nullptr;

    GLFWwindow* window = nullptr;

private:
    int width, height;
    unsigned int texture = 0;
    unsigned int vao = 0, vbo = 0;
    unsigned int shaderProgram = 0;

};
