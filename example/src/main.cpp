#include "Screen.h"

int main(){

    int width = 200;
    int height = 200;

    Screen mainScreen(width,height, "my new screen"); //init screen

    int numberOfPixels = width * height;
    uint32_t buffer[numberOfPixels];

    //make an image of your choice
    for(int i = 0; i < numberOfPixels; i++){
        buffer[i] = i;
    }

    mainScreen.setTexture(buffer);

    while(!mainScreen.shouldClose()){
        
        mainScreen.updateScreen();
    }
}