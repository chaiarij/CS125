#include <stdio.h>
#include <string.h>

/*
Name: Ari Chai
Date: 09-13-25
Course: CS125
Assignment: In Class Exercise 09/10/2025
References: Course Material
*/

int main() {
  
  float num1, num2, num3;
  printf("\nEnter three numbers: \n");
  scanf("%f%f%f", &num1, &num2, &num3);
  
  float sum = num1 + num2 + num3;
  
  char soap[40];
  
  (sum > 12.11) ? (strcpy(soap, "Mission Failed")) : (strcpy(soap, "Mission Passed"));
  
  printf("Total: %.2f\n", sum);
  printf("%s\n\n", soap);
  
  
}