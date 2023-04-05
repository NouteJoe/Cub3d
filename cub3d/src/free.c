/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:32:49 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 15:45:24 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_cub(t_cub *cub)
{
	if (cub->map)
		free_tab(cub->map);
	//if (cub->text)
	//	free_tab(cub->text);
	if (cub->player)
		free(cub->player);
	// /!\ NON ALLOUE ICI! (Ou PTR invalide?)
	// if (cub->ray)
	// 	free(cub->ray);
	mlx_terminate(cub->mlx_pointer);
	close(cub->fd);
	if (cub)
		free(cub);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}
