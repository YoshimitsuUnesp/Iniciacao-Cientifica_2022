// Video de auxilio: https://www.youtube.com/watch?v=rHqkeLxAsTc
// Explicacao WAVE: http://soundfile.sapp.org/doc/WaveFormat/

/*
// Riff chunk (header)
const string chunk_id = "RIFF"; // 4 bytes - sempre recebe a palavra RIFF
const string chunk_size = "####"; // 4 bytes de espaco
const string format = "WAVE"; // 4 bytes - recebe WAVE

// Format subchunk
const string subchunk1_id = "fmt "; // 4 bytes - recebe fmt
const int subchunk1_size = 16; // 4 bytes - tem tamanho de 16
const int audio_format = 1; // 4 bytes - valor acima de 1 indica compressao
const int num_channels = 2; // 2 bytes - 1 (mono), 2 (stereo), ...
const int sample_rate = 44100; // 4 bytes - 8000, 44100
const int byte_rate = sample_rate * num_channels * (bits_per_sample / 8); // 4 bytes
const int block_align = num_channels * (bits_per_sample / 8); // 2 bytes - Num de bytes para uma amostra incluindo os canais
const int bits_per_sample = 16; // 2 bytes - 8 bits = 8, 16 bits = 16, ...

// Data subchunk
const string subchunk2_id = "data"; // 4 bytes - sempre recebe a palavra data
const string subchunk2_size = "####"; // 4 bytes - Num de bytes nos dados
*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Compiled using GCC 64 bit; int = 4 bytes

int main()
{
    int op;

    do
    {
        printf(
            "------------------------------\n"
            "|         MAIN MENU          |\n"
            "------------------------------\n"
            "| 1 - Copy WAV file          |\n"
            "| 2 - Invert Y axis WAV file |\n"
            "| 3 - Invert X axis WAV file |\n"
            "| 0 - Exit                   |\n"
            "------------------------------\n"
            "\nChoose an option:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("\nClosing program...\n");
            exit(0);
            break;
        case 1:
            copy_wav();
            break;
        case 2:
            invert_y_axis_wav();
            break;
        case 3:
            invert_x_axis_wav();
            break;
        default:
            printf("\nERROR: INVALID CODE\n\n");
            break;
        }
    } while (op != 0);

    return 0;
}