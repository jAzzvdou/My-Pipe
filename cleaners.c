/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:31:19 by jazevedo          #+#    #+#             */
/*   Updated: 2023/12/21 16:31:23 by jazevedo         ###   ########.fr       */
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
