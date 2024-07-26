#include "./ansi_color_codes.h"
#include "./escape_sequence.h"
#include <stdio.h>

void app_description(void) {
  add_new_tab();
  printf("%s--------------------------------------------------%s", BLUE, RESET);
  add_new_line();
  add_new_line();
  add_new_tab();
  add_new_tab();
  add_new_tab();
  printf("    %sTempScale%s", GREEN, RESET);
  add_new_line();
  add_new_line();
  add_new_tab();
  printf("   A CLI tool for converting temperature scale.");
  add_new_line();
  add_new_line();
  add_new_tab();
  printf("%s--------------------------------------------------%s", BLUE, RESET);
}
