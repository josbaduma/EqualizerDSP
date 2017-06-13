/*
 * DSP Example is part of the DSP Lecture at TEC-Costa Rica
 * Copyright (C) 2010  Pablo Alvarado
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * \file   freqFilter.h
 *         Implements filtering in the frequency domain
 * \author Pablo Alvarado/Jose Miguel Barboza
 * \date   2010.12.12/2017.05.26
 *
 * $Id: equalizer.cpp $
 */

#include "dspsystem.h"
#include <cstring>

#undef _DSP_DEBUG
#define _DSP_DEBUG

#ifdef _DSP_DEBUG
#define _debug(x) std::cerr << x
#include <iostream>
#else
#define _debug(x)
#endif


dspSystem::dspSystem()
    :sampleRate_(0),bufferSize_(0),cv_(0),filters_(0){
}

dspSystem::~dspSystem() {
    delete cv_;
    delete filters_;
}


void dspSystem::updateVolume(int value){
    /*
    * Updating volume value
    */
    volumeGain_=value;

}

void dspSystem::update31HzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter31HzGain_=value;
    std::cout << "31 Hz -> " << filter31HzGain_ << std::endl;

}

void dspSystem::update63HzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter63HzGain_=value;
    std::cout << "63 Hz -> " << filter63HzGain_ << std::endl;

}

void dspSystem::update125HzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter125HzGain_=value;
    std::cout << "125 Hz -> " << filter125HzGain_ << std::endl;

}

void dspSystem::update250HzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter250HzGain_=value;
    std::cout << "250 Hz -> " << filter250HzGain_ << std::endl;

}

void dspSystem::update500HzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter500HzGain_=value;
    std::cout << "500 Hz -> " << filter500HzGain_ << std::endl;

}

void dspSystem::update1kHzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter1kHzGain_=value;
    std::cout << "1 kHz -> " << filter1kHzGain_ << std::endl;

}

void dspSystem::update2kHzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter2kHzGain_=value;
    std::cout << "2 kHz -> " << filter2kHzGain_ << std::endl;

}

void dspSystem::update4kHzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter4kHzGain_=value;
    std::cout << "4 kHz -> " << filter4kHzGain_ << std::endl;

}

void dspSystem::update8kHzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter8kHzGain_=value;
    std::cout << "8 kHz -> " << filter8kHzGain_ << std::endl;

}

void dspSystem::update16kHzFilter(int value){
    /*
    * Updating filter gain value
    */
    filter16kHzGain_=value;
    std::cout << "16 kHz -> " << filter16kHzGain_ << std::endl;

}

/**
 * Initialization function for the current filter plan
 */
bool dspSystem::init(const int sampleRate,const int bufferSize) {
    _debug("dspSystem::init()" << std::endl);

    sampleRate_ = sampleRate;
    bufferSize_ = bufferSize;
    volumeGain_ = 10;
    filter31HzGain_ = 0;
    filter63HzGain_ = 0;
    filter125HzGain_ = 0;
    filter250HzGain_ = 0;
    filter500HzGain_ = 0;
    filter1kHzGain_ = 0;
    filter2kHzGain_ = 0;
    filter4kHzGain_ = 0;
    filter8kHzGain_ = 0;
    filter16kHzGain_ = 0;


    delete cv_;
    cv_=new controlVolume();

    delete filters_;
    filters_ = new Filtrado();

    return true;
}


/**
 * Processing function
 */
bool dspSystem::process(float* in,float* out) {
    float* tmpIn = in;
    float* tmpOut = out;
    float tmpOut31Hz[bufferSize_];
    float tmpOut63Hz[bufferSize_];
    float tmpOut125Hz[bufferSize_];
    float tmpOut250Hz[bufferSize_];
    float tmpOut500Hz[bufferSize_];
    float tmpOut1kHz[bufferSize_];
    float tmpOut2kHz[bufferSize_];
    float tmpOut4kHz[bufferSize_];
    float tmpOut8kHz[bufferSize_];
    float tmpOut16kHz[bufferSize_];

    copyArray(bufferSize_, tmpOut, tmpOut31Hz);
    copyArray(bufferSize_, tmpOut, tmpOut63Hz);
    copyArray(bufferSize_, tmpOut, tmpOut125Hz);
    copyArray(bufferSize_, tmpOut, tmpOut250Hz);
    copyArray(bufferSize_, tmpOut, tmpOut500Hz);
    copyArray(bufferSize_, tmpOut, tmpOut1kHz);
    copyArray(bufferSize_, tmpOut, tmpOut2kHz);
    copyArray(bufferSize_, tmpOut, tmpOut4kHz);
    copyArray(bufferSize_, tmpOut, tmpOut8kHz);
    copyArray(bufferSize_, tmpOut, tmpOut16kHz);

    cv_->filter(bufferSize_, volumeGain_, tmpIn, tmpOut);

    filters_->filter31Hz(bufferSize_, filter31HzGain_, tmpOut, tmpOut31Hz);
    filters_->filter63Hz(bufferSize_, filter63HzGain_, tmpOut, tmpOut63Hz);
    filters_->filter125Hz(bufferSize_, filter125HzGain_, tmpOut, tmpOut125Hz);
    filters_->filter250Hz(bufferSize_, filter250HzGain_, tmpOut, tmpOut250Hz);
    filters_->filter500Hz(bufferSize_, filter500HzGain_, tmpOut, tmpOut500Hz);
    filters_->filter1kHz(bufferSize_, filter1kHzGain_, tmpOut, tmpOut1kHz);
    filters_->filter2kHz(bufferSize_, filter2kHzGain_, tmpOut, tmpOut2kHz);
    filters_->filter4kHz(bufferSize_, filter4kHzGain_, tmpOut, tmpOut4kHz);
    filters_->filter8kHz(bufferSize_, filter8kHzGain_, tmpOut, tmpOut8kHz);
    filters_->filter16kHz(bufferSize_, filter16kHzGain_, tmpOut, tmpOut16kHz);

    for(int n=0; n<bufferSize_; n++) {
        out[n] = tmpOut31Hz[n] + tmpOut63Hz[n] + tmpOut125Hz[n] + tmpOut250Hz[n] + tmpOut500Hz[n]
                +tmpOut1kHz[n] + tmpOut2kHz[n] + tmpOut4kHz[n] + tmpOut8kHz[n] + tmpOut16kHz[n];
    }

    return true;
}

/**
 * Shutdown the processor
 */
bool dspSystem::shutdown() {
    return true;
}

/**
 * Set buffer size (call-back)
 */
int dspSystem::setBufferSize(const int bufferSize) {
    bufferSize_=bufferSize;
    return 1;
}

/**
 * Set sample rate (call-back)
 */
int dspSystem::setSampleRate(const int sampleRate) {
    sampleRate_=sampleRate;
    return 1;
}

void dspSystem::copyArray(int size, float* in, float* out){
    for(int i=0; i < size; i++){
        out[i] = in[i];
    }
}
