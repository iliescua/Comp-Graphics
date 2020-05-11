#include "triangle.h"

// Default constructor
triangle::triangle() {
  this->pOne = matrix(4, 1);
  this->pTwo = matrix(4, 1);
  this->pThree = matrix(4, 1);
}

// Parameterized constructor to make a triangle
triangle::triangle(int x0, int y0, int x1, int y1, int x2, int y2,
                   unsigned int color)
    : color(color) {
  this->pOne = matrix(4, 1);
  this->pTwo = matrix(4, 1);
  this->pThree = matrix(4, 1);

  this->pOne[0][0] = x0;
  this->pTwo[0][0] = x1;
  this->pThree[0][0] = x2;

  this->pOne[1][0] = y0;
  this->pTwo[1][0] = y1;
  this->pThree[1][0] = y2;

  this->pOne[2][0] = 0;
  this->pTwo[2][0] = 0;
  this->pThree[2][0] = 0;

  this->pOne[3][0] = 1;
  this->pTwo[3][0] = 1;
  this->pThree[3][0] = 1;
}

// Copy constructor to make a triangle
triangle::triangle(const triangle& rhs) : color(rhs.color) {
  this->pOne = matrix(rhs.pOne);
  this->pTwo = matrix(rhs.pTwo);
  this->pThree = matrix(rhs.pThree);
}

// Called in order to draw triangles from given file data
void triangle::draw(GraphicsContext* gc) {
  gc->setColor(color);
  gc->drawLine(this->pOne[0][0], this->pOne[1][0], this->pTwo[0][0],
               this->pTwo[1][0]);
  gc->drawLine(this->pOne[0][0], this->pOne[1][0], this->pThree[0][0],
               this->pThree[1][0]);
  gc->drawLine(this->pTwo[0][0], this->pTwo[1][0], this->pThree[0][0],
               this->pThree[1][0]);
}

// Destructor, no heap memory is used
triangle::~triangle() {}

// Clones attributes of the triangle and returns a new shape pointer to them
shape* triangle::clone() { return new triangle(*this); }

// Overrides the = operator to set one triangle equal to another
triangle& triangle::operator=(const triangle& from) {
  this->pOne = matrix(from.pOne);
  this->pTwo = matrix(from.pTwo);
  this->pThree = matrix(from.pThree);
  this->color = from.color;
}

// Reads in data from file and sets it into coords
std::istream& triangle::in(std::istream& is) {
  is >> this->pOne[0][0] >> this->pOne[1][0] >> this->pOne[2][0] >>
      this->pOne[3][0] >> this->pTwo[0][0] >> this->pTwo[1][0] >>
      this->pTwo[2][0] >> this->pTwo[3][0] >> this->pThree[0][0] >>
      this->pThree[1][0] >> this->pThree[2][0] >> this->pThree[3][0] >>
      this->color;
}

// Outputs data to the console
std::ostream& triangle::out(std::ostream& os) const {
  os << "Triangle" << std::endl;
  os << "x0: " << this->pOne[0][0] << " x1: " << this->pTwo[0][0]
     << " x2: " << this->pThree[0][0] << std::endl;

  os << "y0: " << this->pOne[1][0] << " y1: " << this->pTwo[1][0]
     << " y2: " << this->pThree[1][0] << std::endl;

  os << "z0: " << this->pOne[2][0] << " z1: " << this->pTwo[2][0]
     << " z2: " << this->pThree[2][0] << std::endl;

  os << "Must: " << this->pOne[3][0] << " Be: " << this->pTwo[3][0]
     << " One: " << this->pThree[3][0] << std::endl;
}