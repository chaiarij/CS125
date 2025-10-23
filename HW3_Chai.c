#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Name: Ari Chai
Date: 09/13/2025
Course: CS125
Assignment: Homework 3: Hours Worked Calculator
References: Course Material 
*/

int main() {

  //Collect user input
  char idNum1[40], empType1[40], payChoice1[40], hours1[40], payRate1[40];
  char* endptr;
  int idNum, empType, payChoice;
  float hours, payRate;
  char valUpdate1[40];
  int valUpdate;
  

  printf("\nEnter the number of hours worked: ");
  scanf("%s", &hours1);
  hours = strtof(hours1, &endptr);
  while (hours == 0) {
    printf("Invalid input.\nEnter the number of hours worked: ");
    scanf("%s", &hours1);
    hours = strtof(hours1, &endptr);
  }

  printf("\nEnter your employee ID: ");
  scanf("%s", &idNum1);
  idNum = strtol(idNum1, &endptr, 10);
  while (idNum < 1000 || idNum > 1000000) {
    printf("Invalid input.\nEnter your employee ID: ");
    scanf("%s", &idNum1);
    idNum = strtol(idNum1, &endptr, 10);
  }
  
  printf("\nEnter your hourly rate: ");
  scanf("%s", &payRate1);
  payRate = strtof(payRate1, &endptr);
  while (payRate == 0 || payRate > 100) {
    printf("Invalid input.\nEnter your hourly rate: ");
    scanf("%s", &payRate1);
    payRate = strtof(payRate1, &endptr);
  }
  
  printf("\nAre you an hourly [1] or salaried [2] employee? ");
  scanf("%s", &empType1);
  empType = strtol(empType1, &endptr, 10);
  while (empType == 0 || empType > 2) {
    printf("Invalid input.\nAre you an hourly [1] or salaried [2] employee? ");
    scanf("%s", &empType1);
    empType = strtol(empType1, &endptr, 10);
  }
  
  
  //Summary
  int flag = 0;
  if (hours > 60 && empType == 1) {
    flag = 1;
    hours = 60;
  }
  
  printf("\nGreetings, employee number %d.", idNum);
  if (empType == 1) {
    printf("\nYou are an hourly employee.");
  }
  else if (empType == 2) {
    printf("\nYou are a salaried employee.");
  }
  printf("\nYou've worked %.2f hours at $%.2f per hour.", hours, payRate);
  if (flag == 1) {
    printf("\nHours have been automatically rounded down to 60.");
    printf("\nPlease talk to your manager about your hours.");
  }
  else {
    printf("\nYou're all good! No need to talk to your manager.");
  }
  
  sleep(3);
    
    
  //User Queries
  
  char menuChoice1[40];
  int menuChoice = 1;
  
  while (menuChoice<5) {
    
    printf("\n\nSelect what you'd like to do: \n");
    printf("  1 - Check current pay\n");
    printf("  2 - Update values\n");
    printf("  3 - Check manager status\n");
    printf("  4 - Show summary again\n");
    printf("  5 - Exit menu\n");
    scanf("%s", &menuChoice1);
    menuChoice = strtol(menuChoice1, &endptr, 10);
    while (menuChoice == 0 || menuChoice>5) {
      printf("Invalid input. \n Please enter 1, 2, 3, 4, or 5: ");
      scanf("%s", &menuChoice1);
      menuChoice = strtol(menuChoice1, &endptr, 10);
    }
  
    switch (menuChoice) {
  
      case 1:
        printf("\nWould you like your exact pay [1] or rounded down? [2] ");
        scanf("%s", &payChoice1);
        payChoice = strtol(payChoice1, &endptr, 10);
        while (payChoice == 0 || payChoice > 2) {
          printf("\nInvalid input.\nWould you like your exact pay [1] or rounded down? [2] ");
          scanf("%s", &payChoice1);
          payChoice = strtol(payChoice1, &endptr, 10);
        }
      
        float currentPay = hours * payRate;
        int currentPay2 = currentPay;
        
        if (empType == 2 && hours > 40) {
          currentPay = 40 * payRate;
          currentPay2 = currentPay;
        }
        else if (empType == 1 && hours>60) {
          currentPay = 60 * payRate;
          currentPay2 = currentPay;
        }
      
        if (payChoice == 1) {
          printf("\nYour exact pay for working %.2f hours at $%.2f per hour is: $%.2f ", hours, payRate, currentPay);
        }
        else if (payChoice == 2) {
          printf("\nYour rounded pay for working %.2f hours at $%.2f per hour is: $%d ", hours, payRate, currentPay2);
        }
      
        break;
      
      case 2:
        printf("\nWhich value would you like to update? \n");
        printf("  1 - Hours worked\n");
        printf("  2 - Hourly rate\n");
        printf("  3 - Employee type\n");
        scanf("%s", valUpdate1);
        valUpdate = strtol(valUpdate1, &endptr, 10);
        while (valUpdate<1 || valUpdate>3) {
          printf("Invalid input. Please enter 1, 2, or 3: ");
          scanf("%s", &valUpdate1);
          valUpdate = strtol(valUpdate1, &endptr, 10);
        }
        
        if (valUpdate == 1) {
          printf("\nEnter the number of hours worked: ");
          scanf("%s", &hours1);
          hours = strtof(hours1, &endptr);
          while (hours == 0) {
              printf("Invalid input.\nEnter the number of hours worked: ");
              scanf("%s", &hours1);
              hours = strtof(hours1, &endptr);
          }
          printf("\nHours worked has been successfully updated to %.2f hours.", hours);
        }
        else if (valUpdate == 2) {
          printf("\nEnter your hourly rate: ");
          scanf("%s", &payRate1);
          payRate = strtof(payRate1, &endptr);
          while (payRate == 0 || payRate > 100) {
              printf("Invalid input.\nEnter your hourly rate: ");
              scanf("%s", &payRate1);
              payRate = strtof(payRate1, &endptr);
          }
          printf("\nHourly rate has been successfully updated to $%.2f per hour.", payRate);
        }
        else if (valUpdate == 3) {
          printf("\nAre you an hourly [1] or salaried [2] employee? ");
          scanf("%s", &empType1);
          empType = strtol(empType1, &endptr, 10);
          while (empType == 0 || empType > 2) {
              printf("Invalid input.\nAre you an hourly [1] or salaried [2] employee? ");
              scanf("%s", &empType1);
              empType = strtol(empType1, &endptr, 10);
          }
          printf("Employee type has been successfully updated.");
        }
        
        break;
      
      case 3: 
        flag = 0;
        if (hours > 60 && empType == 1) {
          flag = 1;
        }
        
        (flag == 1) ? (printf("You've worked over 60 hours. Please talk to your manager.", hours))
        : (printf("You're all good, no need to talk to your manager."));
        break;
        
      case 4:
        if (hours > 60 && empType == 1) {
          flag = 1;
          hours = 60;
        }
        
        printf("\nGreetings, employee number %d.", idNum);
        if (empType == 1) {
          printf("\nYou are an hourly employee.");
        }
        else if (empType == 2) {
          printf("\nYou are a salaried employee.");
        }
        printf("\nYou've worked %.2f hours at $%.2f per hour.", hours, payRate);
        if (flag == 1) {
          printf("\nHours have been automatically rounded down to 60.");
          printf("\nPlease talk to your manager");
        }
        else {
          printf("\nYou're all good! No need to talk to your manager.");
        }
        
        break;
        
      case 5: 
        printf("\nThanks for using the Hours Worked Calculator.\n\n");
        return 0;
        
        
        
    } //End switch statement
    
  } //End menu while loop

} //End main()