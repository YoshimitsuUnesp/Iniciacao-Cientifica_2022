#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char     ChunkID[4];
    uint32_t ChunkSize;
    char     Format[4];
    char     Subchunk1ID[4];
    uint32_t Subchunk1Size;
    uint16_t AudioFormat;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    char     Subchunk2ID[4];
    uint32_t Subchunk2Size;
} WavHeader;

int main() {
    // Abre o arquivo WAV para leitura
    FILE *inputFile = fopen("audio.wav", "r");
    if (!inputFile) {
        printf("Não foi possível abrir o arquivo para leitura!\n");
        return 1;
    }
    
    // Lê o cabeçalho do arquivo WAV
    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, inputFile);
    
    // Exibe algumas informações do arquivo WAV
    printf("Caminho do arquivo: audio.wav\n");
    printf("Número de canais: %d\n", header.NumChannels);
    printf("Taxa de amostragem: %d Hz\n", header.SampleRate);
    printf("Bits por amostra: %d\n", header.BitsPerSample);
    
    // Calcula o número total de amostras no arquivo
    uint32_t numSamples = header.Subchunk2Size / (header.BitsPerSample / 8);
    
    // Aloca memória para armazenar os dados do áudio
    int16_t *audioData = (int16_t*)malloc(numSamples * sizeof(int16_t));
    
    // Lê os dados do áudio
    fread(audioData, sizeof(int16_t), numSamples, inputFile);
    
    // Fecha o arquivo de entrada
    fclose(inputFile);
    
    // Abre o arquivo WAV para escrita
    FILE *outputFile = fopen("audio_out.wav", "wb");
    if (!outputFile) {
        printf("Não foi possível abrir o arquivo para escrita!\n");
        return 1;
    }
    
    // Escreve o cabeçalho do arquivo WAV
    fwrite(&header, sizeof(WavHeader), 1, outputFile);
    
    // Escreve os dados do áudio
    fwrite(audioData, sizeof(int16_t), numSamples, outputFile);
    
    // Fecha o arquivo de saída
    fclose(outputFile);
    
    // Libera a memória alocada
    free(audioData);
    
    return 0;
}
