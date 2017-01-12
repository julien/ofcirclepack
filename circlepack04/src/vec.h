#ifndef __VEC_H__
#define __VEC_H__

class vec {
public:
    float x;
    float y;
    ofColor c;

    vec(float x, float y, ofColor c) : x(x), y(y), c(c) {}
};

#endif // VEC_H
