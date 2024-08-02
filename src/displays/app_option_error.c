#include "ansi_color_codes.h"
#include "escape_sequence.h"

void app_option_error(void) {
  add_new_tab();
  printf("%sInvalid option. Please try again.%s", RED, RESET);
}
