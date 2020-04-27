#include "shape.h"

shape::shape(){}

shape::shape(const shape& s){}

shape::~shape(){}

shape& shape::operator=(const unsigned int& color){}

shape shape::draw(GraphicsContext* gc){}

shape shape::clone(){}

std::ostream& operator<<(std::ostream& os, const shape& s) {}

std::istream& operator>>(std::istream& is, const shape& s) {}

