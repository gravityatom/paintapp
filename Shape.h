#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"

class Shape {
protected:
    float x;
    float y;
    Color color;
    bool selected;

public:
    Color currentColor;
    Shape() {
        x = 0.0f;
        y = 0.0f;
        selected = false;
    }

    // virtual functions
    virtual void draw() = 0;
    virtual bool contains(float, float) = 0;

    // getters
    float getX() {
        return x;
    }

    float getY() {
        return y;
    }
    Color getColor() {
        return color;
    }

    bool isSelected() {
        return selected;
    }

    // setters
    void setX(float x) {
        this->x = x;
    }

    void setY(float y) {
        this->y = y;
    }

    void select() {
        selected = true;
    }

    void deselect() {
        selected = false;
    }
    void setColor(Color color) {
        this->color = color;
    }
    

    virtual ~Shape() {}
};

#endif