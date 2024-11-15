#include "Rotory_Encoder.h"

Rotory_Encoder::Rotory_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin)
:encoder_A(encoder_A_pin), encoder_B(encoder_B_pin), button(button_pin)
{
    encoder_A.rise(callback(this, &Rotory_Encoder::encoder_A_ISR_callback));
    encoder_A.fall(callback(this, &Rotory_Encoder::encoder_A_ISR_callback));
    button.rise(callback(this, &Rotory_Encoder::button_rise_callback));
    
    encoder_state = 0;
};

void Rotory_Encoder::encoder_A_ISR_callback(){
    this->debounce_period.stop();
    if(this->debounce_period.elapsed_time() > ROTORY_ENCODER_DEBOUNCE_PERIOD){
        if (encoder_B != encoder_A) {
            encoder_state++;
        } else {
            encoder_state--;
        }
    }
    this->debounce_period.reset();
    this->debounce_period.start();
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