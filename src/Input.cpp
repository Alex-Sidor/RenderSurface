#include "Input.h"

std::vector<int> Input::inputBuffer;

MPos Input::lastMousePosition;
MPos Input::mouseDelta;

Input::Input(GLFWwindow* window){
    
    glfwSetInputMode(window, GLFW_REPEAT, GLFW_FALSE);
    
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);

    mouseDelta = {0,0};

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
}

MPos Input::frameMouseDelta(){
    return mouseDelta;
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
	}
    
    if(action == 1){
        inputBuffer.push_back(key);
    }else{
        if(action == 0){
            inputBuffer.erase(std::remove(inputBuffer.begin(), inputBuffer.end(), key), inputBuffer.end());
        }
    }
}

void Input::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    MPos current = {(float)xpos,(float)ypos};
    mouseDelta = {
        current.x - lastMousePosition.x,
        current.y - lastMousePosition.y
    };

    lastMousePosition = current;
}

void Input::pollInputs(){
    mouseDelta = {0,0};
    glfwPollEvents();
}

bool Input::keyPressed(int charCode){
    for(int i = 0; i < inputBuffer.size(); ++i){
        if(inputBuffer[i] == charCode){
            return true;
        }
    }
    return false;
}

void Input::printVector(){

    for (size_t i = 0; i < inputBuffer.size(); ++i) {
        std::cout << inputBuffer[i] << " ";
    }
    std::cout << std::endl;
}