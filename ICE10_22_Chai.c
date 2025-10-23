#include <stdio.h>
#include <string.h>

/*
Author: Ari Chai
Assignment: CS125 In Class Assignment 10/22/25
Date: 10/22/25
References: Course Material
*/

typedef struct {
  char name[50];
  int age;
  char grade[50];
  int num_courses;
} Student;

void readData(Student *s1) {
  
  char name[50], age[50], grade[50], num_courses[50];
  char* endptr;
  
  printf("\n\nEnter your name: ");
  fgets(name, 50, stdin);
  printf("Enter your age: ");
  fgets(age, 50, stdin);
  printf("Enter your letter grade: ");
  fgets(grade, 50, stdin);
  printf("Enter the number of courses you're enrolled in: ");
  fgets(num_courses, 50, stdin);
  
  strcpy(s1->name, name);
  strcpy(s1->grade, grade);
  s1->age = strtol(age, &endptr, 10);
  s1->num_courses = strtol(num_courses, &endptr, 10);
  
}

void printData(Student *s1) {
  
  printf("\n\nYour name is: %s", s1->name);
  printf("Your age is: %d", s1->age);
  printf("\nYour grade is: %s", s1->grade);
  printf("You are taking %d courses.\n\n", s1->num_courses);
  
}

int main() {
  
  Student s1;
  
  readData(&s1);
  
  printData(&s1);
  
  return(0);
}
