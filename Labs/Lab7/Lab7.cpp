// Lab7.cpp
//
// This program is used for lab #7
//

#include <windows.h>
#include <stdio.h>

#define STRLEN_TEST

char n[] = "Exams are fun!";
char q[] = "  But this lab sux!";

int FUNC1_Solution(char *par1, int *par2);
int FUNC2_Solution(char *par1, int *par2);

// scans a string for the NULL terminator, returns length in par2
// This function MUST make use of some string instructions
int FUNC2_Student(char *par1, int *par2)
{
	__asm
	{
	}

	return 0;
} // FUNC2_Student

// scans a string for the NULL terminator, returns length in par2
int FUNC1_Student(char *par1, int *par2)
{
	__asm
	{
	}

	return 0;
} // FUNC1

int FUNC0(DWORD *funcAddress)
{
	int len = 0;

	__asm
	{
		lea ecx, len		// pushing address of len, in C would be func( &len );
		push ecx
		lea ecx, n			// pushing address of n, a global array
		push ecx
		call funcAddress
		add esp,8

#ifdef STRLEN_TEST
		mov len,eax		// strlen returns length in eax, FUNC1/FUNC2 return it in the parameter
#endif
	}

	printf("FUNC: Length = %d\n", len);
	return len;
} // FUNC0


int main(int argc, char *argv[])
{
	char *ptrNewString;
	int phraseLength;

#ifdef STRLEN_TEST

	phraseLength = FUNC0( (DWORD *)  strlen );

#else

//	phraseLength = FUNC0( (DWORD *) FUNC1_Solution);	// I'll provide these later

//	phraseLength = FUNC0( (DWORD *) FUNC2_Solution);

//	phraseLength = FUNC0( (DWORD *) FUNC1_Student);

//	phraseLength = FUNC0( (DWORD *) FUNC2_Student);

#endif

	// this section allocates 1024 bytes to concatenate the two strings
	ptrNewString = (char *) malloc(1024);
	if(ptrNewString == NULL)
	{
		printf("Error - Could not allocate 1024 bytes.\n\n");
		exit(-1);
	}

	__asm
	{
		mov edi,ptrNewString
		lea esi,n
		xor ah,ah

REPEAT_OP:
		lodsb
		stosb
		test al,al
		jne REPEAT_OP;

		test ah,ah
		jne END_OP;

		inc ah
		lea esi,q
		dec edi
		jmp REPEAT_OP;

END_OP:
		nop
	}

	printf("NewString: %s\n", ptrNewString);
	return 0;
} // main