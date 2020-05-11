#include "image.h"
#include "mydrawing.h"

int main(int argc, char* argv[]) {
  GraphicsContext* gc = new X11Context(800, 600, GraphicsContext::WHITE);
  MyDrawing md;
  gc->runLoop(&md);

  delete gc;
  return 0;
}