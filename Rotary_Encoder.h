#pragma once 
#include "mbed.h"

#define ROTARY_ENCODER_ROTARY_DEBOUNCE_PERIOD 1500us
#define ROTARY_ENCODER_BUTTON_DEBOUNCE_PERIOD 50000us

class Rotary_Encoder
{
protected:
    /* data */
    InterruptIn encoder_A;
    InterruptIn encoder_B;
    InterruptIn button;
    Timer rotor_debounce_period;
    Timer button_debounce_period;

    uint16_t encoder_state;
    bool btn_state;

    void encoder_ISR_callback();
    void button_rise_callback();
    void button_fall_callback();
public:
    Rotary_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin);
    uint8_t get_rotary_state();
    bool get_btn_state();
    void reset_rotary_state();
    void reset_btn_state();
    void set_rotary_state(uint16_t state);
};


