#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile(FILE * fPtr);

int main (int argc, char *argv[]) 
{
	
	if(argc != 2) {
		printf("Expecting only 1 string!");
		return 0;
	}
	
	
	char tag1[] = "**to_build";
	char tag2[] = "**to_learn";
	char tag3[] = "**to_add";
	char tag4[] = "**to_do";

	char *ptr1 =  strstr(argv[1], tag1);
	char *ptr2 = strstr(argv[1], tag2);
	char *ptr3 = strstr(argv[1], tag3);
	char *ptr4 = strstr(argv[1], tag4);


	if(ptr1 == NULL && ptr2 == NULL) {
		printf("You forgot to add a valid tag.\n");
		printf("Valid tags are ...\n**to_learn -> things to learn\n");
		printf("**to_add -> things to add\n**to_do -> things to do\n");
		printf("**to_make -> project ideas");
		return 0;
	}


	FILE *fPtr;
	char *homedir = getenv("HOME");
	char *filePath = "/life/docs/braindump.md";
	char *fullPath = strcat(homedir, filePath);

	fPtr = fopen(fullPath, "a");

	if (fPtr == NULL)
	{
		printf("Can't open %s file", filePath);
		exit(EXIT_FAILURE);
	}


	fputs(argv[1], fPtr);


	return 0;
}
