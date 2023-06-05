#include "includes/minishell.h"

void  ft_errors_buster(int id)
{
  if (id == 1)
    printf("ERROR: run without argument\n");
  exit (0);
}
