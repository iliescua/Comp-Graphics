#ifndef LINE_H_
#define LINE_H_

#include <iostream>  // For std::ostream and std::istream

#include "shape.h"  //Abstract shape class
#include "x11context.h"

/**This class is built and designed to be a line object. It will be called
 * by the user in order to create lines from given data.
 */
class line : public shape {
 public:
  // Default constructor
  line();

  // Parameterized constructor for a line
  line(int x0, int y0, int x1, int y1, unsigned int color);

  // Copy constructor for a line
  line(const line& rhs);

  // Overriden method called in order to draw the line
  // It accepts a gc which contains the algorithms for drawing
  void draw(GraphicsContext* gc);

  // Line destructor to delete stored heap memory
  ~line();

  // Overriden clone method from abstract shape class
  shape* clone();

  // Overload the assignment operator
  line& operator=(const line& rhs);

  // Called to input the line data
  std::istream& in(std::istream& is);

  // Called to ouput the line data
  std::ostream& out(std::ostream& os) const;

 private:
  // Variable to store the color
  unsigned int color;
  // Matrix to store start point
  matrix startP;
  // Matrix to store end point
  matrix endP;
};

#endif