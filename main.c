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
#include <ctype.h>
#include <math.h>

bool checkBounds(int fracBits, int expBits, char hex[]);
void convert(int fracBits, int expBits, int hexNum);
void print(float frac, int exp, int signedBit, int bias, int expBits);

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
  bool valid = checkBounds(fracBits, expBits, argv[3]);
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
checkBounds(int fracBits, int expBits, char hex[]){
  
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

  //check if the hex number provided is a valid hex number
  for(int i = 0; hex[i] != '\0'; i++){
    if(isxdigit(hex[i]) == 0){
      printf("ERROR: Argument 3 is not a hexadecimal number (%s)\n", hex);
      printf("Quitting program.\n");
      return false;
    }
  }
  
  return true; //if none fired, then it is legal input
}

/* convert() takes in the three arguments (fraction bits,
   exponent bits, and the hexadecimal number) and converts
   it into an IEEE floating point number.
 */
void
convert(int fracBits, int expBits, int hexNum){
  int totalBits = fracBits + expBits;

  //check that there is the right amount of bits
  if(hexNum >> (totalBits + 1)){
    printf("Number %x exceeds maximum number of bits. Only %d allowed here.\n", hexNum, totalBits + 1);
    exit(1);
  }
  
  //calculate fraction bits
  float frac = hexNum & ((1 << fracBits) - 1);
  frac /= pow(2, fracBits);
  
  //calculate exponent bits
  int exp = (unsigned int) hexNum >> fracBits;
  exp = ((1 << expBits) -1) & exp;
  
  //calculate signed bit
  int signedBit = (unsigned int) hexNum >> totalBits;
  
  //calculate bias 2^(k-1) -1
  int bias = pow(2, expBits - 1) - 1;

  //call new function to print out result
  print(frac, exp, signedBit, bias, expBits);
}

/* print() takes in the fraction, exponent, signed bit,
   bias, and exponent bits to print out the result.
   Uses the formula (-1)^S * M * 2^E
 */
void print(float frac, int exp, int signedBit, int bias, int expBits){
  int E = 0;
  float M = 0;

  //denormalized:
  if(exp == 0){
    E = 1 - bias;
    M = frac;
  }

  //special values
  else if(exp == ((1 << expBits) - 1)){
    if(frac == 0){
      if(signedBit == 1){
	//negative infinity
	printf("-inf\n");
      } else {
	//positive infinity
	printf("+inf\n");
      }
    } else { //NaN
      printf("NaN\n");
    }
    return;
  }
 
  //normalized:
  else {
    E = exp - bias;
    M = 1 + frac;
  }

  //put into formula
  float ret = pow(-1, signedBit) * M * pow(2, E);
  printf("%f\n", ret);
}
