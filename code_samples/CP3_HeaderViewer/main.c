/**
 * Demonstration of reading a simple 2x2 BMP file.
 *
 * @author Ruben Acuna
 * @version 1.0
 */
#include <stdio.h>

struct BMP_Header {
    char signature[2];
    int size;
    short reserved1;
    short reserved2;
    int offset_pixel_array;
};

struct DIB_Header {
    char temp[40]; //not quite done!
};

int main() {
    FILE* file_input = fopen("wikipedia_2x2.bmp", "rb");
    struct BMP_Header header;
    struct DIB_Header header_dib;

    //read bitmap header
    fread(&header.signature, sizeof(char) * 2, 1, file_input);
    fread(&header.size, sizeof(int), 1, file_input);
    fread(&header.reserved1, sizeof(short), 1, file_input);
    fread(&header.reserved2, sizeof(short), 1, file_input);
    fread(&header.offset_pixel_array, sizeof(int), 1, file_input);

    //display contents
    printf("signature: %c%c\n", header.signature[0], header.signature[1]);
    printf("size: %d\n", header.size);
    printf("reserved1: %d\n", header.reserved1);
    printf("reserved2: %d\n", header.reserved2);
    printf("offset_pixel_array: %d\n", header.offset_pixel_array);

    fread(&header_dib, sizeof(char), 40, file_input);

    //read a single pixel. (format is BGR.)
    unsigned char r, g, b;
    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);
    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    //two pixel pad in the file here!
    fseek(file_input, sizeof(unsigned char) * 2, SEEK_CUR);

    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    fread(&b, sizeof(char), 1, file_input);
    fread(&g, sizeof(char), 1, file_input);
    fread(&r, sizeof(char), 1, file_input);
    printf("color: B=%d, G=%d, R=%d\n", b, g, r);

    fclose(file_input);

    //short writing example
    FILE* file_output = fopen("output.bmp", "wb");
    fwrite(&header.signature, sizeof(char) * 2, 1, file_output);
    fwrite(&header.size, sizeof(int), 1, file_output);
    fwrite(&header.reserved1, sizeof(short), 1, file_output);
    fwrite(&header.reserved2, sizeof(short), 1, file_output);
    fwrite(&header.offset_pixel_array, sizeof(int), 1, file_output);

    fwrite(&header_dib, sizeof(char), 40, file_output);

    fclose(file_output);

    return 0;
}
