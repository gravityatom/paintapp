#ifndef DIAMOND_H
#define DIAMOND_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"

struct Diamond : public Shape{
private:
    float h;
    float w;
    Color color;

public:
    Diamond() {
        w = 0.2;
        h = 0.2;
    }

    Diamond(float x, float y, float w, float h, Color color) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());

        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + w/2, y - h/2);
            glVertex2f(x, y - h);
            glVertex2f(x - w/2, y - h/2);
        glEnd();

        if (selected) {
            Diamond outer(x, y - 0.02f, w - 0.04f, h - 0.04f, Color(1.0f, 1.0f, 1.0f));
            Diamond inner(x, y - 0.04f, w - 0.08f, h - 0.08f, color);
            outer.draw();
            inner.draw();
        }
    }

    bool contains(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        } else {
            return false;
        }
    }
};

#endif