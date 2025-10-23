#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Author: Ari Chai
Assignment: CS125 In Class Exercise 10/20/2025
Date: 10/20/2025
References: Course Material
*/

float addFunc(float num1, float num2) {
  return(num1+num2);
}

float subtrFunc(float num1, float num2) {
  return(num1 - num2);
}

float multFunc(float num1, float num2) {
  return(num1 * num2);
}

float divFunc(float num1, float num2) {
  if (num2 == 0) {
    return(0);
  }
  return(num1 / num2);
}


int main(int argc, char* argv[]) {
  
  if (argc < 4) {
    printf("\nError occurred: wrong number of inputs.\n\n");
    return(0);
  }
  
  char* endptr;
  float input1 = strtof(argv[1], &endptr);
  float input2 = strtof(argv[3], &endptr);
  
  if (strncmp(argv[2],"+",1) == 0) {
    printf("\nResult: %.2f\n\n", addFunc(input1, input2));
  }
  else if (strncmp(argv[2], "-", 1) == 0) {
    printf("\nResult: %.2f\n\n", subtrFunc(input1, input2));
  }
  else if (strncmp(argv[2], "*", 1) == 0) {
    printf("\nResult: %.2f\n\n", multFunc(input1, input2));
  }
  else if (strncmp(argv[2], "/", 1) == 0) {
    printf("\nResult: %.2f\n\n", divFunc(input1, input2));
  }
  else {
    printf("\nError occurred: invalid operation.\n\n");
  }
  
  return(0);
}