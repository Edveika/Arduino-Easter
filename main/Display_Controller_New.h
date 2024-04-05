/*
Hi everyone! Thanks for using my library! 
*/
#include <Arduino.h>


#ifndef DISPLAY_CONTROLLER_H
#define DISPLAY_CONTROLLER_H
//Choose which pin will control what
const int MB = A0;
const int MM = A1;
const int MT = A2;
const int RB = A3;
const int RT = A4;
const int LB = A5;
const int LT = 2;
const int DOT = 3;
const int DIG1 = 4;
const int DIG2 = 5;
const int DIG3 = 6;
const int DIG4 = 7;
//Create the two functions: one for writing one digit to an assigned place, and one for writing full numbers
void exeSetup();
void clearDisplay(int lasts);
void writeDig(int digit, int position);
void writeNum(int number, int lasts);


#endif
