#include<stdio.h>
int * GetDate(int wk,int dy);  
main()  
{  
   int wk,dy;  
   do  
   {  
      printf("Enter week(1-5)day(1-7)\n");  
      scanf("%d%d",&wk,&dy);  
   }  
   while(wk<1||wk>5||dy<1||dy>7);  
   printf("%d\n",*GetDate(wk,dy));  
}  
  
int * GetDate(int wk,int dy)  
{  
   static int calendar[5][7]=  
   {  
     {1,2,3,4,5,6,7},  
     {8,9,10,11,12,13,14},  
     {15,16,17,18,19,20,21},  
     {22,23,24,25,26,27,28},  
     {29,30,31,-1}  
   };  
   return &calendar[wk-1][dy-1];  
}  