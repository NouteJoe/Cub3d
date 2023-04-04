/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:25:31 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 10:40:43 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)(param);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx_pointer);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_W))
		ft_move(cub, MLX_KEY_W);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_S))
		ft_move(cub, MLX_KEY_S);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_A))
		ft_move(cub, MLX_KEY_A);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_D))
		ft_move(cub, MLX_KEY_D);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_RIGHT))
		ft_rotate(cub, MLX_KEY_RIGHT);
	if (mlx_is_key_down(cub->mlx_pointer, MLX_KEY_LEFT))
		ft_rotate(cub, MLX_KEY_LEFT);
}

void	ft_move(t_cub *cub, keys_t key)
{
	if (key == MLX_KEY_W)
	{
		cub->player->pos.x += cub->player->dir.x * cub->player->movspeed;
		cub->player->pos.y += cub->player->dir.y * cub->player->movspeed;
	}
	if (key == MLX_KEY_S)
	{
		cub->player->pos.x -= cub->player->dir.x * cub->player->movspeed;
		cub->player->pos.y -= cub->player->dir.y * cub->player->movspeed;
	}
	if (key == MLX_KEY_D)
	{
		cub->player->pos.x -= cub->player->dir.y * cub->player->movspeed;
		cub->player->pos.y += cub->player->dir.x * cub->player->movspeed;
	}
	if (key == MLX_KEY_A)
	{
		cub->player->pos.x += cub->player->dir.y * cub->player->movspeed;
		cub->player->pos.y -= cub->player->dir.x * cub->player->movspeed;
	}
}

void	ft_rotate(t_cub *cub, keys_t key)
{
	double	oldx;
	double	oldy;

	oldx = cub->player->dir.x;
	oldy = cub->player->dir.y;
	if (key == MLX_KEY_LEFT)
	{
		cub->player->dir.x = cub->player->dir.x * cos(-cub->player->rotspeed)
			- cub->player->dir.y * sin(-cub->player->rotspeed);
		cub->player->dir.y = oldx * sin(-cub->player->rotspeed)
			+ oldy * cos(-cub->player->rotspeed);
	}
	if (key == MLX_KEY_RIGHT)
	{
		cub->player->dir.x = cub->player->dir.x * cos(cub->player->rotspeed)
			- cub->player->dir.y * sin(cub->player->rotspeed);
		cub->player->dir.y = oldx * sin(cub->player->rotspeed)
			+ oldy * cos(cub->player->rotspeed);
	}
}
