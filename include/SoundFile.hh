/*
    At the moment this is home to the playSoundFile function. This might be expanded into
    a larger soundfile class that simply encapsulates the libsndfile functions.
    Also contained here is a "playsine" function used for testing.
*/

#ifndef SOUNDFILE_H
#define SOUNDFILE_H

#ifdef _WIN32
    #include "sndfile.h"
    #include "sndfile.hh"
#else
    #include <sndfile.hh>
#endif

#include "AudioIO.hh"
#include "Factory_AudioIO.hh"
#include "ioUtils.hh"
#include <vector>
#include <math.h>
#include <string>
#include <cstring>
#include <exception>

#define FRAMES_PER_BUFFER (512)
#define TWO_PI 6.28315

class SoundFile_Exception : public std::exception{
    public:
        virtual const char* what() const throw() { return "Play Sound File exception."; }
};

class isNotOutputDevice: public SoundFile_Exception{
    public:
        virtual const char* what() const throw() { return "Device is not an output device."; }
};



void playSoundFile(const char* soundfile, AudioIOType audioIO = AudioIOType::PA_DEFAULT);
    
void playSine();

#endif
