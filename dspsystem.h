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

#ifndef DSPSYSTEM_H
#define DSPSYSTEM_H

#include "processor.h"
#include "controlvolume.h"
#include "filtrado.h"

class dspSystem : public processor {
public:
  /**
   * Constructor
   */
  dspSystem();

  /**
   * Destructor
   */
  ~dspSystem();

  /**
   * Initialization function for the current filter plan
   */
  virtual bool init(const int frameRate,const int bufferSize);

  /**
   * Processing function
   */
  virtual bool process(float* in,float* out);

  /**
   * Shutdown the processor
   */
  virtual bool shutdown();

  /**
   * Set buffer size
   */
  virtual int setBufferSize(const int bufferSize);

  /**
   * Set frame rate
   */
  virtual int setSampleRate(const int sampleRate);

  void updateVolume(int value);

  void update31HzFilter(int value);

  void update63HzFilter(int value);

  void update125HzFilter(int value);

  void update250HzFilter(int value);

  void update500HzFilter(int value);

  void update1kHzFilter(int value);

  void update2kHzFilter(int value);

  void update4kHzFilter(int value);

  void update8kHzFilter(int value);

  void update16kHzFilter(int value);
protected:

  /**
   * Sample rate
   */
  int sampleRate_;

  /**
   * Buffer size
   */
  int bufferSize_;

  /**
   * VolumeGain
   */

  int volumeGain_;

  /**
   * 31 Hz filter Gain
   */

  int filter31HzGain_;

  /**
   * 63 Hz filter Gain
   */

  int filter63HzGain_;

  /**
   * 125 Hz filter Gain
   */

  int filter125HzGain_;

  /**
   * 250 Hz filter Gain
   */

  int filter250HzGain_;

  /**
   * 500 Hz filter Gain
   */

  int filter500HzGain_;

  /**
   * 1 kHz filter Gain
   */

  int filter1kHzGain_;

  /**
   * 2 kHz filter Gain
   */

  int filter2kHzGain_;

  /**
   * 4 kHz filter Gain
   */

  int filter4kHzGain_;

  /**
   * 8 kHz filter Gain
   */

  int filter8kHzGain_;

  /**
   * 16 kHz filter Gain
   */

  int filter16kHzGain_;
  /**
   * control Volume
   */
  controlVolume* cv_;

  /**
   * filters
   */
  Filtrado* filters_;
};


#endif // DSPSYSTEM_H
