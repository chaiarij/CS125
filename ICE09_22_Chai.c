#include <stdio.h>
#include <string.h>

/*
Author: Ari Chai
Date: 09/22/2025
Course: CS125
Assignment: In Class Assignment 09/22
References: Course Material, GeeksforGeeks strcat() documentation
*/


int my_concat(char *str1,char *str2) {
  strcat(str1,str2);
}

int strprint(char *str_to_print) {
  printf("\nThe concatenated string is: %s\n\n", str_to_print);
}


int main() {

  char str1[40], str2[40], strinput1[8], strinput2[8], *str_to_print[40];
  
  printf("\n\nEnter the first string (no spaces): ");
  scanf("%s", strinput1);
  if (strlen(strinput1)>7) {
    printf("\nString cannot be longer than 7 characters. Ending program.\n\n");
    return(0);
  }
  
  printf("\nEnter the second string (no spaces): ");
  scanf("%s", strinput2);
  if (strlen(strinput2)>7) {
    printf("\nString cannot be longer than 7 characters. Ending program.\n\n");
    return(0);
  }
  
  my_concat(strinput1,strinput2);
  strprint(strinput1);
  
  return(0);
}