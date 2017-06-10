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
};

#endif // FILTRADO_H
