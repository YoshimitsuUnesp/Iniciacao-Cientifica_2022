#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Header get_header(Header header, FILE *file)
{
    // Collects the header data
    fread(&header, sizeof(header), 1, file);

    // Prints the collected data
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

    return header;
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

    Header header = get_header(header, input_file);

    // Copies the data
    unsigned int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    short int *data = malloc(num_samples * sizeof(short int)); // Allocates the size audio data

    fread(data, sizeof(short int), num_samples, input_file); // Reads the entire data

    FILE *output_file = fopen("copy.wav", "wb");

    if (!output_file)
    {
        printf("\nERROR: COULD NOT OPEN COPY FILE\n\n");
        return;
    }

    // Writes the header and the data to the copy file
    fwrite(&header, sizeof(header), 1, output_file);
    fwrite(data, sizeof(short int), num_samples, output_file);

    printf("\nFILE COPY CREATED SUCCESSFULLY!\n\n");

    fclose(input_file);
    fclose(output_file);

    free(data);

    return;
}

void invert_wav()
{
    FILE *input_file = fopen("copy.wav", "rb");

    if (!input_file)
    {
        printf("\nERROR: FILE NOT FOUND\n\n");
        return;
    }

    Header header = get_header(header, input_file);

    FILE *output_file = fopen("inverted.wav", "wb");

    // Writes the header in the inverted file
    fwrite(&header, sizeof(Header), 1, output_file);

    // Needs to reverse each sample     

    fclose(input_file);
    fclose(output_file);

    return;
}