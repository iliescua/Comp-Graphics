#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>  // For std::ostream and std::istream

#include "gcontext.h"  //Used for plotting
#include "matrix.h"    //Matrix class for storing data

/**This class is built and designed to be an abstract shape class
 * where other classes in this project can pull methods and values for
 * meaning that it isn't specifically designed or built with the intent
 * to be anyone specific shape but the generic attributes or any shape
 *
 * This class is created to be used by us in order to help us create
 * more specfic shape classes
 */
class shape {
 public:
  // Default constructor
  shape();

  // Copy constructor to make a new duplicate shape
  shape(const shape& s);

  // Destructor to delete heap data
  virtual ~shape();

 protected:
  // Friend function for displaying shape properties
  friend std::ostream& operator<<(std::ostream& os, shape& s);

  // Friend function for reading in shape properties
  friend std::istream& operator>>(std::istream& is, shape& s);

  // Set one shapes' attributes equal to anothers' attributes
  virtual shape& operator=(const unsigned int& color);

  // This method is used to create the drawing
  virtual shape draw(GraphicsContext* gc);

  // This is a clone used to make a deep copy of shapes
  virtual shape clone();
};

// Operator to display results to console
std::ostream& operator<<(std::ostream& os, shape& s);

// Operator to read in results
std::istream& operator>>(std::istream& is, shape& s);

#endif