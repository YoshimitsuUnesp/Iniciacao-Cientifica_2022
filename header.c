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
    fread(&header, sizeof(header), 1, input_file);

    // Needs to decide if will use pointers or change the int types

    // Prints the collected data
    printf("File type: %s");
    printf("File size, excluding header: %d");
    printf("Subtype: %s");
    printf("Identifier: %d");
    printf("Chunck size post header: %d");
    printf("Format type: %d");
    printf("Number of channels: %d");
    printf("Sampling rate: %d");
    printf("Average number os bits per second: %d");
    printf("Block alignment in bytes: %d");
    printf("Resolution: %d");
    printf("Identifier: %d");
    printf("Data chunk size: %d");
    printf("Number of frames to be sampled: %d");
    printf("Windows length: %d");
}

void invert_wav()
{
    printf("Aqui tambem");
}