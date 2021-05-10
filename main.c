/* Author: Allison Delgadp
   Class: CS 201 - Spring 2021
   This program implements an IEEE floating point parser
   for an arbitrary number of bit settings.
   
   Last updated: May 9, 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkBounds(int amount, int fracBits, int expBits);

int
main(int argc, char* argv[]){
  
  //save as a long
  int fracBits = (int) strtol(argv[1], NULL, 0);
  int expBits = (int) strtol(argv[2], NULL, 0);
  
  bool valid = checkBounds(argc, fracBits, expBits);
  if(valid == false){
    exit(1);
  }

  
  return 0;
}


/* checkBounds takes in the amount of arguments
   and the arguments in order to check validity.
   Returns true if valid, false if invalid.
 */
bool
checkBounds(int amount, int fracBits, int expBits){
  //program takes in 3 arguments and an a.out = 4 arguments  
  if(amount != 4){
    printf("ERROR: you didn't enter the right amount of arguments.\n");
    printf("Here are the three arguments: \n"); 
    printf("1. number of fraction bits (between 2 and 10)\n");
    printf("2. number of exponent bits (between 3 and 5)\n");
    printf("3. the hexadecimal representation of your number.\n");
    return false;
  }

  //bound checking fraction bits:
  if(fracBits < 2 || fracBits > 10){ 
    printf("The first argument should be between 2 and 10.\n");
    printf("Quitting program.\n");
    return false;
  }

  //bound checking exponent bits:
  if(expBits < 3 || expBits > 5){
    printf("The second argument should be between 3 and 5.\n");
    printf("Quitting program.\n");
    return false;
  }
  
  return true; //if none fired, then it is legal input
}

