#include <stdio.h>

/*
Author: Ari Chai
Course: CS125
Assignment: In Class Assignment 09/24/2025
References: Course Material
*/

void readIn(int readVal, int i, int arrSize, int myArr[]);
float calcAv(float myAv, int i, int arrSize, int myArr[]);

int main() {
  
  int arrSize, i, readVal, max, min;
  float myAv = 0;
  
  printf("\n\nEnter the size of an array (max 20): ");
  scanf("%d", &arrSize);
  while (arrSize>20) {
    printf("\nInvalid input. Max array size is 20.");
    printf("\nEnter the size of an array (max 20): ");
    scanf("%d", &arrSize);
  }
  
  int myArr[arrSize];
  printf("\n\nEnter values for your array of size %d: ", arrSize);
  
  readIn(readVal, i, arrSize, myArr);
  
  printf("\n\nYour values are: ");
  for (i=0; i<arrSize; i++) {
    printf("%d, ", myArr[i]);
  }
  
  max = myArr[0];
  for (i=0; i<arrSize; i++) {
    if (myArr[i]>max) {
      max = myArr[i];
    }
  }
  
  min = myArr[0];
  for (i=0; i<arrSize; i++) {
    if (myArr[i]<min) {
      min = myArr[i];
    }
  }
  
  printf("\nThe maximum value is: %d", max);
  printf("\nThe minimum value is: %d", min);
  

  myAv = calcAv(myAv, i, arrSize, myArr);
  printf("\nThe average value is: %.2f\n\n", myAv);
}


void readIn(int readVal, int i, int arrSize, int myArr[]) {
  for (i=0; i<arrSize; i++) {
    scanf("%d", &readVal);
    myArr[i] = readVal;
  }
}

float calcAv(float myAv, int i, int arrSize, int myArr[]) {
  for (i=0; i<arrSize; i++) {
    myAv = myAv + myArr[i];
  }
  myAv = myAv / arrSize;
  return(myAv);
}




