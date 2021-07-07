#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char blink_count = 0;
static char time = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  if(time == 250){ time = 0; }
  if(++blink_count == 3 && time >= 0 && time <= 62){
    red_dim(0); time++; blink_count = 0; }
  else if(blink_count == 2 && time >= 63 && time <= 124){
    red_dim(1); time++; blink_count = 0; }
  else if(blink_count == 3 && time >= 125 && time <= 187){
    red_dim(2); time++; blink_count = 0; }
  else if(blink_count == 2 && time >= 188 && time <= 249){
    red_dim(3); time++; blink_count = 0; }
}
