#include <stdio.h>

/*
Author: Ari Chai
Course: CS125
Assignment: In Class Exercise 10/01, Problem 2
References: Course Material
*/

int calcFact(int n) {
  if (n==0 || n==1) {
    return 1;
  }
  else {
    return n*calcFact(n-1);
  }
}


int main() {
  
  int num;
  printf("\n\nEnter a number: ");
  scanf("%d", &num);
  printf("\nThe factorial of %d is %d.", num, calcFact(num));
  
}