#include "matrix.h"

#include <cmath>
#include <string>

// Parameterized constructor
matrix::matrix(unsigned int rows, unsigned int cols) : rows(rows), cols(cols) {
  if (rows < 1 || cols < 1) {
	throw std::runtime_error("Parameterized constructor: bad arguments");
  }
  this->the_matrix = new double *[rows];
  for (unsigned i = 0; i < rows; i++) {
	this->the_matrix[i] = new double[cols];
	for (unsigned j = 0; j < cols; j++) {
	  this->the_matrix[i][j] = 0;
	}
  }
}

// Copy constructor
matrix::matrix(const matrix &from) : rows(from.rows), cols(from.cols) {
  this->the_matrix = new double *[rows];
  for (unsigned i = 0; i < rows; i++) {
	this->the_matrix[i] = new double[cols];
	for (unsigned j = 0; j < cols; j++) {
	  this->the_matrix[i][j] = from.the_matrix[i][j];
	}
  }
}

// Destructor
matrix::~matrix() {
  for (unsigned i = 0; i < rows; i++) {
	delete[] this->the_matrix[i];
  }
  delete[] this->the_matrix;
}

// Assignment operator
matrix &matrix::operator=(const matrix &rhs) {
  if (this != &rhs) {
	for (unsigned i = 0; i < this->rows; i++) {
	  delete[] this->the_matrix[i];
	}
	delete[] this->the_matrix;
  }
  this->rows = rhs.rows;
  this->cols = rhs.cols;

  this->the_matrix = new double *[rows];
  for (unsigned i = 0; i < this->rows; i++) {
	this->the_matrix[i] = new double[cols];
	for (unsigned j = 0; j < this->cols; j++) {
	  this->the_matrix[i][j] = rhs.the_matrix[i][j];
	}
  }
  return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size) {
  // use p-constructor
  matrix identity(size, size);
  for (unsigned i = 0; i < size; i++) {
	identity.the_matrix[i][i] = 1;
  }
  return identity;
}