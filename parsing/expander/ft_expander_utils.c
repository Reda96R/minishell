#include "../../includes/minishell.h"

char	*ft_converter(char c, t_data *data)
{
	char	*str;

	str = (char *) malloc(sizeof (char) * 2);
	if (!str)
		ft_errors_buster(4, data);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

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
	free (*str);
	// *str = ft_itoa(g_var.exit_status);
	*str = "127";
	return (ft_strlen(*str) + 1);
}

int	ft_translator(int i, char *str, char **tmp, t_data *data)
{
	char	*tmp0;
	char	*tmp1;
	int		r;
	t_vars	*var;

	r = 0;
	var = data->vars;
	while (var)
	{
		if (ft_strncmp(str + i + 1, var->key, ft_strlen(var->key)))
		{
			tmp0 = ft_strdup(var->value);
			tmp1 = ft_strjoin(*tmp, tmp0);
			free (*tmp);
			*tmp = tmp1;
			free (tmp0);
			// r = 
		}
		var = var->next;
	}
	return (r);
}
