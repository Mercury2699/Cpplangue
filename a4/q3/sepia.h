#ifndef SEPIA_H
#define SEPIA_H


#include "transform.h"

struct Sepia : public Transformation{
    Sepia(Image *);
    void render(PPM &ppm);
    ~Sepia();
};


#endif

