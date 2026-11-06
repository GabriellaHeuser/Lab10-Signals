/**
 * File: signal_alarm.c
 * Modified by:
 *
 * Brief summary of program:
 *      Sends SIGALRM after 5 seconds.
 *      A signal handler catches SIGALRM and prints a message
 */


/*
 * File: signal_alarm.c
 *
 * Description:
 * Schedules an alarm to send SIGALRM after 5 seconds.
 * A signal handler catches SIGALRM and prints a message
 * when the signal is received.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int signal)
{
    printf("SIGALRM received!\n");
}

int main(void)
{
    signal(SIGALRM, handle_alarm);

    printf("Alarm scheduled for 5 seconds.\n");

    alarm(5);

    while (1){
        pause();
    }

    return 0;
}
