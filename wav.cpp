// Video de auxilio: https://www.youtube.com/watch?v=rHqkeLxAsTc
// Explicacao WAVE: http://soundfile.sapp.org/doc/WaveFormat/

#include <iostream>
#include <fstream>

using namespace std;

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


typedef struct{
    char chunk_id[4]; // riff
    int chunk_size;
    char format[4]; // wave
    char subchunk_1_id[4];
    int subchunk1_size;
    int audio_format;
    int num_channels;
    int sample_rate;
    int byte_rate;
    int block_align;
    int bytes_per_sample;
    
}Header;

int main(){


    return 0;
}