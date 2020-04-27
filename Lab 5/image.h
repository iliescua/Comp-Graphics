#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>  // For std::ostream and std::istream
#include <vector>    //Used as the container device

#include "gcontext.h"  //Used for plotting
#include "line.h"      //Creating lines
#include "triangle.h"  //Creating triangle

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

  // Adds a new shape to the container
  void add(shape* newShape);

  // Ask all of the shapes to draw themselves by invoking each shapes draw()
  void draw(GraphicsContext* gc);

  // Called to output shapes in ostream to file
  void out(std::ostream& os);

  // Called to input shapes in ostream from file
  void in(std::istream& is);

  // Clears the image by removing all shapes and free dynamic memory
  void erase();
};

#endif