/* This is an abstract base class representing a generic graphics
 * context.  Most implementation specifics will need to be provided by
 * a concrete implementation.  See header file for specifics. */

#define _USE_MATH_DEFINES  // for M_PI
#include "gcontext.h"

#include <cmath>  // for trig functions
#include <iostream>

/*
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext() {
  // nothing to do
  // here to insure subclasses handle destruction properly
}

/* This is a private method that checks to see if the slope is
 * positive or negative and changes the values of x and y based on that
 * and sets the increment to move in the proper direction
 */
void GraphicsContext::swapVal(int& dx, int& incx, int& dy, int& incy) {
  if (dx < 0) {
    dx = -dx;
    incx = -1;
  } else {
    incx = 1;
  }

  if (dy < 0) {
    dy = -dy;
    incy = -1;
  } else {
    incy = 1;
  }
}

/* This uses Bresenham's Line Drawing Algorithm
 *
 * Parameters:
 * 	x0, y0 - origin of line
 *  x1, y1 - end of line
 *
 * Returns: void
 */
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1) {
  int dy = y1 - y0;
  int dx = x1 - x0;
  int incx = 0;  // Increment x
  int incy = 0;  // Increment y
  int x = x0;
  int y = y0;

  swapVal(dx, incx, dy, incy);

  if (dx > dy) {            // Slope is < 1
    int dec = 2 * dy - dx;  // Decison variable
    for (auto x = x0; x != x1; x += incx) {
      setPixel(x, y);
      if (dec > 0) {
        dec += 2 * dy - 2 * dx;
        y += incy;
      } else {
        dec += 2 * dy;
      }
    }
  } else {
    int dec = 2 * dx - dy;  // Decision variable
    for (auto y = y0; y != y1; y += incy) {
      setPixel(x, y);
      if (dec > 0) {
        dec += 2 * dx - 2 * dy;
        x += incx;
      } else {
        dec += 2 * dx;
      }
    }
  }
  setPixel(x1, y1);  // Sets the last pixel
}

/* This uses Bresenham's Circle Drawing Algorithm
 *
 * Parameters:
 * 	x0, y0 - origin/center of circle
 *  radius - radius of circle
 *
 * Returns: void
 */
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius) {
  int dec = 1 - radius;
  int y = radius;
  for (auto x = 0; y >= x; x++) {
    setPixel(x0 + x, y0 + y);
    setPixel(x0 + y, y0 + x);
    setPixel(x0 - x, y0 + y);
    setPixel(x0 + x, y0 - y);
    setPixel(x0 - y, y0 + x);
    setPixel(x0 + y, y0 - x);
    setPixel(x0 - x, y0 - y);
    setPixel(x0 - y, y0 - x);

    if (dec > 0) {
      dec += 2 * x - 2 * y + 5;
      y--;
    } else {
      dec += 2 * x + 3;
    }
  }
}

void GraphicsContext::endLoop() { run = false; }
