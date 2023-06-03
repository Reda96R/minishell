#include "../../includes/minishell.h"

char	*ft_path_finder(char **vars)
{
	int		i;
	char	*path;

	i = 0;
  path = NULL;
  while (vars[i])
	{
		if (!ft_strncmp(vars[i], "PATH=", 5))
		{
			path = ft_substr(vars[i], 5, ft_strlen(vars[i]) - 5);
			break;
		}
		i++;
	}

	if (!path)
		path = ft_strdup("");
	return (path);
}

void	ft_envp_parser(t_data *data)
{
	char	*path;
	char	*str;
  char  *last_char;
	int	i;

	i = 0;
	path = ft_path_finder(data->vars);
	data->paths = ft_split(path, ':');
	free(path);

	while (data->paths[i])
	{
    last_char = &data->paths[i][ft_strlen(data->paths[i]) - 1];
		if (!ft_strncmp(last_char, "/", 1))
		{
			str = ft_strjoin(data->paths[i], "/");
			// free(data->paths[i]);
			data->paths[i] = str;
		}
		i++;
	}
}

int	ft_pwd_finder(t_data *data)
{
	int	i;

  i = 0;
	while (data->vars[i])
	{
		if (!ft_strncmp(data->vars[i], "PWD=", 4))
			data->pwd = ft_substr(data->vars[i], 4, ft_strlen(data->vars[i]) - 4);
		else if (!ft_strncmp(data->vars[i], "OLDPWD=", 7))
			data->old_pwd = ft_substr(data->vars[i], 7, ft_strlen(data->vars[i]) - 7);
		i++;
	}
	ft_envp_parser(data);
	return (1);
}

int	ft_env_setter(t_data *data, char **env)
{
	int		i;
	int		j;

	i = 0;
	while (env[i])
		i++;

	data->vars = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->vars)
		return (0);

	j = 0;
	while (j < i)
	{
		data->vars[j] = ft_strdup(env[j]);
		if (!data->vars[j])
		{
			while (j > 0)
				free(data->vars[--j]);
			free(data->vars);
			return (0);
		}
		j++;
	}
	data->vars[i] = NULL;
	ft_pwd_finder(data);
	return (1);
}

