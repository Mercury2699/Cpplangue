#ifndef ROTATE_H
#define ROTATE_H

#include "transform.h"

struct Rotate : public Transformation{
    Rotate(Image *);
    void render(PPM &ppm);
    ~Rotate();
};


#endif


