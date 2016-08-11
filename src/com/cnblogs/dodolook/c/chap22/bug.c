#include "stdio.h"
#include <string.h>

void main()
{
   char szPawd[16] ="dodolook";
   char szIn[16];
   int i =3;

   while(i--)
   {
      scanf("%s", szIn);

      if (strcmp(szIn, szPawd) ==0)
      {
         printf("success\r\n");
         break;
      } 
      else
      {
         printf("fail\r\n");
      }
   }
   
}