#include <unistd.h>

#include <iostream>

#include "x11context.h"

// Custom Shape I made to test my implementation
void customShape(GraphicsContext* gc) {
  gc->setColor(GraphicsContext::BLUE);
  gc->drawLine(200, 300, 400, 100);
  gc->drawLine(400, 100, 600, 300);
  gc->drawLine(200, 300, 400, 500);
  gc->drawLine(400, 500, 600, 300);
  gc->setColor(GraphicsContext::RED);
  gc->drawCircle(400, 300, 200);
  sleep(5);
}

// Default tests provided by professor
void defaultTest(GraphicsContext* gc) {
  gc->setColor(GraphicsContext::GREEN);
  gc->setPixel(10, 10);
  gc->setPixel(30, 30);
  gc->drawLine(100, 100, 100, 500);
  gc->setColor(GraphicsContext::RED);
  gc->drawLine(100, 500, 500, 500);
  gc->setColor(GraphicsContext::BLUE);
  gc->drawLine(500, 500, 500, 100);
  gc->setColor(GraphicsContext::YELLOW);
  gc->drawLine(500, 100, 100, 100);
  gc->setColor(GraphicsContext::MAGENTA);
  gc->drawCircle(300, 300, 200);
  sleep(5);
}

// Testing efficency of different implementations provided by professor
void testSpeed(GraphicsContext* gc) {
  for (int i = 0; i < 20000; i++) {
    gc->setColor(rand() % 16777216);
    gc->drawLine((rand() % 800), (rand() % 600), (rand() % 800),
                 (rand() % 600));
  }
  sleep(10);
}

// Calls the tests to run them.
int main(void) {
  // First Test running custom shape
  GraphicsContext* gc1 = new X11Context(800, 600, GraphicsContext::BLACK);
  customShape(gc1);
  delete gc1;

  // Second test running given example
  GraphicsContext* gc2 = new X11Context(800, 600, GraphicsContext::BLACK);
  defaultTest(gc2);
  delete gc2;

  // Third test given to see implmentation's efficiency
  GraphicsContext* gc3 = new X11Context(800, 600, GraphicsContext::BLACK);
  testSpeed(gc3);
  delete gc3;

  return 0;
}