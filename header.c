#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void copy_wav()
{
    FILE *input_file = fopen("applause.wav", "r");
    Header header;

    // Checks if the file exists
    if (!input_file)
    {
        printf("ERROR: FILE NOT FOUND");
        exit(1);
    }

    // Reads the header
    // fread(&header, sizeof(header), 1, input_file);

    // Collects the header data
    fseek(input_file, 0, SEEK_SET);
    int aqui = ftell(input_file);
    printf("PONTEIRO AQUI 1: %d\n\n", aqui);

    fscanf(input_file, "%s", &header.chunk_id);
    aqui = ftell(input_file);
    printf("PONTEIRO AQUI 2: %d\n\n", aqui);

    fscanf(input_file, "%d", &header.chunk_size);
    aqui = ftell(input_file);
    printf("PONTEIRO AQUI 2: %d\n\n", aqui);

    // Essa merda dando errado aqui tomar no cu porra caralho se foder buceta do cacete
    fscanf(input_file, "%s", &header.format);
    aqui = ftell(input_file);
    printf("PONTEIRO AQUI 3: %d\n\n", aqui);

    // fscanf(input_file, "%4s %d %4s %4s %d %d", &header.chunk_id, &header.chunk_size, &header.format, &header.subchunk1_id, &header.subchunk1_size, &header.audio_format);

    // Prints the collected data
    printf("File type: %s\n", header.chunk_id);
    printf("File size, excluding header: %d\n", header.chunk_size);
    printf("Subtype: %s\n");
    printf("Identifier: %s\n");
    printf("Chunck size post header: %d\n");
    printf("Format type: %d\n");
    printf("Number of channels: %d\n");
    printf("Sampling rate: %d\n");
    printf("Average number os bits per second: %d\n");
    printf("Block alignment in bytes: %d\n");
    printf("Resolution: %d\n");
    printf("Identifier: %s\n");
    printf("Data chunk size: %d\n");
    printf("Number of frames to be sampled: %d\n");
    printf("Windows length: %d\n");

    printf("\nPress ENTER to continue\n");
    getchar();
    getchar();

    fclose(input_file);
}

void invert_wav()
{
    printf("Aqui tambem");
}