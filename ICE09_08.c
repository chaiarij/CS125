#include <stdio.h>

/*
Name: Ari Chai
Date: 09/13/2025
Course: CS125
Assignment: In Class Exercise - 09/08/2025
References: Course Material
*/

int main() {

  int choice;

  printf("Choose an aircraft: \n");
  printf("  1 - B747\n");
  printf("  2 - A320\n");
  printf("  3 - A321\n");
  printf("  4 - B757-3\n");
  printf("  5 - SR71\n");

  scanf("%d", &choice);

  switch (choice) {
  
    case 1:
      printf("\nYou chose B747\n");
      break;
      
    case 2:
      printf("\nYou chose A320\n");
      break;
      
    case 3:
      printf("\nYou chose A321\n");
      break;
      
    case 4:
      printf("\nYou chose B757-3\n");
      break;
      
    case 5:
      printf("\nYou chose SR71\n");
      break;
      
    default:
      printf("\nInvalid input. Please try again.\n");
      break;

  }
  
}