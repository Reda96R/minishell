#include "../includes/minishell.h"

int ft_token_identifier(t_data *data, int i)
{
  if (data->input[i] == '|')
    {
      if (!ft_token_identifier(data, i + 1))
      {
        data->pipes++;
        return (PIPE);
      }
      return (-1);
    }
  else if (data->input[i] == '>')
  {
    if (data->input[i + 1] == '>' && !ft_token_identifier(data, i + 2))
  return (D_GREATER);
    else if (!ft_token_identifier(data, i + 1))
      return (GREATER);
    return (-1);
  }
  else if (data->input[i] == '<')
  {
    if (data->input[i + 1] == '<' && !ft_token_identifier(data, i + 2))
      return (D_LESS);
    else if (! ft_token_identifier(data , i + 1))
      return (LESS);
    return (-1);
  }
  return (0);
}

int ft_token_parser(t_data *data, int *node_id, int id)
{
  t_mylxr *new;

  new = NULL;
  if (!ft_new_node(&new, id, NULL) || !new)
    return (-1);
  new->node_id = (*node_id)++;
  ft_add_node(&data->mylexer, new);
  if (id == 3 || id == 5)
    return (2);
  return (1);
}

int ft_words_parser(t_data *data, int *node_id, int i)
{
  t_mylxr *new;
  int     j;

  new = NULL;
  j = 0;
  while (data->input[i + j] && !ft_token_identifier(data, i + j))
  {
    j += ft_quote_skiper(data->input, '\"', i + j);
    j += ft_quote_skiper(data->input, '\'', i + j);
    if (ft_isspace(data->input[i + j]))
      break ;
    j++;
  }
	if (!ft_new_node(&new, 0, ft_substr(data->input, i, j)) || !new)
		return (-1);
	new->node_id = (*node_id)++;
	ft_add_node(&data->mylexer, new);
	return (j);
}

int ft_token_scanner(t_data *data)
{
  int i;
  int j;
  int id;
  int node_id;

  i = 0;
  j = 0;
  node_id = 0;
  data->pipes = 0;
  while (data->input[i])
  {
    while (data->input[i] && ft_isspace(data->input[i]))
      i++;
    id = ft_token_identifier(data, i);
    if (id < 0 || (id && !node_id))
      return (-1);
    if (id)
      j = ft_token_parser(data, &node_id, id);
    else
      j = ft_words_parser(data, &node_id, i);
    if (j < 0)
      return (0);
    i += j;
  }
  return (1);
}
