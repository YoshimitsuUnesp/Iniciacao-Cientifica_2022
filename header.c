#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "menu.h"

Header get_header(Header header, FILE *file)
{
    // Collects the header data
    fread(&header, sizeof(Header), 1, file);

    printf("\nWAV header copied successfully!\n\n");

    printf("\nPress ENTER to continue\n");
    getchar();
    getchar();

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
}

void copy_wav()
{
    // Change this line to select the audio
    FILE *input_file = fopen("audio1.wav", "rb");

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

    clear_screen();

    printf("\nFILE COPY CREATED SUCCESSFULLY!\n\n");

    printf("\nPress ENTER to continue\n");
    getchar();

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

    clear_screen();

    printf("\nAUDIO INVERTED IN Y AXIS SUCCESSFULLY!\n\n");

    printf("\nPress ENTER to continue\n");
    getchar();

    fclose(input_file);
    fclose(output_file);

    free(data);
    free(inverted_data);

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

    unsigned int num_samples = header.subchunk2_size / (header.bits_per_sample / 8);
    short int *data = malloc(num_samples * sizeof(short int));
    int i;

    // Inverts the amplitude of the samples
    fread(data, sizeof(short int), num_samples, input_file);
    for (i = 0; i < num_samples; i++)
        data[i] *= -1;
    fwrite(data, sizeof(short int), num_samples, output_file);

    clear_screen();

    printf("\nAUDIO INVERTED IN X AXIS SUCCESSFULLY!\n\n");

    printf("\nPress ENTER to continue\n");
    getchar();

    fclose(input_file);
    fclose(output_file);

    free(data);

    return;
}

double calculate_energy(short *frame_data, int frame_size)
{
    double energy = 0;

    for (int i = 0; i < frame_size; i++)
        energy += pow(frame_data[i], 2);

    return energy / frame_size;
}

double calculate_zcr(short *frame_data, int frame_size)
{
    double zcr = 0;

    for (int i = 0; i < frame_size - 1; i++)
        zcr += frame_data[i] * frame_data[i + 1] < 0;

    return zcr / (frame_size - 1);
}

void frame_selector()
{
    FILE *input_file = fopen("audio9.wav", "rb");

    // Checks if the file exists
    if (!input_file)
    {
        printf("\nERROR: FILE NOT FOUND\n\n");
        return;
    }

    // Gets the WAV file header
    Header header = get_header(header, input_file);

    // sampling rate = 441000
    // Since 441000 / 30 miliseconds = 1323, we will consider window size of 1024 samples
    int frame_size = 1024;

    // Number of frames in the entire audio
    int num_frames = header.subchunk2_size / (header.bits_per_sample / 8) / frame_size;

    printf("Number of frames: %d\n", num_frames);

    // 1400 = voiced, 4900 = unvoiced. (4900+1400)/2 = 3150
    // Considering median of 3150 zero-crossings per second, we have 94.5 zero-crossings in 30 ms
    // ZCR hard threshold: 94.5 / (1024-1) = 0.924

    // Considering each window placement covers L = 1024 samples, the normalized level is 1024
    // 1 / 2 ^ 15. 2 ^ 10 / 2 ^ 15 = 2 ^ -5 = 0.0313

    // Thresholds for zero crossings and energy
    double zcr_threshold = 0.924;
    double energy_threshold = 0.0313;

    // Frame data buffer
    short *frame_data = (short *)malloc(frame_size * sizeof(short));

    double max_energy = 0;
    for (int i = 0; i < num_frames; i++)
    {
        // Reads the current frame data
        fread(frame_data, sizeof(short), frame_size, input_file);

        // Calculates the energy of the current frame
        double energy = calculate_energy(frame_data, frame_size);

        // Updates the maximum energy value
        if (energy > max_energy)
            max_energy = energy;
    }

    // Rewinds the input file to the beginning of the data
    fseek(input_file, sizeof(Header), SEEK_SET);

    for (int i = 0; i < num_frames; i++)
    {
        // Reads the current frame data
        fread(frame_data, sizeof(short), frame_size, input_file);

        // Calculates the normalized energy of the current frame
        double energy = calculate_energy(frame_data, frame_size) / max_energy;

        // Calculates the zero crossing rate of the current frame
        double zcr = calculate_zcr(frame_data, frame_size);

        if (energy > energy_threshold && zcr < zcr_threshold && zcr > 0)
        {
            printf("Frame %d is voiced\n", i + 1);
            printf("Energia detectada: %f\nZCR: %f\n", energy, zcr);
        }
        else
            printf("Frame %d is unvoiced\n", i + 1);
    }

    free(frame_data);
    fclose(input_file);
}