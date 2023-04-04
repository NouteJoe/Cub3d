/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:37:22 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/28 16:11:52 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
	if (!check_map(argv[1]))
	{
		printf("Map not valid. Onluy .cub files accepted.");
		exit (0);
	}
	map->cub = argv[1];
	map->fd = open(map->cub, O_RDONLY);
	if (map->fd == -1)
		exit (EXIT_FAILURE);
	printf("Map saved in map.cub");
*/
/*
int	check_map(t_cub *cub, char *str)
{
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		ft_error(3);
	cub->map_cub = str;
	cub->fd = open(cub->map_cub, O_RDONLY);
	if (cub->fd < 0)
		ft_error(2);
	init_map(cub);
	if (!check_compas(cub) || !check_color(cub) || !check_map2(cub))
		ft_error(3);
	init_player(cub);
	if (!cub->player)
		ft_error(2);
	return (1);
}

int	check_compas(t_cub *cub)
{
	(void) cub;
	//cub->NO = ....;
	return (1);
}

int	check_color(t_cub *cub)
{
	(void) cub;
	return (1);
}

int	check_map2(t_cub *cub)
{
	(void) cub;
	return (1);
}
*/