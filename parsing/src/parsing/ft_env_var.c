#include "../../includes/minishell.h"

int ft_pwd_finder(t_data *data)
{
  int i;

  i = 0;
  while (data->vars[i])
  {
    if (!ft_strncmp(data->vars[i], "PWD=", 4))
      data->pwd = ft_substr(data->vars[i], 4, \
      ft_strlen(data->vars[i]) - 4);
    if (!ft_strncmp(data->vars[i], "OLDPWD=", 7))
      data->old_pwd = ft_substr(data->vars[i], 7, \
      ft_strlen(data->vars[i]) - 7);
    i++;
  }
  return (1);
}
