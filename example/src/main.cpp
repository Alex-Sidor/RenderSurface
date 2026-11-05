#include "Screen.h"

int main(){

    const int width = 300;
    const int height = 300;

    Screen mainScreen(width,height, "my new screen"); //init screen

    const int nPixels = width * height;
    pixel buffer[nPixels];

    const int rad = 100;
    const int radSqr = rad * rad;

    int index = 0;

    //make an image of your choice
    for(int x = 0; x < width; x++){
        for (int y = 0; y < height; y++) {
            
            // check if its within the circle
            
            int dx = x - (width / 2);
            int dy = y - (height / 2);

            int dist = (dx * dx) + (dy * dy);

            if (dist < radSqr) {
                buffer[index] = { 255,0,0 };
            }
            else {
                buffer[index] = {0, 0, 255};
            }

            index += 1;
        }
    }

    mainScreen.setTexture(buffer);

    while(!mainScreen.shouldClose()){
        
        mainScreen.updateScreen();
    }
}