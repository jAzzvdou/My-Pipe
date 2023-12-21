/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:31:28 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/21 16:31:31 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_write(char *e)
{
	write(2, e, ft_strlen(e));
	exit(1);
}

void	error_perror(char *e)
{
	perror(e);
	exit (1);
}
