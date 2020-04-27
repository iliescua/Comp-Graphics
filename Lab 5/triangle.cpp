#include "triangle.h"

triangle::triangle(int x0, int y0, int x1, int y1, int x2, int y2,
                   unsigned int color)
    : x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2), color(color) {}

triangle::triangle(const triangle& rhs) {}

shape triangle::clone() {}

shape triangle::draw(GraphicsContext* gc) {}

triangle::~triangle() {}

shape& triangle::operator=(const triangle& rhs) {}

void triangle::getCoordinates(std::string filename) {}

std::ostream& operator<<(std::ostream& os, const triangle& t) {}

std::istream& operator>>(std::istream& is, const triangle& t) {}