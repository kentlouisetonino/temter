#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int check_valid_input(char *input) {
  int input_length = sizeof(input);
  int valid_input = 1;

  for (int i = 0; i < input_length / sizeof(char); i++) {
    switch (input[i]) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      valid_input = 1;
      break;
    default:
      valid_input = 0;
    }
  }

  return valid_input;
}
