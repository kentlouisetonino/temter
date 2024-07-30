#include "string.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int compare(char a, char b) {
  if (a == b) {
    return 1;
  } else {
    return 0;
  }
}

int check_valid_input(char *input) {
  int input_length = sizeof(input);
  int valid_input = 1;
  int decimal_count = 0;

  for (int i = 0; i < strlen(input); i++) {
    if (!isdigit(input[i])) {
      if (input[i] == '.') {
        decimal_count++;

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
