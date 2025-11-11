#include <stdio.h>
void main()
{
int data [100], length, i, sum = 0, checksum;
// Sender Side
printf("Enter length of data: ");
scanf("%d", &length);
printf("Enter %d data integers: \n", length);
for(i = 0; i < length; i++)
{
scanf("%d", &data[i]);
sum += data[i]; // Sum of data
}
checksum = ~sum; // One's complement
printf("Checksum (sender side): %d\n", checksum);
// Receiver Side
int receivedSum = 0;
for(i = 0; i < length; i++)
{
receivedSum += data[i];
}
receivedSum += checksum;
if (receivedSum == 0)
printf("No error: Data received correctly.\n");
else
printf("Error detected in received data.\n");
}
