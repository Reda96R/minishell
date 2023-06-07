/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:10 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/06 15:58:11 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void  ft_errors_buster(int id, t_data *data)
{
  if (id == 1)
    printf("ERROR: run without argument\n");
  else if (id == 2)
      printf("ERROR: unmatched quotes\n");
  data->color *= 0;
}
