
/**
 * File: signal_sigaction.c
 * Modified by: Gabi Heuser
 *
 * Brief summary of program:
 *  Registers a SIGUSR1 signal handler using sigaction().
 *  When SIGUSR1 is received, the handler prints the PID of sender
 *
 * To Send Signal:
 *  in a new terminal use "pgrep -a sigaction"
 *  then use "kill -10 PID" with the PID from the pgrep
 *  alternatively you may use "kill -USR1 PID"
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
    printf("PID of sender: %d\n", info->si_pid);
}

int main(void)
{
    struct sigaction sa; //struct from sigaction

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);

    // Wait until a signal is received
    while (1) {
        sleep(1);
    }

    return 0;
}
