#include "../displays/ansi_color_codes.h"
#include "../displays/clear_screen.h"
#include "../displays/escape_sequence.h"
#include "check_valid_input.h"
#include "fahrenheit_description.h"

void fahrenheit_option(void) {
  char *fahrenheit_string = malloc(sizeof(char) * 50);
  int invalid_input = 0;
  char *garbage_buffer = malloc(sizeof(char) * 50);
  int try_again = 0;

  while (1) {
    // Clean up the terminal.
    clear_screen();
    add_new_line();
    add_new_line();

    // Display the option description.
    fahrenheit_description();
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
    printf(" Fahrenheit (°F)     : ");
    scanf("%s", fahrenheit_string);
    fgets(garbage_buffer, 50, stdin);

    // Check if input is valid.
    int valid_input = check_valid_input(fahrenheit_string);
    if (valid_input == 0) {
      invalid_input = 1;
      continue;
    } else {
      invalid_input = 0;
    }

    // Convert the celcius input to double.
    double fahrenheit_double = atof(fahrenheit_string);

    // Handle computation for celsius scale.
    double celsius = (fahrenheit_double - 32) * (5.0 / 9.0);
    add_new_tab();
    printf(" %sCelsius (°C)%s        : %s%.4lf (°C)%s ", BLUE, RESET, YELLOW,
           celsius, RESET);
    add_new_line();

    // Handle computation for kelvin scale.
    double kelvin = (fahrenheit_double - 32) * (5.0 / 9.0) + 273.15;
    add_new_tab();
    printf(" %sKelvin (°K)%s         : %s%.4lf (°K)%s", BLUE, RESET, YELLOW,
           kelvin, RESET);
    add_new_line();

    // Handle computation for rankine scale.
    double rankine = fahrenheit_double + 459.67;
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
