/*
 * ░█▄█░█▀█░▀█▀░█▀█░░░░█▀▀
 * ░█░█░█▀█░░█░░█░█░░░░█░░
 * ░▀░▀░▀░▀░▀▀▀░▀░▀░▀░░▀▀▀
 *
 */

/*
 * INCLUDES
 */
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * MAIN
 */
int main(int argc, char *argv[]) {

  // Capturing the main options by getopt lib
  t_options *ops = capture_opts(argc, argv);

  destroy_opts(ops);
  return EXIT_SUCCESS;
}
