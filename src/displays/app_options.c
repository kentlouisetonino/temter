#include "ansi_color_codes.h"
#include "escape_sequence.h"
#include <stdio.h>

void app_options(void) {
  add_new_tab();
  printf(" %s[%s %s1%s %s]%s Celsius (°C)", BLUE, RESET, GREEN, RESET, BLUE,
         RESET);
  add_new_line();
  add_new_tab();
  printf(" %s[%s %s2%s %s]%s Fahrenheit (°F)", BLUE, RESET, GREEN, RESET, BLUE,
         RESET);
  add_new_line();
  add_new_tab();
  printf(" %s[%s %s3%s %s]%s Kelvin (°K)", BLUE, RESET, GREEN, RESET, BLUE,
         RESET);
  add_new_line();
  add_new_tab();
  printf(" %s[%s %s4%s %s]%s Rankine (°R)", BLUE, RESET, GREEN, RESET, BLUE,
         RESET);
  add_new_line();
  add_new_tab();
  printf(" %s[%s %s5%s %s]%s Kelvin (°K)", BLUE, RESET, GREEN, RESET, BLUE,
         RESET);
}
