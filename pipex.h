/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/08 16:52:45 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h> //WRITE
# include <stdlib.h> //MALLOC, NULL
# include <fcntl.h> //OPEN
# include <sys/wait.h> //WAITPID
# include <stdio.h> //PERROR

typedef struct s_pipex
{
	pid_t	pid;
	int		pipe[2];
	int		fd[2];
	char	*path;
	char	**cmdargs;
	char	**envi;
}	t_pipex;

//----------PIPEX----------//
int		main(int argc, char **argv, char **envp);
void	cmd_controller(t_pipex *pipex, int cmds_size, char **cmdsi, int i);
char	**spliter(char *cmd);
char	*pathfinder(t_pipex *pipex);

//----------CLEANER----------//
void	cleaner_matrix(char **matrix);

//----------QUOTE----------//
int		verify_quote(char *cmd, int i);
int		is_quote(char *cmd, int i);
char	*remove_quote(char *trim, char quote);

//----------UTILS----------//
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif //PIPEX
