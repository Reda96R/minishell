/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:02 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/06 15:58:05 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int ac, char *av[], char *env[])
{
  t_data  data;

  if (ac > 1 || av[1])
    ft_errors_buster(1, &data);
  if (!ft_env_setter(&data, env, 1))
    return (0);
  data.color = 1;
  ft_shell_starter(&data);
  return (0);
}
