/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarzull <gmarzull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:31:01 by gmarzull          #+#    #+#             */
/*   Updated: 2023/03/30 12:15:28 by gmarzull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef void(*t_hook)(void *);

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		ft_error(1);
	cub = init_cub();
	if (!cub)
		ft_error(2);
	//check_map(cub, argv[1]);
	check_file(cub, argv[1]);
	mlx_loop_hook(cub->mlx_pointer, (t_hook) rendeer_minimap, cub);
	mlx_loop_hook(cub->mlx_pointer, ft_hook, cub);
	mlx_loop(cub->mlx_pointer);
	free_cub(cub);
	printf("Jai free, jai tout compris\n");
	return (0);
}
