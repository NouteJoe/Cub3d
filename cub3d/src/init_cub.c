/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:40:41 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 15:41:16 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_cub	*init_cub(void)
{
	t_cub	*cub;

	cub = malloc(sizeof(*cub));
	if (!cub)
		return (NULL);
	cub->mlx_pointer = init_mlx();
	if (!cub->mlx_pointer)
		ft_error(2);
	cub->ptr_img = mlx_new_image(cub->mlx_pointer, WIDTH / 1.5, HEIGHT / 2);
	if (!cub->ptr_img)
	{
		mlx_close_window(cub->mlx_pointer);
		ft_error(2);
	}
	if (mlx_image_to_window(cub->mlx_pointer, cub->ptr_img, 0, 0) == -1)
	{
		mlx_close_window(cub->mlx_pointer);
		ft_error(2);
	}
	cub->tmp = NULL;
	cub->get_next = NULL;
	cub->flag = 0;
	cub->SO = NULL;
	cub->WE = NULL;
	cub->EA = NULL;
	cub->NO = NULL;
	//ajouter t_color c et f ??
	return (cub);
}

uint32_t	init_color(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a)
{
	u_int8_t	pixel_color[4];

	pixel_color[0] = a;
	pixel_color[1] = b;
	pixel_color[2] = g;
	pixel_color[3] = r;
	return (*(u_int32_t *)pixel_color);
}

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx_pointer;

	mlx_pointer = mlx_init(WIDTH, HEIGHT, "cub3d", 1);
	if (!(mlx_pointer))
		ft_error(2);
	return (mlx_pointer);
}
