/**
* @file signal_segfault.c
* @brief Program that dereferences a null pointer causing a segmentation fault
*/
/**
* Modified by: Gabi Heuser
*
* Brief summary of modifications:
*   A signal handler "handle_signal()" was implemented that ackowledges the segfault.
*   This handler does not resolve the segfault, so an infinite loop of segfaults occurs until termination of the process.
*/
#include <stdio.h>
#include <signal.h>

void handle_signal() {
    printf("Received a segfault\n");
}

int main (int argc, char* argv[]) {

signal(SIGSEGV, handle_signal);

// Declare a null pointer
int* i = NULL;
// Dereference the null pointer
printf("The value of i is: %d\n", *i);
// Return to exit the program
return 0;
}