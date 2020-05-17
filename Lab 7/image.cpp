#include "image.h"

// This is a default constructor for an image
image::image() {}

// This is a copy constructor that makes a deep copy of the image
image::image(const image& im) {
  for (auto i = 0; i < im.images.size(); i++) {
    this->images.push_back(im.images[i]->clone());
  }
}

// Desconstructor that deletes shape* on heap
image::~image() { this->erase(); }

// Assignment operator to make deep copy of one image and store it in another
image& image::operator=(const image& rhs) {
  if (&rhs != this) {
    this->erase();
    for (auto i = 0; i < rhs.images.size(); i++) {
      this->images.push_back(rhs.images[i]->clone());
    }
  }
}

// Method to add a new shape* to the images vector
void image::add(shape* newShape, ViewContext* vc) {
  newShape->convertCoords(vc);
  this->images.push_back(newShape->clone());
}

// Called to draw whatever shape is specified
void image::draw(GraphicsContext* gc, ViewContext* vc) {
  for (auto i = 0; i < this->images.size(); i++) {
    this->images[i]->draw(gc, vc);
  }
}

// Calls shape objects in fucntions to read in the data
std::istream& image::in(std::istream& is, ViewContext* vc) {
  std::string lines;
  std::string word;
  shape* s;
  while (!is.eof()) {
    is >> word;
    if (word == "Line:") {
      s = new line();
      s->in(is);
      this->add(s, vc);
    } else if (word == "Triangle:") {
      s = new triangle();
      s->in(is);
      this->add(s, vc);
    }
  }
}

// Calls shape objects out functions to output data
std::ostream& image::out(std::ostream& os) const {
  for (auto i = 0; i < this->images.size(); i++) {
    this->images[i]->out(os);
  }
}

// This method is called to erase the heap data and empty the vector
void image::erase() {
  for (auto i = 0; i < this->images.size(); i++) {
    delete this->images[i];
  }
  this->images.clear();
}