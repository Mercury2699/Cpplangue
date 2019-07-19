#ifndef TRANSFORM_H
#define TRANSFORM_H


#include "image.h"

class Transformation : public Image {
    protected:
        Image * image;
    public:
        Transformation(Image *);
        virtual void render(PPM &ppm) = 0;
        virtual ~Transformation();
};



#endif

