#include "rotate.h"


Rotate::Rotate(Image * i) : Transformation{i} {}

void Rotate::render(PPM &ppm){
    image->render(ppm);
    int h = ppm.getHeight();
    int w = ppm.getWidth();

    PPM newPPM = ppm;
    newPPM.getHeight() = w;
    newPPM.getWidth() = h;
    std::vector<Pixel> newPixel = newPPM.getPixels();
    for (int i = 0; i < newPPM.getHeight(); i++){
        for (int j = 0; j < newPPM.getWidth(); j++){
            newPixel[i * ppm.getHeight() + j] = ppm.getPixels()[ppm.getWidth() * (ppm.getHeight() - j - 1) + i];
        }
    }
    ppm = newPPM;
    ppm.getPixels() = newPixel;
}

Rotate::~Rotate() {delete image;}
