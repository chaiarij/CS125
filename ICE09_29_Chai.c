#include <stdio.h>
#include <string.h>

/*
Author: Ari Chai
Course: CS125
Assignment: In Class Assignment 09/29/2025
References: Course Material, GeeksforGeeks articles
*/

int strManip(char* userStr, char* userStrLower);

int main() {
  
  char userStr[16];
  char userStrLower[16];
  int vowelNum;
  
  printf("\n\nWelcome to the String Manipulation program! :D");
  printf("\nEnter a word (15 character max): ");
  fgets(userStr, 16, stdin);
  vowelNum = strManip(userStr, userStrLower);
  
  printf("\nOriginal string: %s", userStr);
  printf("\nLowercase string: %s", userStrLower);
  printf("\nNumber of vowels: %d", vowelNum);
  printf("\nThanks for using the program! <3 \n\n");
  
}

int strManip(char* userStr, char* userStrLower) {
  
  int vowelNum=0;
  int iter;
  
  for (iter=0; iter<(strlen(userStr)); iter++) {
    userStrLower[iter] = tolower(userStr[iter]);
  }
  
  for (iter=0; iter<(strlen(userStr)); iter++) {
    if ((userStrLower[iter]=='a') || (userStrLower[iter]=='e') || (userStrLower[iter]=='i') || (userStrLower[iter]=='o') || (userStrLower[iter]=='u')) {
      vowelNum = vowelNum + 1;
    }
  }
  return(vowelNum);
  
}