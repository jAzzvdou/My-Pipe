/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/04 17:34:15 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

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
void	cmd_controller(t_pipex *pipex, int cmds_size, char **cmds);
char	**spliter(char *cmd);
char	*pathfinder(t_pipex *pipex);

//----------CLEANER----------//
void	cleaner_matrix(char **matrix);

//----------QUOTE----------//
int		verify_quote(char *cmd, int i);
int		is_quote(char *cmd, int i);

//----------UTILS----------//
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

#endif //PIPEX
