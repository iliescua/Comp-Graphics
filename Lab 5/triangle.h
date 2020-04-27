#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>  // For std::ostream

#include "shape.h"  //Abstract shape class

/**This class is built and designed to be a triangle object. It will be called
 * by the user in order to create triangles from given data.
 */
class triangle : public shape {
 public:
  // Friend function for displaying triangle properties
  friend std::ostream& operator<<(std::ostream& os, const triangle& t);

  // Friend function for reading in triangle properties
  friend std::istream& operator>>(std::istream& is, const triangle& t);

  // Parameterized constructor for a triangle
  triangle(int x0, int y0, int x1, int y1, int x2, int y2, unsigned int color);

  // Copy constructor for a triangle
  triangle(const triangle& rhs);

  // Overriden clone method from abstract shape class
  shape clone();

  // Overriden method called in order to draw the triangle
  shape draw(GraphicsContext* gc);

  // Triangle destructor to delete stored heap memory
  ~triangle();

  // Overload the assignment operator
  shape& operator=(const triangle& rhs);

  // Called when reading a file to get coordinates from file
  void getCoordinates(std::string filename);

 private:
  // We need a shape to get color attributes from it
  shape s;
  // We need to create variables for the needed points to make a triangle
  int x0;
  int y0;
  int x1;
  int y1;
  int x2;
  int y2;
  // Variable to store the color
  unsigned int color;
};

// Operator to display results to console
std::ostream& operator<<(std::ostream& os, const triangle& t);

// Operator to read in results
std::istream& operator>>(std::istream& is, const triangle& t);

#endif