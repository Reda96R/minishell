#include "../includes/minishell.h"

int main(int ac, char *av[], char *env[])
{
  int   i;
  char  **vars;

  i = 0;
  while (env[i])
    i++;
  if (!(vars = (char **)malloc(sizeof (char *) * i + 1)))
    return (0);
  i = 0;
  while (env[i])
  {
    vars[i] = ft_strdup((const char *)env[i]);
    i++;
  }
    vars[i] = 0;
}
