#include "mydrawing.h"

// Constructor
MyDrawing::MyDrawing() {
  dragging = false;
  x0 = x1 = x2 = y0 = y1 = y2 = 0;
  this->im = im;
  newLine = false;
  newTriangle = false;
  triggered = false;
  inTri = false;
  std::cout << "Instructions:" << std::endl;
  std::cout << "l = line" << std::endl;
  std::cout << "t = triangle" << std::endl;
  std::cout << "c = clear" << std::endl;
  std::cout << "Click to start line and release to draw it" << std::endl;
  std::cout << "To set the last point of the triangle press p" << std::endl;
}

void MyDrawing::paint(GraphicsContext* gc) { im.draw(gc); }

void MyDrawing::mouseButtonDown(GraphicsContext* gc, unsigned int button, int x,
                                int y) {
  if (newLine == true || newTriangle == true) {
    x0 = x1 = x;
    y0 = y1 = y;
    gc->setMode(GraphicsContext::MODE_XOR);
    gc->drawLine(x0, y0, x1, y1);
    dragging = true;
  }
}

void MyDrawing::mouseButtonUp(GraphicsContext* gc, unsigned int button, int x,
                              int y) {
  if (newLine == true && dragging == true) {
    gc->drawLine(x0, y0, x1, y1);
    x1 = x;
    y1 = y;
    line l(x0, y0, x1, y1, GraphicsContext::BLUE);
    im.add(&l);
    gc->setMode(GraphicsContext::MODE_NORMAL);
    im.draw(gc);
    dragging = false;
    newLine = false;
  } else if (newTriangle == true && dragging == true) {
    gc->drawLine(x0, y0, x1, y1);
    x1 = x2 = x;
    y1 = y2 = y;
    triggered = true;
  }
}

void MyDrawing::mouseMove(GraphicsContext* gc, int x, int y) {
  if (dragging == true && newLine == true) {
    gc->drawLine(x0, y0, x1, y1);
    x1 = x;
    y1 = y;
    gc->drawLine(x0, y0, x1, y1);
  } else if (dragging == true && newTriangle == true && triggered == false) {
    gc->drawLine(x0, y0, x1, y1);
    x1 = x;
    y1 = y;
    gc->drawLine(x0, y0, x1, y1);
  } else if (triggered == true) {
    if (inTri == false) {
      gc->drawLine(x0, y0, x2, y2);
      gc->drawLine(x1, y1, x2, y2);
      x2 = x;
      y2 = y;
      gc->drawLine(x0, y0, x2, y2);
      gc->drawLine(x1, y1, x2, y2);
    } else if (inTri == true) {
      triangle t(x0, y0, x1, y1, x2, y2, GraphicsContext::BLUE);
      im.add(&t);
      dragging = false;
      newTriangle = false;
    }
  }
}

void MyDrawing::keyDown(GraphicsContext* gc, unsigned int keycode) {
  switch (keycode) {
    case 0x06C:  // Press l to select line drawing
      newLine = true;
      newTriangle = false;
      break;
    case 0x0074:  // Press t to select triangle drawing
      inTri = false;
      newLine = false;
      newTriangle = true;
      break;
    case 0x0063:  // Clears the canvas with c
      this->clear(gc);
      break;
    case 0x0070:
      inTri = true;
      break;
  }
}
void MyDrawing::keyUp(GraphicsContext* gc, unsigned int keycode) {}

void MyDrawing::clear(GraphicsContext* gc) {
  gc->clear();
  im.erase();
}