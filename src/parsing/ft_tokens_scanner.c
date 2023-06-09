#include "../includes/minishell.h"

int ft_token_identifier(t_data *data, int i)
{
  if (data->input[i] == '|')
    {
      if (!ft_token_identifier(data, i + 1))
        return (PIPE);
      else
        ft_errors_buster(3, data);
    }
  else if (data->input[i] == '>')
  {
    if (data->input[i + 1] == '>' && !ft_token_identifier(data, i + 2))
      return (D_GREATER);
    else if (!ft_token_identifier(data, i + 1))
      return (GREATER);
    else
      ft_errors_buster(3, data);
  }
  else if (data->input[i] == '<')
  {
    if (data->input[i + 1] == '<' && !ft_token_identifier(data, i + 2))
      return (D_LESS);
    else if (! ft_token_identifier(data , i + 1))
      return (LESS);
    else
      ft_errors_buster(3, data);
  }
  return (0);
}

int ft_token_parser(char *str, t_mylxr *mylexer, int *node_id, int id)
{
  t_mylxr *new;

  (void)str;
  new = NULL;
  // ft_new_node(mylexer, new, id, NULL);
  if (!ft_new_node(new, id, NULL) || !new)
    return (-1);
  new->id = *node_id++;
  ft_add_node(mylexer, *new);
  if (id == 3 || id == 5)
    return (2);
  return (1);
}

// int ft_words_parser(char *str, t_mylxr mylexer, int *node_id, int i)
// {
//   t_mylxr *new;
//   int     j;
//
//   j = 0;
//   new = NULL;
//   if (!ft_new_node(new, 0, NULL) || !new)
//     return (-1);
//   while (str[i + j] && !ft_token_identifier())
//
//
//   i = 0;
//   while ()
// }

int ft_token_scanner(t_data *data)
{
  int i;
  int j;
  int id;
  int node_id;

  i = 0;
  j = 0;
  node_id = 0;
  while (data->input[i])
  {
    while (data->input[i] && ft_isspace(data->input[i]))
      i++;
    id = ft_token_identifier(data, i);
    if (id)
      j += ft_token_parser(data->input, &data->mylexer, &node_id, id);
    // else
      // j += ft_words_parser(data->input, data->mylexer, &node_id, i);
    else
      return (0);
    if (j < 0)
      return (0);
    i += j;
  }
  return (1);
}
