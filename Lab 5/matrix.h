/**
 * matrix.h - declaration of matrix class.  This class will be
 * capable of represting a Matrix as a first-class type.
 *
 * For CS321.  (c) 2015 Dr. Darrin Rothe
 * Varnell 2020
 * Updated: Andrew 2020
 */

// compile guard
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>   // for std::ostream
#include <stdexcept>  // for std::runtime_error
#include <string>     // used in exception

/* This is a class that is created as a helper in order to return the
 * row of a matrix as well as the column in order to check for
 * whether the user entered valid data
 */
class mrow {
 public:
  // Parameterized Construsctor
  mrow(unsigned int size, double* matrix_row);

  // Checks the column is valid and returns it (can be set)
  double& operator[](unsigned int col);

  // Checks the column is valid and returns it (can't be set)
  double operator[](unsigned int col) const;

 private:
  // Size of matrix cols
  unsigned int size;
  // Number of matrix rows
  double* matrix_row;
};

/* Class used to create matricies of any size and be able to perform basic
 * operations on the matricies as whole
 */
class matrix {
 public:
  // Friend method to allow the osstream to have access to private data to
  // display
  friend std::ostream& operator<<(std::ostream& os, const matrix& rhs);

  // Friend method to allow the mult operator to have access to private data to
  // display
  friend matrix operator*(const double scale, const matrix& rhs);

  // Parameterized constructor for creating matrix - sets all cells to 0
  matrix(unsigned int rows, unsigned int cols);

  // Copy constructor - make a new Matrix just like rhs
  matrix(const matrix& from);

  // Destructor - free heap memory
  ~matrix();

  // Assignment operator - make this just like rhs.  Must function
  // correctly even if rhs is a different size than this.
  matrix& operator=(const matrix& rhs);

  // Named Constructor - produce a square identity matrix of the
  // requested size.  Since we do not know how the object produced will
  // be used, we pretty much have to return by value.  A size of 0
  // would not make sense and should throw an exception.
  //
  // throw (matrixException)
  //
  static matrix identity(unsigned int size);

  // Matrix addition - lhs and rhs must be same size otherwise
  // an exception shall be thrown
  //
  // throw (matrixException)
  //
  matrix operator+(const matrix& rhs) const;

  // Matrix multiplication - lhs and rhs must be compatible
  // otherwise an exception shall be thrown
  //
  // throw (matrixException)
  //
  matrix operator*(const matrix& rhs) const;

  // Scalar multiplication.  Note, this function will support
  // someMatrixObject * 5.0, but not 5.0 * someMatrixObject.
  matrix operator*(const double scale) const;

  // Transpose of a Matrix - should always work, hence no exception
  matrix operator~() const;

  // Clear Matrix to all members 0.0
  void clear();

  // Created to set values to the matrix in main
  // Checks against row being too small
  mrow operator[](unsigned int row);

  // const version of above - throws an exception if row is out of range
  mrow operator[](unsigned int row) const;

  // I/O - for convenience - this is intended to be called by the global
  // << operator declared below
  std::ostream& out(std::ostream& os) const;

 private:
  // This stores the actual matrix values
  double** the_matrix;
  // The number of rows in the matrix
  unsigned int rows;
  // The number of columns in the matrix
  unsigned int cols;
};

/** Some Related Global Functions **/

// Overloaded global << with std::ostream as lhs, Matrix as rhs.  This method
// should generate output compatible with an ostream which is commonly used
// with console (cout) and files
std::ostream& operator<<(std::ostream& os, const matrix& rhs);

// Scalar multiplication with a global function.  Note, this function will
// support 5.0 * someMatrixObject, but not someMatrixObject * 5.0
matrix operator*(const double scale, const matrix& rhs);

#endif