// Lab4.cpp
//
// This program will be used for Lab#4
//

#include <windows.h>
#include <stdio.h>
#include "Secret.h"

extern char gSecret[];

bool searchString(char *string2Search, char *searchWord, WORD wordLength)
{
	bool result = false;

	__asm
	{
		xor eax,eax
		mov esi,searchWord
		test esi,esi
		je NOT_FOUND

		mov edi,string2Search
		test edi,edi
		je NOT_FOUND

		mov al, byte ptr [esi]
		test al,al
		je NOT_FOUND

MAIN_LOOP:
		mov al,byte ptr [edi]
		test al,al
		je NOT_FOUND

		mov bl,byte ptr [esi]
		cmp al,bl
		jne NEXT_CHAR

		call CHECK_THE_WORD
		test al,al
		jne FOUND

NEXT_CHAR:
		inc edi
		jmp MAIN_LOOP

FOUND:
		mov al,1
		jmp EXIT_FUNC

NOT_FOUND:
		xor al,al

EXIT_FUNC:
		mov result,al
		jmp DONE

///////////////////////////////////////////////////
CHECK_THE_WORD:
		push edi
		push esi

		mov cx,wordLength
		movzx ecx,cx
		mov al,1
		dec ecx
		je EXIT_CHECK_THE_WORD

WORD_CHECK:
		inc esi
		inc edi
		mov al,[edi]
		mov bl,[esi]
		cmp al,bl
		jne NO_MATCH

		dec ecx
		jne WORD_CHECK

		mov al,1
		jmp EXIT_CHECK_THE_WORD

NO_MATCH:
		xor al,al

EXIT_CHECK_THE_WORD:
		pop esi
		pop edi
		ret
	}
DONE:
	return result;
} // searchString

// this program allows the user to enter characters to search for
// in an effort to guess the secret string
int main(int argc, char *argv[])
{
	bool stringCompareResult;
	int wordLength;

	if(argc != 2)
	{
		printf("\n\nEnter the program name followed by a string to help you guess the secret string.\n\n");
		printf("Hint: Computer vs. Human in a game, who won?\n");
		printf("Hint: Mike Tyson player soccer.\n");
		printf("%s <your string, no spaces>\n\n", argv[0]);
		system("pause");
		exit(-1);
	}

	wordLength = strlen(argv[1]);

	stringCompareResult = searchString(gSecret, argv[1], wordLength);	// this length is arbitrary

	if(stringCompareResult)
		printf("Success! The string \"%s\" is in the string!\n\n", argv[1]);
	else
		printf("Failure - your string \"%s\" was not found.\n\n", argv[1]);

	system("pause");
	return 0;
} // main