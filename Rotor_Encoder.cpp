#include "Rotory_Encoder.h"

Rotor_Encoder::Rotor_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin)
:encoder_A(encoder_A_pin), encoder_B(encoder_B_pin), button(button_pin)
{
    encoder_A.rise(callback(this, &Rotor_Encoder::encoder_A_rise_callback));
    encoder_B.rise(callback(this, &Rotor_Encoder::encoder_B_rise_callback));
    button.rise(callback(this, &Rotor_Encoder::button_rise_callback));
    
    encoder_state = 0;
};

void Rotor_Encoder::encoder_A_rise_callback(){
    if (encoder_B == 1) {
        encoder_state++;
    } else {
        encoder_state--;
    }
};

void Rotor_Encoder::encoder_B_rise_callback(){
    if (encoder_A == 1) {
        encoder_state--;
    } else {
        encoder_state++;
    }
};

void Rotor_Encoder::button_rise_callback(){
    btn_state = !btn_state;
};

uint8_t Rotor_Encoder::get_rotory_state(){
    return encoder_state;
};

bool Rotor_Encoder::get_btn_state(){
    return btn_state;
};