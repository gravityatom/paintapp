#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Rectangle.h"
#include "Color.h"

class ColorPicker{
    Rectangle area;
    Rectangle ColorArea;
    Rectangle RedRec;
    Rectangle BlueRec;
    Rectangle GreenRec;
    
    Color color;


    float newredcolor;
    float newgreencolor;
    float newbluecolor;

public:
    Color currentColor;
    Color getCurrentColor(){
        return currentColor;
    }
    
    ColorPicker(){
        area       = Rectangle(-0.8f, -0.7f, 1.8f, 0.7f, Color(0.8f, 0.8f, 0.8f));
        ColorArea  = Rectangle(-0.8f, -0.7f, 0.3f, 0.5f, Color());
        RedRec     = Rectangle(-0.4f, -0.7f, 1.0f, 0.07f, Color(1.0f, 0.0f, 0.0f));
        GreenRec   = Rectangle(-0.4f, -0.8f, 1.0f, 0.07f, Color(0.0f, 1.0f, 0.0f));
        BlueRec    = Rectangle(-0.4f, -0.9f, 1.0f, 0.07f, Color(0.0f, 0.0f, 1.0f));
    };

    void setRed(){
        currentColor = Color(1.0f, 0.0f, 0.0f);
    }
    void setGreen(){
        currentColor = Color(0.0f, 1.0f, 0.0f);
    }
    void setBlue(){
        currentColor = Color(0.0f, 0.0f, 1.0f);
    }

    void handleMouseClick(float x, float y){
        if (RedRec.contains(x, y)){
            // set colorArea
            newredcolor = (x - (-0.4))/1.0;
            currentColor = Color(newredcolor, currentColor.getG(), currentColor.getB());
            ColorArea.setColor(currentColor);
        }
        else if (GreenRec.contains(x, y)){
            newgreencolor = (x - (-0.4))/1.0;
            currentColor = Color(currentColor.getR(), newgreencolor, currentColor.getB());
            ColorArea.setColor(currentColor);
            
            
            
        }
        else if (BlueRec.contains(x, y)){
            newbluecolor = (x - (-0.4))/1.0;
            currentColor = Color(currentColor.getR(), currentColor.getG(), newbluecolor);
            ColorArea.setColor(currentColor);
            
        }

        
    }

    void draw(){
        area.draw();
        ColorArea.draw();
        RedRec.draw();
        BlueRec.draw();
        GreenRec.draw();


    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }





};

#endif