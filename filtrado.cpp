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
    float gain_ = pow(10.0,(filterGain/20))*(0.000000000308911682);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9983833375)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9983833375)*out[1] - (14.9919783715)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9983833375)*out[2] - (14.9919783715)*out[1] - (-19.9840800460)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9983833375)*out[3] - (14.9919783715)*out[2] - (-19.9840800460)*out[1] - (14.9842032854)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9983833375)*out[4] - (14.9919783715)*out[3] - (-19.9840800460)*out[2] - (14.9842032854)*out[1] + (-5.9921632312)*out[0]);

    for (int n=6; n<blockSize; ++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9983833375)*out[n-1] + (14.9919783715)*out[n-2] + (-19.9840800460)*out[n-3]
                + (14.9842032854)*out[n-4] + (-5.9921632312)*out[n-5] + (  0.9984449578)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.000000006551104284);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9954488589)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9954488589)*out[1] - (14.9774957955)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9954488589)*out[2] - (14.9774957955)*out[1] - (-19.9554938669)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9954488589)*out[3] - (14.9774957955)*out[2] - (-19.9554938669)*out[1] - (14.9559954354)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9954488589)*out[4] - (14.9774957955)*out[3] - (-19.9554938669)*out[2] - (14.9559954354)*out[1] + (-5.9782481576)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9954488589)*out[n-1] + (14.9774957955)*out[n-2] + (-19.9554938669)*out[n-3]
                + (14.9559954354)*out[n-4] + (-5.9782481576)*out[n-5] + (  0.9956996525)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.00000005229628304);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9777711984)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9904306999)*out[1] - (14.9531463071)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9904306999)*out[2] - (14.9531463071)*out[1] - (-19.9082722442)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9904306999)*out[3] - (14.9531463071)*out[2] - (-19.9082722442)*out[1] - (14.9102461775)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9904306999)*out[4] - (14.9531463071)*out[3] - (-19.9082722442)*out[2] - (14.9102461775)*out[1] + (-5.9561073503)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9904306999)*out[n-1] + (14.9531463071)*out[n-2] + (-19.9082722442)*out[n-3]
                + (14.9102461775)*out[n-4] + (-5.9561073503)*out[n-5] + (  0.9914178099)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.000000509230188);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9777711984)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9777711984)*out[1] - (14.8928687940)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9777711984)*out[2] - (14.8928687940)*out[1] - (-19.7937080743)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9777711984)*out[3] - (14.8928687940)*out[2] - (-19.7937080743)*out[1] - (14.8016280302)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9777711984)*out[4] - (14.8928687940)*out[3] - (-19.7937080743)*out[2] - (14.8016280302)*out[1] + (-5.9047509932)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9777711984)*out[n-1] + (14.8928687940)*out[n-2] + (-19.7937080743)*out[n-3]
                + (14.8016280302)*out[n-4] + (-5.9047509932)*out[n-5] + (  0.9817334432)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.000001870326812);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.9566671597)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.9566671597)*out[1] - (14.7989290513)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.9566671597)*out[2] - (14.7989290513)*out[1] - (-19.6286236333)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.9566671597)*out[3] - (14.7989290513)*out[2] - (-19.6286236333)*out[1] - (14.6590407945)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.9566671597)*out[4] - (14.7989290513)*out[3] - (-19.6286236333)*out[2] - (14.6590407945)*out[1] + (-5.8445901753)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.9566671597)*out[n-1] + (14.7989290513)*out[n-2] + (-19.6286236333)*out[n-3]
                + (14.6590407945)*out[n-4] + (-5.8445901753)*out[n-5] + (  0.9719112239)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.00004572911214);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.8479543277)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.8479543277)*out[1] - (14.3169399910)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.8479543277)*out[2] - (14.3169399910)*out[1] - (-18.7815374723)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.8479543277)*out[3] - (14.3169399910)*out[2] - (-18.7815374723)*out[1] - (13.9240845134)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.8479543277)*out[4] - (14.3169399910)*out[3] - (-18.7815374723)*out[2] - (13.9240845134)*out[1] + (-5.5314846552)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.8479543277)*out[n-1] + (14.3169399910)*out[n-2] + (-18.7815374723)*out[n-3]
                + (13.9240845134)*out[n-4] + (-5.5314846552)*out[n-5] + (  0.9199605389)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.0002063065936);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-5.6249006805)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-5.6249006805)*out[1] - (13.4083231746)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-5.6249006805)*out[2] - (13.4083231746)*out[1] - (-17.3269633797)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-5.6249006805)*out[3] - (13.4083231746)*out[2] - (-17.3269633797)*out[1] - (12.8002184746)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-5.6249006805)*out[4] - (13.4083231746)*out[3] - (-17.3269633797)*out[2] - (12.8002184746)*out[1] + (-5.1264957930)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-5.6249006805)*out[n-1] + (13.4083231746)*out[n-2] + (-17.3269633797)*out[n-3]
                + (12.8002184746)*out[n-4] + (-5.1264957930)*out[n-5] + (  0.9701951079)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.001509865238);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-4.8218100745)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-4.8218100745)*out[1] - (10.4586298460)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-4.8218100745)*out[2] - (10.4586298460)*out[1] - (-12.9017963082)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-4.8218100745)*out[3] - (10.4586298460)*out[2] - (-12.9017963082)*out[1] - (9.5377292684)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-4.8218100745)*out[4] - (10.4586298460)*out[3] - (-12.9017963082)*out[2] - (9.5377292684)*out[1] + (-4.0105822083)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-4.8218100745)*out[n-1] + (10.4586298460)*out[n-2] + (-12.9017963082)*out[n-3]
                + ( 9.5377292684)*out[n-4] + (-4.0105822083)*out[n-5] + (  0.7593407252)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.01037183846);

    out[0] = gain_*in[0];

    out[1] = gain_*(in[1] - (-2.2875037326)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (-2.2875037326)*out[1] - (3.9846132916)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (-2.2875037326)*out[2] - (3.9846132916)*out[1] - (-4.0482794253)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (-2.2875037326)*out[3] - (3.9846132916)*out[2] - (-4.0482794253)*out[1] - (3.3413333227)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (-2.2875037326)*out[4] - (3.9846132916)*out[3] - (-4.0482794253)*out[2] - (3.3413333227)*out[1] + (-1.5875780060)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((-2.2875037326)*out[n-1] + ( 3.9846132916)*out[n-2] + (-4.0482794253)*out[n-3]
                + ( 3.3413333227)*out[n-4] + (-1.5875780060)*out[n-5] + ( 0.5822014219)*out[n-6]));
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
    float gain_ = pow(10.0,(filterGain/20))*(0.06724550138);

    out[0] = gain_*(in[0]);

    out[1] = gain_*(in[1] - (3.2910860315)*out[0]);

    out[2] = gain_*(in[2] - 3*in[0] - (3.2910860315)*out[1] - (5.0357138855)*out[0]);

    out[3] = gain_*(in[3] - 3*in[1] - (3.2910860315)*out[2] - (5.0357138855)*out[1] - (5.0109976110)*out[0]);

    out[4] = gain_*(in[4] - 3*in[2] + 3*in[0] - (3.2910860315)*out[3] - (5.0357138855)*out[2] - (5.0109976110)*out[1] - (3.5408023977)*out[0]);

    out[5] = gain_*(in[5] - 3*in[3] + 3*in[1] - (3.2910860315)*out[4] - (5.0357138855)*out[3] - (5.0109976110)*out[2] - (3.5408023977)*out[1] + (1.5959798384)*out[0]);

    for (int n=6; n<blockSize;++n){
        out[n] = gain_*(in[n] - 3*in[n-2] + 3*in[n-4] - in[n-6]
                -((3.2910860315)*out[n-1] + (5.0357138855)*out[n-2] + (5.0109976110)*out[n-3]
                + (3.5408023977)*out[n-4] + (1.5959798384)*out[n-5] + (0.3436569793)*out[n-6]));
    }
}
