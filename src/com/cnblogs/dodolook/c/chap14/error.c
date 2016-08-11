#include <stdio.h>

int main()
{
	char szMsg[] = "hello";
	char *pszMsg = "Hello";

	szMsg[3] = 'L';
	pszMsg[3] = 'L';

	printf("szMsg: %s, pszMsg: %s \n", szMsg, pszMsg );
	printf("szMsg: %d, pszMsg: %d \n", sizeof(szMsg), sizeof(pszMsg));
	// system("pause");
}