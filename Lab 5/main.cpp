#include "image.h"

int main(int argc, char* argv[]) {
  std::string filename = argv[1];
  GraphicsContext* gc = new X11Context(800, 600, GraphicsContext::BLACK);
  image im;
  image im2(im);
  std::ifstream filein(filename);
  im.in(filein);
  im.draw(gc);
  sleep(5);
  std::cout << "Image One Values" << std::endl;
  im.out(std::cout);
  std::cout << "Image One Erased" << std::endl;
  im.erase();
  im2.draw(gc);
  sleep(5);

  filein.close();
  return 0;
}