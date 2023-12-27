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
	char	**cmd_args;
}	t_pipex;

//PIPEX
int	main(int argc, char **argv, char **envp);
char    *pathfinder(char *cmd, char **envp);

//UTILS
void    *ft_memset(void *s, int c, size_t n);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
char    **ft_split(char const *s, char c);
char    **spliter(char const *s, char c);

#endif //PIPEX
