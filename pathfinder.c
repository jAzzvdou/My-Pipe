#include "pipex.h"

char *pathfinder(char *cmd, char **envp)
{
	int	i;
	int	ii;
	char	**paths;
	char	*aux;
	char	*path;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		fprintf(stderr, "%s command not found1\n", cmd);
		return (NULL);
	}
	paths = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (paths == NULL)
				return (NULL);
			break ;
		}
	}
	if (paths == NULL)
	{
		fprintf(stderr, "%s command not found2\n", cmd);
		return (NULL);
	}
	aux = ft_strjoin("/", cmd);
	if (aux == NULL)
	{
		cleaner_matrix(paths);
		return (NULL);
	}
	ii = -1;
	while (paths[++ii])
	{
		path = ft_strjoin(paths[i], aux);
		if (path == NULL)
		{
			free(aux);
			cleaner_matrix(paths);
			return (NULL);
		}
		if (access(path, X_OK) == 0)
		{
			free(aux);
			cleaner_matrix(paths);
			return (path);
		}
		free(path);
	}
	cleaner_matrix(paths);
	fprintf(stderr, "%s command not found\n", cmd);
	return (NULL);
}
