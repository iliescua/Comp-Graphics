#include "line.h"

// Default constructor
line::line() {
  this->startP = matrix(4, 1);
  this->endP = matrix(4, 1);
}

// Parameterized constructor to make a line
line::line(int x0, int y0, int x1, int y1, unsigned int color) : color(color) {
  this->startP = matrix(4, 1);
  this->endP = matrix(4, 1);
  this->startP[0][0] = x0;
  this->endP[0][0] = x1;
  this->startP[1][0] = y0;
  this->endP[1][0] = y1;
  this->startP[2][0] = 0;
  this->endP[2][0] = 0;
  this->startP[3][0] = 1;
  this->endP[3][0] = 1;
}

// Copy constructor to make a line
line::line(const line& rhs) : color(rhs.color) {
  this->startP = matrix(rhs.startP);
  this->endP = matrix(rhs.endP);
}

// Called in order to draw lines from given file data
void line::draw(GraphicsContext* gc, ViewContext* vc) {
  gc->setColor(this->color);
  matrix m1(4, 1);
  matrix m2(4, 1);
  m1 = vc->mTOd * this->startP;
  m2 = vc->mTOd * this->endP;
  gc->drawLine(m1[0][0], m1[1][0], m2[0][0],
               m2[1][0]);
}

// Destructor, no heap memory is used
line::~line() {}

// Clones attributes of the line and returns a new shape pointer to them
shape* line::clone() { return new line(*this); }

// Overrides the = operator to set one line equal to another
line& line::operator=(const line& from) {
  this->startP = matrix(from.startP);
  this->endP = matrix(from.endP);
  this->color = from.color;
}

// Reads in data from file and sets it into coords
std::istream& line::in(std::istream& is) {
  unsigned int temp;
  is >> this->startP[0][0] >> this->startP[1][0] >> this->startP[2][0] >>
      this->startP[3][0] >> this->endP[0][0] >> this->endP[1][0] >>
      this->endP[2][0] >> this->endP[3][0] >> this->color;
}

// Outputs data to the console
std::ostream& line::out(std::ostream& os) const {
  os << "Line" << std::endl;
  os << "x0: " << this->startP[0][0] << " x1: " << this->endP[0][0]
     << std::endl;
  os << "y0: " << this->startP[1][0] << " y1: " << this->endP[1][0]
     << std::endl;
  os << "z0: " << this->startP[2][0] << " z1: " << this->endP[2][0]
     << std::endl;
  os << "Mystery: " << this->startP[3][0] << " Surprise: " << this->endP[3][0]
     << std::endl;
}

void line::convertCoords(ViewContext* vc){
  this->startP = vc->dTOm * this->startP;
  this->endP = vc->dTOm * this->endP;
}