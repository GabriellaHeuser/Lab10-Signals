# Lab 10: Signals

CPE 2600 Systems Programming - Gabi Heuser

## Build
    'make'

## Programs

- `signal_handler` - SIGINT handler that does not exit
- `signal_alarm` - SIGALRM after 5 seconds
- `signal_segfault` - SIGSEGV handler
- `signal_sigaction` - prints the PID of the process that sent SIGUSR1
- `recv_signal` / `send_signal` - send a random integer with SIGUSR1
- `tennisRecv` / `tennisSend` - extra credit: signal tennis with tennis scoring

## Running Signal Tennis

    ./recv_signal
    ./send_signal <pid>

    ./tennisRecv
    ./tennisSend <pid>

Start the receiver first. It prints its PID.