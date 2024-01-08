#include "pipex.h"

void	heredoc(t_pipex *pipex, char *limiter)
{
	char	*str_input;

	while (strncmp(str_input, limiter, ft_strlen(str_input)) != 0)
	{
		write(1, "> ", 2);
		str_input = get_next_line(0);
		write(pipex->fd[0], str_input, ft_strlen(str_input));
		write(pipex->fd[0], "\n", 1);
		free(str_input);
	}
	cmd_controller(pipex, argc, argv);
}

static int	start_heredoc(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->path = NULL;
	pipex->cmdargs = NULL;
	pipex->envi = envp;
	pipex->fd[0] = open(".here_doc", O_CREAT | O_RDWR | O_TRUNC, 00700);
	pipex->fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
	if (pipex->fd[0] < 0) 
		return (1);
}

static int      start_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
        pipex->path = NULL;
        pipex->cmdargs = NULL;
        pipex->envi = envp;
        pipex->fd[0] = open(argv[1], O_RDONLY);
        pipex->fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 00700);
        if (pipex->fd[0] < 0 || pipex->fd[1] < 0)
                return (1);
        return (0);
}

int     main(int argc, char **argv, char **envp)
{
        t_pipex pipex;

        if (argc < 5)
                return (write(2, ".ERROR: Invalid Number Of Arguments.\n", 37));
	if (strncpm(argv[1], "here_doc", strlen("here_doc")) == 0)
	{
		if (argc < 6)
			return (write(2, ".ERROR: argc != 6.\n", 19));
		if (start_heredoc(&pipex, argc, argv, envp) != 0)
			return (write(2, ".ERROR: start_heredoc.\n", 22));
		heredoc(&pipex, argv[2]);
	}
	else
	{
        	if (start_pipex(&pipex, argc, argv, envp) != 0)
                	return (write(2, ".ERROR: start_pipex.\n", 20));
        	cmd_controller(&pipex, argc, argv);
	}
        return (0);
}
