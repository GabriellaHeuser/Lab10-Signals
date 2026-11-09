/**
* File: tennisRecv.c
* Modified by: Gabi Heuser
*
* Brief summary of program:
*   Recieving tennis "player", prints its pid to be used by sender
*   Uses tennis scoring with a 4/10 chance to miss (rand int 0-9 < 3)
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "scoring.h"
#define WIN_SCORE 3

static int senderPID;
static int my_score;
static int opp_score;

static const char *point_vals[] = {"0", "15", "30", "40"};

void handle_signal(int sig, siginfo_t *info, void *context)
{
    senderPID = info->si_pid;
    int recieved = info->si_value.sival_int;

    if (recieved < 3){
        printf("Opponent Missed.\n");
        my_score++;
        if(end_game()){
            printf("I won!\n");
            exit(0);
        }
        print_score();
    } else {
        //printf("Recieved %d\n", recieved);
        printf("OPPONENT - ");
        switch (recieved){
            case 4: 
                printf("WHACK!\n");
                break;
            case 5:
                printf("BOINK!\n");
                break;
            case 6: 
                printf("WHOOSH!\n");
                break;
            default:
                printf("HIT!\n");
                break;
        }
    }


    sleep(1+rand()%2); // random wait time

    printf("\a"); //system bell

    union sigval sv;
    int num = rand() % 10;
    sv.sival_int = num;
    if(num < 3){
        printf("I Missed.\n");
        opp_score++;
        sigqueue(senderPID, SIGUSR1, sv);
        if(end_game()){
            printf("I lost\n");
            exit(0);
        }
        print_score();
    } else{
        //printf("Send %d\n", num);
        printf("ME - ");
        switch (num){
            case 4: 
                printf("WHACK!\n");
                break;
            case 5:
                printf("BOINK!\n");
                break;
            case 6: 
                printf("WHOOSH!\n");
                break;
            default:
                printf("HIT!\n");
                break;
        }
        sigqueue(senderPID, SIGUSR1, sv);
    }
    
}

int main(void)
{
    srand(time(NULL));//seeding random

    printf("PID: %d\n", (int)getpid());
    
    struct sigaction sa; //struct from sigaction

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);

    while (1) {
        //infinite loop
    }

    return 0;
}

//scoring helper methods

int end_game(void){
    return (my_score >= 4 || opp_score >=4) && abs(my_score-opp_score) >= 2;
}

void print_score(void){
    if(my_score >= 3 && opp_score >= 3){
        if (my_score == opp_score){
            printf("Score: Deuce\n");
        } else if(my_score>opp_score){
            printf("Score: Advantage me\n");
        } else {
            printf("Score: Advantage opponent\n");
        }
    } else {
        printf("Score: me %s - opponent %s\n", point_vals[my_score], point_vals[opp_score]);
    }
}

