#ifndef _position_h
#define _position_h

struct Position
{
    float x, y, z;
    Position() {
        x = y = z = 0.0f;
    }
};

struct Size
{
    float w, h;
    Size() {
        w = h = 0.0f;
    }
};


#endif 