/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:46:10 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 11:25:57 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_cub *cub)
{
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
		ft_error(2);
	cub->ray = malloc(sizeof(t_ray));
	if (!cub->ray)
		ft_error(2);
	init_vector(&cub->ray->start);
	init_vector(&cub->ray->end);
	init_vector(&cub->player->pos);
	init_vector(&cub->player->dir);
	cub->player->movspeed = 0.5;
	cub->player->rotspeed = 0.1;
	find_player(cub);
}

void	init_vector(t_vector *vector)
{
	vector->x = 0.0;
	vector->y = 0.0;
	return ;
}

void	find_player(t_cub *cub)
{
	int			i;
	int			j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (is_walkable(cub->map[i][j]) == true && cub->map[i][j] != '0')
			{
				cub->player->pos.x = j * 10 + 5;
				cub->player->pos.y = i * 10 + 5;
				find_dir(cub->map[i][j], &cub->player->dir);
			}
			j++;
		}
		i++;
	}
}

void	find_dir(char c, t_vector *dir)
{
	if (c == 'N')
	{
		dir->x = 0;
		dir->y = -1;
	}
	if (c == 'W')
	{
		dir->x = -1;
		dir->y = 0;
	}
	if (c == 'S')
	{
		dir->x = 0;
		dir->y = 1;
	}
	if (c == 'E')
	{
		dir->x = 1;
		dir->y = 0;
	}
}
