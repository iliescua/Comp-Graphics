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

  // This method is used to create the drawing
  // It accepts a gc which contains the algorithms for drawing
  virtual void draw(GraphicsContext* gc) = 0;

  // This is a clone used to make a deep copy of shapes
  virtual shape* clone() = 0;

  // Called to ouput the shape data
  virtual std::ostream& out(std::ostream& os) const;

  // Called to input the shape data
  virtual std::istream& in(std::istream& is);

 protected:
  // Set one shapes' attributes equal to anothers' attributes
  virtual shape& operator=(const unsigned int& color);
};

#endif