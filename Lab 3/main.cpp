#include <iostream>
#include <random>

#include "matrix.h"

// Creates and populates a matrix based on passed in parameters
matrix popMatrix(unsigned int row, unsigned int col) {
  matrix m1(row, col);
  for (auto i = 0; i < 3; i++) {
    for (auto j = 0; j < 3; j++) {
      m1[i][j] = rand() % 10;
    }
  }
  return m1;
}

// Test for the basic functionality of the matrix class like the
// constructor, copy, assignment, identity, pass value, print, and clear
void testMatrixBuild() {
  matrix m1 = popMatrix(3, 3);  // Creates a 3 x 3 matrix of rand values
  std::cout << "Matrix One" << std::endl << m1 << std::endl;
  matrix m2 = matrix::identity(3);  // Creates 3 x 3 identity matrix
  std::cout << "Matrix Two" << std::endl << m2 << std::endl;

  m2 = m1;  // Test assignemnt operator
  std::cout << "Assignment Test" << std::endl << m2 << std::endl;

  matrix m3 = m2;  // Tests copy constructor
  std::cout << "Copy Test" << std::endl << m3 << std::endl;

  m3.clear();  // Tests the clear function
  std::cout << "Clear Test" << std::endl << m3 << std::endl << std::endl;
}

// Tests to make sure the addition function is working properly
void testAddition() {
  matrix m1 = popMatrix(3, 3);  // Creates a 3 x 3 matrix of rand values
  std::cout << "Matrix One" << std::endl << m1 << std::endl;
  matrix m2 = popMatrix(3, 3);  // Creates 3 x 3 matrix of rand values
  std::cout << "Matrix Two" << std::endl << m2 << std::endl;
  matrix m3 = m1 + m2;  // Creates a matrix of the sum of m1 and m2
  std::cout << "Summed Matrix" << std::endl << m3 << std::endl << std::endl;
}

// Tests to make sure the transpose function is working properly
void testTranspose() {
  matrix m1 = popMatrix(3, 3);  // Creates a 3 x 3 matrix of rand values
  std::cout << "Matrix One" << std::endl << m1 << std::endl;
  matrix m2 = ~m1;  // Creates a the transposed matrix or m1
  std::cout << "Transposed Matrix" << std::endl << m2 << std::endl << std::endl;
}

// Tests to make sure the multiplications functions work properly
void testMult() {
  matrix m1 = popMatrix(3, 3);  // Creates a 3 x 3 matrix of rand values
  std::cout << "Matrix One" << std::endl << m1 << std::endl;
  matrix m2 = popMatrix(3, 3);  // Creates 3 x 3 matrix of rand values
  std::cout << "Matrix Two" << std::endl << m2 << std::endl;

  matrix m3 = m1 * m2;  // Creates a product matrix of 2 matricies
  std::cout << "Product Matrix(Two Matricies)" << std::endl << m3 << std::endl;

  m3 = m1 * 2;  // Creates a product of a matrix and scalar
  std::cout << "Product Matrix(Matrix*Scalar)" << std::endl << m3 << std::endl;

  m3 = 2 * m2;  // Creates a product of a scalar and a matrix
  std::cout << "Product Matrix(Scalar*Matrix)" << std::endl << m3 << std::endl;
}

int main(void) {
  std::cout << "Testing Basic Functions" << std::endl;
  testMatrixBuild();
  std::cout << "Testing Addition Functions" << std::endl;
  testAddition();
  std::cout << "Testing Transpose Function" << std::endl;
  testTranspose();
  std::cout << "Testing Multiplication Function" << std::endl;
  testMult();

  return 0;
}