
CFLAGS = -c -g -Wall -Werror
CC = gcc

all: sigaction recv send alarm handler segfault

sigaction: signal_sigaction.o
	$(CC) -o sigaction signal_sigaction.o

recv: recv_signal.o
	$(CC) -o recv recv_signal.o

send: send_signal.o
	$(CC) -o send send_signal.o

alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.o

handler: signal_handler.o
	$(CC) -o handler signal_handler.o

segfault: signal_segfault.o
	$(CC) -o segfault signal_segfault.o

clean:
	rm -f *.o sigaction recv send alarm handler segfault

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
