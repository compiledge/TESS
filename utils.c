/*
 * ░█░█░▀█▀░▀█▀░█░░░█▀▀░░░░█▀▀
 * ░█░█░░█░░░█░░█░░░▀▀█░░░░█░░
 * ░▀▀▀░░▀░░▀▀▀░▀▀▀░▀▀▀░▀░░▀▀▀
 *
 */

/*
 * INCLUDES
 */
#include "utils.h"

/*
 * FUNCTIONS
 */
t_options *capture_opts(int argc, char *argv[]) {
  t_options *op;

  op = malloc(sizeof(struct options));

  op->timesteps = 0;
  op->seed = 0;
  op->curve_flag = 0;
  op->noex_flag = 0;
  op->wait_flag = 0;
  op->dump_flag = 0;
  op->emoji_flag = 0;
  op->verbose_flag = 0;

  while (1) {
    static struct option long_options[] = {

        /* Main options sended by CLI */
        {"curve", no_argument, 0, 'c'},
        {"dump", no_argument, 0, 'd'},
        {"emoji", no_argument, 0, 'e'},
        {"wait", no_argument, 0, 'w'},
        {"help", no_argument, 0, 'h'},
        {"noex", no_argument, 0, 'x'},
        {"verbose", no_argument, 0, 'v'},
        {"lambda", required_argument, 0, 'l'},
        {"model", required_argument, 0, 'm'},
        {"panic", required_argument, 0, 'p'},
        {"random", required_argument, 0, 'r'},
        {"seed", required_argument, 0, 's'},
        {"scenario", required_argument, 0, 'S'},
        {"timesteps", required_argument, 0, 't'},
        {0, 0, 0, 0}};

    /* getopt_long stores the option index here. */
    int option_index = 0;

    op->op = getopt_long(argc, argv, "cdewhxvl:m:p:r:s:S:t:", long_options,
                         &option_index);

    /* Detect the end of the options. */
    if (op->op == -1)
      break;

    switch (op->op) {
    case 0:
      /* If this option set a flag, do nothing else now. */
      if (long_options[option_index].flag != 0)
        break;
      printf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s", optarg);
      printf("\n");
      break;

    case 'c':
      op->curve_flag = 1;
      break;

    case 'd':
      op->dump_flag = 1;
      break;

    case 'e':
      op->emoji_flag = 1;
      break;

    case 'h':
      help_menu();
      free(op);
      exit(1);

    case 'l':
      op->lambda = atoi(optarg);
      break;

    case 'm':
      strcpy(op->model, optarg);
      break;

    case 'p':
      op->panic = atoi(optarg);
      break;

    case 'r':
      op->random = atoi(optarg);
      break;

    case 's':
      op->seed = atoi(optarg);
      break;

    case 'S':
      strcpy(op->map_path, optarg);
      break;

    case 't':
      op->timesteps = atoi(optarg);
      break;

    case 'v':
      op->verbose_flag = 1;
      break;

    case 'w':
      op->wait_flag = 1;
      break;

    case 'x':
      op->noex_flag = 1;
      break;

    case '?':
      /* getopt_long already printed an error message. */
      break;

    default:
      free(op);
      abort();
    }
  }
  return op;
}

void destroy_opts(t_options *op) { free(op); }

void help_menu() {
  printf("\x1b[0;32mTESS v.0\x1b[0m\n");
  printf("TESS Evacuation Simulation System\n");
  printf("\n\x1b[0;33mUSAGE:\x1b[0m\n");
  printf("   \x1b[0;32m./tess [OPTIONS]\x1b[0m\n");
  printf("\n\x1b[0;33mOPTIONS:\x1b[0m\n");

  printf("   \x1b[0;32m-c, --curve\x1b[0m\n");
  printf("      Pedestrians go around obstacles.\n\n");

  printf("   \x1b[0;32m-d, --dump\x1b[0m\n");
  printf("      Export the simulation to the dump file.\n\n");

  printf("   \x1b[0;32m-e, --emoji\x1b[0m\n");
  printf("      Print emojis in the simulation\n");
  printf("      Only avaliable with the verbose option.\n\n");

  printf("   \x1b[0;32m-h, --help\x1b[0m\n");
  printf("      Print this help menu.\n\n");

  printf("   \x1b[0;32m-l, --lambda <int> \x1b[0m\n");
  printf("      Diagonal proportion rate.\n\n");

  printf("   \x1b[0;32m-m, --model <string>\x1b[0m\n");
  printf("      Choose the simulation model.\n\n");

  printf("   \x1b[0;32m-p, --panic <int>\x1b[0m\n");
  printf("      Panic rate. Probability of the pedestrians do not move.\n\n");

  printf("   \x1b[0;32m-r, --randow <int>\x1b[0m\n");
  printf("      Qtd. of random pedestrians on map.\n");
  printf("      When 0, TESS use the default pedestrians in the scenario "
         "file.\n\n");

  printf("   \x1b[0;32m-s, --seed <int>\x1b[0m\n");
  printf("      Integer to generate random numbers.\n\n");

  printf("   \x1b[0;32m-S, --scenario <string> \x1b[0m\n");
  printf("      Path to the scenario file.\n\n");

  printf("   \x1b[0;32m-t, --timesteps\x1b[0m\n");
  printf("      Qtd. of time steps in the simulation.\n\n");

  printf("   \x1b[0;32m-v, --verbose\x1b[0m\n");
  printf("      Print the entire animation.\n\n");

  printf("   \x1b[0;32m-x, --noex\x1b[0m\n");
  printf("      Pedestrians do not cross paths.\n\n");
}
