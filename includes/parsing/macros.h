/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:34:40 by rerayyad          #+#    #+#             */
/*   Updated: 2023/06/06 16:34:42 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*------------Parsing------------*/
/*::: prompt :::*/
# define READLINE_MSG_G "\033[32m<?> \033[0m"
# define READLINE_MSG_R "\033[0;31m<?> \033[0m"
// # define READLINE_MSG_G "\033[32mminishell\033[0m<?> "
// # define READLINE_MSG_R "\033[0;31mminishell\033[0m<?> "

/*::: tokens :::*/
# define PIPE 1
# define GREATER 2
# define D_GREATER 3
# define LESS 4
# define D_LESS 5


#endif
