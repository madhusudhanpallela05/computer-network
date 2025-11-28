Hamming Code:

#include <stdio.h>

int calcParity(int code[], int pos[], int size) {

int parity = 0;

int i;

for (i = 0; i< size; i++) ( parity ^= code[pos[i]];

return parity;

int main() {

int data[4];

int hammingCode[7];

int i;

for (i = 0; i<7; i++) ( hammingCode[i] = 0;

}

printf("Enter 4 data bits (0 or 1):\n");

for (i = 0; i<4; i++) { scanf("%d", &data[i]);

}

hammingCode[2] = data[0];

hammingCode[4] = data[1];

hammingCode[5] = data[2];

hammingCode[6] = data[3];

int p1[] = {2, 4, 6);

int p2[] = {2, 5, 6);

int p4[] = (4, 5, 6);

hammingCode[0] = calcParity(hammingCode, p1, 3); hammingCode[1] = calcParity(hammingCode, p2, 3); hammingCode[3] = calcParity(hammingCode, p4, 3);

printf("Generated 7-bit Hamming code: "); for (i = 0; i<7; i++) (

}

printf("%d", hammingCode[i]);

}

printf("\n");

return 0;
