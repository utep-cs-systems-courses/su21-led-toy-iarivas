#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char blink_count = 0;
static char time = 0;
static char count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  if(time == 249){ time = 0; count++;}

  if(count == 4){ count = 0; }
  else{
    if(++blink_count == 1 && count == 0){
      red_dim(0); time++; blink_count = 0; }
    else if(blink_count == 2 && count == 1){
      red_dim(1); time++; blink_count = 0; }
    else if(blink_count == 1 && count == 2){
      red_dim(2); time++; blink_count = 0; }
    else if(blink_count == 2 && count == 3){
      red_dim(3); time++; blink_count = 0; }
  }
}
