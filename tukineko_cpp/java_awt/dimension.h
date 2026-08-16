#ifndef DIMENSION_H
#define DIMENSION_H

class Dimension
{
public:
    int width;
    int height;
    
    Dimension() : width(0), height(0) {}
    Dimension(int w, int h) : width(w), height(h) {}
};

#endif // DIMENSION_H
