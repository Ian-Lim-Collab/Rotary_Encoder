#pragma once 
#include "mbed.h"

class Rotor_Encoder
{
protected:
    /* data */
    InterruptIn encoder_A;
    InterruptIn encoder_B;
    InterruptIn button;

    uint8_t encoder_state;
    bool btn_state;

    void encoder_A_rise_callback();
    void encoder_B_rise_callback();
    void button_rise_callback();
public:
    Rotor_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin);
    uint8_t get_rotory_state();
    bool get_btn_state();
};


