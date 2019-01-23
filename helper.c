#include "helper.h"

void set_fuse() {
    signal(SIGINT, signal_handler);
    signal(SIGTSTP, signal_handler);
    memset(input, 0, SIZE);
    for (int i = 0; i < 5; ++i) {
        user_answers[i] = "";
    }
}

void explode_bomb() {
    printf("BOOOOOOOMMMM!!!\n");
    printf("Bomb exploded! :(\n");
    exit(0);
}

int get_random_number() {
  srand(1);
  return rand() % 75 + 1;
}

void get_user_input(char* response, int phase){
    phase -= 1;
    if (phase < 0 || phase >= 5) {
        printf("Error!\n");
        explode_bomb();
    }
    if (strncmp(user_answers[phase], "", 1)) {
        strncpy(response, user_answers[phase], SIZE/4 - 1);
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
    if (response[0] != 'r') {
      explode_bomb();
    }
    if (response[1] != 'o') {
      explode_bomb();
    }
    if (response[2] != 'y') {
      explode_bomb();
    }
    if (response[3] != 'a') {
      explode_bomb();
    }
    if (response[4] != 'l') {
      explode_bomb();
    }
    if (response[5] != 'f') {
      explode_bomb();
    }
    if (response[6] != 'l') {
      explode_bomb();
    }
    if (response[7] != 'u') {
      explode_bomb();
    }
    if (response[8] != 's') {
      explode_bomb();
    }
    if (response[9] != 'h') {
      explode_bomb();
    }
}

void phase_4() {
    char response[SIZE/4];
    int arr[4] = {1, 5, 12, 22};
    get_user_input(response, 4);
    int user_arr[4] = {0};
    sscanf(response, "%d f %d f %d f %d", &user_arr[0], &user_arr[1], &user_arr[2], &user_arr[3]);
    for (int i = 0; i < 4; ++i) {
      if (arr[i] != user_arr[i]) {
        explode_bomb();
      }
    }
}

void phase_5() {
    char response[SIZE/4];
    int j = get_random_number();
    get_user_input(response, 5);
    int i = atoi(response);
    if (i != j) {
      explode_bomb();
    }
}

void signal_handler(int dummy) {
    printf("\nYou abadoned the bomb!\n");
    explode_bomb();
}
