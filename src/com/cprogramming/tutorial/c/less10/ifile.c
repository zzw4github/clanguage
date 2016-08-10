#include <stdio.h>
/*
FILE *fp;
FILT *fopen(const char *filename, const char *mode)
  r - open for reading
  w - open for writing (file need not exist)
  a - open for appending (file need not exist)
  r+- open for reading and writing , starting at beginning
  w+- open for reading and writing  (overwrite file)
  a+- open for reading and writing (append if file exists)
FILE *fp;
fp = fopen("c:\\test.txt", "r");

int fclose(FILE *a_file)
fclose(fp)

Reading and writing with fprintf, fscanf fputc, and fgetc
FILE *fp;
fp = fopen("c:\\test.txt", "w");
fprintf(fp, "Testing...\n");

int fgetc( FILE *fp);
int fputc( int c, FILE *fp );

Binary file I/O - fread and fwrite
suze_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);         
size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
*/
int main() {
	FILE *fp;
	fp = fopen("d:\\test.bin", "wb");
	char x[10] = "ABCDEFGHIJ";
	fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[10]), fp);
}