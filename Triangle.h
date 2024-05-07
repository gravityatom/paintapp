#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"

struct Triangle : public Shape{
private:
    float b;
    float h;
    Color color;

public:
    Triangle() {
        b = 0.4f;
        h = 0.4f;
    }

    Triangle(float x, float y, float b, float h, Color color) {
        this->x = x;
        this->y = y;
        this->b = b;
        this->h = h;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_TRIANGLES);
            glVertex2f(x, y);
            glVertex2f(x - b/2, y - h);
            glVertex2f(x + b/2, y - h);
        glEnd();

        if (selected) {
            Triangle outer(x, y - 0.02, b - 0.02, h - 0.02, Color(1.0f, 1.0f, 1.0f));
            Triangle inner(x, y - 0.04, b - 0.004, h - 0.004, color);
            outer.draw();
            inner.draw();
        }
    }

    bool contains(float mx, float my) {
        if (mx >= x - b && mx <= x + b && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }
    }
};

#endif