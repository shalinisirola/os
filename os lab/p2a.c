// Program for simulation of cp Unix command
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destFile;
    char ch;

    // Check if the correct number of arguments is provided
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open the source file in read mode
    sourceFile = fopen(argv[1], "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file: %s\n", argv[1]);
        return 1;
    }

    // Open the destination file in write mode
    destFile = fopen(argv[2], "wb");
    if (destFile == NULL) {
        printf("Unable to create the destination file: %s\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    // Copy contents from source to destination
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);

    // Close both files
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
