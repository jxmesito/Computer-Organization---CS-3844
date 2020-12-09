// These are simplified Roman numerals. Instead of IV for 4, we just use IIII. It is a little easier.
// No "subtractive notation", only "additive notation" in en.wikipedia.org/wiki/Roman_numerals
// All letters must be in order M-D-C-L-X-V-I. Up to four each M-C-X-I and up to one D-L-V.
// 2,618 would be MMDCXVIII (2000 + 500 + 100 + 10 + 5 + 3)
// 24 is XXIIII, 50 is just L, 1001 is MI, and so on. All numbers are positive.
// 4,999 is the largest and longest, MMMMDCCCCLXXXXVIIII. Whew.



// All input is on the command line. Do not prompt for values.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char result[100];



int main(int argc, char *argv[]) {
	int i;
	for (i = 1; i < argc; i++) {
		n = atoi(argv[i]);
		if (n > 0 && n < 5000) {
			__asm {
					mov eax, n // value of n
					mov edi, 0 // offset of our roman value
					mov ecx, 0 // current roman digit

				l1:
					cmp eax, 0
					jle done
					cmp ecx, 7
					jge done

					cmp ecx, 6
					je I
					cmp ecx, 5
					je V
					cmp ecx, 4
					je X
					cmp ecx, 3
					je L
					cmp ecx, 2
					je C
					cmp ecx, 1
					je D
					cmp ecx, 0
					je M

				M :
					push eax
					push ebx
					mov ebx, 1000
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'M'
					mov byte ptr[result + edi], dl
					inc edi
					mov edx, 1000
					sub eax, edx // subtract what value we used minus current value
					jmp l1
				D :
					push eax
					push ebx
					mov ebx, 500
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'D'
					mov byte ptr[result+edi], dl
					inc edi
					mov edx, 500
					sub eax, edx // subtract what value we used minus current value
					jmp l1
				C :
					push eax
					push ebx
					mov ebx, 100
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'C'
					mov byte ptr[result + edi], dl
					inc edi
					mov edx, 100
					sub eax, edx // subtract what value we used minus current value
					jmp l1
				L :
					push eax
					push ebx
					mov ebx, 50
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'L'
					mov byte ptr[result + edi], dl
					inc edi
					mov edx, 50
					sub eax, edx // subtract what value we used minus current value
					jmp l1
				X :
					push eax
					push ebx
					mov ebx, 10
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'X'
					mov byte ptr[result + edi], dl
					inc edi
					mov edx, 10
					sub eax, edx // subtract what value we used minus current value
					jmp l1
				V :
					push eax
					push ebx
					mov ebx, 5
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'V'
					mov byte ptr[result + edi], dl
					inc edi
					mov edx, 5
					sub eax, edx // subtract what value we used minus current value
					jmp l1
				I :
					push eax
					push ebx
					mov ebx, 1
					cdq
					div ebx
					cmp eax, 1
					pop ebx
					pop eax
					jl count
					mov edx, 0
					mov dl, 'I'
					mov byte ptr[result + edi], dl
					inc edi
					mov edx, 1
					sub eax, edx // subtract what value we used minus current value
					jmp l1

				count :
					inc ecx
					jmp l1

				done :
					// does nothing
			}
			printf("Roman(%d) = %s\n", n, result);
		}
	}
	system("pause");
}
