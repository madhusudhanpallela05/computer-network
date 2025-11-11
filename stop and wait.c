#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sender (int totalFrames);
void receiver(int frame);

void main()
{
    int totalFrames;
    printf("=== Stop-and-Wait Protocol Simulation ===\n");
    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);
    sender(totalFrames);
}

void sender (int totalFrames)
{
    int i, ack, choice;
    srand(time(NULL));
    for (i = 1; i <= totalFrames; i++) {
        printf("\nSender: Sending Frame %d", i);
        printf("\nReceiver: Do you want to ACK Frame %d? (1=Yes, 0=No): ", i);
        scanf("%d", &choice);
        if (choice == 1) {
            receiver(i);
            printf("Sender: ACK %d received \n", i);
        } else {
            printf("Sender: ACK %d lost. Retransmitting...\n", i);
            i--;
        }
    }
    printf("\nAll %d frames sent successfully!\n", totalFrames);
}

void receiver(int frame)
{
    printf("Receiver: Frame %d received. Sending ACK %d...\n", frame, frame);
}
