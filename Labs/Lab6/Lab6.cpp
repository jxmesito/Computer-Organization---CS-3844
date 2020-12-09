// Lab6.cpp
//
// This file is used for Lab #6
//

#include <windows.h>
#include <stdio.h>

int printArgV(int argc, char* argv[], char* msg)
{
	int x;

	if (argc == 0)
	{
		printf("%s", msg);
		return -17;
	}

	printf("Argument #%d:\n%p: ", argc, &argv[argc]);

	for (x = 0; x <= (int)strlen(argv[argc]); x++)	// print the hex characters including the terminating NULL
		printf("%02X ", *(argv[argc] + x));

	printf("  %s\n\n", argv[argc]);

	printArgV(argc - 1, argv, msg);

	return true;
} // printArgV

int main(int argc, char* argv[])
{
	int myArgC, resulti;

	myArgC = argc - 1;

	printf("There are %d arguments to this program.\n\n", argc);

	resulti = printArgV(myArgC, argv, "You have reached the goal!\n\n");

	return 0;
} // main