#include "../displays/ansi_color_codes.h"
#include "../displays/clear_screen.h"
#include "../displays/escape_sequence.h"

void celsius_description(void) {
  add_new_tab();
  printf("%s--------------------------------------------------%s", BLUE, RESET);
  add_new_line();
  add_new_line();
  add_new_tab();
  add_new_tab();
  printf("   %sCelsius (°C) to Other Scale%s", GREEN, RESET);
  add_new_line();
  add_new_line();
  add_new_tab();
  printf("%s--------------------------------------------------%s", BLUE, RESET);
}
