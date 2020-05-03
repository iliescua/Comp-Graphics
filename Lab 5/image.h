#ifndef IMAGE_H_
#define IMAGE_H_

#include <fstream>
#include <iostream>  // For std::ostream and std::istream
#include <string>
#include <vector>  //Used as the container device
#include <unistd.h>

#include "gcontext.h"  //Used for plotting
#include "line.h"      //Creating lines
#include "triangle.h"  //Creating triangle
#include "x11context.h"

/**This class is built to be a container for the images that are
 * produced and be the device that allows the user to store
 * multiple image as well as manipulate and alter which
 * shapes are stored. A vector will be the container used
 */
class image {
 public:
  // Default constructor
  image();

  // Copy constructor that creates a deep copy of stored images
  image(const image& im);

  // Destructor for data stored on the heap
  ~image();

  // Assignment operator for setting images equal to one another
  image& operator=(const image& rhs);

  // Adds a new shape to the container
  void add(shape* newShape);

  // Ask all of the shapes to draw themselves by invoking each shapes draw()
  void draw(GraphicsContext* gc);

  // Called to input the data from file
  std::istream& in(std::istream& is);

  // Called to ouput data to console
  std::ostream& out(std::ostream& os) const;

  // Clears the image by removing all shapes and free dynamic memory
  void erase();

 private:
  // This is a container to hold all of my images
  std::vector<shape*> images;
};

#endif