#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define SIZE 1024

char input[SIZE];
char* user_answers[5];

void set_fuse();

void explode_bomb();

int get_random_number();

void get_user_input(char* buf, int phase);

void phase_1();

void phase_2();

void phase_3();

void phase_4();

void phase_5();

void signal_handler(int dummy);
