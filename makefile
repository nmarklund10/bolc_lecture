cc=gcc
CFLAGS= -Wall -O0 -g -static

bomb: helper.o
	$(CC) $(CFLAGS) bomb.c -o bomb helper.o
helper: helper.h
	$(CC) $(CFLAGS) helper.c -o helper.o
clean:
	rm -rf *.o bomb