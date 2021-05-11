/* Author: Allison Delgadp
   Class: CS 201 - Spring 2021
   This program implements an IEEE floating point parser
   for an arbitrary number of bit settings.
   
   Last updated: May 10, 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool checkBounds(int fracBits, int expBits);
void convert(int fracBits, int expBits, int hexNum);

int
main(int argc, char* argv[]){
  int fracBits = 0;
  int expBits = 0;
  int hexNum = 0;

  //program takes in 3 arguments and an a.out = 4 arguments  
  if(argc != 4){
    printf("ERROR: you didn't enter the right amount of arguments.\n");
    printf("Here are the three arguments: \n"); 
    printf("1. number of fraction bits (between 2 and 10)\n");
    printf("2. number of exponent bits (between 3 and 5)\n");
    printf("3. the hexadecimal representation of your number.\n");
    printf("Quitting program.\n");
    exit(1);
  }

  //scan in arguments
  sscanf(argv[1], "%d", &fracBits);
  sscanf(argv[2], "%d", &expBits);
  sscanf(argv[3], "%x", &hexNum);
  
  //check validity
  bool valid = checkBounds(fracBits, expBits);
  if(valid == false){
    exit(1);
  }

  //call function to convert to float
  convert(fracBits, expBits, hexNum);
  
  return 0;
}

/* checkBounds() takes in the arguments
   in order to check validity.
   Returns true if valid, false if invalid.
 */
bool
checkBounds(int fracBits, int expBits){

  //bound checking fraction bits:
  if(fracBits < 2 || fracBits > 10){ 
    printf("ERROR: The first argument should be between 2 and 10.\n");
    printf("Quitting program.\n");
    return false;
  }

  //bound checking exponent bits:
  if(expBits < 3 || expBits > 5){
    printf("ERROR: The second argument should be between 3 and 5.\n");
    printf("Quitting program.\n");
    return false;
  }
  
  return true; //if none fired, then it is legal input
}

/* convert() takes in the three arguments (fraction bits,
   exponent bits, and the hexadecimal number) and converts
   it into an IEEE floating point number.
 */
void
convert(int fracBits, int expBits, int hexNum){
  
  
}
