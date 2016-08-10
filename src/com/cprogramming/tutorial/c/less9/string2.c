#include <stdio.h>
#include <string.h>

/*
this function is designed to remove the newline from the end of a string
entered using fegets. Nose that since we make this into its own function, we
could easily choose a better technique for romoving the newline. Aren't functions great?
*/

void strip_newline( char *str, int size) {
	int i;
	/* remove the null terminator */
	for ( i = 0; i < size; ++i){
		if ( str[i] == '\n') {
			str[i] = '\0';
			/* we're done, so just exit the function by returning */
			return;
		}
	}
	/* if we get all the way to here, there must not have beean a newline */
}

int main() {
	char name[50];
	char lastname[50];
	char fullname[100]; /* big enough to hold both name and lastname */

	printf("please enter your name: ");
	fgets( name, 50, stdin );

	/* see definition above */
	strip_newline(name, 50);

	/* strcmp returns zero when the two strings are equal */
	if ( strcmp (name, "Alex" ) == 0) {
		printf("that's my name too.\n");
	}else{
        printf( "That's not my name.\n" );
    }

    // Finde the length of you name
    printf("Your name is %d letters long ",(int)strlen(name));
    printf(" \nEnter your lastname: ");
    fgets(lastname, 50, stdin);
    strip_newline(lastname, 50);
    fullname[0] = '\0';
    /* strcat will look for the \0 and add the second string starting at
    thar location */
     strcat(fullname, lastname);
     strcat(fullname, " ");
    strcat(fullname, name);
    
   
    printf("Your full name is %s\n", fullname);

    getchar();
    return 0;
}

/*
Safe Programming

The above string functions all rely on the existence of a null terminator at the end of a string. 
This isn't always a safe bet. Moreover, some of them, noticeably strcat, rely on the fact that 
the destination string can hold the entire string being appended onto the end. 
Although it might seem like you'll never make that sort of mistake, historically, 
problems based on accidentally writing off the end of an array in a function like strcat, 
have been a major problem. 

Fortunately, in their infinite wisdom, the designers of C have included functions designed to 
help you avoid these issues. Similar to the way that fgets takes the maximum number of characters 
that fit into the buffer, there are string functions that take an additional argument to 
indicate the length of the destination buffer. 
For instance, the strcpy function has an analogous strncpy function
char *strncpy ( char *dest, const char *src, size_t len );
which will only copy len bytes from src to dest 
(len should be less than the size of dest or the write could still go beyond the bounds of the array). 
Unfortunately, strncpy can lead to one niggling issue: it doesn't guarantee that 
dest will have a null terminator attached to it 
(this might happen if the string src is longer than dest). 
You can avoid this problem by using strlen to get the length of src and 
make sure it will fit in dest. Of course, if you were going to do that, 
then you probably don't need strncpy in the first place, right? Wrong. 
Now it forces you to pay attention to this issue, which is a big part of the battle. 
*/