#include "Input.h"

std::vector<int> Input::inputBuffer;

glm::vec2 Input::lastMousePosition;
glm::vec2 Input::mouseDelta;

Input::Input(Screen& screen){
    
    glfwSetInputMode(screen.window, GLFW_REPEAT, GLFW_FALSE);
    
    glfwSetKeyCallback(screen.window, key_callback);
    glfwSetCursorPosCallback(screen.window, cursor_position_callback);

    lastMousePosition = screen.screenSize()/2.0f;
    mouseDelta = glm::vec2(0,0);

    glfwSetInputMode(screen.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  
}

glm::vec2 Input::frameMouseDelta(){
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
    glm::vec2 current = glm::vec2(xpos,ypos);
    mouseDelta = (current - lastMousePosition);
    lastMousePosition = current;
}

void Input::pollInputs(){
    mouseDelta = glm::vec2(0.0f,0.0f);
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