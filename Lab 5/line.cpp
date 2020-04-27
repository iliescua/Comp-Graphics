#include "line.h"

line::line(int x0, int y0, int x1, int y1, unsigned int color)
    : x0(x0), y0(y0), x1(x1), y1(y1), color(color) {}

line::line(const line& rhs) {}

shape line::clone() {}

shape line::draw(GraphicsContext* gc) {}

line::~line() {}

shape& line::operator=(const line& rhs) {}

void line::getCoordinates(std::string filename) {}

std::ostream& operator<<(std::ostream& os, const line& l) {}

std::istream& operator>>(std::istream& is, const line& l) {}