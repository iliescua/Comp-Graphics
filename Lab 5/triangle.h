#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>  // For std::ostream and std::istream

#include "shape.h"  //Abstract shape class

/**This class is built and designed to be a triangle object. It will be called
 * by the user in order to create triangles from given data.
 */
class triangle : public shape {
 public:
  // Default constructor
  triangle();

  // Parameterized constructor for a triangle
  triangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color);

  // Copy constructor for a triangle
  triangle(const triangle& rhs);

  // Overriden method called in order to draw the triangle
  // It accepts a gc which contains the algorithms for drawing
  void draw(GraphicsContext* gc);

  // triangle destructor to delete stored heap memory
  ~triangle();

  // Overriden clone method from abstract shape class
  shape* clone();

  // Overload the assignment operator
  triangle& operator=(const triangle& rhs);

  // Called to input the triangle data
  std::istream& in(std::istream& is);

  // Called to ouput the triangle data
  std::ostream& out(std::ostream& os) const;

 private:
  // Variable to store the color
  unsigned int color;
  // Matrix to store first point
  matrix pOne;
  // Matrix to store second point
  matrix pTwo;
  // Matrix to store third point
  matrix pThree;
};

#endif