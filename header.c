#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void copy_wav()
{
    int i;
    FILE *input_file = fopen("applause.wav", "rb");
    Header header;

    // Checks if the file exists
    if (!input_file)
    {
        printf("ERROR: FILE NOT FOUND");
        exit(1);
    }

    // Collects the header data
    // First chunk
    fread(&header.chunk_id, sizeof(header.chunk_id) - 1, 1, input_file);
    fread(&header.chunk_size, sizeof(header.chunk_size), 1, input_file);
    fread(&header.format,sizeof(header.format) - 1, 1, input_file);

    // Sub-chunk 1
    fread(&header.subchunk1_id, sizeof(header.subchunk1_id) - 1, 1, input_file);
    fread(&header.subchunk1_size, sizeof(header.subchunk1_size), 1, input_file);
    fread(&header.audio_format, sizeof(header.audio_format), 1, input_file);
    fread(&header.num_channels, sizeof(header.num_channels), 1, input_file);
    fread(&header.sample_rate, sizeof(header.sample_rate), 1, input_file);
    fread(&header.byte_rate, sizeof(header.byte_rate), 1, input_file);
    fread(&header.block_align, sizeof(header.block_align), 1, input_file);
    fread(&header.bits_per_sample, sizeof(header.bits_per_sample), 1, input_file);
    
    // Sub-chunk 2
    fread(&header.subchunk2_id, sizeof(header.subchunk2_id) - 1, 1, input_file);
    fread(&header.subchunk2_size, sizeof(header.subchunk2_id), 1, input_file);

    header.chunk_id[4] = '\0';
    header.format[4] = '\0';
    header.subchunk1_id[4] = '\0';
    header.subchunk2_id[4] = '\0';

    // Prints the collected data
    printf("File type: %s\n", header.chunk_id);    
    printf("File size, excluding header: %d\n", header.chunk_size);
    printf("Subtype: %s\n", header.format);
    printf("Identifier: %s\n", header.subchunk1_id);
    printf("Chunck size post header: %d\n", header.subchunk1_size);
    printf("Format type: %d\n", header.audio_format); // Erro aqui
    printf("Number of channels: %d\n", header.num_channels); // Erro aqui
    printf("Sampling rate: %d\n", header.sample_rate);
    printf("Average number os bits per second: %d\n", header.byte_rate);
    printf("Block alignment in bytes: %hu\n", header.block_align);
    printf("Resolution: %hu\n", header.bits_per_sample);
    printf("Identifier: %s\n", header.subchunk2_id);
    printf("Data chunk size: %d\n", header.subchunk2_size);
    printf("Number of frames to be sampled: %d\n", header.subchunk2_size / header.block_align);
    printf("Windows length: %d\n", header.subchunk2_size / header.block_align / header.num_channels); // Erro aqui

    short int a;
    printf("%d", sizeof(a));

    printf("\nPress ENTER to continue\n");
    getchar();
    getchar();

    fclose(input_file);
}

void invert_wav()
{
    printf("Aqui tambem");
}