typedef struct wav_file
{
    char chunk_id[4]; // riff
    int chunk_size;
    char format[4]; // wave
    char subchunk1_id[4];
    int subchunk1_size;
    int audio_format;
    int num_channels;
    int sample_rate;
    int byte_rate;
    int block_align;
    int bytes_per_sample;
    char subchunk2_id[4];
    int subchunk2_size;
} Header;

void copy_wav();
void invert_wav();