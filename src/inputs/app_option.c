#include "../displays/ansi_color_codes.h"
#include "../displays/escape_sequence.h"
#include <stdlib.h>

int app_option(void) {
  int option = 0;
  char *garbage_buffer = malloc(sizeof(char) * 50);

  add_new_tab();
  printf(" %sEnter the option:%s ", BLUE, RESET);
  scanf("%d", &option);
  fgets(garbage_buffer, 50, stdin);

  return option;
}
