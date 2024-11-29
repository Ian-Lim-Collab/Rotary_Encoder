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
    uint16_t encoder_cap_state;
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

    /**
     * @brief: Set the rotary encoder state
     * @param: state: the state to set the rotary encoder to
     */
    void set_rotary_state(uint16_t state);

    /** 
     * @brief: Set the rotary encoder state cap and stays at the maximum value when the rotary encoder reaches the cap
     * The rotary encoder state cap is the maximum value the rotary encoder can reach 
     * The state number of states is 0:state_cap inclusive so there is state_cap + 1 states
     * @param: state: the state cap
    */
    void set_rotary_state_cap(uint16_t state);
};


