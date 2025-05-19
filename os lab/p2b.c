// Program for simulation of ls Unix command
#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *link;

    // Ensure that the directory argument is provided
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Open the directory
    dp = opendir(argv[1]);
    if (dp == NULL) {
        perror("opendir");  // Print error if directory can't be opened
        return 1;
    }

    printf("\nContents of the directory '%s':\n", argv[1]);

    // Read and print all files and folders in the directory
    while ((link = readdir(dp)) != NULL) {
        printf("%s\n", link->d_name);
    }

    closedir(dp);  // Close the directory stream
    return 0;
}
