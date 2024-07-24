#include "displays/app_description.h"
#include "displays/app_options.h"
#include "displays/clear_screen.h"
#include "displays/escape_sequence.h"
#include <stdio.h>

int main(void) {
  // Clean up the screen.
  clear_screen();
  add_new_line();
  add_new_line();

  // Show the app description.
  app_description();
  add_new_line();
  add_new_line();

  // Show the app options.
  app_options();
  add_new_line();
  add_new_line();

  return 0;
}
