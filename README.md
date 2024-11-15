# Rotary_Encoder
This library is a rotary encoder using interrupts

## Example Code
``` C++
#include "mbed.h"
#include "Rotary_Encoder.h"

int main(){
    Rotary_Encoder rot(PA_1, PA_4,PC_13);
    while(true){
        printf("Rotary Encoder State: %d Button State: %d\n",rot.get_rotary_state(),rot.get_btn_state());
    }
}
```