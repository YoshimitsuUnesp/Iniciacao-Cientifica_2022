#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Header get_header(Header header, FILE *file)
{
    // Collects the header data
    fread(&header, sizeof(Header), 1, file);

    printf("\nWAV header copied successfully!\n\n");

    // printf("\nPress ENTER to continue\n");
    // getchar();
    // getchar();

    return header;
}

void print_header(Header header)
{
    printf("File type: %c%c%c%c\n", header.chunk_id[0], header.chunk_id[1], header.chunk_id[2], header.chunk_id[3]);
    printf("File size, excluding header: %d\n", header.chunk_size);
    printf("Subtype: %c%c%c%c\n", header.format[0], header.format[1], header.format[2], header.format[3]);
    printf("Identifier: %c%c%c%c\n", header.subchunk1_id[0], header.subchunk1_id[1], header.subchunk1_id[2], header.subchunk1_id[3]);
    printf("Chunck size post header: %d\n", header.subchunk1_size);
    printf("Format type: %d\n", header.audio_format);
    printf("Number of channels: %d\n", header.num_channels);
    printf("Sampling rate: %d\n", header.sample_rate);
    printf("Average number os bits per second: %d\n", header.byte_rate);
    printf("Block alignment in bytes: %d\n", header.block_align);
    printf("Resolution: %d\n", header.bits_per_sample);
    printf("Identifier: %c%c%c%c\n", header.subchunk2_id[0], header.subchunk2_id[1], header.subchunk2_id[2], header.subchunk2_id[3]);
    printf("Data chunk size: %d\n", header.subchunk2_size);
    printf("Number of frames to be sampled: %d\n", header.subchunk2_size / header.block_align);
    printf("Windows length: %d\n", header.subchunk2_size / header.block_align / header.num_channels);

    printf("\nPress ENTER to continue\n");
    getchar();
    getchar();
}

void copy_wav()
{
    FILE *input_file = fopen("applause.wav", "rb");

    // Checks if the file exists
    if (!input_file)
    {
        printf("\nERROR: FILE NOT FOUND\n\n");
        return;
    }

    // Gets the WAV file header
    Header header = get_header(header, input_file);

    // Prints the header
    print_header(header);

    // Copies the data
    unsigned int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    short int *data = malloc(header.subchunk2_size); // Allocates the size audio data

    fread(data, header.subchunk2_size, 1, input_file); // Reads the entire data

    FILE *output_file = fopen("copy.wav", "wb");

    if (!output_file)
    {
        printf("\nERROR: COULD NOT OPEN COPY FILE\n\n");
        return;
    }

    // Writes the header and the data to the copy file
    fwrite(&header, sizeof(header), 1, output_file);
    fwrite(data, header.subchunk2_size, 1, output_file);

    printf("\nFILE COPY CREATED SUCCESSFULLY!\n\n");

    fclose(input_file);
    fclose(output_file);

    free(data);

    return;
}

void invert_y_axis_wav()
{
    FILE *input_file = fopen("copy.wav", "rb");

    if (!input_file)
    {
        printf("\nERROR: FILE NOT FOUND\n\n");
        return;
    }

    Header header = get_header(header, input_file);

    FILE *output_file = fopen("inverted_y.wav", "wb");

    // Writes the header in the inverted file
    fwrite(&header, sizeof(Header), 1, output_file);

    // ----------------------------------------------

    unsigned int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    short int *data = malloc(header.subchunk2_size); // Allocates the size audio data
    short int *inverted_data = malloc(header.subchunk2_size);

    // At this moment, the pointer in input_file is after the header
    fread(data, header.subchunk2_size, 1, input_file); // Reads the entire data

    for (unsigned int i = 0; i < num_samples; i++)
    {
        inverted_data[i] = data[num_samples - i - 1];
    }

    fwrite(inverted_data, header.subchunk2_size, 1, output_file);

    printf("\nAUDIO INVERTED IN Y AXIS SUCCESSFULLY!\n\n");

    fclose(input_file);
    fclose(output_file);

    return;
}

void invert_x_axis_wav()
{
    FILE *input_file = fopen("copy.wav", "rb");

    if (!input_file)
    {
        printf("\nERROR: FILE NOT FOUND\n\n");
        return;
    }

    Header header = get_header(header, input_file);

    FILE *output_file = fopen("inverted_x.wav", "wb");

    // Writes the header in the inverted file
    fwrite(&header, sizeof(Header), 1, output_file);

    // ----------------------------------------------

    // Writes the header in the inverted file
    fwrite(&header, sizeof(Header), 1, output_file);

    unsigned int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    short int *data = malloc(num_samples * sizeof(short int));
    int i;

    // Inverts the amplitude of the samples
    fread(data, sizeof(short int), num_samples, input_file);
    for (i = 0; i < num_samples; i++)
        data[i] *= -1;
    fwrite(data, sizeof(short int), num_samples, output_file);

    printf("\nAUDIO INVERTED IN X AXIS SUCCESSFULLY!\n\n");

    // Preencher um vetor com while e um segundo vetor para ler o vetor em ordem inversa
    // Transladar significa mudar o audio no eixo das amplitudes
    // Pegar os valores de amplitudes e guardar num vetor, para extrair suas caracteristicas

    fclose(input_file);
    fclose(output_file);

    free(data);

    return;
}

/* NOISE GENERATOR

// Pointer of output file gets the end of the header;
unsigned int size = ftell(output_file);

// Pointer of input file must be in the final char
fseek(input_file, 0, SEEK_END);
char data;

// Reads the input file backwards until reach the header
while (ftell(input_file) >= size)
{
    fread(&data, sizeof(char), 1, input_file);
    fwrite(&data, sizeof(char), 1, output_file);
    fseek(input_file, -2, SEEK_CUR); // Pointer moves for the previous char
}

*/