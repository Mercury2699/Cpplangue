#include "flip.h"

Flip::Flip(Image * img) : Transformation{img} {}

void Flip::render(PPM &ppm){
    image->render(ppm);
    int h = ppm.getHeight();
    int w = ppm.getWidth();
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w / 2; j++){
            Pixel temp = ppm.getPixels()[i * w + j]; 
            ppm.getPixels()[i * w + j] = ppm.getPixels()[i * w + (w - j - 1)];
            ppm.getPixels()[i * w + (w - j - 1)] = temp;
        }
    }
}

Flip::~Flip() {delete image;}

