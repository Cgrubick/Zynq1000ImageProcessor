#include <stdint.h>
#include <stdio.h>
#include <stdlib.h> 
#pragma pack(1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t clrUsed;
    uint32_t clrImportant;
} DIBHeader;
#pragma pack()

int main() {
    int width = 582;  // Adjust to match your image dimensions
    int height = 634;  // Adjust to match your image dimensions

    FILE *binFile = fopen("output.bin", "rb");
    if (!binFile) {
        perror("Failed to open binary file");
        return 1;
    }

    FILE *bmpFile = fopen("output.bmp", "wb");
    if (!bmpFile) {
        perror("Failed to open BMP file");
        fclose(binFile);
        return 1;
    }

    BMPHeader bmpHeader = {0x4D42, 54 + width * height * 3, 0, 0, 54}; //appends BM to the beginning the BMP file, 54 is the size of the BMP header and the DIB header
    DIBHeader dibHeader = {40, width, height, 1, 24, 0, width * height * 3, 2835, 2835, 0, 0}; 

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, bmpFile);
    uint8_t *pixelData = malloc(width * height * 3);
    if (!pixelData) {
        perror("Failed to allocate memory");
        fclose(binFile);
        fclose(bmpFile);
        return 1;
    }

    fread(pixelData, 1, width * height * 3, binFile);
    fwrite(pixelData, 1, width * height * 3, bmpFile);

    free(pixelData);
    fclose(binFile);
    fclose(bmpFile);

    return 0;
}
