#include "viewcontext.h"

// Default constructor
ViewContext::ViewContext() {}

// View context constructor
ViewContext::ViewContext(GraphicsContext* gc) {
    this->mTOd = matrix::identity(4);
    this->dTOm = matrix::identity(4);
  // Creates the matrices used for createing mTOd and dTOm
  matrix flip = matrix::identity(4);
  matrix translateM = matrix::identity(4);
  flip[1][1] = -1;
  translateM[0][3] = ((gc->getWindowWidth()) / 2);
  translateM[1][3] = -((gc->getWindowHeight()) / 2);

  // Creating the model->device matrix
  this->mTOd = flip * translateM;

  // Creating the device->model matrix
  this->dTOm = matrix::identity(4);
  this->dTOm[1][1] = -1;
  this->dTOm[0][3] = -((gc->getWindowWidth()) / 2);
  this->dTOm[1][3] = ((gc->getWindowHeight()) / 2);
}

// Rotates matrix 90 degrees
void ViewContext::rotate() {
  // Creating the rotation matrix
  matrix rotateM = matrix::identity(4);
  rotateM[0][0] = 0;
  rotateM[0][1] = 1;
  rotateM[1][0] = -1;
  rotateM[1][1] = 0;

  this->mTOd = this->mTOd * rotateM;
  this->dTOm = rotateM * this->dTOm;
}

// Scales matrix
void ViewContext::scale() {
    //Creating the scale matrix
  matrix scaleM = matrix::identity(4);
  scaleM[0][0] = 1.3;
  scaleM[1][1] = 1.3;
  this->mTOd = this->mTOd * scaleM;
  this->dTOm = scaleM * this->dTOm;
}