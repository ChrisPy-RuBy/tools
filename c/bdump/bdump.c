#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
	char tag5[] = "**to_note";

	char *ptr1 = strstr(argv[1], tag1);
	char *ptr2 = strstr(argv[1], tag2);
	char *ptr3 = strstr(argv[1], tag3);
	char *ptr4 = strstr(argv[1], tag4);
	char *ptr5 = strstr(argv[1], tag5);


	if(ptr1 == NULL && 
	   ptr2 == NULL &&
	   ptr3 == NULL &&
	   ptr4 == NULL &&
	   ptr5 == NULL) {
		printf("You forgot to add a valid tag.\n");
		printf("Valid tags are ...\n**to_learn -> things to learn\n");
		printf("**to_add -> things to add\n**to_do -> things to do\n");
		printf("**to_make -> project ideas");
		return 0;
	}

	// generate date to prepend to note
	char s[1000];

	time_t t = time(NULL);
	struct tm * p = localtime(&t);

	strftime(s, 1000, "%F %r", p);
	printf("%s\n", s);
	char *withspace = strcat(s, " ");
	char *payload = strcat(withspace, argv[1]);
	char *withnewline = strcat(payload, "\n");

	FILE *fPtr;
	char *homedir = getenv("HOME");
	char homedirforlife[100];
	char homedirforscripts[100];
    strcpy(homedirforlife, homedir);
    strcpy(homedirforscripts, homedir);
	char *filePath = "/life/docs/braindump.md";
	char *fullPath = strcat(homedirforlife, filePath);

	fPtr = fopen(fullPath, "a");

	if (fPtr == NULL)
	{
		printf("Can't open %s file", filePath);
		exit(EXIT_FAILURE);
	}

	fputs(payload, fPtr);
	
	char *command = strcat(homedirforscripts, "/tools/c/bdump/updatethings ");
	char *part1command = strcat(command, "\"");
	char *part2command = strcat(part1command, argv[1]);
	char *fullcommand = strcat(part2command, "\"");

	system(fullcommand);
	return 0;
}
