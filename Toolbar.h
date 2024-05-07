#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h"

enum Tool {PENCIL, ERASER, MOUSE, CLEAR, SQUARE, CIRCLE, TRIANGLE, DIAMOND, SWAPORDER};

struct Toolbar {
private:
    Rectangle area;
    Texture pencilButton;
    Texture eraserButton;
    Texture mouseButton;
    Texture clearButton;
    Texture squareButton;
    Texture circleButton;
    Texture triangleButton;
    Texture diamondButton;
    Texture swapOrderButton;

    Tool selectedTool;


    void deselectAll(){
        pencilButton.deselect();
        eraserButton.deselect();
        mouseButton.deselect();
        clearButton.deselect();
        squareButton.deselect();
        circleButton.deselect();
        triangleButton.deselect();
        diamondButton.deselect();
        swapOrderButton.deselect();
    }

public:
    Toolbar(){
        area            = Rectangle(-1.0f, 1.0f, 0.2f, 2.0f, Color(0.8f, 0.8f, 0.8f));
        pencilButton    = Texture("assets/pencil.png", -1.0f, 1.0f, 0.2f, 0.2f);
        eraserButton    = Texture("assets/eraser.png", -1.0f, 0.8f, 0.2f, 0.2f);
        mouseButton     = Texture("assets/mouse.png", -1.0f, 0.6f, 0.2f, 0.2f);
        clearButton     = Texture("assets/clear.png", -1.0f, 0.4f, 0.2, 0.2f);
        squareButton    = Texture("assets/square.png", -1.0f, 0.2f, 0.2f, 0.2f);
        circleButton    = Texture("assets/circle.png", -1.0, 0.0f, 0.2f, 0.2f);
        triangleButton  = Texture("assets/triangle.png", -1.0f, -0.2f, 0.2f, 0.2f);
        diamondButton   = Texture("assets/diamond.png", -1.0f, -0.4f, 0.2f, 0.2f);
        swapOrderButton = Texture("assets/swap_order.png", -1.0f, -0.6f, 0.2f, 0.2f);
        

        selectPencil();
    }

    Tool getSelectedTool(){
        return selectedTool;
    }

    void selectPencil() {
        deselectAll();
        pencilButton.select();
        selectedTool = PENCIL;
    }
    void selectEraser() {
        deselectAll();
        eraserButton.select();
        selectedTool = ERASER;
    }
    void selectMouse() {
        deselectAll();
        mouseButton.select();
        selectedTool = MOUSE;
    }
    void selectClear() {
        deselectAll();
        clearButton.select();
        selectedTool = CLEAR;
    }
    void selectSquare() {
        deselectAll();
        squareButton.select();
        selectedTool = SQUARE;
    }   
    void selectCircle() {
        deselectAll();
        circleButton.select();
        selectedTool = CIRCLE;
    }
    void selectTriangle() {
        deselectAll();
        triangleButton.select();
        selectedTool = TRIANGLE;
    }
    void selectDiamond() {
        deselectAll();
        diamondButton.select();
        selectedTool = DIAMOND;
    }
    void selectSwapOrder() {
        deselectAll();
        swapOrderButton.select();
        selectedTool = SWAPORDER;
    }

    void handleMouseClick(float x, float y){
        if (pencilButton.contains(x, y)){
            selectPencil();
        } else if (eraserButton.contains(x, y)){
            selectEraser();
        } else if (mouseButton.contains(x, y)){
            selectMouse();
        } else if (clearButton.contains(x, y)){
            selectClear();
        } else if (squareButton.contains(x, y)){
            selectSquare();
        } else if (circleButton.contains(x, y)){
            selectCircle();
        } else if (triangleButton.contains(x, y)){
            selectTriangle();
        } else if (diamondButton.contains(x, y)){
            selectDiamond();
        } else if (swapOrderButton.contains(x, y)){
            selectSwapOrder();
        }
    }

    void draw(){
        area.draw();
        pencilButton.draw();
        eraserButton.draw();
        mouseButton.draw();
        clearButton.draw();
        squareButton.draw();
        circleButton.draw();
        triangleButton.draw();
        diamondButton.draw();
        swapOrderButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif