#include <stdio.h>

/*
Name: Ari Chai
Course: CS125
Assignment: Midterm
Resources: Cheat Sheet
Date: 10/15/2025
*/

int profitCalc(int var1, int var2);
int profitClass(int var3);

int main() {
  int sellPrice, buyPrice;

  printf("\n\nEnter buy price: ");
  scanf("%d", &buyPrice);
  printf("\nEnter sell price: ");
  scanf("%d", &sellPrice);
  
  int prof = profitCalc(sellPrice, buyPrice);
  printf("\nProfit: %d", prof);
  
  if (profitClass(prof) == 1) {
    printf("\nClassification: High profit\n");
  }
  else if (profitClass(prof) == 2) {
    printf("\nClassification: Moderate profit\n");
  }
  else {
    printf("\nClassification: Loss\n");
  }
  
}

int profitCalc(int var1, int var2) {
  int profit;
  profit = var1 - var2 - (var1 * 0.02);
  return(profit);
}

int profitClass(int var3) {
  int var4 = 0;
  (var3 >= 10000) ? (var4 = 1) : (var4 = 0);
  (var3 < 10000 && var3 > 0) ? (var4 = 2) : (var4 = 3);
  return(var4);
}
