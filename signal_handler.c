/**
* Modified by: Gabi Heuser
*
* Brief summary of modifications:
*   Removed the exit inside the handle_signal() method
*   Exiting now relies on SIGKILL from terminal
*/
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
* @brief Signal handler for SIGINT - prints a message and exits
*/
void handle_signal() {
printf("Received a signal\n");
}
int main() {
// Register for the signal
signal(SIGINT, handle_signal);
// Wait until a signal is received
while(1) {
printf("Sleeping\n");
sleep(1);
}
return 0;
}