#include "../includes/minishell.h"

int ft_env_setter(t_data *data, char **env)
{
  int i;

  i = 0;
  while (env[i])
    i++;
  data->vars = (char **)malloc (sizeof (char *) * (i + 1));
  if (!data->vars)
    return (0);
  i = 0;
  while (env[i])
  {
    data->vars[i] = ft_strdup((const char *)env[i]);
    if (!data->vars[i])
    {
      free (data->vars);
      return (0);
    }
    i++;
  }
  data->vars[i] = 0;
  ft_pwd_finder(data);
  return (1);
}

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
