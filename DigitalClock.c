#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int hours, minutes, seconds; // Variable to store hours, minutes, and seconds
    hours=minutes=seconds=0; // Initialize hours, minutes, and seconds to 0

    while (1)
    {
        system("cls"); // Clear the console screen (use "clear" for Linux/Mac)

        printf("%02d : %02d : %02d", hours, minutes, seconds); // Print the time in HH:MM:SS format
        fflush(stdout); // Flush the output buffer to ensure the time is displayed immediately

        seconds++; // Increment seconds by 1

        /* if seconds reach 60, increment minutes and reset seconds and if minutes reach 60, increment hours and reset minutes also if hours reach 24, reset all */
        if (seconds == 60)
        {
            minutes+=1;
            seconds=0;
        }
        if (minutes == 60)
        {
            hours+=1;
            minutes=0;
        }
        if (hours == 24)
        {
            hours=0;
            minutes=0;
            seconds=0;
        }
        sleep(1); // Sleep for 1 second before updating the time again
    }
    return 0;
}