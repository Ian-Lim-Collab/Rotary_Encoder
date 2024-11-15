#pragma once 
#include "mbed.h"

class Rotory_Encodery
{
protected:
    /* data */
    InterruptIn encoder_A;
    DigitalIn encoder_B;
    InterruptIn button;

    uint8_t encoder_state;
    bool btn_state;

    void encoder_A_ISR_callback();
    void button_rise_callback();
public:
    Rotory_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin);
    uint8_t get_rotory_state();
    bool get_btn_state();
};


