typedef struct wav_file
{
    // It needs 4 characters + \0
    // int = 4 bytes
    // unsigned short int = 2 bytes
    char chunk_id[5]; // riff
    unsigned int chunk_size;
    char format[5]; // wave

    char subchunk1_id[5]; // fmt
    unsigned short int subchunk1_size;
    unsigned short int audio_format;
    unsigned int num_channels;
    unsigned int sample_rate;
    unsigned int byte_rate;
    unsigned short int block_align;
    unsigned short int bits_per_sample;

    char subchunk2_id[5]; // data
    unsigned int subchunk2_size;
} Header;

void copy_wav();
void invert_wav();