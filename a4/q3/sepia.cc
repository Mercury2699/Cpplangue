#include "sepia.h"


Sepia::Sepia(Image * i) : Transformation{i} {}

void Sepia::render(PPM &ppm) {
    image->render(ppm);
    for (int i = 0; i < ppm.getHeight() * ppm.getWidth(); i++) {
        Pixel p = ppm.getPixels()[i];
        Pixel np = Pixel{};
        np.r = p.r *.393 + p.g * .769 + p.b * .189;
        np.g = p.r *.349 + p.g * .686 + p.b * .168;
        np.b = p.r *.272 + p.g * .534 + p.b * .131;
        np.r = np.r > 255 ? 255 : np.r;
        np.g = np.g > 255 ? 255 : np.g;
        np.b = np.b > 255 ? 255 : np.b;
        ppm.getPixels()[i] = np;
    }
}

Sepia::~Sepia() {delete image;}




