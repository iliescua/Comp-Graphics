#ifndef LINE_H_
#define LINE_H_

#include <iostream>  // For std::ostream and std::istream

#include "shape.h"  //Abstract shape class

/**This class is built and designed to be a line object. It will be called
 * by the user in order to create lines from given data.
 */
class line : public shape {
 public:
  // Friend function for displaying line properties
  friend std::ostream& operator<<(std::ostream& os, const line& l);

  // Friend function for reading in shape properties
  friend std::istream& operator>>(std::istream& is, const line& l);

  // Parameterized constructor for a line
  line(int x0, int y0, int x1, int y1, unsigned int color);

  // Copy constructor for a line
  line(const line& rhs);

  // Overriden clone method from abstract shape class
  shape clone();

  // Overriden method called in order to draw the line
  shape draw(GraphicsContext* gc);

  // Line destructor to delete stored heap memory
  ~line();

  // Overload the assignment operator
  shape& operator=(const line& rhs);

  // Called when reading a file to get coordinates from file
  void getCoordinates(std::string filename);

 private:
  // We need a shape to get color attributes from it
  shape s;
  // We need to create variables for the needed points to make a line
  int x0;
  int y0;
  int x1;
  int y1;
  // Variable to store the color
  unsigned int color;
};

// Operator to display results to console
std::ostream& operator<<(std::ostream& os, const line& l);

// Operator to read in results
std::istream& operator>>(std::istream& is, const line& l);

#endif