#include <stdio.h>

/*
Name: Ari Chai
Date: 09/15/2025
Course: CS125
Assignment: In Class Exercise 09/15/2025
References: Course Material
*/

int main() {

  int num;

  printf("\nEnter an integer (1-255): ");
  scanf("%d", &num);
  while (num < 1 || num > 255) {
    printf("\nInvalid input. Enter an integer (1-255): ");
    scanf("%d", &num);
  }
  

  printf("\n\nYour number is: %d", num);
  printf("\nMultiplied by 2: %d", num<<1);
  printf("\nDivided by 2: %d", num>>1);
  printf("\nOne's Compliment Unsigned: %u", ~num);
  printf("\nTwo's Compliment Unsigned: %u\n", ~num+1);


}