#include "includes/minishell.h"

int main(int ac, char *av[], char *env[])
{
  t_data  data;

  // (void)ac;
  // (void)av;
  if (ac > 1 || av[1])
    ft_errors_buster(1);
  if (!ft_env_setter(&data, env))
    return (0);
}
