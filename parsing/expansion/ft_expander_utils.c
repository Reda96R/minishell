#include "../../includes/minishell.h"

int	ft_digit_skipper(char *str, int n)
{
	int	i;

	i = n;
	if (str[n] == '$')
		if (ft_isdigit(str[n + 1]))
			n += 2;
	return (n - i);
}

int	ft_question_handler(char **str)
{
	free (str);
	*str = ft_itoa(g_var.error_status);
	return (ft_strlen(*str) + 1);
}

int	  ft_dollar_skipper(int i, char *str, char **tmp, t_data *data)
{
}
