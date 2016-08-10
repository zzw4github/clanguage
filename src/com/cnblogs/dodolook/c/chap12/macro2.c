#include <stdio.h>

#define IF(r) if (r)
#define THEN {
#define ELSE }else{
#define ENDIF }

#define PRINT(S) printf(S);

#define DIM
#define INT int

int main(){
	DIM INT a = 6;
	IF(a%2 == 0) THEN
	PRINT ("even\n")
	ELSE
	PRINT("odd\n")
	ENDIF
}