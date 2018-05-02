#include "common.h"

#include <iostream>

#include <set>
#include <vector>
#include <tuple>

#include <fstream>
#include <sstream>

#include <iomanip>
#include <cstring>

template <typename Com> void Common <Com>::test()
{
    std::cout << "test common" << std::endl;
}


template <typename Com> std::string Common <Com>::add_zeroes(std::string l, int full_length, bool begin)
{
    if ( (int) l.length() < full_length)
    {
        if (begin) { return std::string(full_length - l.length(), '0') + l; }
        else { return l + std::string(full_length - l.length(), '0'); }
    }            

    else { return l; }
}

template <typename Com> void Common <Com>::output_vector(std::vector<Com> vect)
{
    for (unsigned int i = 0; i < vect.size(); i++)
    {        
        //std::cout << std::streamsize(3) << vect[i] << " ";
        std::cout << std::setw(3) << vect[i] << " ";

    }
    std::cout << "\n\n";
}

template <typename Com> std::vector<Com> Common <Com>::concat_vector(std::vector<Com> v1, std::vector<Com> v2)
{

    v1.insert( v1.end(), v2.begin(), v2.end());    
    return v1;
        
}



template <typename Com> void Common <Com>::write_little_endian(unsigned int word, 
																															 int num_bytes, FILE *wav_file)
{
    unsigned buf;
    while(num_bytes>0)
    {   buf = word & 0xff;
        fwrite(&buf, 1,1, wav_file);
        num_bytes--;
    word >>= 8;
    }
}
  
template <typename Com> void Common <Com>::write_wav(unsigned long num_samples, 
																										 short* data, 
																										 unsigned long int sample_rate)
{
    FILE* wav_file;
    unsigned int num_channels;
    unsigned int bytes_per_sample;
    unsigned int byte_rate;
 
    num_channels = 1;   /* monoaural */
    bytes_per_sample = 2;
 
    byte_rate = sample_rate * num_channels * bytes_per_sample;
 
    wav_file = fopen("message.wav", "w");
    //std::cout << "NUM_SAMPLES = " << num_samples << "\n";

    /* write RIFF header */
    fwrite("RIFF", 1, 4, wav_file);
    write_little_endian(36 + bytes_per_sample* num_samples*num_channels, 4, wav_file);
    fwrite("WAVE", 1, 4, wav_file);	

    /* write fmt  subchunk */
    fwrite("fmt ", 1, 4, wav_file);
    write_little_endian(16, 4, wav_file);   /* SubChunk1Size is 16 */
    write_little_endian(1, 2, wav_file);    /* PCM is format 1 */
    write_little_endian(num_channels, 2, wav_file);
    write_little_endian(sample_rate, 4, wav_file);
    write_little_endian(byte_rate, 4, wav_file);
    write_little_endian(num_channels*bytes_per_sample, 2, wav_file);  /* block align */
    write_little_endian(8*bytes_per_sample, 2, wav_file);  /* bits/sample */
    
    /* write data subchunk */
    fwrite("data", 1, 4, wav_file);
    write_little_endian(bytes_per_sample* num_samples*num_channels, 4, wav_file);
    
		for (unsigned long int i = 0; i < num_samples; i++)
    {   
				write_little_endian((unsigned int)(data[i]), bytes_per_sample, wav_file);
    }
 
    fclose(wav_file);
}


template <typename Com> void Common <Com>::wav_reader()
{
    FILE *fin = fopen("message.wav", "rb");

    //Read WAV header
    WAVHEADER header;
    fread(&header, sizeof(header), 1, fin);

    //Print WAV header
    std::cout << "WAV File Header read:\n";
    std::cout << "File Type: " << header.chunkID << std::endl;
    std::cout << "File Size: " << header.chunkSize << std::endl;
    std::cout << "WAV Marker: " << header.format << std::endl;
    std::cout << "Format Name: " << header.subchunk1ID << std::endl;
    std::cout << "Format Length: " << header.subchunk1Size << std::endl;
    std::cout << "Format Type: " << header.audioFormat << std::endl;
    std::cout << "Number of Channels: " << header.numChannels << std::endl;
    std::cout << "Sample Rate: " << header.sampleRate << std::endl;
    std::cout << "Sample Rate * Bits/Sample * Channels / 8: " << header.byteRate << std::endl;
    std::cout << "Bits per Sample * Channels / 8.1:" << header.blockAlign <<std::endl;
    std::cout << "Bits per Sample: " << header.bitsPerSample << std::endl;

    //skip wExtraFormatBytes & extra format bytes
    //fseek(f, header.chunkSize - 16, SEEK_CUR);

    //Reading file
    CHUNK_T chunk;
    printf("id\t" "size\n");
    //go to data chunk
		
    while (true)
    {
        fread(&chunk, sizeof(chunk), 1, fin);
        //std::cout << chunk.ID[0] << " " << chunk.ID[1] << " " << chunk.ID[3] << " " << chunk.size << "    |    "; 
        if (*(unsigned int *)&chunk.ID == 0x61746164)
            break;
        //skip chunk data bytes
        fseek(fin, chunk.size, SEEK_CUR);
    }
		

    //Number of samples
    int sample_size = header.bitsPerSample / 8;
    int samples_count = chunk.size * 8 / header.bitsPerSample;
    printf("Samples count = %i\n", samples_count);

    short int *value = new short int[samples_count];
    memset(value, 0, sizeof(short int) * samples_count);

    //Reading data
    for (int i = 0; i < samples_count; i++)
    {
        fread(&value[i], sample_size, 1, fin);
        std::cout << value[i] << " ";
    }

}


template <typename Com> std::vector<float> Common<Com>::WavReader()
{

		FILE *fin = fopen("message.wav", "rb");
	
		WAVHEADER header;
		fread(&header, sizeof(header), 1, fin);
		float Fd = header.sampleRate; //÷àñòîòà äèñêðåòèçàöèè
		float Td = (float)2 / Fd;
		CHUNK_T chunk;
	
		while (true)
		{
				int buff;
				fread(&buff, 2, 1, fin);
				fread(&chunk, sizeof(chunk), 1, fin);
				
				if (*(unsigned int *)&chunk.ID == 0x61746164)
						break;
				fseek(fin, chunk.size, SEEK_CUR);
		}

		std::vector<float> res;
		
		int sample_size = header.bitsPerSample / 8;
		int samples_count = chunk.size * 8 / header.bitsPerSample;
		short *value = new short[samples_count];
		memset(value, 0, sizeof(short) * samples_count);
		
		for (int i = 0; i < samples_count; i++) {
				fread(&value[i], sample_size, 1, fin);
		}
	
		fclose(fin);
	
		for (int i = 0; i < samples_count; i++) {
				res.push_back(value[i]);
		}
		
		std::cout << "Decoding..." << std::endl;
		return res;
}

template <typename Com> void Common <Com>::write_wav_0(short *data, int sampleRate)

{
    int size=10000;
    header.sampleRate=44100.0;// частота оцифровки
    header.numChannels=1; // одноканальный
    header.bitsPerSample=16; // бит на один отсчет
    header.blockAlign=2; // размер блока в байтах
    header.subchunk2Size=size*2; // размер данных
 
    FILE* pf;
		pf = fopen("test_0.wav" ,"wb");
		fwrite(&header, sizeof(WAVHEADER), 1, pf); 
    fwrite(data,2,size,pf);
    fclose(pf);
}

template <typename Com> void Common <Com>::write_wav_1(short *data, int sampleRate)
{
		short frameSize = (short)(16 / 8);
		WAVHEADER stream;
		stream.chunkId[0] = 'R';
		stream.chunkId[1] = 'I';
		stream.chunkId[2] = 'F';
		stream.chunkId[3] = 'F';
		stream.chunkSize = (36 + sampleRate * frameSize);
		stream.format[0] = 'W';
		stream.format[1] = 'A';
		stream.format[2] = 'V';
		stream.format[3] = 'E';
		stream.subchunk1Id[0] = 'f';
		stream.subchunk1Id[1] = 'm';
		stream.subchunk1Id[2] = 't';
		stream.subchunk1Id[3] = ' ';
		stream.subchunk1Size = (16);
		stream.audioFormat = ((short)1);
		stream.numChannels = ((short)1);
		stream.sampleRate = sampleRate;
		stream.byteRate = (sampleRate * frameSize);
		stream.blockAlign = frameSize;
		stream.bitsPerSample = ((short)16);
		stream.subchunk2Id[0] = 'd';
		stream.subchunk2Id[1] = 'a';
		stream.subchunk2Id[2] = 't';
		stream.subchunk2Id[3] = 'a';
		stream.subchunk2Size = (sampleRate * frameSize);

		FILE *f1;
		f1 = fopen("test_1.wav", "w+b");
		fwrite(&stream, sizeof(stream), 1, f1);
		
		for (int i = 0; i < sampleRate; i++)
		{  
				fwrite(&data[i], sizeof(short),1, f1);
		}
		std::cout << "next" << std::endl;
		fclose(f1);
}

