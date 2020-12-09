// These are simplified Roman numerals. Instead of IV for 4, we just use IIII. It is a little easier.
// No "subtractive notation", only "additive notation" in en.wikipedia.org/wiki/Roman_numerals
// All letters must be in order M-D-C-L-X-V-I. Up to four each M-C-X-I and up to one D-L-V.
// MMDCXVIII is 2,618 (2000 + 500 + 100 + 10 + 5 + 3)
// XXIIII is 24, L is 50, MI is 1001. All numbers are positive.
// MMMMDCCCCLXXXXVIIII is the largest and longest, 4,999. Whew.

// No error checking is needed. Assume all UPPERCASE letters. Assume all input is valid.

// All input is on the command line. Do not prompt for values.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char source[100];

int main(int argc, char *argv[]) {
	int i;
	for (i = 1; i < argc; i++) {
		strcpy_s(source, 99, argv[i]);
		__asm {

				mov n, 0 // clear for loop so n wont have previous data
				mov eax, n // move value into eax
				mov ebx, 0
				mov ecx, 0
				lea esi, source // load address of source into esi
			
			l1:
				// base cases
				cmp ebx, 0
				je M
				cmp ebx, 1
				je D
				cmp ebx, 2
				je C
				cmp ebx, 3
				je L
				cmp ebx, 4
				je X
				cmp ebx, 5
				je V
				cmp ebx, 6
				je I
				cmp ebx, 7
				jge done

			M :
				push eax
				push ebx
				// move letter into bl and cmp to esi+ecx
				mov bl, 'M'
				cmp bl, byte ptr[esi + ecx]
				// push to stack
				pop ebx
				pop eax
				// if M is not equal to esi+ value of letter
				// increment ebx
				jne count
				// add corresponding value
				add eax, 1000
				// increment ecx
				inc ecx
				// move to next letter
				jmp l1

			D :
				push eax
				push ebx
				mov bl, 'D'
				cmp bl, byte ptr[esi + ecx]
				pop ebx
				pop eax
				jne count
				add eax, 500
				inc ecx
				jmp l1
			C :
				push eax
				push ebx
				mov bl, 'C'
				cmp bl, byte ptr[esi + ecx]
				pop ebx
				pop eax
				jne count
				add eax, 100
				inc ecx
				jmp l1
			L :
				push eax
				push ebx
				mov bl, 'L'
				cmp bl, byte ptr[esi + ecx]
				pop ebx
				pop eax
				jne count
				add eax, 50
				inc ecx
				jmp l1
			X :
				push eax
				push ebx
				mov bl, 'X'
				cmp bl, byte ptr[esi + ecx]
				pop ebx
				pop eax
				jne count
				add eax, 10
				inc ecx
				jmp l1
			V :
				push eax
				push ebx
				mov bl, 'V'
				cmp bl, byte ptr[esi + ecx]
				pop ebx
				pop eax
				jne count
				add eax, 5
				inc ecx
				jmp l1
			I :
				push eax
				push ebx
				mov bl, 'I'
				cmp bl, byte ptr[esi + ecx]
				pop ebx
				pop eax
				jne count
				add eax, 1
				inc ecx
				jmp l1

			count :
				inc ebx
				jmp l1

			done :
				mov n, eax
		}
			// TBD -- Convert 'source' to 'n'
			// Hints:
			// 1. Use 4 registers as follows:
			//    EAX = number so far (200, e.g.), ends up in n
			//    EBX = The letter to check for ('X', e.g.)
			//    ECX = The value of the letter (10, e.g.)
			//    ESI = Where to look in source
			// 2. Call an assembly function for each letter in this order
			//    1000 (M) call this 4 times
			//    500 (D) call this once
			//    100 (C) call this 4 times
			//    50 (L) call this once
			//    10 (X) call this 4 times
			//    5 (V) call this once
			//    1 (I) call this 4 times
			// 3. If you do match a letter, add its count to EAX
		printf("%s -> %d\n", source, n);
	}
	system("pause");
}