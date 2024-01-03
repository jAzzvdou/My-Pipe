/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:21:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/01/03 17:37:26 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int	infile;
	int	outtfile;
	char	*path;
	char	**cmdargs;
}	t_pipex;

//----------PIPEX----------//
int	main(int argc, char **argv, char **envp);
char	**spliter(char *cmd);

//----------QUOTE----------//
int	verify_quote(char *cmd, int i);
int	is_quote(char *cmd, int i);

//----------UTILS----------//
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif //PIPEX
