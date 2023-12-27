#include "pipex.h"

char	*absolute_path(char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		write(2, ".ERROR: Command Not Found.\n", 27);
		return (NULL);
	}
	return (NULL);
}

char	*env_path(char **envp)
{
	int	i;
	char	**paths;

	paths = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				return (NULL);
			break ;
		}
	}
	if (!paths)
	{
		write(2, ".ERROR: PATH Not Found In ENV.\n", 31);
		return (NULL);
	}
	return (paths);
}

char    *pathfinder(char *cmd, char **envp)
{
        char    *abso_path;
        char    **paths;
        char    *cmd_path;

        abso_path = absolute_path(cmd);
        if (abso_path)
                return (abso_path);
        paths = env_path(envp);
        if (!path)
                return (NULL);
        cmd_path = command_path(cmd, paths);
        cleaner_matrix(paths);
        if (!cmd_path)
                write(2, ".ERROR: Command Not Found.\n", 27);
        return (cmd_path);
}
