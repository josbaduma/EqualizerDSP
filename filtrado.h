/**
 * \file   controlVolume.h
 *         Implements filters in the time domain
 * \author Jose Badilla
 * \date   2017.31.05
 *
 * $Id: filtrado.cpp $
 */

#ifndef FILTRADO_H
#define FILTRADO_H
#include <math.h>


class Filtrado
{
public:
    /**
     * Constructor
     * @brief Filtrado
     */
    Filtrado();

    /**
     * Destructor
     */
    ~Filtrado();

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter31Hz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter63Hz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter125Hz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter250Hz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter500Hz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter1kHz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter2kHz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter4kHz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter8kHz(int blockSize,
                int filterGain,
                float* in,
                float* out);

    /**
     * Filter the in buffer and leave the result in out
     */
    void filter16kHz(int blockSize,
                int filterGain,
                float* in,
                float* out);
};

#endif // FILTRADO_H
