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
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter31Hz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*31.5/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter63Hz. Filter 63 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter63Hz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*63.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter125Hz. Filter 125 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter125Hz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*125.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter250Hz. Filter 250 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter250Hz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*250.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter500Hz. Filter 500 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter500Hz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*500.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter1kHz. Filter 1 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter1kHz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*1000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*16000.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter2kHz. Filter 2 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter2kHz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*2000.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter4kHz. Filter 4 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter4kHz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*4000.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter8kHz. Filter 8 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter8kHz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*8000.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}

/**
 * @brief Filtrado::filter16kHz. Filter 16 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter16kHz(int blockSize, int filterGain, float * in, float * out){

    // Calcula parámetros intermedios

    float Q = 1.41;
    float Pi = atan(1)*4;

    // Calcula coeficientes

    float a1, a2;
    float G;

    float K = 1 - ((2*Pi*16000.0)/(2*Q*44100.0));
    float w0 = 2*Pi*16000.0/44100.0;
    G = pow(10,(filterGain/20));

    a1 = -2*K*cos(w0);
    a2 = pow(K,2);


    // Aplica a las entradas

    out[0] = G*in[0];
    out[1] = G*(in[1] - a1*out[0]);

    for (long n = 2; n < blockSize; n++){
        out[n] = G*(in[n] - in[n-2] - a1*out[n-1] - a2*out[n-2]);
    }
}
