#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include "wav.h"


int generate_sinusoid ( double frequency,
                       double amplitude,
                       int32_t SampleRate,
                       int32_t FrameCount,
                       int16_t  *buffer_p,
                       int position)
{
    int ret = 0;
    double SampleRate_d = (double)SampleRate;
    
    int32_t k;
    int16_t wave;

    
    for(k = 0; k < FrameCount ; k++)
    {
        wave = (int16_t) (amplitude * sin(k*frequency*2.0*M_PI/SampleRate_d));
        buffer_p[position + k] = wave;
        
    }
    return ret;

}

size_t write_CSV_file(char* filename, int32_t FrameCount,
                      int16_t  *buffer_p)
{
    size_t ret = 0;
    FILE *csvfile;
    csvfile = fopen(strcat(filename, "_samples.csv"), "w");
    for (int32_t n=0 ; n<FrameCount ; n++){
        ret += fprintf(csvfile, "%d\n", buffer_p[n]);
    }
    fclose(csvfile);
    return ret;
}

void generate_melody (int16_t *buffer_p){


    double amplitude = 1.0 * (double)SHRT_MAX; // (16 bits)
    int duration = 8;//8 secondess
    int32_t FrameCount = duration * SAMPLE_RATE;

   

    double melodie[16] ={264,297, 330, 352, 396, 440, 491, 528, 694, 660, 704, 792, 880, 990, 1056, 0};

    int16_t wave;
 i  int offset = 0;
   
    for (int o = 0; o < 16; ++o)
    {
	    wave = generate_sinusoid ( mel[o],
	                             amplitude,
	                           SAMPLE_RATE,
	                           FrameCount/16,
	                           buffer_p,
	                           offset);
	    offset += FrameCount/16;
    }

    
}

void quantification4bits(int16_t *buffer_p){

    double SampleRate_d = (double)SAMPLE_RATE;
    double amplitude = 1.0 * (double)SHRT_MAX; // (16 bits)
    int duration = 8;//8 secondess
    int32_t FrameCount = duration * SAMPLE_RATE;
    int position = 0;
    double mel[16] ={264,297, 330, 352, 396, 440, 491, 528, 694, 660, 704, 792, 880, 990, 1056, 0};
    int32_t k;
    int16_t wave;
    int tmp;

    for (int o = 0; o < 16; ++o){
        for(k = 0; k < FrameCount/16 ; k++)
        {
            wave = (int16_t) (amplitude * sin(k*mel[o]*2.0*M_PI/SampleRate_d));
            tmp = (int)wave / 4096;
            wave =  tmp * 4096;
            buffer_p[position + k] = wave;
            
        }
        position += FrameCount/16;
    }

}

int main(int argc, char *argv[])
{

    char *filename;
    FILE* file_p;
    int duration = 8;//8 secondes
    int32_t FrameCount = duration * SAMPLE_RATE;
    int16_t *buffer_p = NULL;
    size_t written;
    int ret;

    buffer_p = allocate_PCM16_buffer(FrameCount);
    if(NULL == buffer_p)
    {
        perror("allocate_PCM16_buffer failed in main");
        ret = -1;
        goto error1;
    }
    
    if (argc != 2){ 
        fprintf(stderr, "Usage: %s filename \n", argv[0]);
        exit(1);
    }
    else
        filename = argv[1];

    file_p = fopen("mel_4b.wav", "w");
    if(NULL == file_p)
    {
        perror("fopen failed in main");
        ret = -1;
    }
    //generate_melody(buffer_p);
    quantification4bits(buffer_p);

    write_CSV_file(filename, FrameCount, buffer_p);
    
    /*Write the wav file header*/
    ret = write_PCM16_header(file_p,
                             SAMPLE_RATE,
                             FrameCount);
    if(ret < 0)
    {
        perror("write_PCM16_header failed in main");
        ret = -1;
        goto error2;
    }
    written = write_PCM16wav_data(  file_p,
                                  FrameCount,
                                  buffer_p);

    if(written < FrameCount)
    {
        perror("write_PCM16wav_data failed in main");
        ret = -1;
        goto error2;
    }

error2:
    free(buffer_p);
error1:
    fclose(file_p);

    
    return 0;

    
}
