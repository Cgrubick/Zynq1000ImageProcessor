#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("input.bmp", "rb");
    if (!file) {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = malloc(fileSize);
    if (!buffer) {
        fprintf(stderr, "Could not allocate memory\n");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);

    FILE *outputFile = fopen("output.bin", "wb");
    if (!outputFile) {
        fprintf(stderr, "Could not open output file\n");
        free(buffer);
        return 1;
    }

    fwrite(buffer, 1, fileSize, outputFile);
    fclose(outputFile);
    free(buffer);

    return 0;
}
