/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:36:27 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 16:09:14 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rendeer_minimap(t_cub *cub)
{
	int			i;
	int			j;
	u_int32_t	pixel_color;
	u_int32_t	pixel_color2;
	u_int32_t	pixel_color3;

	pixel_color = init_color(0, 200, 0, 255);
	pixel_color2 = init_color(100, 0, 255, 255);
	pixel_color3 = init_color(200, 0, 0, 255);
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				make_square(cub, j * 10, i * 10, pixel_color);
			if (is_walkable(cub->map[i][j]) == true)
				make_square(cub, j * 10, i * 10, pixel_color2);
			j++;
		}
		i++;
	}
	make_player(cub, pixel_color3);
	make_player_fov(cub, pixel_color3);
}

bool	is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	else
		return (false);
}

void	make_square(t_cub *cub, int x, int y, u_int32_t pixel_color)
{
	int			x1;
	int			y1;

	x1 = x;
	while (x1 <= x + 10)
	{
		y1 = y;
		while (y1 <= y + 10)
		{
			mlx_put_pixel(cub->ptr_img, x1, y1, pixel_color);
			y1++;
		}
		x1++;
	}
}

void	make_player(t_cub *cub, u_int32_t pixel_color)
{
	int r = 5;
	int Cx = cub->player->pos.x;
	int Cy = cub->player->pos.y;

	int x = 0;
	int y = r;

	while (x <= y)
	{
		mlx_put_pixel(cub->ptr_img, Cx + x, Cy + y, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx + x, Cy - y, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx - x, Cy + y, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx - x, Cy - y, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx + y, Cy + x, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx + y, Cy - x, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx - y, Cy + x, pixel_color);
		mlx_put_pixel(cub->ptr_img, Cx - y, Cy - x, pixel_color);
		x++;
		if (x * x + y * y > r * r)
			y--;
	}
	// centre du cercle : cub->player->pos.x - 5, cub->player->pos.y - 5;	
}

void	make_player_fov(t_cub *cub, uint32_t pixel_color)
{
	
	int			Cx = cub->player->pos.x;
	int			Cy = cub->player->pos.y;
	int			delta = 0;
/*
	double	x;
	double	y;

	ft_raycast(cub);
	x = cub->ray->start.x;
	y = cub->ray->start.y;*/
	
	while (delta <= 20)
	{
		mlx_put_pixel(cub->ptr_img, Cx + (cub->player->dir.x * delta),
			Cy + (cub->player->dir.y * delta), pixel_color);
		delta++;
	}
	
/*
	while (x <= HEIGHT / 1.5)
	{
		y = cub->ray->start.y;
		while (y <= WIDTH / 2)
		{
			mlx_put_pixel(cub->ptr_img,(int)x,
			(int)y, pixel_color);
			y++;
		}
		x++;
	}
*/	
}
