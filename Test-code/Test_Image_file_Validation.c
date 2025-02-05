#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_png(const char *filename) {
    // PNG file signature
    unsigned char png_signature[8] = {0x89, 'P', 'N', 'G', '\r', '\n', 0x1A, '\n'};
    unsigned char buffer[8];

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 0;
    }

    // Read the first 8 bytes of the file
    size_t read_size = fread(buffer, 1, 8, file);
    fclose(file);

    if (read_size != 8) {
        fprintf(stderr, "Error reading file\n");
        return 0;
    }

    // Compare the file's signature with the PNG signature
    if (memcmp(buffer, png_signature, 8) == 0) {
        return 1; // Valid PNG file
    } else {
        return 0; // Invalid PNG file
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    // Validate the provided file to check if it is a valid PNG image
    if (validate_png(argv[1])) {
        printf("The file is a valid PNG image.\n");
    } else {
        printf("The file is not a valid PNG image.\n");
    }

    return 0;
}
