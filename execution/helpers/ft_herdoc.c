#include "../../includes/minishell.h"

int	ft_heredoc(t_data *data, char *file, t_mylxr *heredoc)
{
	int	sl;
	int	quote;

	sl = EXIT_SUCCESS;
	if ((heredoc->str[0] == '\"'
	 && heredoc->str[ft_strlen(heredoc->str) - 1] == '\"')
	|| (heredoc->str[0] == '\''
		&& heredoc->str[ft_strlen(heredoc->str) - 1] == '\''))
		quote = 1;
	else
		quote  = 0;
	ft_rm_quote(heredoc->str, '\"');
	ft_rm_quote(heredoc->str, '\'');
	// g_var.hd_stop = 0;
	// g_var.hd_in = 1;
	sl = ft_hd_creator(data, heredoc, quote, file);
	// g_var.hd_in = 0;
	// data->hd = 1;
	return (sl);
}
