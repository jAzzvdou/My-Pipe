/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:22:16 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/18 16:22:53 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_info
{
	pid_t	pid_one;
	pid_t	pid_two;
	int		pipez[2];
	int		infile;
	int		outfile;
	char	*path;
	char	*command;
	char	**commands;
	char	**commands_path;
}	t_info;

// PIPEX
int	main(int argc, char **argv, char **envp)

//HELP FUNCTIONS
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

// ERRORS
void	error_soft(char *e);
void	error(char *e);

#endif //PIPEX
