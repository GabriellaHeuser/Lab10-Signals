/**
* File: send_signal.c
* Modified by: Gabi Heuser
*
* Brief summary of program:
*   One way communication sender. 
*   Must be prompted with PID in command line.
*
* To Send:
*   Run recv_signal in terminal with "./recv"
*   In a new terminal use "pgrep -a recv" to get PID of recv
*   Run send_signal.c with "./send [PID]" with the PID from previous step
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
    if (argc == 2){
        int pid = atoi(argv[1]);

        srand(time(NULL));
        int num = rand();
        printf("From Send: %d\n", num);

        union sigval sv;
        sv.sival_int = num;

        sigqueue(pid, SIGUSR1, sv);
    }

    return 0;
}