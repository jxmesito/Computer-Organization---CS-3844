#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char* hdr = "Hex  Dec  Oct   Ch\n";
	char* msg = "%3x  %3d  %3o   %c\n";
	/*
	puts(hdr);

	for (int i = 32; i <= 255; i++) {
		printf(msg, i, i, i, i);
	}

	*/
	_asm {
		mov edx, hdr // move hdr string into edx
		push edx // push edx onto stack
		call puts // call puts to print edx
		jmp l1 // jump to loop one
	l1:
		push ebp // save previous ebp
		mov ebp, esp // move stack pointer to bottom of stack
		sub esp, 4 // add one varible to the stack
		mov [ebp - 4], 20h // move 32 decimal or 20h hex to top of stack
		jmp l2 // jump to loop 2
	l2:
		mov edx, msg
		push edx
		mov [ebp -4], ecx // move contents of ebp-4 into ecx
		add ecx, 1 // increment counter by one
		call printf
		cmp ecx, 255 // compare to 255
		jne l2
	}
	system("pause");
}
