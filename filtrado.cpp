#include "filtrado.h"

/*
 * Constructor
 */
Filtrado::Filtrado()
{

}

/*
 * Destructor
 */
Filtrado::~Filtrado(){

}

/**
 * @brief Filtrado::filter31Hz. Filter 31 Hz the in buffer and leave an output
 * @param blockSize
 * @param volumeGain
 * @param in
 * @param out
 */
void Filtrado::filter31Hz(int blockSize, int filterGain, float *in, float *out){
    for (int n=6; n<blockSize;++n){
        out[n] = (filterGain*0.02)*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6])
                + (5.9983833375)*out[n-1] - (14.9919783715)*out[n-2] + (19.9840800460)*out[n-3]
                - (14.9842032854)*out[n-4] + (5.9921632312)*out[n-5] - (0.9984449578)*out[n-6];
    }
}
