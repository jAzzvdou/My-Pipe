#include "pipex.h"

static void	cleaner_cmds(t_pipex *cmds, int size_cmds)
{
	int	i;

	i = -1;
	while (i < size_cmds)
	{
		free(cmds[i].path);
		cleaner_matrix(cmds[i].cmd_args);
	}
	free(cmds);
}

static int	single_command(t_pipex *pipex, char *cmd, char **envp)
{
	pipex->cmd_args = spliter(cmd, ' ');
	if (!pipex->cmd_args)
		return (1);
	pipex->path = pathfinder(pipex->cmd_args[0], envp);
	if (!pipex->path)
		return (1);
	return (0);
}

static int	all_commands(t_pipex **pipex_buffer, int size_cmds, char **cmds, char **envp)
{
	int	i;

	*pipex_buffer = malloc(sizeof(t_pipex) * size_cmds);
	if (!*pipex_buffer)
		return (1);
	ft_memset(*pipex_buffer, 0, sizeof(t_pipex) * size_cmds);
	i = -1;
	while (i < size_cmds)
	{
		if (single_command(*pipex_buffer + i, cmds[i], envp) != 0)
		{
			cleaner_cmds(*pipex_buffer, i);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (write(2, ".ERROR: Invalid Number Of Arguments.\n", 37));
	pipex = NULL;
	if (all_commands(&pipex, argc - 3, argv + 2, envp) != 0)
		return (write(2, ".ERROR: Failed To Parse Arguments.\n", 35));
	return (0);
}
