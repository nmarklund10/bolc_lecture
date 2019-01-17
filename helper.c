#include "helper.h"

void set_fuse() {
    signal(SIGINT, signal_handler);
    signal(SIGTSTP, signal_handler);
    memset(input, 0, SIZE);
    for (int i = 0; i < 5; ++i) {
        answers[i] = "";
    }
}

void explode_bomb() {
    printf("BOOOOOOOMMMM!!!\n");
    printf("Bomb exploded! :(\n");
    exit(0);
}

void get_user_input(char* response, int phase){
    phase -= 1;
    if (phase < 0 || phase >= 5) {
        printf("Error!\n");
        explode_bomb();
    }
    if (strncmp(answers[phase], "", 1)) {
        strncpy(response, answers[phase], SIZE/4 - 1);
        printf("Phase %d: %s\n", phase + 1, response);
    }
    else {
        printf("Phase %d: ", phase + 1);
        fgets(response, SIZE/4 - 1, stdin);
    }
    response[SIZE/4 - 1] = '\0';
}

void phase_1() {
    char response[SIZE/4];
    get_user_input(response, 1);
    int i = atoi(response);
    if (i != 18503) {
        explode_bomb();
    }
}

void phase_2() {
    char response[SIZE/4];
    get_user_input(response, 2);
    if (strncmp(response, "Cyber Slayers", 13) != 0) {
        explode_bomb();
    }
}

void phase_3() {
    char response[SIZE/4];
    get_user_input(response, 3);
    // explode_bomb();
}

void phase_4() {
    char response[SIZE/4];
    get_user_input(response, 4);
    // explode_bomb();
}

void phase_5() {
    char response[SIZE/4];
    get_user_input(response, 5);
    // explode_bomb();
}

void signal_handler(int dummy) {
    printf("\nYou abadoned the bomb!\n");
    explode_bomb();
}