#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

static char gcount = 0;
static char rcount = 0;
static char siren = 0; 

void toggle_red()		/* always toggle! */
{
  switch (rcount) {
  case 0:
    red_on = 1;
    rcount = 1;
    break;
  case 1:
    red_on = 0;
    rcount = 0;
    break;
  }
  led_update();
}

void toggle_red_dim()
{
  switch (rcount) {
  case 0:
    red_on = 1;
    rcount = 1;
    break;
  case 1:
    red_on = 0;
    rcount = 2;
    break;
  case 2:
    red_on = 0;
    rcount = 0;
    break;
  }
  led_update();
}

void toggle_red_bright()
{
  switch(rcount) {
  case 0:
    red_on = 1;
    rcount = 1;
    break;
  case 1:
    red_on = 1;
    rcount = 2;
    break;
  case 2:
    red_on = 0;
    rcount = 0;
    break;
  }
  led_update();
}

void toggle_red_off()
{
  red_on = 0;
  led_update();
}

void red_dim(int level)
{
  switch(level){
  case 0:
    toggle_red_dim();
    break;
  case 1:
    toggle_red();
    break;
  case 2:
    toggle_red_bright();
    break;
  case 3:
    toggle_red_off();
    break;
  }
}

void toggle_green()
{
  switch(gcount){
  case 0:
    green_on = 1;
    gcount = 1;
    break;
  case 1:
    green_on = 0;
    gcount = 0;
    break;
  }
  led_update();
}

void toggle_green_dim()
{
  switch(gcount){
  case 0:
    green_on = 1;
    gcount = 1;
    break;
  case 1:
    green_on = 0;
    gcount = 2;
    break;
  case 2:
    green_on = 0;
    gcount = 0;
    break;
  }
  led_update();
}

void toggle_green_bright()
{
  switch(gcount){
    case 0:
      green_on = 1;
      gcount = 1;
      break;
    case 1:
      green_on = 1;
      gcount = 2;
      break;
    case 2:
      green_on = 0;
      gcount = 0;
      break;
  }
  led_update();
}

void toggle_green_off()
{
  green_on = 0;
  led_update();
}

void green_dim(int level)
{
  switch(level){
  case 0:
    toggle_green_dim();
    break;
  case 1:
    toggle_green();
    break;
  case 2:
    toggle_green_bright();
    break;
  case 3:
    toggle_green_off();
    break;
  }
}

void toy_off(){ toggle_red_off(); toggle_green_off(); buzzer_set_period(0); }

void police_siren()
{
  switch(siren){
  case 0:
    toggle_red();
    buzzer_set_period(5000);
    siren = 1;
    break;
  case 1:
    toggle_green();
    buzzer_set_period(1000);
    siren = 0;
    break; 
  }
}

void state_reset(){ gcount = 0; rcount = 0; siren = 0; }
