#include "Rotory_Encodery.h"

Rotory_Encoder::Rotory_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin)
:encoder_A(encoder_A_pin), encoder_B(encoder_B_pin), button(button_pin)
{
    encoder_A.rise(callback(this, &Rotory_Encoder::encoder_A_rise_callback));
    button.rise(callback(this, &Rotory_Encoder::button_rise_callback));
    
    encoder_state = 0;
};

void Rotory_Encoder::encoder_A_ISR_callback(){
    if (encoder_B != encoderA) {
        encoder_state++;
    } else {
        encoder_state--;
    }
};


void Rotory_Encoder::button_rise_callback(){
    btn_state = !btn_state;
};

uint8_t Rotory_Encoder::get_rotory_state(){
    return encoder_state;
};

bool Rotory_Encoder::get_btn_state(){
    return btn_state;
};