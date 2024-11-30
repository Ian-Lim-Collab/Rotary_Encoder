#include "Rotary_Encoder.h"

Rotary_Encoder::Rotary_Encoder(PinName encoder_A_pin, PinName encoder_B_pin, PinName button_pin)
:encoder_A(encoder_A_pin), encoder_B(encoder_B_pin), button(button_pin)
{
    encoder_A.rise(callback(this, &Rotary_Encoder::encoder_A_ISR_callback));
    encoder_A.fall(callback(this, &Rotary_Encoder::encoder_A_ISR_callback));
    encoder_B.rise(callback(this, &Rotary_Encoder::encoder_B_ISR_callback));
    encoder_B.fall(callback(this, &Rotary_Encoder::encoder_B_ISR_callback));
    button.rise(callback(this, &Rotary_Encoder::button_rise_callback));
    button.fall(callback(this, &Rotary_Encoder::button_fall_callback));
    
    encoder_state = 0;
};

void Rotary_Encoder::encoder_A_ISR_callback(){
    this->rotor_debounce_period.stop();
    if(this->rotor_debounce_period.elapsed_time() > ROTARY_ENCODER_ROTARY_DEBOUNCE_PERIOD){
        if (encoder_B != encoder_A) {
            encoder_state++;
        } else {
            encoder_state--;
        }
    }
    this->rotor_debounce_period.reset();
    this->rotor_debounce_period.start();
};

void Rotary_Encoder::encoder_B_ISR_callback(){
    this->rotor_debounce_period.stop();
    if(this->rotor_debounce_period.elapsed_time() > ROTARY_ENCODER_ROTARY_DEBOUNCE_PERIOD){
        if (encoder_B != encoder_A) {
            encoder_state--;
        } else {
            encoder_state++;
        }
    }
    this->rotor_debounce_period.reset();
    this->rotor_debounce_period.start();
};

void Rotary_Encoder::button_rise_callback(){
    this->button_debounce_period.stop();
    if(this->button_debounce_period.elapsed_time() > ROTARY_ENCODER_BUTTON_DEBOUNCE_PERIOD){
        btn_state = !btn_state;
    }
};

void Rotary_Encoder::button_fall_callback(){
    this->button_debounce_period.reset();
    this->button_debounce_period.start();
}

uint8_t Rotary_Encoder::get_rotary_state(){ 
    encoder_state = encoder_state > encoder_cap_state ? encoder_cap_state : encoder_state;
    return encoder_state >> 2;
};

bool Rotary_Encoder::get_btn_state(){
    return btn_state;
};

void Rotary_Encoder::reset_rotary_state(){
    encoder_state = 0;
};

void Rotary_Encoder::reset_btn_state(){
    btn_state = false;
};

void Rotary_Encoder::set_rotary_state(uint16_t state){
    encoder_state = state << 2;
};  

void Rotary_Encoder::set_rotary_state_cap(uint16_t state){
    this->encoder_cap_state = (state - 1) << 2 ;
};