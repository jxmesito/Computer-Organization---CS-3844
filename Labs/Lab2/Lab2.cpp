// Lab2.cpp
//
// This file contains Lab#2 for CS3844
//

#include <Windows.h>
#include <stdio.h>

// main function for Lab #2
// This lab will illustrate the use of registers by doing a simple add
// 
int main(int argc, char *argv[])
{
	unsigned char ux, uy, usum;
	char sx, sy, ssum;
	unsigned int usum32 = 0;
	int ssum32 = 0;

	ux = -5;  uy = 240;
	sx = ux;  sy = uy;

	__asm 
	{
		xor eax,eax	// zero the registers
		xor ebx,ebx

		mov al,ux	// put the value of ux into al
		mov bl,uy	// put the value of uy into bl
		add al,bl	// al = al + bl

		mov usum,al
		movzx ecx,al	// zero extend the result
		mov usum32,ecx

		mov ah,sx	// put the value in ux into ah
		mov bh,sy	// put the value in uy into bh
		add ah,bh	// ah = ah + bh
		mov ssum,ah

		movsx edx,ah
		mov ssum32,edx
	}

	printf("usum = %02X, ssum = %02X\n\n", (unsigned char) usum, (char) ssum);
	printf("usum = %u, and ssum = %d\n\n", usum, ssum);
	printf("What if we tell the printf to interpret the results backwards?\n\n");
	printf("usum = %u, and ssum = %d\n\n", (unsigned char) ssum, (char) usum);
	printf("Zero-Extended the unsigned result, Sign-Extended the signed result.\n\n");
	printf("usum32 = %u (0x%08X), ssum32 = %d (0x%08X)\n\n", usum32, usum32, ssum32, ssum32);

	system("pause");
	return 0;
} // main