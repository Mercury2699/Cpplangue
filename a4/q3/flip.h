#ifndef FLIP_H
#define FLIP_H


#include "transform.h"

struct Flip : public Transformation{
    Flip(Image *);
    void render(PPM &ppm);
    ~Flip();
};



#endif


