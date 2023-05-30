#include "../includes/minishell.h"

int ft_env_setter(char **vars, char **env)
{
  int i;

  i = 0;
  while (env[i])
    i++;
  if (!(vars = (char **)malloc (sizeof (char *) * i + 1)))
    return (0);
  i = 0;
  while (env[i])
  {
    vars[i] = ft_strdup((const char *)env[i]);
    if (!vars[i])
    {
      free (vars);
      return (0);
    }
    i++;
  }
  vars[i] = 0;
  return (1);
}

int main(int ac, char *av[], char *env[])
{
  char  **vars;

  (void) ac;
  (void) av;
  vars = NULL;
  if (!ft_env_setter(vars, env))
    return (0);
}
