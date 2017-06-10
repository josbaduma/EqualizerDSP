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
  :sampleRate_(0),bufferSize_(0),cv_(0){
}

dspSystem::~dspSystem() {
    delete cv_;
    delete filters_;
    cv_;
    filters_;
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

}

void dspSystem::update63HzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter63HzGain_=value;

}

void dspSystem::update125HzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter125HzGain_=value;

}

void dspSystem::update250HzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter250HzGain_=value;

}

void dspSystem::update500HzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter500HzGain_=value;

}

void dspSystem::update1kHzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter1kHzGain_=value;

}

void dspSystem::update2kHzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter2kHzGain_=value;

}

void dspSystem::update4kHzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter4kHzGain_=value;

}

void dspSystem::update8kHzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter8kHzGain_=value;

}

void dspSystem::update16kHzFilter(int value){
   /*
    * Updating filter gain value
    */
   filter16kHzGain_=value;

}

/**
 * Initialization function for the current filter plan
 */
bool dspSystem::init(const int sampleRate,const int bufferSize) {
  _debug("dspSystem::init()" << std::endl);

  sampleRate_ = sampleRate;
  bufferSize_ = bufferSize;
  volumeGain_ = 1;
  filter31HzGain_ = 1;


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
  //float* tmpOutFilter31Hz = out;

  cv_->filter(bufferSize_, volumeGain_, tmpIn, tmpOut);

  //filters_->filter31Hz(bufferSize_, filter31HzGain_, tmpOut, tmpOutFilter31Hz);

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
