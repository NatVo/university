//#include <stdafx.h>
#include <math.h>
#include <iostream>
//#include <Windows.h>
#include <climits>
 
 
double PI=3.14159265358979323846;
class Generator {
    public: 
 
        static void Wave() {
            int sampleRate = 44100;// частота дискретизации.
            short *data = new short[sampleRate]; // Инициализируем массив 16 битных значений
            double frequency = PI * 2 * 1040.0 / sampleRate; // Рассчитываем требующуюся частоту.
            for (int index = 0; index < sampleRate; index++) { 
                 std::cout << "-";
                 data[index] = (short)(Sine(index, frequency) * SHRT_MAX);// Приводим уровень к амплитуде от 32767 до -32767.
            }
            SaveWave(data, sampleRate);
        }
 
        static double Sine(int index, double frequency) {//Расчет значений для синусоидальной волны
            return sin(frequency * index);
        }
        //Header WAV файла
        struct WAVHEADER{
            // WAV-формат начинается с RIFF-заголовка:
            char chunkId[4];// Содержит символы "RIFF" в ASCII кодировке
            unsigned long chunkSize;// 36 + subchunk2Size, или более точно:
            char format[4];// Содержит символы "WAVE"
            char subchunk1Id[4];// Содержит символы "fmt "
            unsigned long subchunk1Size;// 16 для формата PCM.
            unsigned short audioFormat;// Для PCM = 1 (то есть, Линейное квантование).
            unsigned short numChannels;// Количество каналов. Моно = 1, Стерео = 2 и т.д.
            unsigned long sampleRate;// Частота дискретизации. 8000 Гц, 44100 Гц и т.д.
            unsigned long byteRate;// sampleRate * numChannels * bitsPerSample/8
            unsigned short blockAlign;// Количество байт для одного сэмпла, включая все каналы. numChannels * bitsPerSample/8
            unsigned short bitsPerSample;// Так называемая "глубиная" или точность звучания. 8 бит, 16 бит и т.д.
            char subchunk2Id[4];// Подцепочка "data" содержит аудио-данные и их размер.Содержит символы "data"
            unsigned long subchunk2Size;// Количество байт в области данных. numSamples * numChannels * bitsPerSample/8
        };
        //Функция записи WAV файла
        static void SaveWave( short *data, int sampleRate){
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
            f1 = fopen("test.wav", "w+b");
            fwrite(&stream, sizeof(stream), 1, f1);
            for (int i = 0; i < sampleRate; i++){   
                    fwrite(&data[i], sizeof(short),1, f1);//записываем байты элемента i массива data
            }
            fclose(f1);
        }
 };
int main()
{
    Generator r;
    r.Wave();
    //std::cin.get(); 
    return 0;
}
