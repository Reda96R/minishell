/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:42:53 by rerayyad          #+#    #+#             */
/*   Updated: 2023/07/26 13:56:46 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_dollar_s(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_gold_finder(t_data *data, char *str)
{
	(void) data;
	(void) str;
	// int		i;
	// char	*tmp0;
	// char	*tmp1;
	// char	*tmp2;
	//
	// i = 0;
	// tmp0 = ft_strdup("\0");
	// while (str[i])
	// {
	// 	i += ft_digit_skipper(str, i);
	// 	if (str[i] == '$' && str[i + 1])
	// 	{
	// 		if (str[i + 1] == '?')
	// 			i += ft_question_handler(&tmp0);
	// 		else if ((str[i + 1] != '"' || str[i + 2]) && str[i + 1] != ' ')
	// 			i += ft_translater(i, str, &tmp0, data);
	// 	}
	// 	else
	// 	{
	// 		tmp1 = ft_converer(str[i++]);
	// 		tmp2 = ft_strjoin(tmp0, tmp1);
	// 		free (tmp0);
	// 		tmp0 = tmp2;
	// 		free (tmp1);
	// 	}
	// }
	// return (tmp0);
	return (NULL);
}

char	**ft_expander(t_data *data, char **cmd)
{
	(void) data;
	(void) cmd;
	// char	*str;
	// int		i;
	//
	// i = 0;
	// cmd = NULL;
	// while (cmd[i])
	// {
	// 	if (ft_dollar_s(cmd[i]) && cmd[i][ft_dollar_s(cmd[i]) - 2] != '\''
	// 		&& cmd[i][ft_dollar_s(cmd[i])])
	// 	{
	// 		str = ft_gold_finder(data, cmd[i]);
	// 		free(cmd);
	// 		cmd[i] = str;
	// 	}
	// 	if (ft_strncmp(cmd[0], "export", ft_strlen(str[0]) - 1))
	// 	{
	// 		cmd = ft_rm_quote(cmd[i], '\"');
	// 		cmd = ft_rm_quote(cmd[i], '\'');
	// 	}
	// 	i++;
	// }
	return (cmd);
}
