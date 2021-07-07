#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char tdim = 0;
static char tcnt = 0;
static char temp = 0;

char toggle_red()		/* always toggle! */
{
  switch (temp) {
  case 0:
    red_on = 1;
    temp = 1;
    break;
  case 1:
    red_on = 0;
    temp = 0;
    break;
  }
  led_update();
  return 1;
}

char toggle_red_dim()
{
  switch (temp) {
  case 0:
    red_on = 1;
    temp = 1;
    break;
  case 1:
    red_on = 0;
    temp = 2;
    break;
  case 2:
    red_on = 0;
    temp = 0;
    break;
  }
  led_update();
  return 1;
}

char toggle_red_bright()
{
  switch(temp) {
  case 0:
    red_on = 1;
    temp = 1;
    break;
  case 1:
    red_on = 1;
    temp = 2;
    break;
  case 2:
    red_on = 0;
    temp = 0;
    break;
  }
  led_update();
  return 1; 
}

char toggle_red_off()
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
