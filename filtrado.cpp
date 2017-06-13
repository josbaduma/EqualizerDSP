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
void Filtrado::filter31Hz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.000000001124378194);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9975509793)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9975509793)*out[1] - (14.9878126341)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9975509793)*out[2] - (14.9878126341)*out[1] - (-19.9757406551)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9975509793)*out[3] - (14.9878126341)*out[2] - (-19.9757406551)*out[1] - (14.9758559543)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9975509793)*out[4] - (14.9878126341)*out[3] - (-19.9757406551)*out[2] - (14.9758559543)*out[1] + (-5.9879855835)*out[0]);

    for (int n=6; n<blockSize; ++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9975509793)*out[n-1] + (14.9878126341)*out[n-2] + (-19.9757406551)*out[n-3]
                + (14.9758559543)*out[n-4] + (-5.9879855835)*out[n-5] + (  0.9976086294)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter63Hz. Filter 63 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter63Hz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.00000000898428);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9949133849)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9949133849)*out[1] - (14.9748774920)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9949133849)*out[2] - (14.9748774920)*out[1] - (-19.9503751179)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9949133849)*out[3] - (14.9748774920)*out[2] - (-19.9503751179)*out[1] - (14.9509942790)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9949133849)*out[4] - (14.9748774920)*out[3] - (-19.9503751179)*out[2] - (14.9509942790)*out[1] + (-5.9758062478)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9949133849)*out[n-1] + (14.9748774920)*out[n-2] + (-19.9503751179)*out[n-3]
                + (14.9509942790)*out[n-4] + (-5.9758062478)*out[n-5] + (  0.9952229796)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter125Hz. Filter 125 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter125Hz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.00000000379251);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9954577157)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9954577157)*out[1] - (14.9782485236)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9954577157)*out[2] - (14.9782485236)*out[1] - (-19.9584140673)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9954577157)*out[3] - (14.9782485236)*out[2] - (-19.9584140673)*out[1] - (14.9603285171)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9954577157)*out[4] - (14.9782485236)*out[3] - (-19.9584140673)*out[2] - (14.9603285171)*out[1] + (-5.9811203477)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9954577157)*out[n-1] + (14.9782485236)*out[n-2] + (-19.9584140673)*out[n-3]
                + (14.9603285171)*out[n-4] + (-5.9811203477)*out[n-5] + (  0.9964150901)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter250Hz. Filter 250 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter250Hz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.000000641731);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9745236311)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9745236311)*out[1] - (14.8767017017)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9745236311)*out[2] - (14.8767017017)*out[1] - (-19.7615068609)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9745236311)*out[3] - (14.8767017017)*out[2] - (-19.7615068609)*out[1] - (14.7695513489)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9745236311)*out[4] - (14.8767017017)*out[3] - (-19.7615068609)*out[2] - (14.7695513489)*out[1] + (-5.8887707334)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9745236311)*out[n-1] + (14.8767017017)*out[n-2] + (-19.7615068609)*out[n-3]
                + (14.7695513489)*out[n-4] + (-5.8887707334)*out[n-5] + (  0.9785481764)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter500Hz. Filter 500 Hz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter500Hz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.00000111239);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9608944217)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9608944217)*out[1] - (14.8202343946)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9608944217)*out[2] - (14.8202343946)*out[1] - (-19.6716033410)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9608944217)*out[3] - (14.8202343946)*out[2] - (-19.6716033410)*out[1] - (14.7024243087)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9608944217)*out[4] - (14.8202343946)*out[3] - (-19.6716033410)*out[2] - (14.7024243087)*out[1] + (-5.8665031596)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9608944217)*out[n-1] + (14.8202343946)*out[n-2] + (-19.6716033410)*out[n-3]
                + (14.7024243087)*out[n-4] + (-5.8665031596)*out[n-5] + (  0.9763423334)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter1kHz. Filter 1 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter1kHz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.00002339173);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.8733587260)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.8733587260)*out[1] - (14.4327950810)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.8733587260)*out[2] - (14.4327950810)*out[1] - (-18.9926667321)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.8733587260)*out[3] - (14.4327950810)*out[2] - (-18.9926667321)*out[1] - (14.1160322733)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.8733587260)*out[4] - (14.4327950810)*out[3] - (-18.9926667321)*out[2] - (14.1160322733)*out[1] + (-5.6184095317)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.8733587260)*out[n-1] + (14.4327950810)*out[n-2] + (-18.9926667321)*out[n-3]
                + (14.1160322733)*out[n-4] + (-5.6184095317)*out[n-5] + (  0.9356139645)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter2kHz. Filter 2 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter2kHz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.000068734299);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.6662568491)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.6662568491)*out[1] - (13.6068870936)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.6662568491)*out[2] - (13.6068870936)*out[1] - (-17.7123427245)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.6662568491)*out[3] - (13.6068870936)*out[2] - (-17.7123427245)*out[1] - (13.1791793660)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.6662568491)*out[4] - (13.6068870936)*out[3] - (-17.7123427245)*out[2] - (13.1791793660)*out[1] + (-5.3157173092)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.6662568491)*out[n-1] + (13.6068870936)*out[n-2] + (-17.7123427245)*out[n-3]
                + (13.1791793660)*out[n-4] + (-5.3157173092)*out[n-5] + (  0.9086935543)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter4kHz. Filter 4 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter4kHz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.001509865235276);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-4.8218100748)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-4.8218100748)*out[1] - (10.4586298469)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-4.8218100748)*out[2] - (10.4586298469)*out[1] - (-12.9017963092)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-4.8218100748)*out[3] - (10.4586298469)*out[2] - (-12.9017963092)*out[1] - (9.5377292688)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-4.8218100748)*out[4] - (10.4586298469)*out[3] - (-12.9017963092)*out[2] - (9.5377292688)*out[1] + (-4.0105822081)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-4.8218100748)*out[n-1] + (10.4586298469)*out[n-2] + (-12.9017963092)*out[n-3]
                + ( 9.5377292688)*out[n-4] + (-4.0105822081)*out[n-5] + (  0.7593407251)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter8kHz. Filter 8 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter8kHz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.007243698709928);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-2.3133538168)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-2.3133538168)*out[1] - (4.1357673991)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-2.3133538168)*out[2] - (4.1357673991)*out[1] - (-4.2373233559)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-2.3133538168)*out[3] - (4.1357673991)*out[2] - (-4.2373233559)*out[1] - (3.5381193574)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-2.3133538168)*out[4] - (4.1357673991)*out[3] - (-4.2373233559)*out[2] - (3.5381193574)*out[1] + (-1.6783927043)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-2.3133538168)*out[n-1] + ( 4.1357673991)*out[n-2] + (-4.2373233559)*out[n-3]
                + ( 3.5381193574)*out[n-4] + (-1.6783927043)*out[n-5] + ( 0.6210356193)*out[n-6]));
    }
}

/**
 * @brief Filtrado::filter16kHz. Filter 16 kHz the in buffer and leave an output
 * @param blockSize
 * @param filterGain
 * @param in
 * @param out
 */
void Filtrado::filter16kHz(int blockSize, int filterGain, float *in, float *out){
    float gain_ = pow(10.0,(filterGain/20))*(0.022317639424501);

    out[0] = gain_*(in[0]);

    out[1] = gain_*(in[1] - (3.4665421693)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (3.4665421693)*out[1] - (6.0461900507)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (3.4665421693)*out[2] - (6.0461900507)*out[1] - (6.5860914913)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (3.4665421693)*out[3] - (6.0461900507)*out[2] - (6.5860914913)*out[1] - (4.7653622561)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (3.4665421693)*out[4] - (6.0461900507)*out[3] - (6.5860914913)*out[2] - (4.7653622561)*out[1] + (2.1379007307)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((3.4665421693)*out[n-1] + (6.0461900507)*out[n-2] + (6.5860914913)*out[n-3]
                + (4.7653622561)*out[n-4] + (2.1379007307)*out[n-5] + (0.4909913081)*out[n-6]));
    }
}
