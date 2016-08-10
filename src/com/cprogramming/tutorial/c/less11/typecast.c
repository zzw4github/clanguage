#include <stdio.h> 

int main()       
{
  /* The (char) is a typecast, telling the computer to interpret the 65 as a
     character, not as a number.  It is going to give the character output of 
     the equivalent of the number 65 (It should be the letter A for ASCII).
     Note that the %c below is the format code for printing a single character
   */
  printf( "%c\n", (char)65 );
  getchar();
}