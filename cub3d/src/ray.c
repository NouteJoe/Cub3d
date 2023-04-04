/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:40:06 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 15:53:06 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_raycast(t_cub *cub)
{
	float	angle;
	int		x;
	int		y;
	float	dx;
	float	dy;
	float	rx;
	float	ry;

	x = 0;
	y = 0;
	cub->ray->start = cub->player->pos;
	cub->ray->end = cub->player->pos;
	angle = atan2(cub->player->dir.y, cub->player->dir.x);
	while (x < WIDTH / 1.5)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			dx = (float)x - cub->player->pos.x;
			dy = (float)y - cub->player->pos.y;
			rx = dx * cos(angle) + dy * sin(angle);
			ry = dy * cos(angle) - dy * sin(angle);
			if (ry == 0)
			{
				cub->ray->end.x = cub->player->pos.x + rx;
				cub->ray->end.y = cub->player->pos.y + ry;
				return ;
			}
			y++;
		}
		x++;
	}
	cub->ray->end.x = cub->player->pos.x + cub->player->dir.x * WIDTH / 1.5;
	cub->ray->end.y = cub->player->pos.y + cub->player->dir.y * HEIGHT / 2;
	return ;
}