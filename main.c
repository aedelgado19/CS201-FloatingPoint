/* Author: Allison Delgadp
   Class: CS 201 - Spring 2021
   This program implements an IEEE floating point parser
   for an arbitrary number of bit settings.
   
   Last updated: May 9, 2021
 */
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char* argv[]){
  //program takes in 3 arguments and an a.out = 4 arguments
  if(argc != 4){
    printf("ERROR: you didn't enter the right amount of arguments.\n");
    printf("Here are the three arguments: \n"); 
    printf("1. number of fraction bits (between 2 and 10)\n");
    printf("2. number of exponent bits (between 3 and 5)\n");
    printf("3. the hexadecimal representation of your number.\n");
    exit(1);
  }

}
