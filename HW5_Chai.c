#include <stdio.h>
#include <stdlib.h>

/*
Name: Ari Chai
Date: 09/28/2025
Course: CS125
Assignment: Homework 5: HW3 Remastered
References: Course Material, GeeksForGeeks strtol() and strtof() 
documentation and Type Conversion article
*/

void errorHandle(float* var, char tempVar[40], char* endptr, int lowBound, int uppBound) {
  if (lowBound != 0) {
    while (*var==0 || *var < lowBound) {
      printf("Invalid input. Please try again. ");
      scanf("%s", tempVar);
      *var = strtof(tempVar, &endptr);
    }
  }
  else if (uppBound != 0) {
    while (*var==0 || *var > uppBound) {
      printf("Invalid input. Please try again. ");
      scanf("%s", tempVar);
      *var = strtof(tempVar, &endptr);
    }
  }
  else {
    while (*var==0) {
      printf("Invalid input. Please try again. ");
      scanf("%s", tempVar);
      *var = strtof(tempVar, &endptr);
    }
  }
}

void collectInput(float* var, char tempVar[40], char* endptr, int lowBound, int uppBound) {
  scanf("%s", tempVar);
  *var = strtof(tempVar, &endptr);
  errorHandle(var, tempVar, endptr, lowBound, uppBound);
}

int main() {

  //Collect user input
  char idNum1[40], empType1[40], payChoice1[40], hours1[40], payRate1[40], tempVar[40], valUpdate1[40];
  char* endptr;
  int lowBound, uppBound;
  float hours, payRate, var, idNum, empType, payChoice, valUpdate;

  printf("\nEnter the number of hours worked: ");
  collectInput(&hours, hours1, endptr, 0,0);

  printf("\nEnter your employee ID: ");
  collectInput(&idNum, idNum1, endptr, 1000,1000000);
 
  printf("\nEnter your hourly rate: ");
  collectInput(&payRate, payRate1, endptr, 0,100);
  
  printf("\nAre you an hourly [1] or salaried [2] employee? ");
  collectInput(&empType, empType1, endptr, 0,2);
  
  
  //Summary
  int flag = 0;
  if (hours > 60 && empType == 1) {
    flag = 1;
    hours = 60;
  }
  
  printf("\nGreetings, employee number %d.", (int)idNum);
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
        collectInput(&payChoice, payChoice1, endptr, 0, 2);
      
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
        collectInput(&valUpdate, valUpdate1, endptr, 1, 3);
        
        if (valUpdate == 1) {
          printf("\nEnter the number of hours worked: ");
          collectInput(&hours, hours1, endptr, 0, 0);
          printf("\nHours worked has been successfully updated to %.2f hours.", hours);
        }
        else if (valUpdate == 2) {
          printf("\nEnter your hourly rate: ");
          collectInput(&payRate, payRate1, endptr, 0, 100);
          printf("\nHourly rate has been successfully updated to $%.2f per hour.", payRate);
        }
        else if (valUpdate == 3) {
          printf("\nAre you an hourly [1] or salaried [2] employee? ");
          collectInput(&empType, empType1, endptr, 0, 2);
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
        
        printf("\nGreetings, employee number %d.", (int)idNum);
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