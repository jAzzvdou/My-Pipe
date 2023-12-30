#include "pipex.h"

int	all_commands(t_pipex *pipex, int argc, char **commands, char **envp)
{
	int	i;

	i = 1;
	while (++i < argc - 1)
	{
		if (single_command(commands[i]) != 0)
		{
			cleaner
	return (0);
}

int	start_pipex(t_pipex *pipex, int argc, char **argv)
{
	pipex->path = NULL;
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
	if (pipex->infile < 0 | pipex->outfile < 0)
		return (1);
	return (0);
}	

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	if (argc != 5)
		return (write(2, ".ERROR: Invalid Number Of Arguments.\n", 37));
	if (start_pipex(&pipex, argc, argv) != 0)
		return (write(2, ".ERROR: start_pipex.\n", 21));
	if (all_commands(&pipex, argc, argv, envp) != 0);
		return (write(2, ".ERROR: all_commands.\n", 22)); 
	return (0);
}
