#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

static char blink_count = 0;
static char time = 0;
static char seq = 0;
char switch_state = 4;

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  if(switch_state == 0){
    seq = 0;
    if(time == 249){ time = 0; seq++; }
    if(seq == 4){ seq = 0; }
    else{
      if(++blink_count == 1 && seq == 0){
	red_dim(seq); time++; blink_count = 0; }
      else if(blink_count == 2 && seq == 1){
	red_dim(seq); time += 2; blink_count = 0; }
      else if(blink_count == 1 && seq == 2){
	red_dim(seq); time++; blink_count = 0; }
      else if(blink_count == 2 && seq == 3){
	red_dim(seq); time += 2; blink_count = 0; }
    }
  }
  else if(switch_state == 1){
    seq = 0;
    if(time == 249){ time = 0; seq++; }
    if(seq == 4){ seq = 0; }
    else{
      if(++blink_count == 1 && seq == 0){
	green_dim(seq); time++; blink_count = 0; }
      else if(blink_count == 2 && seq == 1){
	green_dim(seq); time += 2; blink_count = 0; }
      else if(blink_count == 1 && seq == 2){
	green_dim(seq); time++; blink_count = 0; }
      else if(blink_count == 2 && seq == 3){
	green_dim(seq); time += 2; blink_count = 0; }
    }
  }
}
