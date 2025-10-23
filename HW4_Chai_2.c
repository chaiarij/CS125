#include <stdio.h>
#include <stdlib.h>

/*
Name: Ari Chai
Date: 09/21/2025
Course: CS125
File name: HW4_Chai.c
Assignment: Homework 4: Binary Helper
References: Course Material
*/

int main() {
  
  int num1, num2, menuChoice;
  char temp1[40], temp2[40], temp3[40];
  char* endptr;
  
  //Collect user input
  printf("\nWelcome to the Binary Helper Program! :D");
  printf("\n\nEnter your first integer (1-255): ");
  scanf("%s", &temp1);
  num1 = strtol(temp1, &endptr, 10);
  while (num1 < 1 || num1 > 255) {
    printf("\nInvalid input. Enter your first integer (1-255): ");
    scanf("%s", &temp1);
    num1 = strtol(temp1, &endptr, 10);
  }
  
  printf("\nEnter your second integer (1-255): ");
  scanf("%s", &temp2);
  num2 = strtol(temp2, &endptr, 10);
  while (num2<1 || num2>255) {
    printf("\nInvalid input. Enter your first integer (1-255): ");
    scanf("%s", &temp2);
    num2 = strtol(temp2, &endptr, 10);
  }
  
  
  //Menu of Operations
  
  menuChoice = 1;
  while (menuChoice<5) {
  
    printf("\n\nWhat would you like to do?");
    printf("\n  1 - XOR operation");
    printf("\n  2 - OR operation");
    printf("\n  3 - AND operation");
    printf("\n  4 - 2's Complement operation");
    printf("\n  5 - Exit program\n");
  
    scanf("%s", &temp3);
    menuChoice = strtol(temp3, &endptr, 10);
    while (menuChoice<1 || menuChoice>5) {
      printf("\nInvalid input. Enter a number 1-5: ");
      scanf("%s", &temp3);
      menuChoice = strtol(temp3, &endptr, 10);
    }
  
    switch (menuChoice) {
  
      case 1:
        printf("\n\nThe XOR operation of %d and %d is: %d", num1, num2, num1^num2);
        break;
        
      case 2: 
        printf("\n\nThe OR operation of %d and %d is: %d", num1, num2, num1|num2);
        break;
        
      case 3:
        printf("\n\nThe AND operation of %d and %d is: %d", num1, num2, num1&num2);
        break;
      
      case 4:
        printf("\n\nThe 2's Complement operations of %d and %d are: %d and %d", num1, num2, ~num1+1, ~num2+1);
        break;
        
      case 5:
        printf("\n\nThank you for using the Binary Helper program!\n\n");
        return;
      
  
    } //End switch statement
    
  } //End menu while loop

} //End main()