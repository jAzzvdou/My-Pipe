#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int	infile;
	int	outfile;
	char	*path;
	char	*cmd_args;
}	t_pipex;
