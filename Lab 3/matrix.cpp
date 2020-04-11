#include "matrix.h"

#include <string>     // used in exception
#include <cmath>

// Parameterized constructor for matricies
matrix::matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
  if (rows < 1 || cols < 1) {
    throw std::runtime_error("Parameterized constructor: bad arguments");
  }
  this->the_matrix = new double*[rows];  // Allocates heap space for rows
  for (auto i = 0; i < rows; i++) {
    this->the_matrix[i] = new double[cols];  // Allocates heap space for cols
    for (auto j = 0; j < cols; j++) {
      this->the_matrix[i][j] = 0.0;  // Sets all matrix entries to 0.0
    }
  }
}

// Parameterized constructor for mrow
mrow::mrow(unsigned int size, double* matrix_row)
    : size(size), matrix_row(matrix_row) {}

// Copy constructor
matrix::matrix(const matrix& from) : rows(from.rows), cols(from.cols) {
  this->the_matrix = new double*[rows];  // Allocates heap space for rows
  for (auto i = 0; i < rows; i++) {
    this->the_matrix[i] = new double[cols];  // Allocates heap space for cols
    for (auto j = 0; j < cols; j++) {
      this->the_matrix[i][j] =
          from.the_matrix[i][j];  // Copies one matrix into the other
    }
  }
}

// Destructor
matrix::~matrix() {
  for (auto i = 0; i < rows; i++) {
    delete[] this->the_matrix[i];  // Deletes cols first to leave no memory
  }
  delete[] this->the_matrix;  // The deletes rows
}

// Assignment operator
matrix& matrix::operator=(const matrix& rhs) {
  if (this != &rhs) {  // Checks against setting a value equal to itself
    for (auto i = 0; i < this->rows; i++) {
      delete[] this->the_matrix[i];  // Deletes cols
    }
    delete[] this->the_matrix;  // Deletes rows
    this->rows = rhs.rows;
    this->cols = rhs.cols;
    this->the_matrix = new double*[rows];  // Allocates heap space for rows
    for (auto i = 0; i < this->rows; i++) {
      this->the_matrix[i] = new double[cols];  // Allocates heap space for cols
      for (auto j = 0; j < this->cols; j++) {
        this->the_matrix[i][j] = rhs.the_matrix[i][j];  // Copies matricies
      }
    }
  }
  return *this;
}

// Named constructor for the identity matrix (static)
matrix matrix::identity(unsigned int size) {
  if (size == 0) {  // Checks for bad input
    throw std::runtime_error("Matrix can't be size 0");
  }
  matrix identity(size, size);  // Calls constructor
  for (auto i = 0; i < size; i++) {
    identity.the_matrix[i][i] = 1;
  }
  return identity;
}

// Allows for two matricies to be added together
matrix matrix::operator+(const matrix& rhs) const {
  if (this->rows != rhs.rows || this->cols != rhs.cols) {
    throw std::runtime_error("Matricies are not the same size");
  }
  matrix retVal(rhs.rows, rhs.cols);     // Creates new matrix
  for (auto i = 0; i < rhs.rows; i++) {  // Does the adddition for each value
    for (auto j = 0; j < rhs.cols; j++) {
      retVal.the_matrix[i][j] = this->the_matrix[i][j] + rhs.the_matrix[i][j];
    }
  }
  return retVal;
}

// Allows for two matricies to be multiplied together
matrix matrix::operator*(const matrix& rhs) const {
  if (this->cols != rhs.rows) {  // Checks for bad input
    throw std::runtime_error("Column of first matrix must equal row of second");
  }
  matrix retVal(this->rows, rhs.cols);     // Creates a new matrix
  for (auto i = 0; i < this->rows; i++) {  // Does multiplication for each value
    for (auto j = 0; j < rhs.cols; j++) {
      for (auto k = 0; k < rhs.rows; k++) {
        retVal.the_matrix[i][j] +=
            this->the_matrix[i][k] * rhs.the_matrix[k][j];
      }
    }
  }
  return retVal;
}

// Allows for a matrix to bu multiplied by a value (only works as matrix * val)
matrix matrix::operator*(const double scale) const {
  matrix retVal(this->rows, this->cols);   // Creates new matrix
  for (auto i = 0; i < this->rows; i++) {  // Does the mult for each cell
    for (auto j = 0; j < this->cols; j++) {
      retVal.the_matrix[i][j] = this->the_matrix[i][j] * scale;
    }
  }
  return retVal;
}

// Transposing the matrix
matrix matrix::operator~() const {
  matrix retVal(this->cols, this->rows);   // Creates a new matrix
  for (auto i = 0; i < this->cols; i++) {  // Reassigns the values
    for (auto j = 0; j < this->rows; j++) {
      retVal.the_matrix[i][j] = this->the_matrix[j][i];
    }
  }
  return retVal;
}

// Clears the matrix by replacing it with all 0's
void matrix::clear() {
  for (auto i = 0; i < this->rows; i++) {
    for (auto j = 0; j < this->cols; j++) {
      this->the_matrix[i][j] = 0.0;
    }
  }
}

// Checks calls from main about row size
mrow matrix::operator[](unsigned int row) {
  if (row >= this->rows) {
    throw std::runtime_error("Row index too large");
  }
  mrow mr(cols, the_matrix[row]);
  return mr;
}

// Checks calls from main about row size (const version)
mrow matrix::operator[](unsigned int row) const {
  if (row >= this->rows) {
    throw std::runtime_error("Row index too large");
  }
  mrow mr(cols, the_matrix[row]);
  return mr;
}

// Checks calls from main about col size
double& mrow::operator[](unsigned int col) {
  if (col >= this->size) {
    throw std::runtime_error("Column index too large");
  }
  return this->matrix_row[col];
}

// Checks calls from main about col size (const version)
double mrow::operator[](unsigned int col) const {
  if (col >= this->size) {
    throw std::runtime_error("Column index too large");
  }
  return this->matrix_row[col];
}

// Global insertion and operator for printing the matrixies to console
std::ostream& operator<<(std::ostream& os, const matrix& rhs) {
  for (auto i = 0; i < rhs.rows; i++) {
    for (auto j = 0; j < rhs.cols; j++) {
      os << rhs.the_matrix[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}

// Global scalar multiplication allows for (value * matrix)
matrix operator*(const double scale, const matrix& rhs) {
  matrix retVal(rhs.rows, rhs.cols);     // Creates new matrix
  for (auto i = 0; i < rhs.rows; i++) {  // Does the mult for each cell
    for (auto j = 0; j < rhs.cols; j++) {
      retVal.the_matrix[i][j] = rhs.the_matrix[i][j] * scale;
    }
  }
  return retVal;
}