// PROGRAM FOR SIMULATION OF GREP UNIX COMMANDS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1024

void usage() {
    printf("usage:\t ./a.out filename word\n");
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char fline[MAX];
    char *newline;
    int count = 0;
    int occurrences = 0;

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        usage();
        exit(1);
    }

    // Open the file in read mode
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("grep: could not open file: %s\n", argv[1]);
        exit(1);
    }

    // Read the file line by line
    while (fgets(fline, MAX, fp) != NULL) {
        count++;

        // Remove the newline character at the end of the line if present
        if ((newline = strchr(fline, '\n')) != NULL) {
            *newline = '\0';
        }

        // Check if the search word is found in the current line
        if (strstr(fline, argv[2]) != NULL) {
            printf("%s: %d %s\n", argv[1], count, fline);
            occurrences++;
        }
    }

    // Print message if no occurrences found
    if (occurrences == 0) {
        printf("No occurrences of '%s' found in the file.\n", argv[2]);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
