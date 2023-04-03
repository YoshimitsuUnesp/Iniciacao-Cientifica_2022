typedef struct wav_file{

    // int = 4 bytes
    // short int = 2 bytes
    char chunk_id[4]; // riff
    unsigned int chunk_size;
    char format[4]; // wave

    char subchunk1_id[4]; // fmt
    unsigned int subchunk1_size;
    unsigned short int audio_format;
    unsigned short int num_channels;
    unsigned int sample_rate;
    unsigned int byte_rate;
    unsigned short int block_align;
    unsigned short int bits_per_sample;

    char subchunk2_id[4]; // data
    unsigned int subchunk2_size;
} Header;

void copy_wav();
void invert_wav();