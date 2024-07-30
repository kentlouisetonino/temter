#include "string.h"
#include <ctype.h>

int check_valid_input(char *input) {
  int input_length = sizeof(input);
  int valid_input = 1;
  int decimal_count = 0;

  for (int i = 0; i < strlen(input); i++) {
    // Allow negative values.
    if (i == 0 && input[i] == '-') {
      // Allow a leading minus sign
      continue;
    }

    // Handle if value is not digit.
    if (!isdigit(input[i])) {
      // Check if its the first decimal.
      if (input[i] == '.') {
        decimal_count++;

        // If its not the first period, exit the function.
        if (decimal_count > 1) {
          valid_input = 0;
          break;
        }
      } else {
        valid_input = 0;
        break;
      }
    }
  }

  return valid_input;
}
