#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STR_LEN 100
#define PASSWORD "Python123"

int main(int argc, char** argv) {
    while (true) {
        printf("Enter password: ");
        char user_input[STR_LEN];
        fgets(user_input, STR_LEN - 1, stdin);

        user_input[strlen(user_input) - 1] = '\0';

        if (strcmp(user_input, PASSWORD) == 0)
            break;

        printf("Wrong password, please try again.\n");
    }

    printf("Access granted!\n");
}
