#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char blink_count = 0;
static char time = 0;
static char seq = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  if(time == 249){ time = 0; seq++; }
  if(seq == 8){ seq = 0; }
  else{
    if(++blink_count == 1 && seq == 0){
      red_dim(seq); time++; blink_count = 0; }
    else if(blink_count == 2 && seq == 1){
      red_dim(seq); time++; blink_count = 0; }
    else if(blink_count == 1 && seq == 2){
      red_dim(seq); time++; blink_count = 0; }
    else if(blink_count == 2 && seq == 3){
      red_dim(seq); time++; blink_count = 0; }
    else if(blink_count == 1 && seq == 4){
      green_dim(seq-4); time++; blink_count = 0; }
    else if(blink_count == 2 && seq == 5){
      green_dim(seq-4); time++; blink_count = 0; }
    else if(blink_count == 1 && seq == 6){
      green_dim(seq-4); time++; blink_count = 0; }
    else if(blink_count == 1 && seq == 7){
      green_dim(seq-4); time++; blink_count = 0; }
  }
}
