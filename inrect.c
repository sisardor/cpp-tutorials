#include<stdio.h>
#include<stdlib.h>


// declaration of function to test
int InRectangle( float pt[2], float rect[4] ) {
  printf("%f %f\n", pt[0], pt[1]);
  // printf("%f %f %f %f\n", rect[0], rect[1], rect[2], rect[3]);
  float x1 = rect[0];
  float y1 = rect[1];
  float x2 = rect[2];
  float y2 = rect[3];
  float x = pt[0];
  float y = pt[1];
  if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
      return 1;

  return 0;
}
