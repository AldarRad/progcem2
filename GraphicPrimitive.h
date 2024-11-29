#ifndef GRAPHIC_PRIMITIVE_H
#define GRAPHIC_PRIMITIVE_H

#include <iostream>

class GraphicPrimitive {
public:
    virtual void draw() const = 0;
    virtual ~GraphicPrimitive() = default;
};

class Rectangle : public GraphicPrimitive {
public:
    void draw() const override;
};

class Circle : public GraphicPrimitive {
public:
    void draw() const override;
};

#endif
