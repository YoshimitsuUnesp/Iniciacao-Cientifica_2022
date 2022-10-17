// Video de auxilio: https://www.youtube.com/watch?v=rHqkeLxAsTc
// Explicacao WAVE: http://soundfile.sapp.org/doc/WaveFormat/

#include <iostream>
#include <fstream>

using namespace std;

// Riff chunk (header)
const string chunk_id = "RIFF"; // 4 bytes - sempre recebe a palavra RIFF
const string chunk_size = "####"; // 4 bytes de espaco
const string format = "WAVE"; // 4 bytes - format recebe WAVE

// Format sub-chunk
const string subchunk1_id = "fmt "; // 4 bytes - recebe fmt
const int subchunk1_size = 16; // 4 bytes - tem tamanho de 16
const int audio_format = 1; // 4 bytes - valor acima de 1 indica compressao
const /* short */ int num_channels = 2; // 2 bytes - 1 (mono), 2 (stereo), ...
const int sample_rate = 44100; // 4 bytes - 8000, 44100





int main(){


    return 0;
}