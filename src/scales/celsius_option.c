#include "../displays/ansi_color_codes.h"
#include "../displays/clear_screen.h"
#include "../displays/escape_sequence.h"
#include "celsius_description.h"
#include "check_valid_input.h"

void celsius_option(void) {
  char *celsius_string = malloc(sizeof(char) * 50);
  int invalid_input = 0;
  char *garbage_buffer = malloc(sizeof(char) * 50);
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_screen();
    add_new_line();
    add_new_line();

    // Display the option description.
    celsius_description();
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
    printf(" Celsius (°C): ");
    scanf("%s", celsius_string);
    fgets(garbage_buffer, 50, stdin);

    // Check if input is valid.
    int valid_input = check_valid_input(celsius_string);
    if (valid_input == 0) {
      invalid_input = 1;
      continue;
    } else {
      invalid_input = 0;
    }

    // Convert the celcius input to double.
    double celsius_double = atof(celsius_string);

    // Handle computation for fahrenheit.
    double fahrenheit = ((9.0 / 5.0) * celsius_double) + 32;
    add_new_tab();
    printf(" %sFahrenheit (°F):%s %s%.4lf%s", BLUE, RESET, GREEN, fahrenheit,
           RESET);
    add_new_line();

    // Handle computation for kelvbin
    double kelvin = celsius_double + 273.15;
    add_new_tab();
    printf(" %sKelvin (°K):%s %s%.4lf%s", BLUE, RESET, GREEN, kelvin, RESET);
    add_new_line();

    // Handle computation for rankine.
    double rankine = celsius_double * (9.0 / 5.0) + 491.67;
    add_new_tab();
    printf(" %sRankine (°R):%s %s%.4lf%s", BLUE, RESET, GREEN, rankine, RESET);
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
