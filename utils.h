/*
 * ░█░█░▀█▀░▀█▀░█░░░░░░█░█
 * ░█░█░░█░░░█░░█░░░░░░█▀█
 * ░▀▀▀░░▀░░▀▀▀░▀▀▀░▀░░▀░▀
 *
 */

/*
 * INCLUDES
 */
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * STRUCTURES
 */
struct options {
  int op;             // option captured by getopt
  char map_path[100]; // path to the scenario
  char model[100];    // simulation model
  int lambda;         // diagonal proportion rate
  int panic;          // panic rate
  int random;         // qtd. of random pedestrians on map
  int seed;           // to generate random numbers
  int timesteps;      // qtd. of time steps in the simulation
  int curve_flag;     // pedestrians go arround obstacles
  int noex_flag;      // pedestrians do not cross paths
  int wait_flag;      // pedestrians Wait for the target place
  int dump_flag;      // export the simulation process to the dump file
  int emoji_flag;     // print emojis in the simulation
  int verbose_flag;   // print every step of the simulation
};

typedef struct options t_options;

/*
 * FUNCTIONS
 */
t_options *capture_opts(int argc, char *argv[]);
void destroy_opts(t_options *op);
void help_menu();
