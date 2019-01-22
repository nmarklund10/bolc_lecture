#include "helper.h"

int main(int argc, char** argv) {
    set_fuse();
    if (argc == 2) {
        FILE* solution_file = fopen(argv[1], "r");
        if (solution_file == NULL) {
            printf("Could not find solution file, now reading from stdin.\n");
        }
        else {
            fread(input, sizeof(char), SIZE, solution_file);
            input[SIZE - 1] = '\0';
            fclose(solution_file);
            char* result = strtok(input, "\n");
            int index = 0;
            while (result != NULL && index < 5) {
                user_answers[index] = result;
                result = strtok(NULL, "\n");
                ++index;
            }
        }
    }
    else if (argc != 1) {
        printf("Usage: ./bomb <?solution_file>\n");
        printf("  Optional args:\n");
        printf("    solution_file: path to file with already solved solutions.  Once EOF is reached, program reads from stdin.\n");
        return 0;
    }
    printf("There is a bomb you must defuse!  There are 5 phases you must pass.\n");

    phase_1();
    phase_2();
    phase_3();
    phase_4();
    phase_5();

    printf("\nCongratulations, you are now Cyber EOD!\n");
    exit(0);
}
