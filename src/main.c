#include "displays/app_description.h"
#include "displays/app_options.h"
#include "displays/clear_screen.h"
#include "displays/escape_sequence.h"
#include "inputs/app_option.h"
#include <stdio.h>

int main(void) {
  int option;

  while (1) {
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

    // Ask the user for their input.
    option = app_option();

    // Reset the loop if invalid input.
    if (option == 0) {
      continue;
    };

    break;
  }

  return 0;
}
