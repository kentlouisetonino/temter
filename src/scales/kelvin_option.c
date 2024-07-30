#include "../displays/ansi_color_codes.h"
#include "../displays/clear_screen.h"
#include "../displays/escape_sequence.h"
#include "check_valid_input.h"
#include "kelvin_description.h"

void kelvin_option(void) {
  char *kelvin_string = malloc(sizeof(char) * 50);
  int invalid_input = 0;
  char *garbage_buffer = malloc(sizeof(char) * 50);
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_screen();
    add_new_line();
    add_new_line();

    // Display the option description.
    kelvin_description();
    add_new_line();
    add_new_line();

    // Display the error message.
    if (invalid_input) {
      add_new_tab();
      printf(" %sInvalid input. Please try again.%s", RED, RESET);
      add_new_line();
      add_new_line();
    }

    // Ask the input.
    add_new_tab();
    printf(" Kelvin (°K)         : ");
    scanf("%s", kelvin_string);
    fgets(garbage_buffer, 50, stdin);

    // Check if input is valid.
    int valid_input = check_valid_input(kelvin_string);
    if (valid_input == 0) {
      invalid_input = 1;
      continue;
    } else {
      invalid_input = 0;
    }

    // Convert the kelvin input to double..
    double kelvin_double = atof(kelvin_string);

    // Handle computation for celsius scale.
    double celsius = kelvin_double - 273.15;
    add_new_tab();
    printf(" %sCelsius (°C)%s        : %s%.4lf (°C)%s ", BLUE, RESET, YELLOW,
           celsius, RESET);
    add_new_line();

    // Handle computation for fahrenheit scale.
    double fahrenheit = (kelvin_double - 273.15) * (9.0 / 5.0) + 32;
    add_new_tab();
    printf(" %sFahrenheit (°F)%s     : %s%.4lf (°F)%s", BLUE, RESET, YELLOW,
           fahrenheit, RESET);
    add_new_line();

    // Handle computation for rankine scale.
    double rankine = kelvin_double * 1.8;
    add_new_tab();
    printf(" %sRankine (°R)%s        : %s%.4lf (°R)%s", BLUE, RESET, YELLOW,
           rankine, RESET);
    add_new_line();
    add_new_line();

    // Ask user if want to try again.
    add_new_tab();
    printf(" Try again (1-yes, 0-no): ");
    scanf("%d", &try_again);
    fgets(garbage_buffer, 50, stdin);

    // Handle the input of user.
    if (try_again == 1) {
      invalid_input = 0;
      continue;
    } else {
      break;
    }
  }
}
