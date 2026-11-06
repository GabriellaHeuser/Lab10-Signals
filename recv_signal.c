/**
* File: recv_signal.c
* Modified by: Gabi Heuser
*
* Brief summary of program:
*   One way communication program that recieves a value from send_signal.c
*   and prints out the value.
*/

#include <stdio.h>
#include <signal.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
    printf("Value Recieved: %d\n", info->si_value.sival_int);
}

int main(void)
{
    struct sigaction sa; //struct from sigaction

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);

    while (1) {
        //infinite loop
    }

    return 0;
}