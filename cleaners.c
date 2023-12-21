/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:30:48 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/21 11:33:32 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleaner_child(t_info *info)
{
	int	i;

	i = -1;
	while (info->cmds[++i])
		free(info->cmds[i]);
	free(info->cmds);
	free(info->cmd);
}

void	cleaner(t_info *info)
{
	int	i;

	i = -1;
	close(info->infile);
	close(info->outfile);
	while (info->cmd_path[++i])
		free(info->cmd_path[i]);
	free(info->cmd_path);
}
