// this program aides with Lab #1 by allowing you to enter a decimal numebr and see
// the hex/binary/octal equivalents
//
// It also illustrates the use of bit fields and the difference between signed and unsigned numbers
//
// Linux: gcc Lab1.cpp -o /tmp/Lab1 --- remove windows.h
// Windows: compile Lab1.cpp using Visual Studio
// Sample Usage:
// /tmp/Number 0 5 23 345 -2 99999999 -99999999 2147483647 -2147483648
//

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>


union {
  int n;
  unsigned int u;
} onion;

struct _BIT_FIELD {
	int			b4signed:4;		// 4 bits, signed
	unsigned int	b4unsigned:4;	// 4 bits unsigned

	int b2signed:2;
	unsigned int b2unsigned:2;

	int b5signed:5;
	unsigned int b5unsigned:5;
} gBitF;

char *binary(int n, int nc) {
  static char str[100];

  int pos = 96;
  int which = 1;

  memset(str, 0, 100);
  for (int i = 0; i < nc; i++) {
    str[pos--] = (n & which) ? '1' : '0';
    if (i % 8 == 7 && pos > 0) str[pos--] = ' ';
    which <<= 1;
  }
  return &str[pos+1];
}

int main(int argc, char *argv[]) {
	char dummy[8], *ptr;
	int i;

  if (argc < 2) {
    printf("Usage: Number 123 -44 etc.\n\nDo you wish to exit? y/n\n\n");	// answer does NOT matter
    scanf("%s", dummy);
    exit(0);
  }

  for(i = 0; i < 64; i++)	// 4 bits only have 16 values, so notice how they repeat
  {
	  gBitF.b4signed = i;
	  gBitF.b4unsigned = i;
	  gBitF.b2signed = i;
	  gBitF.b2unsigned = i;
	  gBitF.b5signed = i;
	  gBitF.b5unsigned =i;

	  if( (i % 16) == 0) printf("\n");
	  ptr =  binary(i, 8);
	  printf("i=%2d:  S2:%3d, U2:%3u    S4:%3d, U4:%3u    S5:%3d, U5:%3u   Binary i: %s\n", i, 
		  gBitF.b2signed, gBitF.b2unsigned, gBitF.b4signed, gBitF.b4unsigned, gBitF.b5signed, gBitF.b5unsigned, ptr);
  }

  printf("\n\n%11s  %-8s  %-11s  %-35s  %10s\n", "Decimal", "Hex", "Octal", "Binary", "Unsigned");
  for (int i = 1; i < argc; i++) {
    onion.n = atoi(argv[i]);
    printf("%11d  %08x  %011o  %s  %10u\n", onion.n, onion.n, onion.n, binary(onion.n, 32), onion.u);
  }

  printf("\n\nDo you wish to exit? y/n\n\n");
  scanf("%s", dummy);
  return 0;
}