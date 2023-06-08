#include "../includes/minishell.h"

int ft_new_node(t_mylxr *new ,int id, char *str)
{
  new = (t_mylxr *) malloc(sizeof (t_mylxr));
  if (!new)
    return (0);
  new->id = id;
  new->str = str;
  new->next = NULL;
  new->prev = NULL;
  return (1);
}

void  ft_add_node(t_mylxr *mylxr, t_mylxr new)
{
  t_mylxr *tmp;

  tmp = mylxr;
  if (!mylxr)
  {
    *mylxr = new;
    return ;
  }
  while (tmp->next)
    tmp = tmp->next;
  *tmp->next = new;
  new.prev = tmp;
}
