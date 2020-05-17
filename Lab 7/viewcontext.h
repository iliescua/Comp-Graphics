#ifndef VIEWCONTEXT_H
#define VIEWCONTEXT_H

#include "gcontext.h"
#include "matrix.h"

class ViewContext {
 public:
  ViewContext();

  ViewContext(GraphicsContext* gc);

  // Rotates the image 90 degrees
  void rotate();

  // Scale the matrix a specified x and y
  void scale();

  // Matrix for model to device coords
  matrix mTOd;

  // Matrix for device to mode coords
  matrix dTOm;
};

#endif
