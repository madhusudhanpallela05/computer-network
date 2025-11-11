#include <stdio.h>
#include <math.h>

int input[32];
int code[32];

int ham_calc(int position, int c);

void main()
{
    int n, i, pn = 0, c, j, k;

    printf("Please enter the length of the Data Word: ");
    scanf("%d", &n);

    printf("Please enter the Data Word: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &input[i]);

    /* find number of parity bits pn such that 2^pn >= n + pn + 1 */
    while ((int)pow(2, pn) < n + pn + 1)
        pn++;

    c = pn + n;

    j = 0;
    k = 0;
    for (i = 0; i < c; i++) {
        if (i == ((int)pow(2, k) - 1)) {
            code[i] = 0;      /* placeholder for parity */
            k++;
        } else {
            code[i] = input[j];
            j++;
        }
    }

    /* calculate parity bits */
    for (i = 0; i < pn; i++) {
        int position = (int)pow(2, i);
        int value = ham_calc(position, c);
        code[position - 1] = value;
    }

    printf("\nThe calculated Code Word is: ");
    for (i = 0; i < c; i++)
        printf("%d", code[i]);
    printf("\n");

    /* read received code word */
    printf("Please enter the received Code Word:\n");
    for (i = 0; i < c; i++)
        scanf("%d", &code[i]);

    /* compute error position */
    {
        int error_pos = 0;
        for (i = 0; i < pn; i++) {
            int position = (int)pow(2, i);
            int value = ham_calc(position, c);
            if (value != 0)
                error_pos += position;
        }

        if (error_pos == 0)
            printf("The received Code Word is correct.\n");
        else
            printf("Error at bit position: %d\n", error_pos);
    }
}

int ham_calc(int position, int c)
{
    int count = 0, i, j;
    i = position - 1;
    while (i < c) {
        for (j = i; j < i + position && j < c; j++) {
            if (code[j] == 1)
                count++;
        }
        i = i + 2 * position;
    }
    if (count % 2 == 0)
        return 0;
    else
        return 1;
}
