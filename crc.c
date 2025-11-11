#include <stdio.h>
#include <string.h>

#define MAX 100

void xor_op(char *dividend, char *divisor, int pos) {
    for (int i = 0; divisor[i] != '\0'; i++)
        dividend[pos + i] = (dividend[pos + i] == divisor[i]) ? '0' : '1';
}

void crc(char *data, char *divisor, char *rem) {
    int dl = strlen(data), gl = strlen(divisor);
    char temp[MAX];
    strcpy(temp, data);

    for (int i = 0; i <= dl - gl; i++) {
        if (temp[i] == '1')
            xor_op(temp, divisor, i);
    }

    strcpy(rem, temp + dl - gl + 1);
}

int main() {
    char data[MAX], gen[MAX], rem[MAX], recv[MAX];

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator (CRC-12): ");
    scanf("%s", gen);

    int gl = strlen(gen);
    strcat(data, "000000000000");  // append 12 zeros for CRC-12

    crc(data, gen, rem);
    printf("\nCRC Remainder: %s\n", rem);

    // append remainder to original data (transmitted frame)
    data[strlen(data) - gl + 1] = '\0';
    strcat(data, rem);
    printf("\nTransmitted Frame: %s\n", data);

    printf("\nEnter received frame: ");
    scanf("%s", recv);

    crc(recv, gen, rem);
    if (strstr(rem, "1"))
        printf("\nError detected in received frame.\n");
    else
        printf("\nNo error detected.\n");

    return 0;
}



ïnput:
Enter data bits: 1101011011
Enter generator (CRC-12): 10011
Enter received frame: 1101011011110



output :
CRC Remainder: 110

Transmitted Frame: 1101011011110

Enter received frame: 1101011011110
No error detected.
