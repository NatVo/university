#ifndef __COMMON_H__
#define __COMMON_H__
#include <iostream>
#include <vector>

template <typename Com> class Common
{
  private: 
    //int common;          
    struct WAVHEADER
    {
        char chunkID[4];
        unsigned long chunkSize;
        char format[4];
        char subchunk1ID[4];
        unsigned long subchunk1Size; 
        unsigned short audioFormat;
        unsigned short numChannels;
        unsigned long sampleRate;
        unsigned long byteRate;
        unsigned short blockAlign;
        unsigned short bitsPerSample;
        char subchunk2ID[4];
        unsigned long subchunk2Size;
         
    }header;

		struct CHUNK_T
		{
    		char ID[4]; //"data" = 0x61746164
    		unsigned long size;  //Chunk data bytes
		};
        
  public:
    
    void test();          
       
    std::string add_zeroes(std::string l, int full_length, bool begin);
    void output_vector(std::vector<Com> vect);
    std::vector<Com> concat_vector(std::vector<Com> v1, std::vector<Com> v2);

    //void write_wav(short *data, int sampleRate);

    void write_little_endian(unsigned int word, int num_bytes, FILE *wav_file);
    void write_wav(unsigned long num_samples, 
                   short * data, 
                   unsigned long int sample_rate);


    void wav_reader();	
		std::vector<float> WavReader();

    void write_wav_0(short *data, int sampleRate);
    void write_wav_1(short *data, int sampleRate);

};

#endif
