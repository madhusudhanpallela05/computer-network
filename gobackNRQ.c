#include <stdio.h>

void main()
{
    int total_frames, window_size;
    int sent = 0, lost_frame, i;

    printf("Enter total number of frames to send: ");
    scanf("%d", &total_frames);

    printf("Enter window size: ");
    scanf("%d", &window_size);

    printf("\n-- Go-Back-N Sliding Window Protocol Simulation--\n\n");

    while (sent < total_frames)
    {
        // Send a window of frames
        printf("Sender: Sending frames ");
        for (i = sent; i < sent + window_size && i < total_frames; i++)
            printf("%d ", i);
        printf("\n");

        // Ask user to choose a lost frame
        printf("Enter the frame number to be lost (or 1 if none lost): ");
        scanf("%d", &lost_frame);

        if (lost_frame >= sent && lost_frame < sent + window_size && lost_frame < total_frames)
        {
            // Simulate loss
            printf("Receiver: Frame %d lost! Go back and resend from %d\n\n", lost_frame, lost_frame);
            sent = lost_frame; // retransmit from lost frame
        }
        else
        {
            // All frames acknowledged
            int ack = sent + window_size;
            if (ack > total_frames)
                ack = total_frames;
            printf("Receiver: Acknowledged up to frame %d\n\n", ack - 1);
            sent = ack; // Move window forward
        }
    }

    printf("All frames sent successfully using Go-Back-N!\n");
}
