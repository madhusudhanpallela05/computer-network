#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void main()
{
    int totalFrames, windowSize;
    int frameStatus[MAX];
    int i, choice, resend;

    printf("\n=== Selective Repeat ARQ Simulation ===\n");
    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);

    printf("Enter window size: ");
    scanf("%d", &windowSize);

    for (i = 0; i < totalFrames; i++)
        frameStatus[i] = 0;

    int sent = 0;

    while (sent < totalFrames)
    {
        printf("\n--- Sending Window of Frames ---\n");

        for (i = sent; i < sent + windowSize && i < totalFrames; i++)
        {
            if (frameStatus[i] == 0)
                printf("Frame %d sent.\n", i);
        }

        for (i = sent; i < sent + windowSize && i < totalFrames; i++)
        {
            if (frameStatus[i] == 0)
            {
                printf("Did frame %d get ACK? (1 = Yes, 0 = Lost): ", i);
                scanf("%d", &choice);
                if (choice == 1)
                {
                    printf("ACK for frame %d received.\n", i);
                    frameStatus[i] = 1;
                }
                else
                {
                    printf("Frame %d lost / not acknowledged.\n", i);
                }
            }
        }

        printf("\nDo you want to resend any lost frame? (Enter frame number, -1 to stop): ");
        scanf("%d", &resend);
        while (resend != -1)
        {
            if (resend >= sent && resend < totalFrames && frameStatus[resend] == 0)
            {
                printf("Resending frame %d...\n", resend);
                printf("ACK for frame %d received now.\n", resend);
                frameStatus[resend] = 1;
            }
            else
            {
                printf("Invalid frame number or already ACKed.\n");
            }
            printf("Enter next frame to resend (-1 to stop): ");
            scanf("%d", &resend);
        }

        // Slide window
        while (sent < totalFrames && frameStatus[sent] == 1)
        {
            sent++;
        }
    }

    printf("\nAll frames sent and acknowledged successfully!\n");
}
