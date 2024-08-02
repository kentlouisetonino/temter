#include "displays/app_description.h"
#include "displays/app_option_error.h"
#include "displays/app_options.h"
#include "displays/clear_screen.h"
#include "displays/escape_sequence.h"
#include "inputs/app_option.h"
#include "scales/celsius_option.h"
#include "scales/fahrenheit_option.h"
#include "scales/kelvin_option.h"
#include "scales/rankine_option.h"

int main(void) {
  int option;
  int invalid_option = 0;

  while (1) {
    // Clean up the screen.
    clear_screen();
    add_new_line();
    add_new_line();

    // Show the app description.
    app_description();
    add_new_line();
    add_new_line();

    // Show the error message.
    if (invalid_option) {
      app_option_error();
      add_new_line();
      add_new_line();
    }

    // Show the app options.
    app_options();
    add_new_line();
    add_new_line();

    // Ask the user for their input.
    option = app_option();

    if (option == 5) {
      break;
    } else if (option == 0) {
      invalid_option = 1;
      continue;
    } else if (option == 1) {
      invalid_option = 0;
      celsius_option();
      continue;
    } else if (option == 2) {
      invalid_option = 0;
      fahrenheit_option();
      continue;
    } else if (option == 3) {
      invalid_option = 0;
      kelvin_option();
      continue;
    } else if (option == 4) {
      invalid_option = 0;
      rankine_option();
      continue;
    };

    break;
  }

  add_new_line();
  add_new_line();
  return 0;
}
